#include "AsByteArray.h"
#include "AsByteArray.h"
#include "AsString.h"
#include "AsObject.h"
#include "AsString.h"
#include "AsByteArray.h"
#include "AsObject.h"
 
 
int AsByteArray::bytesAvailable()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::clear()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::defaultObjectEncoding()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::defaultObjectEncoding(int version)
{
	throw new AsNotImplementedError();
}
 
AsString_ref AsByteArray::endian()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::endian(const AsString_ref& type)
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::length()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::length(int _value)
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::objectEncoding()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::objectEncoding(int version)
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::position()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::position(int offset)
{
	throw new AsNotImplementedError();
}
 
BOOL AsByteArray::readBoolean()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readByte()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes, int offset, int length)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes, int offset)
{
	readBytes(bytes, offset, (uint)(0));
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes)
{
	readBytes(bytes, (uint)(0), (uint)(0));
}
 
float AsByteArray::readDouble()
{
	throw new AsNotImplementedError();
}
 
float AsByteArray::readFloat()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readInt()
{
	throw new AsNotImplementedError();
}
 
AsString_ref AsByteArray::readMultiByte(int length, const AsString_ref& charSet)
{
	throw new AsNotImplementedError();
}
 
AsObject_ref AsByteArray::readObject()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readShort()
{
	throw new AsNotImplementedError();
}
 
AsString_ref AsByteArray::readUTF()
{
	throw new AsNotImplementedError();
}
 
AsString_ref AsByteArray::readUTFBytes(int length)
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readUnsignedByte()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readUnsignedInt()
{
	throw new AsNotImplementedError();
}
 
int AsByteArray::readUnsignedShort()
{
	throw new AsNotImplementedError();
}
 
AsString_ref AsByteArray::toString()
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeBoolean(BOOL _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeByte(int _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes, int offset, int length)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes, int offset)
{
	writeBytes(bytes, offset, (uint)(0));
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes)
{
	writeBytes(bytes, (uint)(0), (uint)(0));
}
 
void AsByteArray::writeDouble(float _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeFloat(float _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeInt(int _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeMultiByte(const AsString_ref& _value, const AsString_ref& charSet)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeObject(const AsObject_ref& _object)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeShort(int _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeUTF(const AsString_ref& _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeUTFBytes(const AsString_ref& _value)
{
	throw new AsNotImplementedError();
}
 
void AsByteArray::writeUnsignedInt(int _value)
{
	throw new AsNotImplementedError();
}
 
AsByteArray_ref AsByteArray::__createAsByteArray()
{
	AsByteArray_ref __reference(new AsByteArray());
	return __reference;
}
 
void AsByteArray::__internalInitialiseAsByteArray()
{
}
 
StaticInit AsByteArray::__internalStaticInitializerAsByteArray(&AsByteArray::__internalStaticInit);
BOOL AsByteArray::__internalStaticInitializedAsByteArray = false;
 
void AsByteArray::__internalStaticInit()
{
	if (!__internalStaticInitializedAsByteArray)
	{
		__internalStaticInitializedAsByteArray = true;
		AsObject::__internalStaticInit();
	}
}
 
AsByteArray::AsByteArray()
{
}
 
