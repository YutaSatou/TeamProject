#include "StageCreator.h"
#include "../Data/ObjectData.h"
#include "../Data/ObjectDataReader.h"

// コンストラクタ
StageCreator::StageCreator()
	: mListener( []( ObjectDataPtr ) { } )
{
	
}

// リスナの追加
void StageCreator::addListener( DataLoadListener listener )
{
	// リスナを保管する。
	const DataLoadListener& prev { mListener };
	
	// リスナを合成する。
	mListener = [ = ]( ObjectDataPtr objectData ) { prev( objectData ); listener( objectData ); };
}

// ステージの生成
void StageCreator::createStage( const std::string& plistFilePath )
{
	ObjectDataReader						objectDataReader;
	ObjectDataReader::ObjectDataContainer	container;
	
	// プロパティリストファイルを読み込む。
	container = objectDataReader.read( plistFilePath );
	
	std::for_each( container.begin(), container.end(), [ this ]( ObjectDataPtr objectData )
	{
		// リスナにコールバックを送信する。
		mListener( objectData );
	} );
}