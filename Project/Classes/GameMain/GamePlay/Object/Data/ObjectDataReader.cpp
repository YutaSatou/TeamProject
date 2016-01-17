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
	
	Color3B readColor( const ValueMap& valueMap )
	{
		return { valueMap.at( "ColorR" ).asByte(), valueMap.at( "ColorG" ).asByte(), valueMap.at( "ColorB" ).asByte() };
	}
	
	Vec2 readPosition( const ValueMap& valueMap )
	{
		return { valueMap.at( "PositionX" ).asFloat(), valueMap.at( "PositionY" ).asFloat() };
	}
	
	LiquidFunMaterial readMaterial( const ValueMap& valueMap )
	{
		return { valueMap.at( "Density" ).asFloat(), valueMap.at( "Restitution" ).asFloat(), valueMap.at( "Friction" ).asFloat() };
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
		ObjectDataPtr data
		{
			std::make_shared< ObjectData >( readTextureName( valueMap ),
										    readColor( valueMap ),
										    readPosition( valueMap ),
										    readMaterial( valueMap ) )
		};
		
		container.emplace_back( data );
	}
	
	return container;
}