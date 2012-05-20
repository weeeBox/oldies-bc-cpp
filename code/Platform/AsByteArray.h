#ifndef AsByteArray_h__
#define AsByteArray_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
 
#include "AsString.h"
#include "AsByteArray.h"
#include "AsObject.h"
 
 
AS_CLASS(AsByteArray);
 
class AsByteArray : public AsObject
{
public:
	AS_OBJ(AsByteArray, AsObject);
	
public:
	virtual uint getBytesAvailable();
	virtual void clear();
	static uint getDefaultObjectEncoding();
	static void setDefaultObjectEncoding(uint version);
	virtual AsString_ref getEndian();
	virtual void setEndian(const AsString_ref& type);
	virtual uint getLength();
	virtual void setLength(uint value);
	virtual uint getObjectEncoding();
	virtual void setObjectEncoding(uint version);
	virtual uint getPosition();
	virtual void setPosition(uint offset);
	virtual bool readBoolean();
	virtual int readByte();
	virtual void readBytes(const AsByteArray_ref& bytes, uint offset, uint length);
	virtual void readBytes(const AsByteArray_ref& bytes, uint offset);
	virtual void readBytes(const AsByteArray_ref& bytes);
	virtual float readDouble();
	virtual float readFloat();
	virtual int readInt();
	virtual AsString_ref readMultiByte(uint length, const AsString_ref& charSet);
	virtual AsObject_ref readObject();
	virtual int readShort();
	virtual AsString_ref readUTF();
	virtual AsString_ref readUTFBytes(uint length);
	virtual uint readUnsignedByte();
	virtual uint readUnsignedInt();
	virtual uint readUnsignedShort();
	virtual AsString_ref toString();
	virtual void writeBoolean(bool value);
	virtual void writeByte(int value);
	virtual void writeBytes(const AsByteArray_ref& bytes, uint offset, uint length);
	virtual void writeBytes(const AsByteArray_ref& bytes, uint offset);
	virtual void writeBytes(const AsByteArray_ref& bytes);
	virtual void writeDouble(float value);
	virtual void writeFloat(float value);
	virtual void writeInt(int value);
	virtual void writeMultiByte(const AsString_ref& value, const AsString_ref& charSet);
	virtual void writeObject(const AsObject_ref& object);
	virtual void writeShort(int value);
	virtual void writeUTF(const AsString_ref& value);
	virtual void writeUTFBytes(const AsString_ref& value);
	virtual void writeUnsignedInt(uint value);
	
	static void _as_static_init_AsByteArray();
	
private:
	static bool _as_static_initialized_AsByteArray;
	static AsStaticRefInitializer _as_static_initializer_AsByteArray;
};
 
#endif // AsByteArray_h__
