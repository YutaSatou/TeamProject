#include "ObjectCreator.h"
#include "cocos2d.h"
#include "../Data/ObjectData.h"

using namespace cocos2d;

namespace
{
	/**
	 *	@brief	拡張子の削除
	 *	@param	fileName	ファイルの名前
	 *	@return	std::string	拡張子を削除した文字列
	 */
	std::string deleteExtension( const std::string& fileName )
	{
		std::string	str			= fileName;
		std::string	extension	= ".png";
		
		str.erase( str.size() - extension.size() );
		
		return str;
	}
}

// コンストラクタ
ObjectCreator::ObjectCreator( Node* parentNode )
	: mParentNode( parentNode )
{
	
}

// デストラクタ
ObjectCreator::~ObjectCreator()
{
	mCreateFunctionContainer.clear();
}

// オブジェクト生成関数の追加
void ObjectCreator::addCreateFunction( const ObjectName& name, CreateFunction func )
{
	mCreateFunctionContainer[ name ] = func;
}

// オブジェクトの生成
void ObjectCreator::createObject( IDataLoader::ObjectDataContainer& objectDataContainer )
{
	int objectNumber = 0;
	
	std::for_each( objectDataContainer.begin(), objectDataContainer.end(),
				   [ this, &objectNumber ]( SharedPtr< ObjectData > objectData )
	{
		// オブジェクトの名前を設定する。
		std::string name = deleteExtension( objectData->textureName );
		name += std::to_string( objectNumber );
		
		if ( mCreateFunctionContainer.count( name ) != 0 )
		{
			// オブジェクトの名前に対応するオブジェクトを生成し、親ノードに追加する。
			Node* node = mCreateFunctionContainer[ name ]( objectData, name );
			mParentNode->addChild( node );
			objectNumber++;
		}
	} );
}