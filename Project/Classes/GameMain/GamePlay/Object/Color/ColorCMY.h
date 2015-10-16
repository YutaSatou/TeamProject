#ifndef _COLOR_CMY_H_
#define _COLOR_CMY_H_

#include "base/ccTypes.h"
#include <tuple>

/*------------------------------------------------------------*/
//	@class		：	ColorCMY
//	@brief		：	色の三原色
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorCMY
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ColorCMY();
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_c	シアン
	 *	@param	_m	マゼンタ
	 *	@param	_y	イエロー
	 */
	ColorCMY( GLubyte _c, GLubyte _m, GLubyte _y );
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	colorRGB	光の三原色( RGB )
	 */
	explicit ColorCMY( const cocos2d::Color3B& colorRGB );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ColorCMY() = default;
	
	/**
	 *	@brief	色の三原色( CMY )から光の三原色( RGB )への変換
	 *	@param	colorCMY	色の三原色
	 *	@return	Color3B		光の三原色
	 */
	static cocos2d::Color3B convertToRGB( const ColorCMY& colorCMY );
	
	/**
	 *	@brief	光の三原色( RGB )から色の三原色( CMY )への変換
	 *	@param	colorRGB	光の三原色
	 *	@return	ColorCMY	色の三原色
	 */
	static ColorCMY convertToCMY( const cocos2d::Color3B& colorRGB );
	
	/**
	 *	@brief	等価演算子
	 *	@param	colorCMY	色の三原色
	 *	@return	bool		等しいか否か
	 */
	bool operator == ( const ColorCMY& colorCMY ) const;
	
	/**
	 *	@brief	等価演算子
	 *	@param	colorRGB	光の三原色
	 *	@return	bool		等しいか否か
	 */
	bool operator == ( const cocos2d::Color3B& colorRGB ) const;
	
	/**
	 *	@brief	非等価演算子
	 *	@param	colorCMY	色の三原色
	 *	@return	bool		等しくないか否か
	 */
	bool operator != ( const ColorCMY& colorCMY ) const;
	
	/**
	 *	@brief	非等価演算子
	 *	@param	colorRGB	光の三原色
	 *	@return	bool		等しくないか否か
	 */
	bool operator != ( const cocos2d::Color3B& colorRGB ) const;
	
private:
	
	using ColorTuple = std::tuple< float, float, float >;
	
	/**
	 *	@brief	RGB⇔CMYの相互変換
	 *	@param	element1	色要素1
	 *	@param	element2	色要素2
	 *	@param	element3	色要素3
	 *	@return	ColorTuple	色要素タプル
	 */
	static ColorTuple convertColor( float element1, float element2, float element3 );
	
public:
	
	GLubyte	c;	//=> シアン
	GLubyte	m;	//=> マゼンタ
	GLubyte y;	//=> イエロー
	
	static const ColorCMY WHITE;
	static const ColorCMY BLACK;
	static const ColorCMY CYAN;
	static const ColorCMY MAGENTA;
	static const ColorCMY YELLOW;
	static const ColorCMY RED;
	static const ColorCMY GREEN;
	static const ColorCMY BLUE;
};

#endif