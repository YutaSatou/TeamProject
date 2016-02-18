#ifndef _COLOR_CONVERTER_H_
#define _COLOR_CONVERTER_H_

#include "base/ccTypes.h"
#include <array>
#include <tuple>
#include <functional>

class ColorRYB;

/*------------------------------------------------------------*/
//	@class		：	ColorConverter
//	@brief		：	色の変換補助
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ColorConverter
{
	
private:
	
	static const std::size_t VERTEX_COUNT = 8;	//=> カラーキューブの頂点数
	
	using ColorRGB			= std::tuple< double, double, double >;
	using ColorCube			= std::array< ColorRGB, VERTEX_COUNT >;
	using ColorSelectFunc	= std::function< double( const ColorRGB& ) >;
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ColorConverter();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ColorConverter() = default;
	
	/**
	 *	@brief	色の三原色（絵の具）から光の三原色への変換
	 *	@param	colorRYB	色の三原色
	 *	@return	Color3B		光の三原色
	 */
	cocos2d::Color3B rybToRGB( const ColorRYB& colorRYB ) const;
	
private:
	
	/**
	 *	@brief	カラーキューブの初期化
	 */
	void initColorCube();
	
	/**
	 *	@brief	色の取得
	 *	@param	color	色の三原色
	 *	@param	func	色を選択する関数
	 */
	double getColor( const ColorRYB& color, const ColorSelectFunc& func ) const;
	
private:
	
	ColorCube mColorCube;	//=> カラーキューブ
};

#endif