//
//  ADX2CueSheet.cpp
//  TeamProject
//
//  Created by Satou yuta on 2015/08/14.
//
//

#include "ADX2CueSheet.h"
#include "ADX2FlieConverer.h"

using namespace cocos2d;

ADX2CueSheet::ADX2CueSheet()
: mAcbHandle( nullptr ){
    
}

ADX2CueSheet::~ADX2CueSheet(){
    
    criAtomExAcb_Release( mAcbHandle );
}

ADX2CueSheet* ADX2CueSheet::create( const std::string& acb, const std::string& awb ){
    
    ADX2CueSheet* inst = new ADX2CueSheet();
    
    if ( inst && inst->loadAcb( acb, awb ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

CriAtomExAcbHn ADX2CueSheet::getAcbHandle(){
    
    return mAcbHandle;
}

bool ADX2CueSheet::loadAcb( const std::string& acb, const std::string& awb ){
    
    std::string acbFilePath = ADX2FlieConverter::convertFilePath( acb );
    std::string awbFilePath = ADX2FlieConverter::convertFilePath( awb );
    
    if ( awb == "" ){
        mAcbHandle = criAtomExAcb_LoadAcbFile( NULL, acbFilePath.c_str(), NULL, NULL, NULL, 0 );
    }else{
        mAcbHandle = criAtomExAcb_LoadAcbFile( NULL, acbFilePath.c_str(), NULL, awbFilePath.c_str(), NULL, 0 );
    }
    
    if ( mAcbHandle == nullptr ){
        return false;
    }
    
    return true;
}
