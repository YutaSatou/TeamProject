#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <memory>

/*------------------------------------------------------------*/
//	@class		：	Singleton
//	@brief		：	シングルトンのテンプレート
//	@author		：	利川聖太
/*------------------------------------------------------------*/
template< typename T >
class Singleton
{
	
public:
	
	/**
	 *	@brief	インスタンスの取得
	 *	@return	T	唯一のインスタンスのアドレス
	 */
	static T& getInstance()
	{
		static typename std::unique_ptr< T > instance( new T() );
		return *instance;
	}
	
protected:
	
	/**
	 *	@brief	コンストラクタ, コピーコンストラクタ, ムーブコンストラクタ
	 */
	Singleton()						= default;
	Singleton( const Singleton& )	= delete;
	Singleton( Singleton&& )		= delete;
	
	/**
	 *	@brief	代入演算子
	 */
	Singleton& operator=( const Singleton& )	= delete;
	Singleton& operator=( Singleton&& )			= delete;
};

#endif