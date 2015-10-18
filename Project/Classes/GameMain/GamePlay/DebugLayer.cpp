#include "DebugLayer.h"
#include "ui/CocosGUI.h"
#include "Utility/Template/SmartPtr.h"
#include "Utility/Assistant/SceneSwitcher.h"
#include "Object/Collision/ContactListener.h"
#include "Object/Data/ObjectData.h"
#include "Object/Wall/WallManager.h"
#include "Object/Player/Player.h"
#include "Object/Enemy/Slime.h"
#include "User/Brush/Brush.h"

using namespace cocos2d;
using namespace ui;

bool DebugLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	ContactListener* contactListener = ContactListener::create();
	
	const auto texName = "Texture/Debug/Circle_White.png";
	
	auto playerData	= makeShared< ObjectData >( texName, Color3B::WHITE,	Vec2( 480.0f, 1200.0f ), PhysicsMaterial( 0.6f, 0.2f, 0.7f ) );
	auto slimeData1	= makeShared< ObjectData >( texName, Color3B::BLUE,		Vec2( 480.0f,  200.0f ), PhysicsMaterial( 0.6f, 0.4f, 0.6f ) );
	auto slimeData2	= makeShared< ObjectData >( texName, Color3B::RED,		Vec2( 480.0f,  390.0f ), PhysicsMaterial( 0.6f, 0.4f, 0.6f ) );
	
	WallManager*	wallManager	= WallManager::create();
	Player*			player		= Player::create( playerData );
	Slime*			slime1		= Slime::create( slimeData1, "Slime1" );
	Slime*			slime2		= Slime::create( slimeData2, "Slime2" );
	Brush*			brush		= Brush::create();
	
	addChild( contactListener );
	addChild( wallManager );
	addChild( player );
	addChild( slime1 );
	addChild( slime2 );
	addChild( brush );
	
	auto resetButton = Button::create();
	
	resetButton->setTitleText( "Reset" );
	resetButton->setTitleColor( Color3B::GREEN );
	resetButton->setTitleFontSize( 64.0f );
	resetButton->setPosition( Vec2( 100.0f, 1100.0f ) );
	resetButton->addTouchEventListener( []( Ref*, Widget::TouchEventType type )
	{
		if ( type == Widget::TouchEventType::ENDED )
		{
			SceneSwitcher::change( SceneType::PLAY );
		}
	} );
	
	addChild( resetButton );
	
	return true;
}

void DebugLayer::update( float deltaTime )
{
	
}

DebugLayer* DebugLayer::create()
{
	DebugLayer* inst = new DebugLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}