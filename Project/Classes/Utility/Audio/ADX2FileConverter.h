//
//  ADX2FileConverter.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/22.
//
//

#ifndef _ADX2FILECONVERTER_H_
#define _ADX2FILECONVERTER_H_

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
