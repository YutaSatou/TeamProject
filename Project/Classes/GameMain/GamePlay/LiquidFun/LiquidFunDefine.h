#ifndef _LIQUID_FUN_DEFINE_H_
#define _LIQUID_FUN_DEFINE_H_

class	b2Vec2;
class	b2Vec3;
class	b2Vec4;
class	b2World;
class	b2Body;
class	b2Joint;
class	b2ParticleColor;
class	b2ParticleGroup;
class	b2ParticleSystem;
class	b2Fixture;
class	b2Shape;
class	b2CircleShape;
class	b2EdgeShape;
class	b2PolygonShape;
class	b2ChainShape;
class	b2Contact;
class	b2ContactListener;
struct	b2BodyDef;
struct	b2JointDef;
struct	b2ParticleBodyContact;
struct	b2ParticleGroupDef;
struct	b2ParticleSystemDef;
struct	b2FixtureDef;
struct	b2Filter;
struct	b2Manifold;

using LiquidFunVec2					= b2Vec2;
using LiquidFunVec3					= b2Vec3;
using LiquidFunVec4					= b2Vec4;
using LiquidFunWorld				= b2World;
using LiquidFunBody					= b2Body;
using LiquidFunJoint				= b2Joint;
using LiquidFunParticleColor		= b2ParticleColor;
using LiquidFunParticleGroup		= b2ParticleGroup;
using LiquidFunParticle				= b2ParticleSystem;
using LiquidFunFixture				= b2Fixture;
using LiquidFunShape				= b2Shape;
using LiquidFunCircleShape			= b2CircleShape;
using LiquidFunEdgeShape			= b2EdgeShape;
using LiquidFunPolygonShape			= b2PolygonShape;
using LiquidFunChainShape			= b2ChainShape;
using LiquidFunContact				= b2Contact;
using LiquidFunBaseContactListener	= b2ContactListener;
using LiquidFunBodyDesc				= b2BodyDef;
using LiquidFunJointDesc			= b2JointDef;
using LiquidFunParticleBodyContact	= b2ParticleBodyContact;
using LiquidFunParticleGroupDesc	= b2ParticleGroupDef;
using LiquidFunParticleDesc			= b2ParticleSystemDef;
using LiquidFunFixtureDesc			= b2FixtureDef;
using LiquidFunFilter				= b2Filter;
using LiquidFunManifold				= b2Manifold;

#endif