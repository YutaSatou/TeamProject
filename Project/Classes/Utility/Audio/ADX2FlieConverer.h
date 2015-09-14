//
//  ADX2FlieConverer.h
//  TeamProject
//
//  Created by Satou yuta on 2015/08/07.
//
//

#ifndef __TeamProject__ADX2FlieConverer__
#define __TeamProject__ADX2FlieConverer__

#include <string>

class ADX2FlieConverter{
    
public:
    
    /**
     *	@brief	コンストラクタ
     */
    ADX2FlieConverter();
    
    /**
     *	@brief	デストラクタ
     */
    ~ADX2FlieConverter();
    
    /**
     *	@brief	ファイルパスの変換
     */
    static std::string convertFilePath( const std::string& filePath );
};

#endif /* defined(__TeamProject__ADX2FlieConverer__) */
