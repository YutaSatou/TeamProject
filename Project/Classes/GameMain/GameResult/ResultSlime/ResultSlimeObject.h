//
//  ResultSlimeObject.hpp
//  TeamProject
//
//  Created by Satou yuta on 2016/01/15.
//
//

#ifndef ResultSlimeObject_hpp
#define ResultSlimeObject_hpp

#include "../../GamePlay/Object/Common/LiquidObject.h"

class ResultSlimeObject : public LiquidObject
{
    
protected:
    
    /**
     *	@brief	コンストラクタ
     */
    ResultSlimeObject();
    
    /**
     *	@brief	デストラクタ
     */
    ~ResultSlimeObject() = default;
    
    /**
     *	@brief	初期化
     *	@param	objectData	オブジェクトデータ
     *	@return	bool		初期化が完了したか否か
     */
    virtual bool init() override;
    
    /**
     *	@brief	更新
     *	@param	deltaTime	デルタ時間
     */
    virtual void update( float deltaTime ) override;
    
public:
    
    /**
     *	@brief	インスタンスの生成
     *	@param	objectData	オブジェクトデータ
     *	@return	Player		インスタンス
     */
    static ResultSlimeObject* create();
    
private:
    
    /**
     *	@brief	パーティクルの初期化
     */
    virtual void initParticle() override;
};


#endif
