//
//  StageData.h
//  TeamProject
//
//  Created by Satou yuta on 2015/10/19.
//
//

#ifndef __TeamProject__StageData__
#define __TeamProject__StageData__

#include <cocos2d.h>

class ObjectData;

class StageData
{
    
public:
    
    // 型定義
    using ObjectDataPtr = std::shared_ptr< ObjectData >;
    using StageDataVector = std::vector< ObjectDataPtr >;
    
public:
    
    /**
     @brief	ステージデータの読み込み
     
     @param	fileName	ファイルの名前
     @return				読み込んだデータを格納したベクタ
     */
    StageDataVector read( const std::string& fileName );
    
private:
    
    /**
     @brief	デバッグ出力
     @param	data	出力するパラメータ
     */
    void debugLog( const ObjectData& data );
};

#endif
