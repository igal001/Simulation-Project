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

//#ifndef RPLAPP_H_
//#define RPLAPP_H_

#include <omnetpp.h>
#include <string>
#include <vector>
#include "ICMPv6.h"
#include "TrickleMessage_m.h"
#include "DAOMessage_m.h"
#include "DIOMessage_m.h"
#include "DISMessage_m.h"
#include "DAOACKMessage_m.h"
#include "IPv6Address.h"
#include "IPAddressResolver.h"
#include "cRPLDODAGtable.h"

//-----------------------------RPL
#define BASE_RANK							0		//The rank for a virtual root that might be used to coordinate multiple roots
#define ROOT_RANK							1		//The rank of DODAG root.
#define INFINITE_RANK						0xFFFF	//Constant maximum for the rank.
#define RPL_DEFAULT_INSTANCE				0		//Used by a node without any overriding policy.
#define DEFAULT_PATH_CONTROL_SIZE			0
#define DEFAULT_DIO_INTERVAL_MIN  			3		//Trickle - Imin value.
#define DEFAULT_DIO_INTERVAL_DOUBLINGS  	20		//Trickle - Imax value.
#define DEFAULT_DIO_REDUNDANCY_CONSTANT  	10		//Trickle - K value.
#define DEFAULT_MIN_HOP_RANK_INCREASE  		256
#define CHECK_OF_MERIC		0xFFFF	// Used to check if supported OF/Metric
#define SUPPORTED			0	// OF/Metric supported
#define NOT_SUPPORTED		-1	// OF/Metric not supported

//-----------------------------OF0
#define DEFAULT_STEP_OF_RANK		3
#define MINIMUM_STEP_OF_RANK		1
#define MAXIMUM_STEP_OF_RANK		9
#define DEFAULT_RANK_STRETCH		0
#define MAXIMUM_RANK_STRETCH		5
#define DEFAULT_RANK_FACTOR			1
#define MINIMUM_RANK_FACTOR			1
#define MAXIMUM_RANK_FACTOR			4

//----------------------------ETX
#define MAX_ETX_VALUE	0xFFFF
#define BASE_ETX		0


class INET_API RPLapp  : public cSimpleModule{
	protected:
		DODAGtable *m_rt;
		bool m_bIsRoot;
		unsigned int m_iMOP;
		int m_iSr;
		int m_iRf;
		std::vector<int> m_iRPLinstanceID;
		//==================================
		double m_dA;				// ETX calculation parameter
		IPv6Address m_srcAddr;
		IPv6Address m_multAddr;

		std::vector<double> ETX_values;
	protected:

		/**
		 *Checks if the node is a DODAG root and if so sets the DODAG parameters and starts Trickle.
		 */
		virtual void initialize();

		/**
		 * Main function which handle every message that this module gets.
		 * From this function all other functions activated depending on the message type that arrives.
		 * @param msg Incoming message to be handled.
		 */
		virtual void handleMessage(cMessage *msg);

		/**
		 * Chooses the right OF to calculate the rank.
		 * @param ParentR parents rank
		 * @param OF OF serial number
		 * @param MinHopRankIncrease Minimal rank increase to be done
		 * @return Node's rank or -1 if OF not supported
		 */
		virtual uint16 RPLapp_iOF(uint16 ParentR, uint8 OF, uint16 MinHopRankIncrease, double ETX);

		/**
		 * Chooses the right metric to be calculated.
		 * @param Metric Metric serial number
		 * @param CurrentAvg Current metric value to be updated.
		 * @param parentID Parent ID that sent the current message.
		 * @param parentETX Stored ETX value through this parent
		 * @return Node's metric or -1 if Metric not supported
		 */
		virtual double RPLapp_iMetric(int Metric, uint16 CurrentAvg, int parentID, double parentETX);

		/**
		 * Calculates the ETX value on a specific link.
		 * @param CurrentAvg Current metric value to be updated.
		 * @param parentID Parent ID that sent the current message.
		 * @param parentETX Stored ETX value through this parent
		 */
		virtual double RPLapp_iCalcETX(uint16 CurrentAvg, int parentID, double parentETX);

		/**
		 * Calculates the node's rank regarding the parent received.
		 * @param ParentR parent rank
		 */
		virtual uint16 RPLapp_iOF0(uint16 ParentR, uint16 MinHR, double ETX);

		/**
		 *Forwards the RPL message to the ICMPv6 module.
		 *@param msg The message to be forwarded.
		 *@param destAddr Message destination address.
		 *@param srcAddr Message source address.
		 *@param hopLimit TODO
		 */
		virtual void RPLapp_vSendToICMP(cMessage *msg, const IPvXAddress& destAddr, const IPvXAddress& srcAddr, int hopLimit);

		/**
		 *Handles the creation of the DODAG by the root by generating the first DIO message – starts the DODAG construction algorithm.
		 */
		virtual void RPLapp_vDODAGinitioanization();

		/**
		 *Handles the incoming DIO messages and updates the DODAGtable accordingly – continues the DODAG construction.
		 *If the node decides to join the DODAG it saves/updates the new information regarding the DODAG in the DODAG
		 *table and sends a DIO message to its neighbors with the updated Rank and DTSN fields.
		 *@param msg The received DIO message.
		 */
		virtual void RPLapp_vDIOhandler(DIOMessage *msg);

		/**
		 *Generates DIS messages when needed and handles incoming DIS messages – Joining new node to the DODAG algorithm.
		 *@param msg The received DIS message.
		 */
		virtual void RPLapp_vDIShandler(DISMessage *msg);

		/**
		 *Generates DAO messages and handles incoming DAO messages.
		 *@param msg The received DAO message.
		 */
		virtual void RPLapp_vDAOhandler(DAOMessage *msg);

		/**
		 *Generates DAO-ACK messages and handles incoming DAO-ACK messages.
		 *@param msg The received DAO-ACK message.
		 */
		virtual void RPLapp_vDAOACKhandler(DAOACKMessage *msg);

		/**
		 *Handles Trickle timeout messages. On receiving a timeout message from Trickle module generates a DIO message.
		 *@param msg The received Trickle message.
		 */
		virtual void RPLapp_vTricklehandler(cMessage *msg);

		/**
		 * Send the initial parameters to the Trickle
		 * @param DIOIntMin Imin
		 * @param DIOIntDoubl Imax
		 * @param DIORedun K
		 * @param i Specific Trickle's gate index
		 */
		virtual void RPLapp_vSetTrickle(uint8 DIOIntMin, uint8 DIOIntDoubl, uint8 DIORedun, int i);

		/**
		 * Get available Trickle's index
		 * @return index
		 */
		virtual int RPLapp_iGetTrickleFreeIndex();

		/**
		 * Handles the reception of DIO message with DODAG configuration option.
		 * @param msg Received DIO message
		 * @param conf Configuration option
		 */
		virtual void RPLapp_DIOconfiguration(DIOMessage *msg, DODAG_CONFop *conf);

		/**
		 * Handles the reception of DIO message with DODAG configuration option.
		 * @param msg Received DIO message
		 * @param met Metric container option
		 */
		virtual void RPLapp_MetricConfiguration(DIOMessage *msg, METRIC_CONTop *met);

		/**
		 * Checks if the node should join the DODAG.
		 * @param DODAGID DODAG root IPv6 address
		 * @param Prf DODAG preference
		 * @param OCP OF the DODAG is using
		 * @param MOP mode of operation received
		 * @return True if the should join the DODAG, false otherwise.
		 */
		virtual bool RPLapp_bCheckJoinConditions(IPv6Address DODAGID, uint8 RPLInstanceID, uint8 Prf, uint8 OCP, uint8 MOP);

		/**
		 * Adds Configuration option to the DIO message.
		 * @param msg The message to which the option is added.
		 * @param dodag Holds the DODAG parameters to be used.
		 */
		virtual void RPLapp_vAddConfiguration(DIOMessage *DIO, DODAG *dodag);

		/**
		 * Adds Metric container to the DIO message.
		 * @param msg The message to which the option is added.
		 * @param dodag Holds the DODAG parameters to be used.
		 */
		virtual void RPLapp_vAddETXMetric(DIOMessage *DIO, DODAG *dodag);

		/**
		 * Adds PAD1/PADN containers.
		 * @param msg The message to which the container is added.
		 * @param i The size of the container.
		 */
		virtual void RPLapp_vPAD(DIOMessage *DIO, int i);
};

//#endif /* RPLAPP_H_ */
