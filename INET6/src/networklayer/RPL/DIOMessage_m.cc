//
// Generated file, do not edit! Created by opp_msgc 4.1 from networklayer/RPL/DIOMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DIOMessage_m.h"

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




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("DIO_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("DIO_TYPE"));
    e->insert(Pad1, "Pad1");
    e->insert(PadN, "PadN");
    e->insert(Metric_Container, "Metric_Container");
    e->insert(Routing_Information, "Routing_Information");
    e->insert(DODAG_CONFIGURATION, "DODAG_CONFIGURATION");
    e->insert(Prefix_Information, "Prefix_Information");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("DIO_LENGTH");
    if (!e) enums.getInstance()->add(e = new cEnum("DIO_LENGTH"));
    e->insert(DIO_HEADER, "DIO_HEADER");
    e->insert(PAD1_LENGTH, "PAD1_LENGTH");
    e->insert(DODAG_CONFIGURATION_LENGTH, "DODAG_CONFIGURATION_LENGTH");
    e->insert(Prefix_Information_LENGTH, "Prefix_Information_LENGTH");
    e->insert(ETX_LENGTH, "ETX_LENGTH");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("METRIC_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("METRIC_TYPE"));
    e->insert(ETX_TYPE, "ETX_TYPE");
);

Register_Class(DIOheader);

DIOheader::DIOheader(const char *name, int kind) : cPacket(name,kind)
{
    this->RPLInstance_var = 0;
    this->VersionNumber_var = 0;
    this->Rank_var = 0;
    this->GMP_var = 0;
    this->DTSN_var = 0;
    this->Flags_var = 0;
    this->Reserved_var = 0;
}

DIOheader::DIOheader(const DIOheader& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

DIOheader::~DIOheader()
{
}

DIOheader& DIOheader::operator=(const DIOheader& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->RPLInstance_var = other.RPLInstance_var;
    this->VersionNumber_var = other.VersionNumber_var;
    this->Rank_var = other.Rank_var;
    this->GMP_var = other.GMP_var;
    this->DTSN_var = other.DTSN_var;
    this->Flags_var = other.Flags_var;
    this->Reserved_var = other.Reserved_var;
    this->DODAGID_var = other.DODAGID_var;
    return *this;
}

void DIOheader::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->RPLInstance_var);
    doPacking(b,this->VersionNumber_var);
    doPacking(b,this->Rank_var);
    doPacking(b,this->GMP_var);
    doPacking(b,this->DTSN_var);
    doPacking(b,this->Flags_var);
    doPacking(b,this->Reserved_var);
    doPacking(b,this->DODAGID_var);
}

void DIOheader::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->RPLInstance_var);
    doUnpacking(b,this->VersionNumber_var);
    doUnpacking(b,this->Rank_var);
    doUnpacking(b,this->GMP_var);
    doUnpacking(b,this->DTSN_var);
    doUnpacking(b,this->Flags_var);
    doUnpacking(b,this->Reserved_var);
    doUnpacking(b,this->DODAGID_var);
}

uint8_t DIOheader::getRPLInstance() const
{
    return RPLInstance_var;
}

void DIOheader::setRPLInstance(uint8_t RPLInstance_var)
{
    this->RPLInstance_var = RPLInstance_var;
}

uint8_t DIOheader::getVersionNumber() const
{
    return VersionNumber_var;
}

void DIOheader::setVersionNumber(uint8_t VersionNumber_var)
{
    this->VersionNumber_var = VersionNumber_var;
}

uint16_t DIOheader::getRank() const
{
    return Rank_var;
}

void DIOheader::setRank(uint16_t Rank_var)
{
    this->Rank_var = Rank_var;
}

uint8_t DIOheader::getGMP() const
{
    return GMP_var;
}

void DIOheader::setGMP(uint8_t GMP_var)
{
    this->GMP_var = GMP_var;
}

uint8_t DIOheader::getDTSN() const
{
    return DTSN_var;
}

void DIOheader::setDTSN(uint8_t DTSN_var)
{
    this->DTSN_var = DTSN_var;
}

uint8_t DIOheader::getFlags() const
{
    return Flags_var;
}

void DIOheader::setFlags(uint8_t Flags_var)
{
    this->Flags_var = Flags_var;
}

uint8_t DIOheader::getReserved() const
{
    return Reserved_var;
}

void DIOheader::setReserved(uint8_t Reserved_var)
{
    this->Reserved_var = Reserved_var;
}

IPv6Address& DIOheader::getDODAGID()
{
    return DODAGID_var;
}

void DIOheader::setDODAGID(const IPv6Address& DODAGID_var)
{
    this->DODAGID_var = DODAGID_var;
}

class DIOheaderDescriptor : public cClassDescriptor
{
  public:
    DIOheaderDescriptor();
    virtual ~DIOheaderDescriptor();

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

Register_ClassDescriptor(DIOheaderDescriptor);

DIOheaderDescriptor::DIOheaderDescriptor() : cClassDescriptor("DIOheader", "cPacket")
{
}

DIOheaderDescriptor::~DIOheaderDescriptor()
{
}

bool DIOheaderDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DIOheader *>(obj)!=NULL;
}

const char *DIOheaderDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DIOheaderDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int DIOheaderDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *DIOheaderDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "RPLInstance",
        "VersionNumber",
        "Rank",
        "GMP",
        "DTSN",
        "Flags",
        "Reserved",
        "DODAGID",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int DIOheaderDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RPLInstance")==0) return base+0;
    if (fieldName[0]=='V' && strcmp(fieldName, "VersionNumber")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "Rank")==0) return base+2;
    if (fieldName[0]=='G' && strcmp(fieldName, "GMP")==0) return base+3;
    if (fieldName[0]=='D' && strcmp(fieldName, "DTSN")==0) return base+4;
    if (fieldName[0]=='F' && strcmp(fieldName, "Flags")==0) return base+5;
    if (fieldName[0]=='R' && strcmp(fieldName, "Reserved")==0) return base+6;
    if (fieldName[0]=='D' && strcmp(fieldName, "DODAGID")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DIOheaderDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint16_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "IPv6Address",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *DIOheaderDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DIOheaderDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DIOheader *pp = (DIOheader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DIOheaderDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DIOheader *pp = (DIOheader *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRPLInstance());
        case 1: return ulong2string(pp->getVersionNumber());
        case 2: return ulong2string(pp->getRank());
        case 3: return ulong2string(pp->getGMP());
        case 4: return ulong2string(pp->getDTSN());
        case 5: return ulong2string(pp->getFlags());
        case 6: return ulong2string(pp->getReserved());
        case 7: {std::stringstream out; out << pp->getDODAGID(); return out.str();}
        default: return "";
    }
}

bool DIOheaderDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DIOheader *pp = (DIOheader *)object; (void)pp;
    switch (field) {
        case 0: pp->setRPLInstance(string2ulong(value)); return true;
        case 1: pp->setVersionNumber(string2ulong(value)); return true;
        case 2: pp->setRank(string2ulong(value)); return true;
        case 3: pp->setGMP(string2ulong(value)); return true;
        case 4: pp->setDTSN(string2ulong(value)); return true;
        case 5: pp->setFlags(string2ulong(value)); return true;
        case 6: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *DIOheaderDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        NULL,
        "IPv6Address",
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *DIOheaderDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DIOheader *pp = (DIOheader *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getDODAGID()); break;
        default: return NULL;
    }
}

Register_Class(DIOop);

DIOop::DIOop(const char *name, int kind) : cPacket(name,kind)
{
    this->Type_var = 0;
}

DIOop::DIOop(const DIOop& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

DIOop::~DIOop()
{
}

DIOop& DIOop::operator=(const DIOop& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->Type_var = other.Type_var;
    return *this;
}

void DIOop::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->Type_var);
}

void DIOop::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->Type_var);
}

uint8_t DIOop::getType() const
{
    return Type_var;
}

void DIOop::setType(uint8_t Type_var)
{
    this->Type_var = Type_var;
}

class DIOopDescriptor : public cClassDescriptor
{
  public:
    DIOopDescriptor();
    virtual ~DIOopDescriptor();

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

Register_ClassDescriptor(DIOopDescriptor);

DIOopDescriptor::DIOopDescriptor() : cClassDescriptor("DIOop", "cPacket")
{
}

DIOopDescriptor::~DIOopDescriptor()
{
}

bool DIOopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DIOop *>(obj)!=NULL;
}

const char *DIOopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DIOopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int DIOopDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *DIOopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int DIOopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "Type")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DIOopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *DIOopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "DIO_TYPE";
            return NULL;
        default: return NULL;
    }
}

int DIOopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DIOop *pp = (DIOop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DIOopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DIOop *pp = (DIOop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getType());
        default: return "";
    }
}

bool DIOopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DIOop *pp = (DIOop *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *DIOopDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *DIOopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DIOop *pp = (DIOop *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PAD1op);

PAD1op::PAD1op(const char *name, int kind) : DIOop(name,kind)
{
}

PAD1op::PAD1op(const PAD1op& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

PAD1op::~PAD1op()
{
}

PAD1op& PAD1op::operator=(const PAD1op& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    return *this;
}

void PAD1op::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
}

void PAD1op::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
}

class PAD1opDescriptor : public cClassDescriptor
{
  public:
    PAD1opDescriptor();
    virtual ~PAD1opDescriptor();

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

Register_ClassDescriptor(PAD1opDescriptor);

PAD1opDescriptor::PAD1opDescriptor() : cClassDescriptor("PAD1op", "DIOop")
{
}

PAD1opDescriptor::~PAD1opDescriptor()
{
}

bool PAD1opDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PAD1op *>(obj)!=NULL;
}

const char *PAD1opDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PAD1opDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int PAD1opDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *PAD1opDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int PAD1opDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PAD1opDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *PAD1opDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PAD1opDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PAD1op *pp = (PAD1op *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PAD1opDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PAD1op *pp = (PAD1op *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool PAD1opDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PAD1op *pp = (PAD1op *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PAD1opDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *PAD1opDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PAD1op *pp = (PAD1op *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PADNop);

PADNop::PADNop(const char *name, int kind) : DIOop(name,kind)
{
    this->Option_Length_var = 0;
}

PADNop::PADNop(const PADNop& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

PADNop::~PADNop()
{
}

PADNop& PADNop::operator=(const PADNop& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    this->Option_Length_var = other.Option_Length_var;
    return *this;
}

void PADNop::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
    doPacking(b,this->Option_Length_var);
}

void PADNop::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
    doUnpacking(b,this->Option_Length_var);
}

uint8_t PADNop::getOption_Length() const
{
    return Option_Length_var;
}

void PADNop::setOption_Length(uint8_t Option_Length_var)
{
    this->Option_Length_var = Option_Length_var;
}

class PADNopDescriptor : public cClassDescriptor
{
  public:
    PADNopDescriptor();
    virtual ~PADNopDescriptor();

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

Register_ClassDescriptor(PADNopDescriptor);

PADNopDescriptor::PADNopDescriptor() : cClassDescriptor("PADNop", "DIOop")
{
}

PADNopDescriptor::~PADNopDescriptor()
{
}

bool PADNopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PADNop *>(obj)!=NULL;
}

const char *PADNopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PADNopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PADNopDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *PADNopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Option_Length",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int PADNopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Option_Length")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PADNopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *PADNopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PADNopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PADNop *pp = (PADNop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PADNopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PADNop *pp = (PADNop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getOption_Length());
        default: return "";
    }
}

bool PADNopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PADNop *pp = (PADNop *)object; (void)pp;
    switch (field) {
        case 0: pp->setOption_Length(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PADNopDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *PADNopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PADNop *pp = (PADNop *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(METRIC_CONTop);

METRIC_CONTop::METRIC_CONTop(const char *name, int kind) : DIOop(name,kind)
{
    this->Option_Length_var = 0;
    this->RMCT_var = 0;
    this->FPC0_var = 0;
    this->RAP_var = 0;
    this->Length_var = 0;
}

METRIC_CONTop::METRIC_CONTop(const METRIC_CONTop& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

METRIC_CONTop::~METRIC_CONTop()
{
}

METRIC_CONTop& METRIC_CONTop::operator=(const METRIC_CONTop& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    this->Option_Length_var = other.Option_Length_var;
    this->RMCT_var = other.RMCT_var;
    this->FPC0_var = other.FPC0_var;
    this->RAP_var = other.RAP_var;
    this->Length_var = other.Length_var;
    return *this;
}

void METRIC_CONTop::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
    doPacking(b,this->Option_Length_var);
    doPacking(b,this->RMCT_var);
    doPacking(b,this->FPC0_var);
    doPacking(b,this->RAP_var);
    doPacking(b,this->Length_var);
}

void METRIC_CONTop::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
    doUnpacking(b,this->Option_Length_var);
    doUnpacking(b,this->RMCT_var);
    doUnpacking(b,this->FPC0_var);
    doUnpacking(b,this->RAP_var);
    doUnpacking(b,this->Length_var);
}

uint8_t METRIC_CONTop::getOption_Length() const
{
    return Option_Length_var;
}

void METRIC_CONTop::setOption_Length(uint8_t Option_Length_var)
{
    this->Option_Length_var = Option_Length_var;
}

uint8_t METRIC_CONTop::getRMCT() const
{
    return RMCT_var;
}

void METRIC_CONTop::setRMCT(uint8_t RMCT_var)
{
    this->RMCT_var = RMCT_var;
}

uint8_t METRIC_CONTop::getFPC0() const
{
    return FPC0_var;
}

void METRIC_CONTop::setFPC0(uint8_t FPC0_var)
{
    this->FPC0_var = FPC0_var;
}

uint8_t METRIC_CONTop::getRAP() const
{
    return RAP_var;
}

void METRIC_CONTop::setRAP(uint8_t RAP_var)
{
    this->RAP_var = RAP_var;
}

uint8_t METRIC_CONTop::getLength() const
{
    return Length_var;
}

void METRIC_CONTop::setLength(uint8_t Length_var)
{
    this->Length_var = Length_var;
}

class METRIC_CONTopDescriptor : public cClassDescriptor
{
  public:
    METRIC_CONTopDescriptor();
    virtual ~METRIC_CONTopDescriptor();

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

Register_ClassDescriptor(METRIC_CONTopDescriptor);

METRIC_CONTopDescriptor::METRIC_CONTopDescriptor() : cClassDescriptor("METRIC_CONTop", "DIOop")
{
}

METRIC_CONTopDescriptor::~METRIC_CONTopDescriptor()
{
}

bool METRIC_CONTopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<METRIC_CONTop *>(obj)!=NULL;
}

const char *METRIC_CONTopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int METRIC_CONTopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int METRIC_CONTopDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *METRIC_CONTopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Option_Length",
        "RMCT",
        "FPC0",
        "RAP",
        "Length",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int METRIC_CONTopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Option_Length")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RMCT")==0) return base+1;
    if (fieldName[0]=='F' && strcmp(fieldName, "FPC0")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "RAP")==0) return base+3;
    if (fieldName[0]=='L' && strcmp(fieldName, "Length")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *METRIC_CONTopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *METRIC_CONTopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "METRIC_TYPE";
            return NULL;
        default: return NULL;
    }
}

int METRIC_CONTopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    METRIC_CONTop *pp = (METRIC_CONTop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string METRIC_CONTopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    METRIC_CONTop *pp = (METRIC_CONTop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getOption_Length());
        case 1: return ulong2string(pp->getRMCT());
        case 2: return ulong2string(pp->getFPC0());
        case 3: return ulong2string(pp->getRAP());
        case 4: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool METRIC_CONTopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    METRIC_CONTop *pp = (METRIC_CONTop *)object; (void)pp;
    switch (field) {
        case 0: pp->setOption_Length(string2ulong(value)); return true;
        case 1: pp->setRMCT(string2ulong(value)); return true;
        case 2: pp->setFPC0(string2ulong(value)); return true;
        case 3: pp->setRAP(string2ulong(value)); return true;
        case 4: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *METRIC_CONTopDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *METRIC_CONTopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    METRIC_CONTop *pp = (METRIC_CONTop *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ETX);

ETX::ETX(const char *name, int kind) : METRIC_CONTop(name,kind)
{
    this->ETX_VALUE_var = 0;
}

ETX::ETX(const ETX& other) : METRIC_CONTop()
{
    setName(other.getName());
    operator=(other);
}

ETX::~ETX()
{
}

ETX& ETX::operator=(const ETX& other)
{
    if (this==&other) return *this;
    METRIC_CONTop::operator=(other);
    this->ETX_VALUE_var = other.ETX_VALUE_var;
    return *this;
}

void ETX::parsimPack(cCommBuffer *b)
{
    METRIC_CONTop::parsimPack(b);
    doPacking(b,this->ETX_VALUE_var);
}

void ETX::parsimUnpack(cCommBuffer *b)
{
    METRIC_CONTop::parsimUnpack(b);
    doUnpacking(b,this->ETX_VALUE_var);
}

uint16_t ETX::getETX_VALUE() const
{
    return ETX_VALUE_var;
}

void ETX::setETX_VALUE(uint16_t ETX_VALUE_var)
{
    this->ETX_VALUE_var = ETX_VALUE_var;
}

class ETXDescriptor : public cClassDescriptor
{
  public:
    ETXDescriptor();
    virtual ~ETXDescriptor();

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

Register_ClassDescriptor(ETXDescriptor);

ETXDescriptor::ETXDescriptor() : cClassDescriptor("ETX", "METRIC_CONTop")
{
}

ETXDescriptor::~ETXDescriptor()
{
}

bool ETXDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ETX *>(obj)!=NULL;
}

const char *ETXDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ETXDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int ETXDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *ETXDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ETX_VALUE",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int ETXDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='E' && strcmp(fieldName, "ETX_VALUE")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ETXDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *ETXDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ETXDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ETX *pp = (ETX *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ETXDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ETX *pp = (ETX *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getETX_VALUE());
        default: return "";
    }
}

bool ETXDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ETX *pp = (ETX *)object; (void)pp;
    switch (field) {
        case 0: pp->setETX_VALUE(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ETXDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *ETXDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ETX *pp = (ETX *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ROUTING_INFOop);

ROUTING_INFOop::ROUTING_INFOop(const char *name, int kind) : DIOop(name,kind)
{
    this->Option_Length_var = 0;
    this->Prefix_Length_var = 0;
    this->RPR_var = 0;
    this->Rout_Lifrtime_var = 0;
}

ROUTING_INFOop::ROUTING_INFOop(const ROUTING_INFOop& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

ROUTING_INFOop::~ROUTING_INFOop()
{
}

ROUTING_INFOop& ROUTING_INFOop::operator=(const ROUTING_INFOop& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    this->Option_Length_var = other.Option_Length_var;
    this->Prefix_Length_var = other.Prefix_Length_var;
    this->RPR_var = other.RPR_var;
    this->Rout_Lifrtime_var = other.Rout_Lifrtime_var;
    this->Prefix_var = other.Prefix_var;
    return *this;
}

void ROUTING_INFOop::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
    doPacking(b,this->Option_Length_var);
    doPacking(b,this->Prefix_Length_var);
    doPacking(b,this->RPR_var);
    doPacking(b,this->Rout_Lifrtime_var);
    doPacking(b,this->Prefix_var);
}

void ROUTING_INFOop::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
    doUnpacking(b,this->Option_Length_var);
    doUnpacking(b,this->Prefix_Length_var);
    doUnpacking(b,this->RPR_var);
    doUnpacking(b,this->Rout_Lifrtime_var);
    doUnpacking(b,this->Prefix_var);
}

uint8_t ROUTING_INFOop::getOption_Length() const
{
    return Option_Length_var;
}

void ROUTING_INFOop::setOption_Length(uint8_t Option_Length_var)
{
    this->Option_Length_var = Option_Length_var;
}

uint8_t ROUTING_INFOop::getPrefix_Length() const
{
    return Prefix_Length_var;
}

void ROUTING_INFOop::setPrefix_Length(uint8_t Prefix_Length_var)
{
    this->Prefix_Length_var = Prefix_Length_var;
}

uint8_t ROUTING_INFOop::getRPR() const
{
    return RPR_var;
}

void ROUTING_INFOop::setRPR(uint8_t RPR_var)
{
    this->RPR_var = RPR_var;
}

uint32_t ROUTING_INFOop::getRout_Lifrtime() const
{
    return Rout_Lifrtime_var;
}

void ROUTING_INFOop::setRout_Lifrtime(uint32_t Rout_Lifrtime_var)
{
    this->Rout_Lifrtime_var = Rout_Lifrtime_var;
}

IPv6Address& ROUTING_INFOop::getPrefix()
{
    return Prefix_var;
}

void ROUTING_INFOop::setPrefix(const IPv6Address& Prefix_var)
{
    this->Prefix_var = Prefix_var;
}

class ROUTING_INFOopDescriptor : public cClassDescriptor
{
  public:
    ROUTING_INFOopDescriptor();
    virtual ~ROUTING_INFOopDescriptor();

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

Register_ClassDescriptor(ROUTING_INFOopDescriptor);

ROUTING_INFOopDescriptor::ROUTING_INFOopDescriptor() : cClassDescriptor("ROUTING_INFOop", "DIOop")
{
}

ROUTING_INFOopDescriptor::~ROUTING_INFOopDescriptor()
{
}

bool ROUTING_INFOopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ROUTING_INFOop *>(obj)!=NULL;
}

const char *ROUTING_INFOopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ROUTING_INFOopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int ROUTING_INFOopDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ROUTING_INFOopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Option_Length",
        "Prefix_Length",
        "RPR",
        "Rout_Lifrtime",
        "Prefix",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int ROUTING_INFOopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Option_Length")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "Prefix_Length")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "RPR")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "Rout_Lifrtime")==0) return base+3;
    if (fieldName[0]=='P' && strcmp(fieldName, "Prefix")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ROUTING_INFOopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint32_t",
        "IPv6Address",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *ROUTING_INFOopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ROUTING_INFOopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ROUTING_INFOop *pp = (ROUTING_INFOop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ROUTING_INFOopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ROUTING_INFOop *pp = (ROUTING_INFOop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getOption_Length());
        case 1: return ulong2string(pp->getPrefix_Length());
        case 2: return ulong2string(pp->getRPR());
        case 3: return ulong2string(pp->getRout_Lifrtime());
        case 4: {std::stringstream out; out << pp->getPrefix(); return out.str();}
        default: return "";
    }
}

bool ROUTING_INFOopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ROUTING_INFOop *pp = (ROUTING_INFOop *)object; (void)pp;
    switch (field) {
        case 0: pp->setOption_Length(string2ulong(value)); return true;
        case 1: pp->setPrefix_Length(string2ulong(value)); return true;
        case 2: pp->setRPR(string2ulong(value)); return true;
        case 3: pp->setRout_Lifrtime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ROUTING_INFOopDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        "IPv6Address",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *ROUTING_INFOopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ROUTING_INFOop *pp = (ROUTING_INFOop *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getPrefix()); break;
        default: return NULL;
    }
}

Register_Class(DODAG_CONFop);

DODAG_CONFop::DODAG_CONFop(const char *name, int kind) : DIOop(name,kind)
{
    this->Option_Length_var = 0;
    this->FAP_var = 0;
    this->DIOIntDoubl_var = 0;
    this->DIOIntMin_var = 0;
    this->DIORedun_var = 0;
    this->MaxRankIncrease_var = 0;
    this->MinHopRankIncrease_var = 0;
    this->OCP_var = 0;
    this->Reserved_var = 0;
    this->Def_Lifetime_var = 0;
    this->Lifetime_Unit_var = 0;
}

DODAG_CONFop::DODAG_CONFop(const DODAG_CONFop& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

DODAG_CONFop::~DODAG_CONFop()
{
}

DODAG_CONFop& DODAG_CONFop::operator=(const DODAG_CONFop& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    this->Option_Length_var = other.Option_Length_var;
    this->FAP_var = other.FAP_var;
    this->DIOIntDoubl_var = other.DIOIntDoubl_var;
    this->DIOIntMin_var = other.DIOIntMin_var;
    this->DIORedun_var = other.DIORedun_var;
    this->MaxRankIncrease_var = other.MaxRankIncrease_var;
    this->MinHopRankIncrease_var = other.MinHopRankIncrease_var;
    this->OCP_var = other.OCP_var;
    this->Reserved_var = other.Reserved_var;
    this->Def_Lifetime_var = other.Def_Lifetime_var;
    this->Lifetime_Unit_var = other.Lifetime_Unit_var;
    return *this;
}

void DODAG_CONFop::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
    doPacking(b,this->Option_Length_var);
    doPacking(b,this->FAP_var);
    doPacking(b,this->DIOIntDoubl_var);
    doPacking(b,this->DIOIntMin_var);
    doPacking(b,this->DIORedun_var);
    doPacking(b,this->MaxRankIncrease_var);
    doPacking(b,this->MinHopRankIncrease_var);
    doPacking(b,this->OCP_var);
    doPacking(b,this->Reserved_var);
    doPacking(b,this->Def_Lifetime_var);
    doPacking(b,this->Lifetime_Unit_var);
}

void DODAG_CONFop::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
    doUnpacking(b,this->Option_Length_var);
    doUnpacking(b,this->FAP_var);
    doUnpacking(b,this->DIOIntDoubl_var);
    doUnpacking(b,this->DIOIntMin_var);
    doUnpacking(b,this->DIORedun_var);
    doUnpacking(b,this->MaxRankIncrease_var);
    doUnpacking(b,this->MinHopRankIncrease_var);
    doUnpacking(b,this->OCP_var);
    doUnpacking(b,this->Reserved_var);
    doUnpacking(b,this->Def_Lifetime_var);
    doUnpacking(b,this->Lifetime_Unit_var);
}

uint8_t DODAG_CONFop::getOption_Length() const
{
    return Option_Length_var;
}

void DODAG_CONFop::setOption_Length(uint8_t Option_Length_var)
{
    this->Option_Length_var = Option_Length_var;
}

uint8_t DODAG_CONFop::getFAP() const
{
    return FAP_var;
}

void DODAG_CONFop::setFAP(uint8_t FAP_var)
{
    this->FAP_var = FAP_var;
}

uint8_t DODAG_CONFop::getDIOIntDoubl() const
{
    return DIOIntDoubl_var;
}

void DODAG_CONFop::setDIOIntDoubl(uint8_t DIOIntDoubl_var)
{
    this->DIOIntDoubl_var = DIOIntDoubl_var;
}

uint8_t DODAG_CONFop::getDIOIntMin() const
{
    return DIOIntMin_var;
}

void DODAG_CONFop::setDIOIntMin(uint8_t DIOIntMin_var)
{
    this->DIOIntMin_var = DIOIntMin_var;
}

uint8_t DODAG_CONFop::getDIORedun() const
{
    return DIORedun_var;
}

void DODAG_CONFop::setDIORedun(uint8_t DIORedun_var)
{
    this->DIORedun_var = DIORedun_var;
}

uint16_t DODAG_CONFop::getMaxRankIncrease() const
{
    return MaxRankIncrease_var;
}

void DODAG_CONFop::setMaxRankIncrease(uint16_t MaxRankIncrease_var)
{
    this->MaxRankIncrease_var = MaxRankIncrease_var;
}

uint16_t DODAG_CONFop::getMinHopRankIncrease() const
{
    return MinHopRankIncrease_var;
}

void DODAG_CONFop::setMinHopRankIncrease(uint16_t MinHopRankIncrease_var)
{
    this->MinHopRankIncrease_var = MinHopRankIncrease_var;
}

uint16_t DODAG_CONFop::getOCP() const
{
    return OCP_var;
}

void DODAG_CONFop::setOCP(uint16_t OCP_var)
{
    this->OCP_var = OCP_var;
}

uint8_t DODAG_CONFop::getReserved() const
{
    return Reserved_var;
}

void DODAG_CONFop::setReserved(uint8_t Reserved_var)
{
    this->Reserved_var = Reserved_var;
}

uint8_t DODAG_CONFop::getDef_Lifetime() const
{
    return Def_Lifetime_var;
}

void DODAG_CONFop::setDef_Lifetime(uint8_t Def_Lifetime_var)
{
    this->Def_Lifetime_var = Def_Lifetime_var;
}

uint16_t DODAG_CONFop::getLifetime_Unit() const
{
    return Lifetime_Unit_var;
}

void DODAG_CONFop::setLifetime_Unit(uint16_t Lifetime_Unit_var)
{
    this->Lifetime_Unit_var = Lifetime_Unit_var;
}

class DODAG_CONFopDescriptor : public cClassDescriptor
{
  public:
    DODAG_CONFopDescriptor();
    virtual ~DODAG_CONFopDescriptor();

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

Register_ClassDescriptor(DODAG_CONFopDescriptor);

DODAG_CONFopDescriptor::DODAG_CONFopDescriptor() : cClassDescriptor("DODAG_CONFop", "DIOop")
{
}

DODAG_CONFopDescriptor::~DODAG_CONFopDescriptor()
{
}

bool DODAG_CONFopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DODAG_CONFop *>(obj)!=NULL;
}

const char *DODAG_CONFopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DODAG_CONFopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int DODAG_CONFopDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *DODAG_CONFopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Option_Length",
        "FAP",
        "DIOIntDoubl",
        "DIOIntMin",
        "DIORedun",
        "MaxRankIncrease",
        "MinHopRankIncrease",
        "OCP",
        "Reserved",
        "Def_Lifetime",
        "Lifetime_Unit",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int DODAG_CONFopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Option_Length")==0) return base+0;
    if (fieldName[0]=='F' && strcmp(fieldName, "FAP")==0) return base+1;
    if (fieldName[0]=='D' && strcmp(fieldName, "DIOIntDoubl")==0) return base+2;
    if (fieldName[0]=='D' && strcmp(fieldName, "DIOIntMin")==0) return base+3;
    if (fieldName[0]=='D' && strcmp(fieldName, "DIORedun")==0) return base+4;
    if (fieldName[0]=='M' && strcmp(fieldName, "MaxRankIncrease")==0) return base+5;
    if (fieldName[0]=='M' && strcmp(fieldName, "MinHopRankIncrease")==0) return base+6;
    if (fieldName[0]=='O' && strcmp(fieldName, "OCP")==0) return base+7;
    if (fieldName[0]=='R' && strcmp(fieldName, "Reserved")==0) return base+8;
    if (fieldName[0]=='D' && strcmp(fieldName, "Def_Lifetime")==0) return base+9;
    if (fieldName[0]=='L' && strcmp(fieldName, "Lifetime_Unit")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DODAG_CONFopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint16_t",
        "uint16_t",
        "uint16_t",
        "uint8_t",
        "uint8_t",
        "uint16_t",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *DODAG_CONFopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "DIO_LENGTH";
            return NULL;
        default: return NULL;
    }
}

int DODAG_CONFopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DODAG_CONFop *pp = (DODAG_CONFop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DODAG_CONFopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DODAG_CONFop *pp = (DODAG_CONFop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getOption_Length());
        case 1: return ulong2string(pp->getFAP());
        case 2: return ulong2string(pp->getDIOIntDoubl());
        case 3: return ulong2string(pp->getDIOIntMin());
        case 4: return ulong2string(pp->getDIORedun());
        case 5: return ulong2string(pp->getMaxRankIncrease());
        case 6: return ulong2string(pp->getMinHopRankIncrease());
        case 7: return ulong2string(pp->getOCP());
        case 8: return ulong2string(pp->getReserved());
        case 9: return ulong2string(pp->getDef_Lifetime());
        case 10: return ulong2string(pp->getLifetime_Unit());
        default: return "";
    }
}

bool DODAG_CONFopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DODAG_CONFop *pp = (DODAG_CONFop *)object; (void)pp;
    switch (field) {
        case 0: pp->setOption_Length(string2ulong(value)); return true;
        case 1: pp->setFAP(string2ulong(value)); return true;
        case 2: pp->setDIOIntDoubl(string2ulong(value)); return true;
        case 3: pp->setDIOIntMin(string2ulong(value)); return true;
        case 4: pp->setDIORedun(string2ulong(value)); return true;
        case 5: pp->setMaxRankIncrease(string2ulong(value)); return true;
        case 6: pp->setMinHopRankIncrease(string2ulong(value)); return true;
        case 7: pp->setOCP(string2ulong(value)); return true;
        case 8: pp->setReserved(string2ulong(value)); return true;
        case 9: pp->setDef_Lifetime(string2ulong(value)); return true;
        case 10: pp->setLifetime_Unit(string2ulong(value)); return true;
        default: return false;
    }
}

const char *DODAG_CONFopDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<11) ? fieldStructNames[field] : NULL;
}

void *DODAG_CONFopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DODAG_CONFop *pp = (DODAG_CONFop *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PREFIX_INFOop);

PREFIX_INFOop::PREFIX_INFOop(const char *name, int kind) : DIOop(name,kind)
{
    this->Option_Length_var = 0;
    this->Prefix_Length_var = 0;
    this->LARR_var = 0;
    this->Valid_Lifetime_var = 0;
    this->Prf_Lifetime_var = 0;
    this->Reserved2_var = 0;
}

PREFIX_INFOop::PREFIX_INFOop(const PREFIX_INFOop& other) : DIOop()
{
    setName(other.getName());
    operator=(other);
}

PREFIX_INFOop::~PREFIX_INFOop()
{
}

PREFIX_INFOop& PREFIX_INFOop::operator=(const PREFIX_INFOop& other)
{
    if (this==&other) return *this;
    DIOop::operator=(other);
    this->Option_Length_var = other.Option_Length_var;
    this->Prefix_Length_var = other.Prefix_Length_var;
    this->LARR_var = other.LARR_var;
    this->Valid_Lifetime_var = other.Valid_Lifetime_var;
    this->Prf_Lifetime_var = other.Prf_Lifetime_var;
    this->Reserved2_var = other.Reserved2_var;
    this->Prefix_var = other.Prefix_var;
    return *this;
}

void PREFIX_INFOop::parsimPack(cCommBuffer *b)
{
    DIOop::parsimPack(b);
    doPacking(b,this->Option_Length_var);
    doPacking(b,this->Prefix_Length_var);
    doPacking(b,this->LARR_var);
    doPacking(b,this->Valid_Lifetime_var);
    doPacking(b,this->Prf_Lifetime_var);
    doPacking(b,this->Reserved2_var);
    doPacking(b,this->Prefix_var);
}

void PREFIX_INFOop::parsimUnpack(cCommBuffer *b)
{
    DIOop::parsimUnpack(b);
    doUnpacking(b,this->Option_Length_var);
    doUnpacking(b,this->Prefix_Length_var);
    doUnpacking(b,this->LARR_var);
    doUnpacking(b,this->Valid_Lifetime_var);
    doUnpacking(b,this->Prf_Lifetime_var);
    doUnpacking(b,this->Reserved2_var);
    doUnpacking(b,this->Prefix_var);
}

uint8_t PREFIX_INFOop::getOption_Length() const
{
    return Option_Length_var;
}

void PREFIX_INFOop::setOption_Length(uint8_t Option_Length_var)
{
    this->Option_Length_var = Option_Length_var;
}

uint8_t PREFIX_INFOop::getPrefix_Length() const
{
    return Prefix_Length_var;
}

void PREFIX_INFOop::setPrefix_Length(uint8_t Prefix_Length_var)
{
    this->Prefix_Length_var = Prefix_Length_var;
}

uint8_t PREFIX_INFOop::getLARR() const
{
    return LARR_var;
}

void PREFIX_INFOop::setLARR(uint8_t LARR_var)
{
    this->LARR_var = LARR_var;
}

uint32_t PREFIX_INFOop::getValid_Lifetime() const
{
    return Valid_Lifetime_var;
}

void PREFIX_INFOop::setValid_Lifetime(uint32_t Valid_Lifetime_var)
{
    this->Valid_Lifetime_var = Valid_Lifetime_var;
}

uint32_t PREFIX_INFOop::getPrf_Lifetime() const
{
    return Prf_Lifetime_var;
}

void PREFIX_INFOop::setPrf_Lifetime(uint32_t Prf_Lifetime_var)
{
    this->Prf_Lifetime_var = Prf_Lifetime_var;
}

uint32_t PREFIX_INFOop::getReserved2() const
{
    return Reserved2_var;
}

void PREFIX_INFOop::setReserved2(uint32_t Reserved2_var)
{
    this->Reserved2_var = Reserved2_var;
}

IPv6Address& PREFIX_INFOop::getPrefix()
{
    return Prefix_var;
}

void PREFIX_INFOop::setPrefix(const IPv6Address& Prefix_var)
{
    this->Prefix_var = Prefix_var;
}

class PREFIX_INFOopDescriptor : public cClassDescriptor
{
  public:
    PREFIX_INFOopDescriptor();
    virtual ~PREFIX_INFOopDescriptor();

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

Register_ClassDescriptor(PREFIX_INFOopDescriptor);

PREFIX_INFOopDescriptor::PREFIX_INFOopDescriptor() : cClassDescriptor("PREFIX_INFOop", "DIOop")
{
}

PREFIX_INFOopDescriptor::~PREFIX_INFOopDescriptor()
{
}

bool PREFIX_INFOopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PREFIX_INFOop *>(obj)!=NULL;
}

const char *PREFIX_INFOopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PREFIX_INFOopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int PREFIX_INFOopDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *PREFIX_INFOopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Option_Length",
        "Prefix_Length",
        "LARR",
        "Valid_Lifetime",
        "Prf_Lifetime",
        "Reserved2",
        "Prefix",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int PREFIX_INFOopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='O' && strcmp(fieldName, "Option_Length")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "Prefix_Length")==0) return base+1;
    if (fieldName[0]=='L' && strcmp(fieldName, "LARR")==0) return base+2;
    if (fieldName[0]=='V' && strcmp(fieldName, "Valid_Lifetime")==0) return base+3;
    if (fieldName[0]=='P' && strcmp(fieldName, "Prf_Lifetime")==0) return base+4;
    if (fieldName[0]=='R' && strcmp(fieldName, "Reserved2")==0) return base+5;
    if (fieldName[0]=='P' && strcmp(fieldName, "Prefix")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PREFIX_INFOopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
        "uint8_t",
        "uint8_t",
        "uint32_t",
        "uint32_t",
        "uint32_t",
        "IPv6Address",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *PREFIX_INFOopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "DIO_LENGTH";
            return NULL;
        default: return NULL;
    }
}

int PREFIX_INFOopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PREFIX_INFOop *pp = (PREFIX_INFOop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PREFIX_INFOopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PREFIX_INFOop *pp = (PREFIX_INFOop *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getOption_Length());
        case 1: return ulong2string(pp->getPrefix_Length());
        case 2: return ulong2string(pp->getLARR());
        case 3: return ulong2string(pp->getValid_Lifetime());
        case 4: return ulong2string(pp->getPrf_Lifetime());
        case 5: return ulong2string(pp->getReserved2());
        case 6: {std::stringstream out; out << pp->getPrefix(); return out.str();}
        default: return "";
    }
}

bool PREFIX_INFOopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PREFIX_INFOop *pp = (PREFIX_INFOop *)object; (void)pp;
    switch (field) {
        case 0: pp->setOption_Length(string2ulong(value)); return true;
        case 1: pp->setPrefix_Length(string2ulong(value)); return true;
        case 2: pp->setLARR(string2ulong(value)); return true;
        case 3: pp->setValid_Lifetime(string2ulong(value)); return true;
        case 4: pp->setPrf_Lifetime(string2ulong(value)); return true;
        case 5: pp->setReserved2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PREFIX_INFOopDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        "IPv6Address",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *PREFIX_INFOopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PREFIX_INFOop *pp = (PREFIX_INFOop *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getPrefix()); break;
        default: return NULL;
    }
}

Register_Class(DIOMessage);

DIOMessage::DIOMessage(const char *name, int kind) : DIOheader(name,kind)
{
}

DIOMessage::DIOMessage(const DIOMessage& other) : DIOheader()
{
    setName(other.getName());
    operator=(other);
}

DIOMessage::~DIOMessage()
{
}

DIOMessage& DIOMessage::operator=(const DIOMessage& other)
{
    if (this==&other) return *this;
    DIOheader::operator=(other);
    return *this;
}

void DIOMessage::parsimPack(cCommBuffer *b)
{
    DIOheader::parsimPack(b);
}

void DIOMessage::parsimUnpack(cCommBuffer *b)
{
    DIOheader::parsimUnpack(b);
}

class DIOMessageDescriptor : public cClassDescriptor
{
  public:
    DIOMessageDescriptor();
    virtual ~DIOMessageDescriptor();

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

Register_ClassDescriptor(DIOMessageDescriptor);

DIOMessageDescriptor::DIOMessageDescriptor() : cClassDescriptor("DIOMessage", "DIOheader")
{
}

DIOMessageDescriptor::~DIOMessageDescriptor()
{
}

bool DIOMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DIOMessage *>(obj)!=NULL;
}

const char *DIOMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DIOMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int DIOMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *DIOMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int DIOMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DIOMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *DIOMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DIOMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DIOMessage *pp = (DIOMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DIOMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DIOMessage *pp = (DIOMessage *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool DIOMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DIOMessage *pp = (DIOMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *DIOMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *DIOMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DIOMessage *pp = (DIOMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


