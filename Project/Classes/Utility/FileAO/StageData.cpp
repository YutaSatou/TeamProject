//
//  StageData.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/10/19.
//
//

#include "StageData.h"
#include "PlistReader.h"
#include "../../GameMain/GamePlay/Object/Data/ObjectData.h"

StageData::StageDataVector StageData::read( const std::string& fileName )
{
    // plistファイルを読み込みます
    PlistReader		reader;
    auto valueMap =	reader.read( fileName );
    
    // 読み込んだデータを格納するベクタを準備します
    StageDataVector stageData;
    
    for ( auto map : valueMap )
    {
        // 読み込んだデータを格納します
        ObjectDataPtr data = std::make_shared< ObjectData >();
        
        GLubyte r, g, b;
        float posX, posY;
        
        data->textureName = map.at( "TextureName" ).asString();
        //カラー
        r = map.at( "ColorR" ).asByte();
        g = map.at( "ColorG" ).asByte();
        b = map.at( "ColorB" ).asByte();
        data->textureColor = cocos2d::Color3B( r, g, b );
        data->blendColor = ColorCMY::convertToCMY( data->textureColor );
        //座標
        posX = map.at( "positionX" ).asInt();
        posY = map.at( "positionY" ).asInt();
        data->position = cocos2d::Vec2( posX, posY);
        
        stageData.push_back( data );
        
        // デバック出力
        //CCLOG( "テクスチャの名前 : %s", data->textureName.c_str() );
        //CCLOG( "カラーR : %i",  (int)data->textureColor.r );
        //CCLOG( "カラーG : %i",  (int)data->textureColor.g );
        //CCLOG( "カラーB : %i",  (int)data->textureColor.b );
        //CCLOG( "座標 : %f, %f", data->position.x , data->position.y );
    }
    
    return stageData;
}