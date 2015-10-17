#ifndef _SMART_PTR_H_
#define _SMART_PTR_H_

#include <memory>

template< typename T > using SharedPtr	= std::shared_ptr< T >;
template< typename T > using WeakPtr	= std::weak_ptr< T >;
template< typename T > using UniquePtr	= std::unique_ptr< T >;

namespace
{
	/*------------------------------------------------------------*/
	//	@class		：	TWrapper
	//	@brief		：	テンプレートで受け取った型のラッパ
	//	@author		：	このファイルは書籍を参考に制作
	/*------------------------------------------------------------*/
	template< typename T >
	struct TWrapper : public T
	{
		/**
		 *	@brief	コンストラクタ
		 *	@param	param	可変長引数
		 */
		template< typename... Param >
		TWrapper( Param&&... param )
			: T( std::forward< Param >( param )... )
		{
			
		}
	};
}

/**
 *	@brief	std::make_shared
 *	@param	param			parameter
 *	@return	SharedPtr< T >	std::shared_ptr
 */
template< typename T, typename... Param >
SharedPtr< T > makeShared( Param&&... param )
{
	return std::move( std::make_shared< TWrapper< T > >( std::forward< Param >( param )... ) );
}

/**
 *	@brief	std::make_unique
 *	@param	param			parameter
 *	@return	UniquePtr< T >	std::unique_ptr
 */
template< typename T, typename... Param >
UniquePtr< T > makeUnique( Param&&... param )
{
	// C++11ではmake_uniqueが存在しないのでnewを使用する。
	return std::move( std::unique_ptr< T >( new TWrapper< T >( std::forward< Param >( param )... ) ) );
}

#endif