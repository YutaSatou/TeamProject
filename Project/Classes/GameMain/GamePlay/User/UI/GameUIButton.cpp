#include "GameUIButton.h"

using namespace cocos2d;

namespace
{
	using TouchEventType = ui::Widget::TouchEventType;
	
	const std::string DIRECTORY = "Texture/GamePlay/";	//=> テクスチャのディレクトリ
}

// 初期化
bool GameUIButton::init( const GameUIButtonDesc& desc )
{
	if ( !ui::Button::init( DIRECTORY + desc.textureName ) )
	{
		return false;
	}
	
	// 座標を設定する。
	setPosition( desc.position );
	
	// ボタンのイベントリスナを登録する。
	addTouchEventListener( [ = ]( Ref*, TouchEventType type )
	{
		// タッチ開始時はボタンを少し薄暗くする。
		// タッチ取消時はボタンを通常の色に戻す。
		// タッチ終了時は登録された関数を呼び出し、ボタンが複数回押されるのを防止する。
		if ( type == TouchEventType::BEGAN )	{ setOpacity( 160 ); setColor( Color3B( 200, 200, 200 ) );	}
		if ( type == TouchEventType::CANCELED )	{ setOpacity( 255 ); setColor( Color3B::WHITE );			}
		if ( type == TouchEventType::ENDED )	{ desc.touchEndedFunc(); setEnabled( false );				}
	} );
	
	return true;
}

// インスタンスの生成
GameUIButton* GameUIButton::create( const GameUIButtonDesc& desc )
{
	GameUIButton* inst = new GameUIButton();
	
	if ( inst && inst->init( desc ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}