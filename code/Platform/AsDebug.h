#ifndef AsDebug_h__
#define AsDebug_h__
 
#define ASSERT(x) if (!(x)) abort()
#define IMPLEMENT_ME abort();

/*class AsDebug : public AsObject
{
public:
	ASOBJ(AsDebug, AsObject);
	
public:
	static void assert(BOOL condition, const AsString_ref& message);
	static void assert(BOOL condition);
	static void implementMe(const AsString_ref& message);
	static void implementMe();
	
public:
	static AsDebug_ref __createAsDebug();
	void __internalInitialiseAsDebug();
	
private:
	static StaticInit __internalStaticInitializerAsDebug;
	static BOOL __internalStaticInitializedAsDebug;
	
public:
	static void __internalStaticInit();
	
protected:
	AsDebug();
};
*/
 
#endif // AsDebug_h__
