//
// Generated file, do not edit! Created by opp_msgc 4.1 from chaospacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "chaospacket_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




ChaosData::ChaosData()
{
    node_id = 0;
    val = 0;
}

void doPacking(cCommBuffer *b, ChaosData& a)
{
    doPacking(b,a.node_id);
    doPacking(b,a.val);
    doPacking(b,a.flag);
}

void doUnpacking(cCommBuffer *b, ChaosData& a)
{
    doUnpacking(b,a.node_id);
    doUnpacking(b,a.val);
    doUnpacking(b,a.flag);
}

class ChaosDataDescriptor : public cClassDescriptor
{
  public:
    ChaosDataDescriptor();
    virtual ~ChaosDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ChaosDataDescriptor);

ChaosDataDescriptor::ChaosDataDescriptor() : cClassDescriptor("ChaosData", "")
{
}

ChaosDataDescriptor::~ChaosDataDescriptor()
{
}

bool ChaosDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ChaosData *>(obj)!=NULL;
}

const char *ChaosDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ChaosDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int ChaosDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *ChaosDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "node_id",
        "val",
        "flag",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int ChaosDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "node_id")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "val")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "flag")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ChaosDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "double",
        "BitVector",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *ChaosDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ChaosDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ChaosData *pp = (ChaosData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ChaosDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ChaosData *pp = (ChaosData *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->node_id);
        case 1: return double2string(pp->val);
        //case 2: {std::stringstream out; out << pp->flag; return out.str();}
        case 2: return pp->flag.to_string();
        default: return "";
    }
}

bool ChaosDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ChaosData *pp = (ChaosData *)object; (void)pp;
    switch (field) {
        case 0: pp->node_id = string2ulong(value); return true;
        case 1: pp->val = string2double(value); return true;
        default: return false;
    }
}

const char *ChaosDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        "BitVector",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *ChaosDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ChaosData *pp = (ChaosData *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->flag); break;
        default: return NULL;
    }
}

Register_Class(ChaosPacket);

ChaosPacket::ChaosPacket(const char *name, int kind) : ApplicationPacket(name,kind)
{
}

ChaosPacket::ChaosPacket(const ChaosPacket& other) : ApplicationPacket()
{
    setName(other.getName());
    operator=(other);
}

ChaosPacket::~ChaosPacket()
{
}

ChaosPacket& ChaosPacket::operator=(const ChaosPacket& other)
{
    if (this==&other) return *this;
    ApplicationPacket::operator=(other);
    this->ExtraData_var = other.ExtraData_var;
    return *this;
}

void ChaosPacket::parsimPack(cCommBuffer *b)
{
    ApplicationPacket::parsimPack(b);
    doPacking(b,this->ExtraData_var);
}

void ChaosPacket::parsimUnpack(cCommBuffer *b)
{
    ApplicationPacket::parsimUnpack(b);
    doUnpacking(b,this->ExtraData_var);
}

ChaosData& ChaosPacket::getExtraData()
{
    return ExtraData_var;
}

void ChaosPacket::setExtraData(const ChaosData& ExtraData_var)
{
    this->ExtraData_var = ExtraData_var;
}

class ChaosPacketDescriptor : public cClassDescriptor
{
  public:
    ChaosPacketDescriptor();
    virtual ~ChaosPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ChaosPacketDescriptor);

ChaosPacketDescriptor::ChaosPacketDescriptor() : cClassDescriptor("ChaosPacket", "ApplicationPacket")
{
}

ChaosPacketDescriptor::~ChaosPacketDescriptor()
{
}

bool ChaosPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ChaosPacket *>(obj)!=NULL;
}

const char *ChaosPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ChaosPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int ChaosPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ChaosPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ExtraData",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int ChaosPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='E' && strcmp(fieldName, "ExtraData")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ChaosPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "ChaosData",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *ChaosPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ChaosPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ChaosPacket *pp = (ChaosPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ChaosPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ChaosPacket *pp = (ChaosPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getExtraData(); return out.str();}
        default: return "";
    }
}

bool ChaosPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ChaosPacket *pp = (ChaosPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ChaosPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "ChaosData",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *ChaosPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ChaosPacket *pp = (ChaosPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getExtraData()); break;
        default: return NULL;
    }
}


