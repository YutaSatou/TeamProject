#include "TestArea.h"
#include "Utility/Network/Storage/WebStorage.h"
#include "Utility/Debug/Debug.h"

using namespace cocos2d;

bool TestArea::init(){
	if ( !LayerColor::initWithColor( Color4B::BLACK ) ){
		return false;
	}
	
    //  ウェブストレージからxmlファイルをDLして読み込むテスト
//    Utility::Network::WebStorage downloadXml;
//    const std::string urlXml("https://s3-ap-northeast-1.amazonaws.com/cocosnetwork/XML/Test.xml");
//    downloadXml.start(urlXml);
    
    // ASSERT("sss");
    
	return true;
}

TestArea* TestArea::create(){
	TestArea* inst = new TestArea();
    
	if ( inst && inst->init() ){
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}