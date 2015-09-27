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
		Vec2( 480.0f, 1200.0f ),
		PhysicsMaterial( 0.6f, 0.1f, 0.8f )
	);
	auto slimeData1 = std::make_shared< ObjectData >
	(
		BlendColorType::RED,
		"Texture/Debug/Circle_Red.png",
		Vec2( 200.0f, 200.0f ),
		PhysicsMaterial( 0.6f, 0.4f, 0.6f )
	);
	auto slimeData2 = std::make_shared< ObjectData >
	(
		BlendColorType::BLUE,
		"Texture/Debug/Circle_Blue.png",
		Vec2( 310.0f, 390.0f ),
		PhysicsMaterial( 0.6f, 0.4f, 0.6f )
	);
	
	Wall*	wall	= Wall::create();
	Player*	player	= Player::create( playerData );
	Slime*	slime1	= Slime::create( slimeData1, "Slime1" );
	Slime*	slime2	= Slime::create( slimeData2, "Slime2" );
	Brush*	brush	= Brush::create();
	
	addChild( contactListener );
	addChild( wall );
	addChild( player );
	addChild( slime1 );
	addChild( slime2 );
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