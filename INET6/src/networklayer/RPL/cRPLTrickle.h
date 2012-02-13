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

#ifndef TRICKLE_H_
#define TRICKLE_H_

#include <omnetpp.h>
#include <string>
#include <stdio.h>
#include "ICMPv6.h"
#include "TrickleMessage_m.h"


class INET_API Trickle : public cSimpleModule {
	protected:
		simtime_t m_Imin;
		simtime_t m_Imax;
		int m_iK;
		simtime_t m_t;
		int m_ic;
		simtime_t m_I;
		bool m_bIsBusy;
		cMessage *m_timeOutt;
		cMessage *m_timeOutI;
	protected:

		virtual void initialize();

		/**
		 *Main function which handle every message that this module gets. From this function all other functions activated depending on the message type that arrives.
		 *@param msg The received message to be handled.
		 */
		virtual void handleMessage(cMessage *msg);

		/**
		 *On I timeout increases I.
		 *On t timeout checks whether to send and restarts the timer.
		 *@param msg Defines the timeout type - I/t.
		 */
		virtual void Trickle_vTimeOutEvent(cMessage *msg);

		/**
		 *Receives Imin, Imax, K from the RPL module (msg) and generates parameters I, t, c and starts the timer.
		 *@param msg The message with the parameters.
		 */
		virtual void Trickle_vInitTimer(TrickleMessage *msg);

		/**
		 *Sets I to Imin, c to 0 , chooses t and starts the timer.
		 */
		virtual void Trickle_vResetTimer();

		/**
		 *Sets 0 to c and selects new value to t.
		 */
		virtual void Trickle_vStartCycle();

		/**
		 * Stops Trickle.
		 * Happens when a node disconnects from the DODAG.
		 */
		virtual void Trickle_Stop();

	public:
		/**
		 * Inline function. Returns if the module is busy or idle.
		 */
		virtual bool Trickle_bGetBusy() {Enter_Method("Trickle_bGetBusy()");
		    			return m_bIsBusy;};
};

#endif /* TRICKLE_H_ */
