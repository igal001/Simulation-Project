//
// Generated file, do not edit! Created by opp_msgc 4.1 from networklayer/RPL/TrickleMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "TrickleMessage_m.h"

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




Register_Class(TrickleMessage);

TrickleMessage::TrickleMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->Imax_var = 0;
    this->Imin_var = 0;
    this->K_var = 0;
}

TrickleMessage::TrickleMessage(const TrickleMessage& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

TrickleMessage::~TrickleMessage()
{
}

TrickleMessage& TrickleMessage::operator=(const TrickleMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->Imax_var = other.Imax_var;
    this->Imin_var = other.Imin_var;
    this->K_var = other.K_var;
    return *this;
}

void TrickleMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->Imax_var);
    doPacking(b,this->Imin_var);
    doPacking(b,this->K_var);
}

void TrickleMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->Imax_var);
    doUnpacking(b,this->Imin_var);
    doUnpacking(b,this->K_var);
}

simtime_t TrickleMessage::getImax() const
{
    return Imax_var;
}

void TrickleMessage::setImax(simtime_t Imax_var)
{
    this->Imax_var = Imax_var;
}

simtime_t TrickleMessage::getImin() const
{
    return Imin_var;
}

void TrickleMessage::setImin(simtime_t Imin_var)
{
    this->Imin_var = Imin_var;
}

int TrickleMessage::getK() const
{
    return K_var;
}

void TrickleMessage::setK(int K_var)
{
    this->K_var = K_var;
}

class TrickleMessageDescriptor : public cClassDescriptor
{
  public:
    TrickleMessageDescriptor();
    virtual ~TrickleMessageDescriptor();

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

Register_ClassDescriptor(TrickleMessageDescriptor);

TrickleMessageDescriptor::TrickleMessageDescriptor() : cClassDescriptor("TrickleMessage", "cPacket")
{
}

TrickleMessageDescriptor::~TrickleMessageDescriptor()
{
}

bool TrickleMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<TrickleMessage *>(obj)!=NULL;
}

const char *TrickleMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int TrickleMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int TrickleMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *TrickleMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Imax",
        "Imin",
        "K",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int TrickleMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "Imax")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "Imin")==0) return base+1;
    if (fieldName[0]=='K' && strcmp(fieldName, "K")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *TrickleMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *TrickleMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int TrickleMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    TrickleMessage *pp = (TrickleMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string TrickleMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    TrickleMessage *pp = (TrickleMessage *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getImax());
        case 1: return double2string(pp->getImin());
        case 2: return long2string(pp->getK());
        default: return "";
    }
}

bool TrickleMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    TrickleMessage *pp = (TrickleMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setImax(string2double(value)); return true;
        case 1: pp->setImin(string2double(value)); return true;
        case 2: pp->setK(string2long(value)); return true;
        default: return false;
    }
}

const char *TrickleMessageDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *TrickleMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    TrickleMessage *pp = (TrickleMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


