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

#include "cRPLDODAGtable.h"


Define_Module(DODAGtable);

std::string DODAG::info() const
{
    std::stringstream out;
    out << "DODAGID:" << DODAG_GetDODAGID() << " RPLInstance:" << DODAG_iGetRPLInstanceID() << " VN:" << DODAG_iGetDODAGVersionNumber();
    out << " Rank:" << DODAG_iGetRank() << " OCP:" << DODAG_iGetOCP(); /*<< " DIOparents:" << " Prefixes:" << " DAOparents:"*/
    out << " DTSN:" << DODAG_iGetDTSN();
    //TODO check how to display the whole information
/*    out << " Imin:" << DODAG_iGetDIOIntMin() << " Imax:" << DODAG_iGetDIOIntDoubl();
    out << " K:" << DODAG_iGetDIORedun() << " MaxRankInc:" << DODAG_iGetMaxRankIncrease() << " MinRankInc:" << DODAG_iGetMinHopRankIncrease();
    out << " DefLT:" << DODAG_iGetDefLT() << " LTU:" << DODAG_iGetLTU() << " PCS:" << DODAG_iGetPCS() << " Prf:" << DODAG_iGetPrf();
    out << " MOP:" << DODAG_iGetMOP() << " G:" << DODAG_iGetGrounded();*/
    return out.str();
}

std::string DODAG::detailedInfo() const
{
    return std::string();
}


//----

std::ostream& operator<<(std::ostream& os, const DODAG& e)
{
    os << e.info();
    return os;
};

void DODAG::DODAG_updateDIOParents(IPv6Address parentIP, uint16 rank, int ID, double MetricVal)
{
	ParentSet::iterator it;
	bool found = false, inserted = false;
	PARENT *p = new PARENT();
	for(it = m_DIOparents.begin(); it != m_DIOparents.end(); it++)
	{
		if((*it)->ParentIPv6 == parentIP)
		{
			p->ParentIPv6 = parentIP;
			p->iRank = rank;
			p->MetricVal = MetricVal;
			p->ID = ID;
			m_DIOparents.erase(it);
			found = true;
			break;
		}
	}
	if(found == false)
	{
		p->ParentIPv6 = parentIP;
		p->iRank = rank;
		p->MetricVal = MetricVal;
		p->ID = ID;
	}
	for(it = m_DIOparents.begin(); it != m_DIOparents.end(); it++)
	{
		if((*it)->iRank > p->iRank)
		{
			m_DIOparents.insert(it, p);
			inserted = true;
			break;
		}
	}
	if(inserted == false)
		m_DIOparents.push_back(p);
	EV<<"parent set\n";
	for(it = m_DIOparents.begin(); it != m_DIOparents.end(); it++)
	{
		EV<<"ParentIPv6= "<<(*it)->ParentIPv6<<" Rank= "<<(*it)->iRank<<" MetricVal= "<<(*it)->MetricVal<<"\n";
	}
	m_iRank = m_DIOparents[0]->iRank;
}


double DODAG::DODAG_GetParentMetric(IPv6Address parentIP)
{
	ParentSet::iterator it;
	for(it = m_DIOparents.begin(); it != m_DIOparents.end(); it++)
	{
		if((*it)->ParentIPv6 == parentIP)
		{
			return (*it)->MetricVal;
		}
	}
	return 0;
}


uint16 DODAG::DODAG_GetParentRank(IPv6Address parentIP)
{
	ParentSet::iterator it;
	for(it = m_DIOparents.begin(); it != m_DIOparents.end(); it++)
	{
		if((*it)->ParentIPv6 == parentIP)
		{
			return (*it)->iRank;
		}
	}
	return 0;
}


DODAGtable::DODAGtable() {

}

DODAGtable::~DODAGtable() {
	//TODO complete distructor
	for (unsigned int i=0; i<m_DODAGlist.size(); i++)
	        delete m_DODAGlist[i];
}


void DODAGtable::initialize(int stage)
{
	WATCH_PTRVECTOR(m_DODAGlist);
	WATCH(m_bIsleaf);
}


void DODAGtable::handleMessage(cMessage *msg)
{
    opp_error("This module doesn't process messages");
}


void DODAGtable::DODAGtable_vAddDODAG(DODAG *dodag)
{
	m_DODAGlist.push_back(dodag);
	EV<<"DODAG added\n";
}


DODAG* DODAGtable::DODAGtable_GetDODAGbyTrickle(int i)
{
	for (DODAGList::const_iterator it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if((*it)->DODAG_iGetTrickleIndex() == i)
		{
			return *it;
		}
	}
	return NULL;
}


DODAG* DODAGtable::DODAGtable_GetDODAGbyID(IPv6Address DODAGID, uint8 Inst)
{
	for (DODAGList::const_iterator it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if((*it)->DODAG_iGetRPLInstanceID() == Inst && (*it)->DODAG_GetDODAGID() == DODAGID)
		{
			return *it;
		}
	}
	return NULL;
}


void DODAGtable::DODAGtable_iUpdateParentSet(IPv6Address DODAGID, uint8 Inst, IPv6Address parentAddr, uint16 rank, int ID, double MetricVal)
{
	DODAGList::const_iterator it;
	for (it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if((*it)->DODAG_iGetRPLInstanceID() == Inst && (*it)->DODAG_GetDODAGID() == DODAGID)
		{
			(*it)->DODAG_updateDIOParents(parentAddr, rank, ID, MetricVal);
			break;
		}
	}
}


void DODAGtable::DODAGtable_UpdateVN(IPv6Address DODAGID, uint8 Inst, uint8 VN)
{
	for (DODAGList::const_iterator it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if((*it)->DODAG_iGetRPLInstanceID() == Inst && (*it)->DODAG_GetDODAGID() == DODAGID)
		{
			(*it)->DODAG_SetVersionNumber(VN);
			m_DODAGlist.erase(m_DODAGlist.begin(),m_DODAGlist.end());
			break;
		}
	}
}


IPv6Address DODAGtable::DODAGtable_GetParentByIndex(IPv6Address DODAGID, uint8 Inst, uint8 VN, int i)
{
	for (DODAGList::const_iterator it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if(((*it)->DODAG_iGetRPLInstanceID() == Inst) && ((*it)->DODAG_GetDODAGID() == DODAGID) && ((*it)->DODAG_iGetDODAGVersionNumber() == VN))
		{
			return (*it)->DODAG_GetDIOparent(i);
		}
	}
	return NULL;
}


int DODAGtable::DODAGtable_GetParentID(IPv6Address DODAGID, uint8 Inst, uint8 VN, int i)
{
	for (DODAGList::const_iterator it=m_DODAGlist.begin(); it!=m_DODAGlist.end(); it++)
	{
		if(((*it)->DODAG_iGetRPLInstanceID() == Inst) && ((*it)->DODAG_GetDODAGID() == DODAGID) && ((*it)->DODAG_iGetDODAGVersionNumber() == VN))
		{
			return (*it)->DODAG_GetDIOparentID(i);
		}
	}
	return -1;
}
