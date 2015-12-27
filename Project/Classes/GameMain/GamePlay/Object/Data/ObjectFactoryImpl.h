#ifndef _OBJECT_FACTORY_IMPL_H_
#define _OBJECT_FACTORY_IMPL_H_

#include "ObjectFactory.h"

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

// 要素が空か否か
template< typename InstanceType, typename... Param >
bool ObjectFactory< InstanceType, Param... >::isEmptyElement( const std::string& key ) const
{
	return ( mCreateFunctionContainer.count( key ) == 0 );
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