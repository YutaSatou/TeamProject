#ifndef _ADX2_CUESHEET_H_
#define _ADX2_CUESHEET_H_

#include "cocos2d.h"
#include "cri_adx2le.h"

/*------------------------------------------------------------*/
//	@class		：	ADX2CueSheet
//	@brief		：	ADX2キューシート
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ADX2CueSheet : public cocos2d::Ref
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2CueSheet();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2CueSheet();
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	acb				ACBファイルのパス
	 *	@param	awb				AWBファイルのパス
	 *	@return	ADX2CueSheet	インスタンス
	 */
	static ADX2CueSheet* create( const std::string& acb, const std::string& awb );
	
	/**
	 *	@brief	ACBハンドルの取得
	 *	@return	CriAtomExAcbHn	ACBハンドル
	 */
	CriAtomExAcbHn getAcbHandle();
	
private:
	
	/**
	 *	@brief	ACBファイルの読み込み
	 *	@param	acb		ACBファイルのパス
	 *	@param	awb		AWBファイルのパス
	 *	@return	bool	ファイルの読み込みに成功したか否か
	 */
	bool loadAcb( const std::string& acb, const std::string& awb );
	
private:
	
	CriAtomExAcbHn mAcbHandle;	//=>	ACBハンドル
};

#endif