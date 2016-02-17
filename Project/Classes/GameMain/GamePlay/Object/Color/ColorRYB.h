#ifndef _COLOR_RYB_H_
#define _COLOR_RYB_H_

/*------------------------------------------------------------*/
//	@class		：	ColorRYB
//	@brief		：	色の三原色（絵の具）
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorRYB
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ColorRYB();
	
	/**
	 *	@brief	コンストラクタ
	 *	@param	_r	赤
	 *	@param	_y	黄
	 *	@param	_b	青
	 */
	ColorRYB( double _r, double _y, double _b );
	
	/**
	 *	@brief	コピーコンストラクタ
	 *	@param	copy	コピー
	 */
	ColorRYB( const ColorRYB& copy );
	
	/**
	 *	@brief	デストラクタ
	 */
	~ColorRYB() = default;
	
	/**
	 *	@brief	等価演算子
	 *	@param	color	色の三原色
	 *	@return	bool	等しいか否か
	 */
	bool operator==( const ColorRYB& color ) const;
	
	/**
	 *	@brief	非等価演算子
	 *	@param	color	色の三原色
	 *	@return	bool	等しくないか否か
	 */
	bool operator!=( const ColorRYB& color ) const;
	
public:
	
	double	r;	//=> 赤成分
	double	y;	//=> 黄成分
	double	b;	//=> 青成分
	
	static const ColorRYB WHITE;
	static const ColorRYB RED;
	static const ColorRYB YELLOW;
	static const ColorRYB BLUE;
	static const ColorRYB ORANGE;
	static const ColorRYB GREEN;
	static const ColorRYB PURPLE;
	static const ColorRYB BLACK;
};

#endif