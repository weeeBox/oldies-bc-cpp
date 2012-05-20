#ifndef AsBitmapData_h__
#define AsBitmapData_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
#include "AsIBitmapDrawable.h"
 
#include "AsString.h"
 
AS_REF(AsIBitmapDrawable);
AS_CLASS(AsMatrix);
AS_CLASS(AsColorTransform);
AS_CLASS(AsRectangle);
 
AS_CLASS(AsBitmapData);
 
class AsBitmapData : public AsObject
{
public:
	AS_OBJ(AsBitmapData, AsObject);
	
private:
	int mWidth;
	int mHeight;
	bool mTransparent;
	uint mFillColor;
	
public:
	virtual void draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode, const AsRectangle_ref& clipRect, bool smoothing);
	virtual void draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode, const AsRectangle_ref& clipRect);
	virtual void draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform, const AsString_ref& blendMode);
	virtual void draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix, const AsColorTransform_ref& colorTransform);
	virtual void draw(const AsIBitmapDrawable_ref& source, const AsMatrix_ref& matrix);
	virtual void draw(const AsIBitmapDrawable_ref& source);
	virtual void dispose();
	virtual int getWidth();
	virtual int getHeight();
	
	
public:
	static AsBitmapData_ref _as_create_AsBitmapData(int width, int height, bool transparent, uint fillColor);
	static AsBitmapData_ref _as_create_AsBitmapData(int width, int height, bool transparent);
	static AsBitmapData_ref _as_create_AsBitmapData(int width, int height);
	
protected:
	void _as_construct_AsBitmapData(int width, int height, bool transparent, uint fillColor);
	void _as_construct_AsBitmapData(int width, int height, bool transparent);
	void _as_construct_AsBitmapData(int width, int height);
	
public:
	static void _as_static_init_AsBitmapData();
	
private:
	static bool _as_static_initialized_AsBitmapData;
	static AsStaticRefInitializer _as_static_initializer_AsBitmapData;
	
	
protected:
	AsBitmapData();
	
/* AsIBitmapDrawable interface wrapper */
public:
	class _as_interface_AsIBitmapDrawable : public AsIBitmapDrawable
	{
	public:
		_as_interface_AsIBitmapDrawable(AsBitmapData *target) : m_target(target) { m_target->retain(); } 
		~_as_interface_AsIBitmapDrawable() { m_target->release(); } 
		void _as_gc_mark() { if (_as_gc_mark_needed()) { AsIBitmapDrawable::_as_gc_mark(); AS_GC_MARK(m_target); }} 
		private: AsBitmapData *m_target; 
		friend class AsBitmapData;
		
	public:
	};
	
	inline AsIBitmapDrawable_ref _as_box_AsIBitmapDrawable() { return new _as_interface_AsIBitmapDrawable(this); }
	inline static AsBitmapData* _as_unbox(AsIBitmapDrawable* obj) { return ((_as_interface_AsIBitmapDrawable*)obj)->m_target; }
};
 
#endif // AsBitmapData_h__
