//file: Hubris/HType/HTypeHandle.h
#ifndef _H_TYPE_HANDLE_H_
#define _H_TYPE_HANDLE_H_


//static const HSINT INVALID_INDEX = HCOMMON_INVALID_INDEX;

#define HTYPE_HANDLE( IN_HANDLE_NAME )															\
class IN_HANDLE_NAME																			\
{																								\
public:																							\
	IN_HANDLE_NAME( const HSINT in_handle ) : m_handle( in_handle ) { return; }					\
	IN_HANDLE_NAME( const IN_HANDLE_NAME& in_src ) : m_handle( in_src.m_handle ) { return; }	\
	IN_HANDLE_NAME() : m_handle( HCOMMON_INVALID_INDEX ) { return; }							\
	~IN_HANDLE_NAME() { return; }																\
	operator HSINT()const { return m_handle; }													\
	HBOOL operator <( const HSINT in_rhs )const { return( m_handle < in_rhs ); }				\
	HBOOL operator >( const HSINT in_rhs )const { return( m_handle > in_rhs ); }				\
	HBOOL operator <=( const HSINT in_rhs )const { return( m_handle <= in_rhs ); }				\
	HBOOL operator >=( const HSINT in_rhs )const { return( m_handle >= in_rhs ); }				\
	HBOOL operator ==( const HSINT in_rhs )const { return( m_handle == in_rhs ); }				\
	HBOOL operator !=( const HSINT in_rhs )const { return( m_handle != in_rhs ); }				\
private:																						\
	HSINT m_handle;																				\
};

#endif // _H_TYPE_HANDLE_H_