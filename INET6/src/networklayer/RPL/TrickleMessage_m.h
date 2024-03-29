//
// Generated file, do not edit! Created by opp_msgc 4.1 from networklayer/RPL/TrickleMessage.msg.
//

#ifndef _TRICKLEMESSAGE_M_H_
#define _TRICKLEMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>networklayer/RPL/TrickleMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet TrickleMessage {
 *     simtime_t Imax;
 *     simtime_t Imin;
 *     int K;
 * }
 * </pre>
 */
class TrickleMessage : public ::cPacket
{
  protected:
    simtime_t Imax_var;
    simtime_t Imin_var;
    int K_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TrickleMessage&);

  public:
    TrickleMessage(const char *name=NULL, int kind=0);
    TrickleMessage(const TrickleMessage& other);
    virtual ~TrickleMessage();
    TrickleMessage& operator=(const TrickleMessage& other);
    virtual TrickleMessage *dup() const {return new TrickleMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getImax() const;
    virtual void setImax(simtime_t Imax_var);
    virtual simtime_t getImin() const;
    virtual void setImin(simtime_t Imin_var);
    virtual int getK() const;
    virtual void setK(int K_var);
};

inline void doPacking(cCommBuffer *b, TrickleMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TrickleMessage& obj) {obj.parsimUnpack(b);}


#endif // _TRICKLEMESSAGE_M_H_
