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

#include "cRPLTrickle.h"

Define_Module(Trickle);

void Trickle::initialize()
{
	m_bIsBusy = false;
	WATCH(m_bIsBusy);
}


void Trickle::handleMessage(cMessage *msg)
{
	if(msg->isSelfMessage())
		Trickle_vTimeOutEvent(msg);
	else if(strcmp(msg->getName(),"startTrickle")==0)
		Trickle_vInitTimer(check_and_cast<TrickleMessage *>(msg));
	else if(strcmp(msg->getName(),"consistent")==0)
	{
		m_ic++;
		delete msg;
	}
	else if(strcmp(msg->getName(),"inconsistent")==0)
		Trickle_vResetTimer();
	else if(strcmp(msg->getName(),"stop")==0)
	{
		Trickle_Stop();
		delete msg;
	}
	else
		delete msg;
}


void Trickle::Trickle_vTimeOutEvent(cMessage *msg)
{
	EV<<"timeout event\n";
	if(strcmp(msg->getName(),"timeout_t")==0)
	{
		EV<<"timeout t\n";
		if(m_ic<m_iK)
		{
			cMessage *incos = new cMessage("transmit",getIndex());
			send(incos,"t_RPL");
		}
		Trickle_vStartCycle();
	}
	else if(strcmp(msg->getName(),"timeout_I")==0)
	{
		EV<<"timeout I\n";
		if(m_I*2>m_Imax)
			m_I=m_Imax;
		else
			m_I=m_I*2;
		cMessage *time_I = new cMessage("timeout_I");
		m_timeOutI=time_I;
		scheduleAt(simTime()+m_I,time_I);
	}
	delete msg;
}


void Trickle::Trickle_vInitTimer(TrickleMessage *msg)
{
	m_bIsBusy = true;
	EV<<"Trickle started\n";
	m_Imax=msg->getImax();
	m_Imin=msg->getImin();
	m_iK=msg->getK();
	m_I=m_Imin;
	Trickle_vStartCycle();
	cMessage *time_I = new cMessage("timeout_I");
	m_timeOutI=time_I;
	scheduleAt(simTime()+m_I,time_I);
	delete msg;
}


void Trickle::Trickle_vStartCycle()
{
	m_ic=0;
	m_t=uniform(m_I/2,m_I);
	cMessage *time_t = new cMessage("timeout_t");
	m_timeOutt=time_t;
	scheduleAt(simTime()+m_t,time_t);
}


void Trickle::Trickle_vResetTimer()
{
	if(m_timeOutt->isScheduled())
		cancelAndDelete(m_timeOutt);
	if(m_timeOutI->isScheduled())
		cancelAndDelete(m_timeOutI);
	m_I = m_Imin;
	cMessage *time_I = new cMessage("timeout_I");
	m_timeOutI = time_I;
	scheduleAt(simTime()+m_I,time_I);
	Trickle_vStartCycle();
}


void Trickle::Trickle_Stop()
{
	EV<<"stopped\n";
	m_bIsBusy = false;

	if(m_timeOutt->isScheduled())
		cancelAndDelete(m_timeOutt);
	if(m_timeOutI->isScheduled())
		cancelAndDelete(m_timeOutI);
}
