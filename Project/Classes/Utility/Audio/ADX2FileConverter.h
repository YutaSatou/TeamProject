//
//  ADX2FileConverter.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#ifndef __TeamProject__ADX2FileConverter__
#define __TeamProject__ADX2FileConverter__

#include <string>

class ADX2FlieConverter{
    
protected:
    
    //コンストラクタ
    ADX2FlieConverter();
    
    //デストラクタ
    ~ADX2FlieConverter();
    
public:
    
    //ファイルパスの変換
    static std::string convertFilePath( const std::string& filePath );
};

#endif /* defined(__TeamProject__ADX2FileConverter__) */
