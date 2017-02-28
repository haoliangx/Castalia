//
// Generated file, do not edit! Created by opp_msgc 4.1 from src/node/communication/mac/MacPacket.msg.
//

#ifndef _MACPACKET_M_H_
#define _MACPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>src/node/communication/mac/MacPacket.msg</tt> by opp_msgc.
 * <pre>
 * enum MacControlMessage_type {
 * 	MAC_BUFFER_FULL = 1;
 * }
 * </pre>
 */
enum MacControlMessage_type {
    MAC_BUFFER_FULL = 1
};

/**
 * Struct generated from src/node/communication/mac/MacPacket.msg by opp_msgc.
 */
struct MacRadioInfoExchange_type
{
    MacRadioInfoExchange_type();
    double RSSI;
    double LQI;
};

void doPacking(cCommBuffer *b, MacRadioInfoExchange_type& a);
void doUnpacking(cCommBuffer *b, MacRadioInfoExchange_type& a);

/**
 * Class generated from <tt>src/node/communication/mac/MacPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet MacPacket {
 * 	MacRadioInfoExchange_type macRadioInfoExchange;
 * 	
 * 	int source;
 * 	int destination;
 * 	unsigned int sequenceNumber;	
 * }
 * </pre>
 */
class MacPacket : public ::cPacket
{
  protected:
    ::MacRadioInfoExchange_type macRadioInfoExchange_var;
    int source_var;
    int destination_var;
    unsigned int sequenceNumber_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacPacket&);

  public:
    MacPacket(const char *name=NULL, int kind=0);
    MacPacket(const MacPacket& other);
    virtual ~MacPacket();
    MacPacket& operator=(const MacPacket& other);
    virtual MacPacket *dup() const {return new MacPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual MacRadioInfoExchange_type& getMacRadioInfoExchange();
    virtual const MacRadioInfoExchange_type& getMacRadioInfoExchange() const {return const_cast<MacPacket*>(this)->getMacRadioInfoExchange();}
    virtual void setMacRadioInfoExchange(const MacRadioInfoExchange_type& macRadioInfoExchange_var);
    virtual int getSource() const;
    virtual void setSource(int source_var);
    virtual int getDestination() const;
    virtual void setDestination(int destination_var);
    virtual unsigned int getSequenceNumber() const;
    virtual void setSequenceNumber(unsigned int sequenceNumber_var);
};

inline void doPacking(cCommBuffer *b, MacPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MacPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/node/communication/mac/MacPacket.msg</tt> by opp_msgc.
 * <pre>
 * message MacControlMessage {
 * 	int macControlMessageKind enum (MacControlMessage_type);
 * }
 * </pre>
 */
class MacControlMessage : public ::cMessage
{
  protected:
    int macControlMessageKind_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MacControlMessage&);

  public:
    MacControlMessage(const char *name=NULL, int kind=0);
    MacControlMessage(const MacControlMessage& other);
    virtual ~MacControlMessage();
    MacControlMessage& operator=(const MacControlMessage& other);
    virtual MacControlMessage *dup() const {return new MacControlMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getMacControlMessageKind() const;
    virtual void setMacControlMessageKind(int macControlMessageKind_var);
};

inline void doPacking(cCommBuffer *b, MacControlMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MacControlMessage& obj) {obj.parsimUnpack(b);}


#endif // _MACPACKET_M_H_
