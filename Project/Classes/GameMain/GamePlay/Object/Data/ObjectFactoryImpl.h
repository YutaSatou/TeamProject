#ifndef _OBJECT_FACTORY_IMPL_H_
#define _OBJECT_FACTORY_IMPL_H_

#include "ObjectFactory.h"
#include <cstring>

// デストラクタ
template< typename InstanceType, typename... Param >
ObjectFactory< InstanceType, Param... >::~ObjectFactory()
{
	mCreateFunctionContainer.clear();
}

// オブジェクト生成関数の追加
template< typename InstanceType, typename... Param >
void ObjectFactory< InstanceType, Param... >::addCreateFunction( const std::string& key, CreateFunction func )
{
	mCreateFunctionContainer[ key ] = func;
}

// オブジェクトの生成
template< typename InstanceType, typename... Param >
InstanceType* ObjectFactory< InstanceType, Param... >::createObject( const std::string& key, Param... param )
{
	return mCreateFunctionContainer.at( key )( param... );
}

// 要素が登録済みか否か
template< typename InstanceType, typename... Param >
bool ObjectFactory< InstanceType, Param... >::isRegisterElement( const std::string& key ) const
{
	return ( mCreateFunctionContainer.count( key ) != 0 );
}

// 文字列にキーが含まれているか否か
template< typename InstanceType, typename... Param >
bool ObjectFactory< InstanceType, Param... >::containsKeyToStr( const std::string& key, const std::string& str ) const
{
	return std::strstr( str.c_str(), key.c_str() );
}

// ファイルパスからファイルネームの抽出
template< typename InstanceType, typename... Param >
std::string ObjectFactory< InstanceType, Param... >::extractFileName( const std::string& filePath ) const
{
	std::string	str { filePath };
	
	// 階層を削除する。
	std::size_t hierarchy { str.find_last_of( "/" ) + 1 };
	str.erase( 0, hierarchy );
	
	// 拡張子を削除する。
	std::size_t extension { str.find_last_of( "." ) };
	str.erase( extension );
	
	return str;
}

#endif