#ifndef _LIQUID_FUN_BOX2D_H_
#define _LIQUID_FUN_BOX2D_H_

#include "Box2D/Box2D.h"

using LiquidFunVec2			= b2Vec2;
using LiquidFunVec3			= b2Vec3;
using LiquidFunVec4			= b2Vec4;

using LiquidFunWorld		= b2World;
using LiquidFunBody			= b2Body;
using LiquidFunJoint		= b2Joint;
using LiquidFunParticle		= b2ParticleSystem;
using LiquidFunFixture		= b2Fixture;

using LiquidFunBodyDef		= b2BodyDef;
using LiquidFunJointDef		= b2JointDef;
using LiquidFunParticleDef	= b2ParticleSystemDef;
using LiquidFunFixtureDef	= b2FixtureDef;

using LiquidFunShape		= b2Shape;
using LiquidFunCircleShape	= b2CircleShape;
using LiquidFunEdgeShape	= b2EdgeShape;
using LiquidFunPolygonShape	= b2PolygonShape;
using LiquidFunChainShape	= b2ChainShape;

using LiquidFunBodyType		= b2BodyType;
using LiquidFunParticleType	= b2ParticleFlag;

#endif