#include "ObjectDataReader.h"
#include "ObjectData.h"
#include "Utility/FileIO/PlistReader.h"

using namespace cocos2d;

namespace
{
	std::string readTextureName( const ValueMap& valueMap )
	{
		return valueMap.at( "TextureName" ).asString();
	}
	
	ColorRYB readColor( const ValueMap& valueMap )
	{
		return { valueMap.at( "ColorR" ).asDouble(), valueMap.at( "ColorY" ).asDouble(), valueMap.at( "ColorB" ).asDouble() };
	}
	
	Vec2 readPosition( const ValueMap& valueMap )
	{
		return { valueMap.at( "PositionX" ).asFloat(), valueMap.at( "PositionY" ).asFloat() };
	}
	
	LiquidFunMaterial readMaterial( const ValueMap& valueMap )
	{
		return { valueMap.at( "Density" ).asFloat(), valueMap.at( "Restitution" ).asFloat(), valueMap.at( "Friction" ).asFloat() };
	}
	
	std::uint8_t readAlpha( const ValueMap& valueMap )
	{
		return { valueMap.at( "Alpha" ).asByte() };
	}
}

// データの読み込み
ObjectDataReader::ObjectDataContainer ObjectDataReader::read( const std::string& plistFilePath )
{
	PlistReader			reader;
	ObjectDataContainer	container;
	
	auto valueMapContainer = reader.read( plistFilePath );
	
	for ( auto& valueMap : valueMapContainer )
	{
		ObjectDataPtr data { std::make_shared< ObjectData >() };
		
		data->blendColor	= readColor( valueMap );
		data->textureName	= readTextureName( valueMap );
		data->textureColor	= ColorRYB::convertToRGB( data->blendColor );
		data->position		= readPosition( valueMap );
		data->material		= readMaterial( valueMap );
		data->alpha			= readAlpha( valueMap );
		
		container.push_back( data );
	}
	
	return container;
}