#include "AsByteArray.h"
#include "AsString.h"
#include "AsByteArray.h"
#include "AsObject.h"
#include "AsNotImplementedError.h"
 
uint AsByteArray::getBytesAvailable()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::clear()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::getDefaultObjectEncoding()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::setDefaultObjectEncoding(uint version)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsByteArray::getEndian()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::setEndian(const AsString_ref& type)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::getLength()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::setLength(uint _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::getObjectEncoding()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::setObjectEncoding(uint version)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::getPosition()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::setPosition(uint offset)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsByteArray::readBoolean()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsByteArray::readByte()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes, uint offset, uint length)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes, uint offset)
{
	readBytes(bytes, offset, (uint)(0));
}
 
void AsByteArray::readBytes(const AsByteArray_ref& bytes)
{
	readBytes(bytes, (uint)(0), (uint)(0));
}
 
float AsByteArray::readDouble()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
float AsByteArray::readFloat()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsByteArray::readInt()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsByteArray::readMultiByte(uint length, const AsString_ref& charSet)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsObject_ref AsByteArray::readObject()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
int AsByteArray::readShort()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsByteArray::readUTF()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsByteArray::readUTFBytes(uint length)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::readUnsignedByte()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::readUnsignedInt()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
uint AsByteArray::readUnsignedShort()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
AsString_ref AsByteArray::toString()
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeBoolean(bool _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeByte(int _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes, uint offset, uint length)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes, uint offset)
{
	writeBytes(bytes, offset, (uint)(0));
}
 
void AsByteArray::writeBytes(const AsByteArray_ref& bytes)
{
	writeBytes(bytes, (uint)(0), (uint)(0));
}
 
void AsByteArray::writeDouble(float _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeFloat(float _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeInt(int _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeMultiByte(const AsString_ref& _value, const AsString_ref& charSet)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeObject(const AsObject_ref& _object)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeShort(int _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeUTF(const AsString_ref& _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeUTFBytes(const AsString_ref& _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
void AsByteArray::writeUnsignedInt(uint _value)
{
	throw AS_NEW(AsNotImplementedError,());
}
 
bool AsByteArray::_as_static_initialized_AsByteArray = false;
AsStaticRefInitializer AsByteArray::_as_static_initializer_AsByteArray(_as_static_init_AsByteArray);
void AsByteArray::_as_static_init_AsByteArray()
{
	if (!_as_static_initialized_AsByteArray)
	{
		_as_static_initialized_AsByteArray = true;
	}
}
