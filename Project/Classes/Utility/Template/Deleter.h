#ifndef _DELETER_H_
#define _DELETER_H_

#include <functional>

/*------------------------------------------------------------*/
//	@class		：	Deleter
//	@brief		：	デストラクトラッパ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
template< typename T >
class Deleter
{
	
public:
	
	using DeleteFunction = std::function< void( T* ) >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Deleter()
		: mInstance( nullptr )
		, mDeleteFunction( []( T* ) { } )
	{
		
	}
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Deleter()
	{
		mDeleteFunction( mInstance );
	}
	
	/**
	 *	@brief	コピー禁止
	 */
	Deleter( const Deleter& )				= delete;
	Deleter( Deleter&& )					= delete;
	Deleter& operator = ( const Deleter& )	= delete;
	Deleter& operator = ( Deleter&& )		= delete;
	
	/**
	 *	@brief	削除するインスタンスの登録
	 *	@param	instance	インスタンス
	 */
	void registerDeleteInstance( T* instance )
	{
		mInstance = instance;
	}
	
	/**
	 *	@brief	インスタンスを削除する関数の登録
	 *	@param	deleteFunction	インスタンスを削除する関数
	 */
	void registerDeleteFunction( DeleteFunction deleteFunction )
	{
		mDeleteFunction = deleteFunction;
	}
	
private:
	
	T*				mInstance;			//=> 削除するインスタンス
	DeleteFunction	mDeleteFunction;	//=> インスタンスを削除する関数
};

#endif