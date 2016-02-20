#ifndef _COLOR_STACK_H_
#define _COLOR_STACK_H_

#include "ColorRYB.h"
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
	void push( const ColorRYB& color );
	
	/**
	 *	@brief	末尾の取得
	 *	@param	isDelete	末尾を削除するか否か
	 *	@return	ColorRYB	色情報
	 */
	ColorRYB pop( bool isDelete = true );
	
private:
	
	using ColorStackData = std::stack< ColorRYB >;
	
	ColorStackData mStack;	//=> 色情報のスタック
};

#endif