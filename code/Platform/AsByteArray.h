#ifndef AsByteArray_h__
#define AsByteArray_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
ASTYPEREF(AsByteArray)
ASTYPEREF(AsString)
ASTYPEREF(AsObject)
 
class AsByteArray : public AsObject
{
public:
	ASOBJ(AsByteArray, AsObject);
	
public:
	virtual int bytesAvailable();
	virtual void clear();
	static int defaultObjectEncoding();
	static void defaultObjectEncoding(int version);
	virtual AsString_ref endian();
	virtual void endian(const AsString_ref& type);
	virtual int length();
	virtual void length(int _value);
	virtual int objectEncoding();
	virtual void objectEncoding(int version);
	virtual int position();
	virtual void position(int offset);
	virtual BOOL readBoolean();
	virtual int readByte();
	virtual void readBytes(const AsByteArray_ref& bytes, int offset, int length);
	virtual void readBytes(const AsByteArray_ref& bytes, int offset);
	virtual void readBytes(const AsByteArray_ref& bytes);
	virtual float readDouble();
	virtual float readFloat();
	virtual int readInt();
	virtual AsString_ref readMultiByte(int length, const AsString_ref& charSet);
	virtual AsObject_ref readObject();
	virtual int readShort();
	virtual AsString_ref readUTF();
	virtual AsString_ref readUTFBytes(int length);
	virtual int readUnsignedByte();
	virtual int readUnsignedInt();
	virtual int readUnsignedShort();
	virtual AsString_ref toString();
	virtual void writeBoolean(BOOL _value);
	virtual void writeByte(int _value);
	virtual void writeBytes(const AsByteArray_ref& bytes, int offset, int length);
	virtual void writeBytes(const AsByteArray_ref& bytes, int offset);
	virtual void writeBytes(const AsByteArray_ref& bytes);
	virtual void writeDouble(float _value);
	virtual void writeFloat(float _value);
	virtual void writeInt(int _value);
	virtual void writeMultiByte(const AsString_ref& _value, const AsString_ref& charSet);
	virtual void writeObject(const AsObject_ref& _object);
	virtual void writeShort(int _value);
	virtual void writeUTF(const AsString_ref& _value);
	virtual void writeUTFBytes(const AsString_ref& _value);
	virtual void writeUnsignedInt(int _value);
	
public:
	static AsByteArray_ref __createAsByteArray();
	void __internalInitialiseAsByteArray();
	
private:
	static StaticInit __internalStaticInitializerAsByteArray;
	static BOOL __internalStaticInitializedAsByteArray;
	
public:
	static void __internalStaticInit();
	
protected:
	AsByteArray();
};
 
#endif // AsByteArray_h__
