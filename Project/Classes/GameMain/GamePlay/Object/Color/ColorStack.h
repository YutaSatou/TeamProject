#ifndef _COLOR_STACK_H_
#define _COLOR_STACK_H_

#include "ColorCMY.h"
#include <stack>

/*------------------------------------------------------------*/
//	@class		：	ColorStack
//	@brief		：	色情報のスタック
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorStack
{
	
public:
	
	/**
	 *	@brief	末尾への追加
	 *	@param	color	色情報
	 */
	void push( const ColorCMY& color );
	
	/**
	 *	@brief	末尾の取得
	 *	@param	isDelete	末尾を削除するか否か
	 *	@return	ColorCMY	色情報
	 */
	ColorCMY pop( bool isDelete = true );
	
private:
	
	using ColorStackData = std::stack< ColorCMY >;
	
	ColorStackData mStack;	//=> 色情報のスタック
};

#endif