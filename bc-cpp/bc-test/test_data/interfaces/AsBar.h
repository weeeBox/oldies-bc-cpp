#ifndef AsBar_h__
#define AsBar_h__
 
#include "AsBc.h"
 
#include "AsObject.h"
#include "AsInterface1.h"
#include "AsInterface2.h"
 
#include "AsString.h"
 
 
AS_CLASS(AsBar);
 
class AsBar : public AsObject
{
public:
	AS_OBJ(AsBar, AsObject);
	
public:
	virtual AsString_ref string1();
	virtual AsString_ref string2();
	
	
public:
	static AsBar_ref _as_create_AsBar();
	
protected:
	void _as_construct_AsBar();
	static void _as_static_init_AsBar();
	
private:
	static bool _as_static_initialized_AsBar;
	
/* AsInterface1 interface wrapper */
public:
	class _as_interface_AsInterface1 : public AsInterface1
	{
	public:
		_as_interface_AsInterface1(AsBar *target) : m_target(target) { m_target->retain(); } 
		~_as_interface_AsInterface1() { m_target->release(); } 
		void _as_gc_mark() { if (_as_gc_mark_needed()) { AsInterface1::_as_gc_mark(); AS_GC_MARK(m_target); }} 
		private: AsBar *m_target; 
		friend class AsBar;
		
	public:
		AsString_ref string1() { return m_target->string1(); }
	};
	
	inline AsInterface1_ref _as_box_AsInterface1() { return new _as_interface_AsInterface1(this); }
	inline static AsBar* _as_unbox(AsInterface1* obj) { return ((_as_interface_AsInterface1*)obj)->m_target; }
	
/* AsInterface2 interface wrapper */
public:
	class _as_interface_AsInterface2 : public AsInterface2
	{
	public:
		_as_interface_AsInterface2(AsBar *target) : m_target(target) { m_target->retain(); } 
		~_as_interface_AsInterface2() { m_target->release(); } 
		void _as_gc_mark() { if (_as_gc_mark_needed()) { AsInterface2::_as_gc_mark(); AS_GC_MARK(m_target); }} 
		private: AsBar *m_target; 
		friend class AsBar;
		
	public:
		AsString_ref string2() { return m_target->string2(); }
	};
	
	inline AsInterface2_ref _as_box_AsInterface2() { return new _as_interface_AsInterface2(this); }
	inline static AsBar* _as_unbox(AsInterface2* obj) { return ((_as_interface_AsInterface2*)obj)->m_target; }
};
 
#endif // AsBar_h__
