#ifndef _GAME_CONTROL_MEDIATOR_H_
#define _GAME_CONTROL_MEDIATOR_H_

/*------------------------------------------------------------*/
//	@class		：	GameControlMediator
//	@brief		：	ゲーム制御仲介者
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class GameControlMediator
{
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~GameControlMediator() = default;
	
	/**
	 *	@brief	ゲーム開始
	 */
	virtual void gameStart() = 0;
	
	/**
	 *	@brief	ゲーム中断
	 */
	virtual void gamePause() = 0;
	
	/**
	 *	@brief	ゲーム終了
	 */
	virtual void gameEnd() = 0;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GameControlMediator() = default;
};

#endif