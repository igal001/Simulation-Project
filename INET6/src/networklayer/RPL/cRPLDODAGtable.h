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

#ifndef DODAGTABLE_H_
#define DODAGTABLE_H_

#include "IPv6Address.h"
#include <omnetpp.h>
#include <vector>
#include "IInterfaceTable.h"
#include "NotificationBoard.h"
#include "INETDefs.h"
#include "IPv6.h"

class INET_API DODAG : public cPolymorphic
{
  protected:
	/**
	 * A struct describing parent node.
	 */
	struct PARENT
	{
		IPv6Address ParentIPv6;	/**<parent IPv6. */
		uint16 iRank;		/**<Node's rank based on this parent.*/
		double MetricVal;
		int ID;
	};
	typedef std::vector<PARENT *> ParentSet;

	uint8 m_iRPLInstanceID;
	IPv6Address m_DODAGID;
	uint8 m_iDODAGVersionNumber;
	uint16 m_iRank;
	uint16 m_iOCP;
	ParentSet m_DIOparents;
	IPv6Address m_Prefixs;
//	timer set TODO
	ParentSet m_DAOparents;
	uint8 m_iDTSN;
	uint8 m_iDIOIntDoubl;
	uint8 m_iDIOIntMin;
	uint8 m_iDIORedun;
	uint16 m_iMaxRankIncrease;
	uint16 m_iMinHopRankIncrease;
	uint8 m_iDefLT;
	uint8 m_iLTU;
	uint8 m_iPCS;
	uint8 m_iPrf;
	uint8 m_iMOP;
	uint8 m_iGrounded;
	int m_iMetric;

	unsigned int m_iTI;		// Trickle index

  public:
	/**
	 * DODAG constructor
	 */
	DODAG(){};
	~DODAG(){};

	virtual std::string info() const;
	virtual std::string detailedInfo() const;
//	static const char *routeSrcName(RouteSrc src);

	/**
	 * Sets RPLInstance of the DODAG network.
	 * @param insID The new RPLInstance.
	 */
	void DODAG_SetInstanceID(uint8 insID){m_iRPLInstanceID = insID;};

	/**
	 * Sets DODAGID of the DODAG network.
	 * @param dodagid The new DODAGID.
	 */
	void DODAG_SetDODAGID(IPv6Address dodagid){m_DODAGID = dodagid;};

	/**
	 * Sets VersionNumber of the DODAG network.
	 * @param VN The new VersionNumber.
	 */
	void DODAG_SetVersionNumber(uint8 VN){m_iDODAGVersionNumber = VN;};

	/**
	 * Sets node's rank in the DODAG network.
	 * @param rank The new Rank.
	 */
	void DODAG_SetRank(uint16 rank){m_iRank = rank;};

	/**
	 * Sets OCP of the DODAG network.
	 * @param ocp The new OCP.
	 */
	void DODAG_SetOCP(uint16 ocp){m_iOCP = ocp;};

	/**
	 * Add one DIO parent to the parent list.
	 * @param parent The parent to be added - IPv6 and Rank
	 */
	void DODAG_AddDIOparent(PARENT *parent){m_DIOparents.push_back(parent);};
//	void updatePrefixs();
//	void updateDAOparents();

	/**
	 * Sets DTSN of the DODAG network.
	 * @param dtsn The new DTSN.
	 */
	void DODAG_SetDTSN(uint8 dtsn){m_iDTSN = dtsn;};

	/**
	 * Sets the Trickle parameters in the table.
	 * @param DIOIntMin Imin value to be stored
	 * @param DIOIntDoubl Imax value to be stored
	 * @param DIORedun K value to be stored
	 */
	void DODAG_SetTrickle(uint8 DIOIntMin, uint8 DIOIntDoubl, uint8 DIORedun){m_iDIOIntMin=DIOIntMin; m_iDIOIntDoubl=DIOIntDoubl; m_iDIORedun=DIORedun;};

	/**
	 * Set the rank increase limitations for the OF.
	 * @param MinHopRankIncrease Maximum limitation
	 * @param MaxRankIncrease Minimum limitation
	 */
	void DODAG_SetOF(uint16 MinHopRankIncrease, uint16 MaxRankIncrease){m_iMaxRankIncrease=MaxRankIncrease; m_iMinHopRankIncrease=MinHopRankIncrease;};

	/**
	 * Set PCS.
	 * @param PCS PCS value to be stored
	 */
	void DODAG_SetPCS(uint8 PCS){m_iPCS=PCS;};

	/**
	 * Set the life time parameters.
	 * @param DefLT Default life time unit.
	 * @param LTU Amount of DefLT
	 */
	void DODAG_SetLT(uint8 DefLT, uint8 LTU){m_iDefLT=DefLT; m_iLTU=LTU;};


	/**
	 * Sets Prf, MOP, Grounded
	 * @param Prf The DODAg preference value
	 * @param MOP Mode of operation of the DODAG
	 * @param G Grounded root or not
	 */
	void DODAG_SetPMG(uint8 Prf, uint8 MOP, uint8 G){m_iPrf=Prf; m_iMOP=MOP; m_iGrounded=G;};

	/**
	 * Set the index of the Trickle timer connected to the DODAG
	 * @param i Trickle index
	 */
	void DODAG_SetTrickleIndex(int i){m_iTI=i;};

	/**TODO
	 * Set ETX value of the DODAG.
	 * @param etx The value to be set.
	 */
	void DODAG_SetMetric(int metric){m_iMetric = metric;};



	/**
	 * Get the index of the Trickle timer connected to the DODAG
	 * @return Trickle index
	 */
	int DODAG_iGetTrickleIndex(){return m_iTI;};

	/**
	 * Gets RPLInstance of the DODAG network.
	 * @return RPLInstanceID
	 */
	uint8 DODAG_iGetRPLInstanceID() const {return m_iRPLInstanceID;};

	/**
	 * Gets DODAGID of the DODAG network.
	 * @return DODAGID
	 */
	IPv6Address DODAG_GetDODAGID() const {return m_DODAGID;};

	/**
	 * Gets VertionNumber of the DODAG network.
	 * @return VertionNumber
	 */
	uint8 DODAG_iGetDODAGVersionNumber() const {return m_iDODAGVersionNumber;};

	/**
	 * Gets node's rank in the DODAG network.
	 * @return Rank
	 */
	uint16 DODAG_iGetRank() const {return m_iRank;};

	/**
	 * Gets OCP of the DODAG network.
	 * @return OCP
	 */
	uint16 DODAG_iGetOCP() const {return m_iOCP;};

	virtual void DODAG_updateDIOParents(IPv6Address parentIP, uint16 rank, int ID, double MetricVal);


//	void updateParents(Parent *parent);//TODO change names
//	void getPrefixs();
//	void updateDAOparents();

	/**
	 * Gets DTSN of the DODAG network.
	 * @return DTSN
	 */
	uint8 DODAG_iGetDTSN() const {return m_iDTSN;};

	/**
	 * Gets DIOIntMin of the DODAG network.
	 * @return DIOIntMin
	 */
	uint8 DODAG_iGetDIOIntMin(){return m_iDIOIntMin;};

	/**
	 * Gets DIOIntDoubl of the DODAG network.
	 * @return DIOIntDoubl
	 */
	uint8 DODAG_iGetDIOIntDoubl(){return m_iDIOIntDoubl;};

	/**
	 * Gets DIORedun of the DODAG network.
	 * @return DIORedun
	 */
	uint8 DODAG_iGetDIORedun(){return m_iDIORedun;};

	/**
	 * Gets MinHopRankIncrease of the DODAG network.
	 * @return MinHopRankIncrease
	 */
	uint16 DODAG_iGetMinHopRankIncrease(){return m_iMinHopRankIncrease;};

	/**
	 * Gets MaxRankIncrease of the DODAG network.
	 * @return MaxRankIncrease
	 */
	uint16 DODAG_iGetMaxRankIncrease(){return m_iMaxRankIncrease;};

	/**
	 * Gets PCS of the DODAG network.
	 * @return PCS
	 */
	uint8 DODAG_iGetPCS(){return m_iPCS;};

	/**
	 * Gets DefLT of the DODAG network.
	 * @return DefLT
	 */
	uint8 DODAG_iGetDefLT(){return m_iDefLT;};

	/**
	 * Gets LTU of the DODAG network.
	 * @return LTU
	 */
	uint8 DODAG_iGetLTU(){return m_iLTU;};

	/**
	 * Gets Prf of the DODAG network.
	 * @return Prf
	 */
	uint8 DODAG_iGetPrf(){return m_iPrf;};

	/**
	 * Gets MOP of the DODAG network.
	 * @return MOP
	 */
	uint8 DODAG_iGetMOP(){return m_iMOP;};

	/**
	 * Gets Grounded of the DODAG network.
	 * @return Grounded
	 */
	uint8 DODAG_iGetGrounded(){return m_iGrounded;};

	/**TODO
	 * Gets ETX value.
	 */
	int DODAG_iGetMetric(){return m_iMetric;};

	double DODAG_GetParentMetric(IPv6Address parentIP);

	uint16 DODAG_GetParentRank(IPv6Address parentIP);

	/**
	 * Gets the DIO i'th best parent.
	 * @return DIO parent address, or NULL if none exist
	 */
	IPv6Address DODAG_GetDIOparent(int i){if(m_DIOparents.size() <= (unsigned int)i) return "0::0";
											else return m_DIOparents[i]->ParentIPv6;};

	int DODAG_GetDIOparentID(int i){if(m_DIOparents.size() <= (unsigned int)i) return -1;
												else return m_DIOparents[i]->ID;};
};


class INET_API DODAGtable : public cSimpleModule
{
	public:
		DODAGtable();
		virtual ~DODAGtable();


	protected:
		bool m_bIsleaf;
		typedef std::vector<DODAG *> DODAGList;
		DODAGList m_DODAGlist;


	protected:
		virtual void initialize(int stage);
		virtual void handleMessage(cMessage *msg);
	public:

		/**
		 * Returns if the node is a leaf.
		 */
		virtual bool DODAGtable_bIsLeaf() const {return m_bIsleaf;}

		/**
		 * Adds new DODAG to the DODAG table.
		 * @param dodag The DODAG to be added.
		 */
		virtual void DODAGtable_vAddDODAG(DODAG *dodag);

		/**
		 * Get DODAG by Trickle index
		 * @param i Trickle index
		 */
		virtual DODAG* DODAGtable_GetDODAGbyTrickle(int i);

		/**
		 * Get DODAG by DODAGID and RPLInstanceID.
		 * @param DODAGID DODAGID
		 * @param Inst RPLInstanceID
		 * @return The requested DODAG if present, NULL otherwise.
		 */
		virtual DODAG* DODAGtable_GetDODAGbyID(IPv6Address DODAGID, uint8 Inst);

		/**
		 * Update if necessary the parent list of the DODAG stored,
		 * @param dodag The DODAG to be updated.
		 * @param parentAddr Parent's IPv6 address.
		 * @param rank The node's rank through parentAddr
		 * @return true if update occurred, false otherwise.
		 */
		virtual void DODAGtable_iUpdateParentSet(IPv6Address DODAGID, uint8 Inst, IPv6Address parentAddr, uint16 rank, int ID, double MetricVal);

		/**
		 * Updates DODAG VertionNumber and clears the parent list.
		 * @param DODAGID the DODAG to be updated.
		 * @param Inst DODAG's InstanceID.
		 * @param VN The new VeraionNumber.
		 */
		virtual void DODAGtable_UpdateVN(IPv6Address DODAGID, uint8 Inst, uint8 VN);

		/**
		 * Get DIO parent IPv6 address with the i'th rank.
		 * @param DODAGID root's IPv6 address
		 * @param Inst DODAG instance ID
		 * @param VN DODAG version number
		 * @param i The parent required
		 * @return parent IPv6 address
		 */
		virtual IPv6Address DODAGtable_GetParentByIndex(IPv6Address DODAGID, uint8 Inst, uint8 VN, int i);

		/**
		 * used for visual presentation only.
		 */
		virtual int DODAGtable_GetParentID(IPv6Address DODAGID, uint8 Inst, uint8 VN, int i);
};

#endif /* DODAGTABLE_H_ */
