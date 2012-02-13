//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "cRPLRPLapp.h"
#include "IPv6.h"
#include "IPv6ControlInfo.h"
#include <math.h>
#include "cRPLDODAGtableAccess.h"
#include "cRPLTrickle.h"
#include <cstringtokenizer.h>
#include "IPAddressResolver.h"
Define_Module(RPLapp);

void RPLapp::initialize()
{
	std::string str = par("const_ETX_values");
	ETX_values = cStringTokenizer(str.c_str()).asDoubleVector();
	ETX_values[getParentModule()->getParentModule()->getIndex()] = 0;

	m_rt = DODAGtableAccess().get();
	m_iMOP = par("MOP");
	m_iSr = par("Sr");
	m_iRf = par("Rf");
	m_dA = par("A");
	m_bIsRoot=par("isRoot");
	std::string str1 = par("RPLinstList");
	m_iRPLinstanceID = cStringTokenizer(str1.c_str()).asIntVector();
	cMessage *addr = new cMessage("addr");
	scheduleAt(simTime(),addr);

	WATCH_VECTOR(ETX_values);
}


void RPLapp::handleMessage(cMessage *msg)
{
	if(msg->isSelfMessage())
	{
		if(strcmp(msg->getName(),"addr")==0)
		{
			cModule *temp = getParentModule()->getParentModule()->getSubmodule("networkLayer6")->getSubmodule("ipv6");
			IPv6 *IP=check_and_cast<IPv6 *>(temp);
			m_srcAddr = IP->getIPv6();
			m_multAddr = IPv6Address::ALL_RPL_NODES;
			ASSERT(!m_multAddr.isUnspecified());
			if(m_bIsRoot)
			{
				simtime_t startTime = par("startTime");
				cMessage *msg = new cMessage("startRPL");
				scheduleAt(startTime,msg);
			}
		}
		else
		{
			RPLapp_vDODAGinitioanization();
		}
		delete msg;
	}
	else if(dynamic_cast<DIOMessage *>(msg))
	{
		RPLapp_vDIOhandler((DIOMessage *)msg);
	}
	else if(dynamic_cast<DISMessage *>(msg))
	{
		RPLapp_vDIShandler((DISMessage *)msg);
	}
	else if(dynamic_cast<DAOMessage *>(msg))
	{
		RPLapp_vDAOhandler((DAOMessage *)msg);
	}
	else if(dynamic_cast<DAOACKMessage *>(msg))
	{
		RPLapp_vDAOACKhandler((DAOACKMessage *)msg);
	}
	else if(strcmp(msg->getName(),"transmit")==0)
	{
		RPLapp_vTricklehandler(msg);
	}
	else
		delete msg;
}


void RPLapp::RPLapp_vDODAGinitioanization()
{
	//TODO update the values for virtual roots
	DODAG *dodag = new DODAG();
	dodag->DODAG_SetDODAGID(m_srcAddr);
	dodag->DODAG_SetDTSN(par("DTSN"));
	dodag->DODAG_SetInstanceID(par("RPLInstanceID"));
	dodag->DODAG_SetOCP(par("OCP"));
	dodag->DODAG_SetRank(ROOT_RANK);
	dodag->DODAG_SetVersionNumber(par("VersionNumber"));
	dodag->DODAG_SetTrickle(par("Imin"),par("Imax"),par("K"));
	dodag->DODAG_SetOF(par("MinHopRankInc"),par("MaxRankIncrease"));
	dodag->DODAG_SetPCS(par("PCS"));
	dodag->DODAG_SetLT(par("DefaultLifetime"),par("LifetimeUnit"));
	dodag->DODAG_SetPMG(par("Prf"),m_iMOP,par("Grounded"));
	dodag->DODAG_SetTrickleIndex(RPLapp_iGetTrickleFreeIndex());
	dodag->DODAG_SetMetric(par("Metric"));
	m_rt->DODAGtable_vAddDODAG(dodag);
	//start Trickle
	RPLapp_vSetTrickle(par("Imin"), par("Imax"), par("K"), dodag->DODAG_iGetTrickleIndex());
}


void RPLapp::RPLapp_vDIOhandler(DIOMessage *msg)
{
	int i=0;
	cArray arr = msg->getParList();
	for(i=0; i<arr.size(); i++)
	{
		cObject *obj = arr.get(i);

		DIOop *op = check_and_cast<DIOop *>(obj);
		switch(op->getType())
		{
		case Pad1:
		{
			EV<<"Pad1 received\n";
			break;
		}
		case PadN:
		{
			EV<<"PadN received\n";
			break;
		}
		case Metric_Container:
		{
			EV<<"Metric Container received\n";
			RPLapp_MetricConfiguration(msg, check_and_cast<METRIC_CONTop *>(obj));
			break;
		}
		case Routing_Information:
		{
			EV<<"Routing Information received\n";
			break;
		}
		case DODAG_CONFIGURATION:
		{
			EV<<"DODG configuration received\n";
			RPLapp_DIOconfiguration(msg, check_and_cast<DODAG_CONFop *>(obj));
			break;
		}
		case Prefix_Information:
		{
			EV<<"Prefix Information received\n";
			break;
		}
		default:
		{
			EV<<"wrong DIO message Type\n";
		}
		}
	}
	delete msg;
}


void RPLapp::RPLapp_DIOconfiguration(DIOMessage *msg, DODAG_CONFop *conf)
{
	uint8 Grounded, MOP, Prf;
	uint8 RPLInstanceID, VersionNumber, DTSN, OptL, FlagConf, A, PCS, DIOIntDoubl;
	uint8 DIOIntMin, DIORedun, OCP, LTU, DefLT;
	uint16 Rank, MinHopRankIncrease, MaxRankIncrease;
	IPv6Address DODAGID;
	IPv6Address srcParentAddr;

	IPv6ControlInfo *ctrl = (IPv6ControlInfo *)msg->getControlInfo();
	srcParentAddr = ctrl->getSrcAddr();
	//DIO header
	RPLInstanceID = msg->getRPLInstance();
	VersionNumber = msg->getVersionNumber();
	Rank = msg->getRank();
	Grounded = (msg->getGMP()>>7);
	MOP = (uint8_t)(msg->getGMP()<<2)>>5;
	Prf = (uint8_t)(msg->getGMP()<<5)>>5;
	DTSN = msg->getDTSN();
	DODAGID = msg->getDODAGID();

	//	DODAG configuration option
	OptL = conf->getOption_Length();
	FlagConf = conf->getFAP()>>4;
	A = (uint8_t)(conf->getFAP()<<4)>>7;
	PCS = (uint8_t)(conf->getFAP()<<5)>>5;
	DIOIntDoubl = conf->getDIOIntDoubl();
	DIOIntMin = conf->getDIOIntMin();
	DIORedun = conf->getDIORedun();
	MaxRankIncrease = conf->getMaxRankIncrease();
	MinHopRankIncrease = conf->getMinHopRankIncrease();
	OCP = conf->getOCP();
	DefLT = conf->getDef_Lifetime();
	LTU = conf->getLifetime_Unit();
	if(RPLapp_bCheckJoinConditions(DODAGID,RPLInstanceID,Prf,OCP,MOP))//TODO check metrics is missing
	{
		EV<<"DIO accepted\n";
		DODAG *storedDodag = m_rt->DODAGtable_GetDODAGbyID(DODAGID, RPLInstanceID);
		if(storedDodag == NULL)
		{
			EV<<"new DODAG configuration added\n";
			DODAG *dodag = new DODAG();
			dodag->DODAG_updateDIOParents(srcParentAddr, INFINITE_RANK/*RPLapp_iOF(Rank, OCP, MinHopRankIncrease, BASE_ETX)*/,msg->getKind(), BASE_ETX);//FIXME decide on initial ETX value when non received
			dodag->DODAG_SetDODAGID(DODAGID);
			dodag->DODAG_SetDTSN(DTSN);
			dodag->DODAG_SetInstanceID(RPLInstanceID);
			dodag->DODAG_SetOCP(OCP);
			dodag->DODAG_SetRank(INFINITE_RANK/*RPLapp_iOF(Rank, OCP, MinHopRankIncrease, BASE_ETX)*/);
			dodag->DODAG_SetVersionNumber(VersionNumber);
			dodag->DODAG_SetTrickle(DIOIntMin, DIOIntDoubl, DIORedun);
			dodag->DODAG_SetOF(MinHopRankIncrease, MaxRankIncrease);
			dodag->DODAG_SetPCS(PCS);
			dodag->DODAG_SetLT(DefLT, LTU);
			dodag->DODAG_SetPMG(Prf, MOP, Grounded);
			dodag->DODAG_SetTrickleIndex(RPLapp_iGetTrickleFreeIndex());
			m_rt->DODAGtable_vAddDODAG(dodag);
			RPLapp_vSetTrickle(DIOIntMin, DIOIntDoubl, DIORedun, dodag->DODAG_iGetTrickleIndex());
		}
		else
		{
			EV<<"DODAG already existing\n";
			if((unsigned int)(storedDodag->DODAG_iGetDODAGVersionNumber()) == VersionNumber)
			{
				if(storedDodag->DODAG_GetParentMetric(srcParentAddr) != 0)
				{
					if(storedDodag->DODAG_iGetRank() <= RPLapp_iOF(Rank, OCP, MinHopRankIncrease, storedDodag->DODAG_GetParentMetric(srcParentAddr)))
					{
						EV<<"no updates\n";
						//TODO if there is need to check for update in parent list (rfc 8.3)
						cMessage *cons = new cMessage("consistent");
						send(cons,"t_Trickle",storedDodag->DODAG_iGetTrickleIndex());
					}
					EV<<"parent set updated\n";
					m_rt->DODAGtable_iUpdateParentSet(DODAGID, RPLInstanceID, srcParentAddr, RPLapp_iOF(Rank, OCP, MinHopRankIncrease, storedDodag->DODAG_GetParentMetric(srcParentAddr)),msg->getKind(), storedDodag->DODAG_GetParentMetric(srcParentAddr));
				}
			}
			else if ((unsigned int)(storedDodag->DODAG_iGetDODAGVersionNumber()) < VersionNumber)
			{
				m_rt->DODAGtable_UpdateVN(DODAGID, RPLInstanceID, VersionNumber);
				cMessage *cons = new cMessage("inconsistent");
				send(cons,"t_Trickle",storedDodag->DODAG_iGetTrickleIndex());
			}
			else
			{
				EV<<"previous version received\n";
			}
		}
	}
	else
		EV<<"DIO denied\n";
}


void RPLapp::RPLapp_MetricConfiguration(DIOMessage *msg, METRIC_CONTop *met)
{
	uint8 Grounded, MOP, Prf, RPLInstanceID, VersionNumber, DTSN;
	uint16 Rank, myRank;
	IPv6Address DODAGID, srcParentAddr;
	double ETXv;

	IPv6ControlInfo *ctrl = (IPv6ControlInfo *)msg->getControlInfo();
	srcParentAddr = ctrl->getSrcAddr();
	//DIO header
	RPLInstanceID = msg->getRPLInstance();
	VersionNumber = msg->getVersionNumber();
	Rank = msg->getRank();
	Grounded = (msg->getGMP()>>7);
	MOP = (uint8_t)(msg->getGMP()<<2)>>5;
	Prf = (uint8_t)(msg->getGMP()<<5)>>5;
	DTSN = msg->getDTSN();
	DODAGID = msg->getDODAGID();

	//metric container
	DODAG *storedDodag = m_rt->DODAGtable_GetDODAGbyID(DODAGID, RPLInstanceID);
	if((RPLapp_iMetric(met->getRMCT(),CHECK_OF_MERIC, simulation.getModule(msg->getKind())->getIndex(), storedDodag->DODAG_GetParentMetric(srcParentAddr)) == SUPPORTED) && (storedDodag != NULL) && m_srcAddr != DODAGID)
	{
		ETX *etx = check_and_cast<ETX *>(met);
		EV<<"ETX update\n";
		storedDodag->DODAG_SetMetric(met->getRMCT());
		ETXv = RPLapp_iMetric(storedDodag->DODAG_iGetMetric(), etx->getETX_VALUE(), simulation.getModule(msg->getKind())->getIndex(), storedDodag->DODAG_GetParentMetric(srcParentAddr));
		myRank = RPLapp_iOF(Rank, storedDodag->DODAG_iGetOCP(), storedDodag->DODAG_iGetMinHopRankIncrease(), ETXv);
		m_rt->DODAGtable_iUpdateParentSet(DODAGID, RPLInstanceID, srcParentAddr, myRank, msg->getKind(), ETXv);
	}

	//visual effect only
	DODAG *td = m_rt->DODAGtable_GetDODAGbyID(DODAGID, RPLInstanceID);
	for(int i=0; i<getParentModule()->getParentModule()->gateSize("io$o"); i++)
		getParentModule()->getParentModule()->gate("io$o",i)->disconnect();
	for(int i=0; i<td->DODAG_iGetPCS()+1; i++)
	{
		int id = m_rt->DODAGtable_GetParentID(DODAGID, RPLInstanceID, VersionNumber, i);
		if(id!=-1)
		{
			cGate *g = getParentModule()->getParentModule()->gate("io$o",simulation.getModule(id)->getIndex());
			cGate *gn = simulation.getModule(id)->gate("io$i",getParentModule()->getParentModule()->getIndex());
			g->connectTo(gn);
		}
		else
			break;
	}
}


void RPLapp::RPLapp_vDIShandler(DISMessage *msg)
{

}


void RPLapp::RPLapp_vDAOhandler(DAOMessage *msg)
{

}


void RPLapp::RPLapp_vDAOACKhandler(DAOACKMessage *msg)
{

}


void RPLapp::RPLapp_vTricklehandler(cMessage *msg)
{
	uint8 Grounded, MOP, Prf;

	EV<<"trickle arrived\n";
	DODAG *dodag = m_rt->DODAGtable_GetDODAGbyTrickle(msg->getKind());
	DIOMessage *DIO = new DIOMessage("RPL-DIO",getParentModule()->getParentModule()->getId());
	Grounded = dodag->DODAG_iGetGrounded();
	MOP = dodag->DODAG_iGetMOP();
	Prf = dodag->DODAG_iGetPrf();
	DIO->setRPLInstance(dodag->DODAG_iGetRPLInstanceID());
	DIO->setVersionNumber(dodag->DODAG_iGetDODAGVersionNumber());
	DIO->setRank(dodag->DODAG_iGetRank());
	DIO->setGMP((Grounded<<7)+(0<<6)+(MOP<<3)+Prf);
	DIO->setDTSN(dodag->DODAG_iGetDTSN());
	DIO->setFlags(0);
	DIO->setReserved(0);
	DIO->setDODAGID(dodag->DODAG_GetDODAGID());
	DIO->setByteLength(DIO_HEADER);
	EV<<"rank= "<<(dodag->DODAG_iGetRank())<<"*******************\n";
	//add options
	RPLapp_vAddConfiguration(DIO,dodag);
	RPLapp_vAddETXMetric(DIO,dodag);
	EV<<"PETX="<<dodag->DODAG_GetParentMetric(dodag->DODAG_GetDIOparent(0))<<"\n";
//	RPLapp_vPAD(DIO,6);
//	RPLapp_vPAD(DIO,1);
	//==================================================================================================
	//TODO check hopLimit
	int hopLimit = 30;
	IPv6Address destAddr = m_multAddr;
	RPLapp_vSendToICMP(DIO, destAddr, m_srcAddr, hopLimit);
}


void RPLapp::RPLapp_vAddConfiguration(DIOMessage *DIO, DODAG *dodag)
{
	uint8 FlagConf, A, PCS;

	DODAG_CONFop *CONF = new DODAG_CONFop();
	CONF->setType(DODAG_CONFIGURATION);
	CONF->setOption_Length(DODAG_CONFIGURATION_LENGTH);
	FlagConf = 0;
	A = 0;
	PCS = dodag->DODAG_iGetPCS();
	CONF->setFAP((FlagConf<<4)+(A<<3)+PCS);
	CONF->setDIOIntDoubl(dodag->DODAG_iGetDIOIntDoubl());
	CONF->setDIOIntMin(dodag->DODAG_iGetDIOIntMin());
	CONF->setDIORedun(dodag->DODAG_iGetDIORedun());
	CONF->setMaxRankIncrease(dodag->DODAG_iGetMaxRankIncrease());
	CONF->setMinHopRankIncrease(dodag->DODAG_iGetMinHopRankIncrease());
	CONF->setOCP(dodag->DODAG_iGetOCP());
	CONF->setReserved(0);
	CONF->setDef_Lifetime(dodag->DODAG_iGetDefLT());
	CONF->setLifetime_Unit(dodag->DODAG_iGetLTU());
	DIO->addObject(CONF);
	DIO->setByteLength(DIO->getByteLength()+DODAG_CONFIGURATION_LENGTH);
}


void RPLapp::RPLapp_vAddETXMetric(DIOMessage *DIO, DODAG *dodag)
{
	ETX *MET = new ETX();
	MET->setType(Metric_Container);
	MET->setRMCT(dodag->DODAG_iGetMetric());
	MET->setFPC0(8);	// Flags=0, P=1, C=0, O=0
	MET->setRAP(0);		// R=0, A=0x00, Prec=0
	MET->setLength(2);	// ETX data length = 2bytes
//	EV<<"parent ETX: "<<dodag->DODAG_GetParentMetric(dodag->DODAG_GetDIOparent(0))<<"\n";
	MET->setETX_VALUE((uint16)(dodag->DODAG_GetParentMetric(dodag->DODAG_GetDIOparent(0))*128));
	DIO->addObject(MET);
	DIO->setByteLength(DIO->getByteLength()+ETX_LENGTH);
}


void RPLapp::RPLapp_vPAD(DIOMessage *DIO, int i)
{
	if(i == 1)
	{
		PAD1op *p = new PAD1op();
		p->setType(Pad1);
		DIO->addObject(p);
	}
	else
	{
		PADNop *p = new PADNop();
		p->setType(PadN);
		p->setOption_Length(i-2);
		DIO->addObject(p);
	}
	DIO->setByteLength(DIO->getByteLength()+i);
}


void RPLapp::RPLapp_vSendToICMP(cMessage *msg, const IPvXAddress& destAddr, const IPvXAddress& srcAddr, int hopLimit)
{
	// send to IPv6
	IPv6ControlInfo *ctrl = new IPv6ControlInfo();
	ctrl->setSrcAddr(srcAddr.get6());
	ctrl->setDestAddr(destAddr.get6());
	ctrl->setHopLimit(hopLimit);
	msg->setControlInfo(ctrl);
	send(msg, "t_ICMP");
}


uint16 RPLapp::RPLapp_iOF(uint16 ParentR, uint8 OF, uint16 MinHopRankIncrease, double ETX)
{
	switch (OF)
	{
	case 0:
		if(ParentR == CHECK_OF_MERIC)
			return SUPPORTED;
		else
			return RPLapp_iOF0(ParentR, MinHopRankIncrease, ETX);
	default:
		return NOT_SUPPORTED;
	}
}


uint16 RPLapp::RPLapp_iOF0(uint16 ParentR, uint16 MinHR, double ETX)
{
	EV<<"ETX= "<<ETX<<" MinHR= "<<MinHR<<"\n";
	double Sp = 1 - (double)1/(double)(ETX);
	int Nr = ParentR+(m_iRf*Sp+m_iSr)*MinHR;
	EV<<"m_iSr="<<m_iSr<<" Rf="<<m_iRf<<" Sp="<<Sp<<" Nr="<<Nr<<"\n";
//	EV<<"ParentR="<<ParentR<<" (m_iRf*m_iSp+Sr)="<<(m_iRf*m_iSp+Sr)<<" (m_iRf*m_iSp+Sr)*MinHR="<<((m_iRf*m_iSp+Sr)*MinHR)<<"\n";
	if(Nr > INFINITE_RANK)
		return INFINITE_RANK;
	else
		return Nr;
}


double RPLapp::RPLapp_iMetric(int Metric, uint16 CurrentAvg, int parentID, double parentETX)
{
	switch (Metric)
	{
	case 7:
		if(CurrentAvg == CHECK_OF_MERIC)
			return SUPPORTED;
		else
			return RPLapp_iCalcETX(CurrentAvg, parentID, parentETX);
	default:
		return NOT_SUPPORTED;
	}
}


double RPLapp::RPLapp_iCalcETX(uint16 CurrentAvg, int parentID, double parentETX)
{
	//TODO update the function NewAvg = AxCurrTx + (1-A) x CurrentAvg
	double CurrTx;

	if(simTime() > 12)
	{
		std::string str = par("changed_ETX_values");
		ETX_values = cStringTokenizer(str.c_str()).asDoubleVector ();
		ETX_values[getParentModule()->getParentModule()->getIndex()] = 0;
	}
	EV<<"CurrentAvg="<<CurrentAvg<<" parentID="<<parentID<<" parentETX="<<parentETX<<"\n";
	CurrTx = ETX_values[parentID];// + parentETX;
//	CurrTx = intuniform(128,1024)+CurrentAvg;
//	EV<<"CurrentAvg="<<CurrentAvg<<" "<<"CurrTx="<<CurrTx<<"****************************************\n";
//	EV<<"m_dA*CurrTx="<<(m_dA*CurrTx)<<" "<<"(1-m_dA)*CurrentAvg="<<((1-m_dA)*CurrentAvg)<<"\n";
	double updatedETX = (double)((m_dA*CurrTx+(1-m_dA)*CurrentAvg));
	EV<<"updatedETX="<<updatedETX<<"\n";
	if(updatedETX < MAX_ETX_VALUE)
		return updatedETX;
	else
		return MAX_ETX_VALUE;
}


void RPLapp::RPLapp_vSetTrickle(uint8 DIOIntMin, uint8 DIOIntDoubl, uint8 DIORedun,int i)
{
	TrickleMessage *trickle = new TrickleMessage("startTrickle");
	trickle->setK(DIORedun);
	trickle->setImin(pow(2,DIOIntMin)/1000);
	trickle->setImax((pow(2,DIOIntMin)/1000)*pow(2,DIOIntDoubl));
	send(trickle,"t_Trickle",i);
}


int RPLapp::RPLapp_iGetTrickleFreeIndex()
{
	int i, size = gateSize("t_Trickle");

	for(i=0; i<size; i++)
	{
		cModule *temp = getParentModule()->getSubmodule("trickle",i);
		Trickle *Tr = check_and_cast<Trickle *>(temp);
		if(!(Tr->Trickle_bGetBusy()))
			return i;
	}
	return -1;
}


bool RPLapp::RPLapp_bCheckJoinConditions(IPv6Address DODAGID, uint8 RPLInstanceID, uint8 Prf, uint8 OCP, uint8 MOP/*, uint8 Metric*/)
{
	if(m_srcAddr == DODAGID)
		return false;

	bool foundInst = false;
	std::vector<int>::iterator it;
	for(it = m_iRPLinstanceID.begin(); it != m_iRPLinstanceID.end(); it++)
	{
		if(*it == RPLInstanceID)
			foundInst = true;
	}
	//TODO should metric and DODAGID be checked?
	if(/*RPLapp_iMetric(Metric)>=0 && */RPLapp_iOF(CHECK_OF_MERIC, OCP, 0, 1)==SUPPORTED && MOP == m_iMOP && foundInst)
		return true;
	else
		return false;
}
