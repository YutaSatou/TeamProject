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
		, mDeleteFunction( []( T* instance ) { if ( !instance ) { return; } delete instance; instance = nullptr; } )
	{
		// インスタンスを削除する関数を登録しない場合は、通常のデリートが行われる。
	}
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Deleter()
	{
		// インスタンスを削除する。
		mDeleteFunction( mInstance );
	}
	
	/**
	 *	@brief	コピーコンストラクタ( 封印 )
	 */
	Deleter( const Deleter& )	= delete;
	Deleter( Deleter&& )		= delete;
	
	/**
	 *	@brief	代入演算子( 封印 )
	 */
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