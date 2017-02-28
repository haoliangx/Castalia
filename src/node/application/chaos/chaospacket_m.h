//
// Generated file, do not edit! Created by opp_msgc 4.1 from chaospacket.msg.
//

#ifndef _CHAOSPACKET_M_H_
#define _CHAOSPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "ApplicationPacket_m.h"
#include <bitset>
typedef std::bitset<256> BitVector;
// }}



/**
 * Struct generated from chaospacket.msg by opp_msgc.
 */
struct ChaosData
{
    ChaosData();
    unsigned short node_id;
    double val;
    ::BitVector flag;
};

void doPacking(cCommBuffer *b, ChaosData& a);
void doUnpacking(cCommBuffer *b, ChaosData& a);

/**
 * Class generated from <tt>chaospacket.msg</tt> by opp_msgc.
 * <pre>
 * packet ChaosPacket extends ApplicationPacket {
 * 	ChaosData ExtraData;
 * }
 * </pre>
 */
class ChaosPacket : public ::ApplicationPacket
{
  protected:
    ::ChaosData ExtraData_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ChaosPacket&);

  public:
    ChaosPacket(const char *name=NULL, int kind=0);
    ChaosPacket(const ChaosPacket& other);
    virtual ~ChaosPacket();
    ChaosPacket& operator=(const ChaosPacket& other);
    virtual ChaosPacket *dup() const {return new ChaosPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual ChaosData& getExtraData();
    virtual const ChaosData& getExtraData() const {return const_cast<ChaosPacket*>(this)->getExtraData();}
    virtual void setExtraData(const ChaosData& ExtraData_var);
};

inline void doPacking(cCommBuffer *b, ChaosPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ChaosPacket& obj) {obj.parsimUnpack(b);}


#endif // _CHAOSPACKET_M_H_
