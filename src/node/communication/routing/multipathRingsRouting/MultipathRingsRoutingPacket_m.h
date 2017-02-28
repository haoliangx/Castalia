//
// Generated file, do not edit! Created by opp_msgc 4.1 from src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket.msg.
//

#ifndef _MULTIPATHRINGSROUTINGPACKET_M_H_
#define _MULTIPATHRINGSROUTINGPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "RoutingPacket_m.h"
// }}



/**
 * Enum generated from <tt>src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket.msg</tt> by opp_msgc.
 * <pre>
 * enum multipathRingsRoutingPacketDef {
 * 	MPRINGS_DATA_PACKET = 1;
 * 	MPRINGS_TOPOLOGY_SETUP_PACKET = 2;
 * }
 * </pre>
 */
enum multipathRingsRoutingPacketDef {
    MPRINGS_DATA_PACKET = 1,
    MPRINGS_TOPOLOGY_SETUP_PACKET = 2
};

/**
 * Class generated from <tt>src/node/communication/routing/multipathRingsRouting/MultipathRingsRoutingPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet MultipathRingsRoutingPacket extends RoutingPacket {
 * 	int multipathRingsRoutingPacketKind enum (multipathRingsRoutingPacketDef);	
 * 	int sinkID;			
 * 	int senderLevel;	
 * 
 * 	
 * 	
 * }
 * </pre>
 */
class MultipathRingsRoutingPacket : public ::RoutingPacket
{
  protected:
    int multipathRingsRoutingPacketKind_var;
    int sinkID_var;
    int senderLevel_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MultipathRingsRoutingPacket&);

  public:
    MultipathRingsRoutingPacket(const char *name=NULL, int kind=0);
    MultipathRingsRoutingPacket(const MultipathRingsRoutingPacket& other);
    virtual ~MultipathRingsRoutingPacket();
    MultipathRingsRoutingPacket& operator=(const MultipathRingsRoutingPacket& other);
    virtual MultipathRingsRoutingPacket *dup() const {return new MultipathRingsRoutingPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getMultipathRingsRoutingPacketKind() const;
    virtual void setMultipathRingsRoutingPacketKind(int multipathRingsRoutingPacketKind_var);
    virtual int getSinkID() const;
    virtual void setSinkID(int sinkID_var);
    virtual int getSenderLevel() const;
    virtual void setSenderLevel(int senderLevel_var);
};

inline void doPacking(cCommBuffer *b, MultipathRingsRoutingPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MultipathRingsRoutingPacket& obj) {obj.parsimUnpack(b);}


#endif // _MULTIPATHRINGSROUTINGPACKET_M_H_
