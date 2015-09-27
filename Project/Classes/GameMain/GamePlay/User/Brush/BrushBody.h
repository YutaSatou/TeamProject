#ifndef _BRUSH_BODY_H_
#define _BRUSH_BODY_H_

#include <vector>
#include <functional>

namespace cocos2d
{
	class PhysicsBody;
	class PhysicsShape;
	class Vec2;
}

/*------------------------------------------------------------*/
//	@class		：	BrushBody
//	@brief		：	ブラシ用の物理構造
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class BrushBody
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	BrushBody();
	
	/**
	 *	@brief	デストラクタ
	 */
	~BrushBody();
	
	/**
	 *	@brief	シェイプの追加
	 *	@param	start		線の開始地点
	 *	@param	end			線の終了地点
	 *	@param	lineSize	線の大きさ
	 */
	void pushShape( const cocos2d::Vec2& start, const cocos2d::Vec2& end, float lineSize );
	
	/**
	 *	@brief	コンテナの解放
	 */
	void clear();
	
	/**
	 *	@brief	コンテナが空か否か
	 *	@return	コンテナが空か否か
	 */
	bool isEmpty() const;
	
	/**
	 *	@brief	ボディの生成
	 *	@return	PhysicsBody	ボディ
	 */
	cocos2d::PhysicsBody* createBody();
	
private:
	
	/**
	 *	@brief	コンテナの巡回
	 *	@param	func	実行する関数
	 */
	void each( std::function< void( cocos2d::PhysicsShape* ) > func );
	
private:
	
	using ShapeContainer = std::vector< cocos2d::PhysicsShape* >;
	
	ShapeContainer mShapeContainer;	//=> シェイプコンテナ
};

#endif