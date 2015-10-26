#include "ObjectDataReader.h"
#include "ObjectData.h"
#include "cocos2d.h"
#include "Utility/FileO/PlistReader.h"

using namespace cocos2d;

namespace
{
	std::string readTextureName( const ValueMap& valueMap )
	{
		return valueMap.at( "TextureName" ).asString();
	}
	
	Color3B readColor( const ValueMap& valueMap )
	{
		return Color3B { valueMap.at( "ColorR" ).asByte(), valueMap.at( "ColorG" ).asByte(), valueMap.at( "ColorB" ).asByte() };
	}
	
	Vec2 readPosition( const ValueMap& valueMap )
	{
		return Vec2 { valueMap.at( "PositionX" ).asFloat(), valueMap.at( "PositionY" ).asFloat() };
	}
	
	PhysicsMaterial readMaterial( const ValueMap& valueMap )
	{
		return PhysicsMaterial { valueMap.at( "Density" ).asFloat(), valueMap.at( "Restitution" ).asFloat(), valueMap.at( "Friction" ).asFloat() };
	}
}

// データの読み込み
ObjectDataReader::ObjectDataContainer ObjectDataReader::read( const std::string& plistFilePath )
{
	PlistReader			reader;
	ObjectDataContainer	container;
	
	auto valueMapContainer = reader.read( plistFilePath );
	
	container.resize( valueMapContainer.size() );
	
	for ( auto valueMap : valueMapContainer )
	{
		SharedPtr< ObjectData > data = makeShared< ObjectData >();
		
		data->textureName	= readTextureName( valueMap );
		data->textureColor	= readColor( valueMap );
		data->position		= readPosition( valueMap );
		data->material		= readMaterial( valueMap );
		data->blendColor	= ColorCMY::convertToCMY( data->textureColor );
		
		container.push_back( data );
	}
	
	return container;
}