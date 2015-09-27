#include "DebugLayer.h"
#include "Object/Collision/ContactListener.h"
#include "Object/Wall/Wall.h"
#include "Object/Player/Player.h"
#include "Object/Enemy/Slime.h"
#include "User/Brush/Brush.h"

using namespace cocos2d;

bool DebugLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	scheduleUpdate();
	
	ContactListener* contactListener = ContactListener::create();
	
	auto playerData = std::make_shared< ObjectData >
	(
		BlendColorType::COLORLESS,
		"Texture/Debug/Circle_White.png",
		Vec2( 600.0f, 600.0f ),
		PhysicsMaterial( 0.6f, 0.6f, 0.6f )
	);
	auto slimeData1 = std::make_shared< ObjectData >
	(
		BlendColorType::RED,
		"Texture/Debug/Circle_Red.png",
		Vec2( 100.0f, 100.0f ),
		PhysicsMaterial( 0.6f, 0.4f, 0.6f )
	);
	
	Wall*	wall	= Wall::create();
	Player*	player	= Player::create( playerData );
	Slime*	slime1	= Slime::create( slimeData1, "Slime1" );
	Brush*	brush	= Brush::create();
	
	addChild( contactListener );
	addChild( wall );
	addChild( player );
	addChild( slime1 );
	addChild( brush );
	
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