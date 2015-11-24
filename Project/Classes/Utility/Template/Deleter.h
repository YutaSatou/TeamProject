#ifndef _DELETER_H_
#define _DELETER_H_

#include <functional>
#include <type_traits>

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
		, mDeleteFunction( []( T* instance ) { } )
		, mIsRegister( false )
	{
		
	}
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Deleter()
	{
		// static_assert( mIsRegister, "インスタンスを削除する関数が登録されていません。" );
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
		mDeleteFunction	= deleteFunction;
		mIsRegister		= true;
	}
	
private:
	
	T*				mInstance;			//=> 削除するインスタンス
	DeleteFunction	mDeleteFunction;	//=> インスタンスを削除する関数
	bool			mIsRegister;		//=> 登録を完了したか否か
};

#endif