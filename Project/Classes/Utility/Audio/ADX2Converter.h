#ifndef _ADX2_CONVERTER_H_
#define _ADX2_CONVERTER_H_

#include <string>

/*------------------------------------------------------------*/
//	@class		：	ADX2Converter
//	@brief		：	ADX2コンバータ
//	@author		：	利川聖太
/*------------------------------------------------------------*/
class ADX2Converter
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2Converter() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2Converter() = delete;
	
	/**
	 *	@brief	ファイルパスの変換
	 *	@param	filePath	ファイルパス
	 *	@return	std::string	変換を行ったファイルパス
	 */
	static std::string convertFilePath( const std::string& filePath );
};

#endif