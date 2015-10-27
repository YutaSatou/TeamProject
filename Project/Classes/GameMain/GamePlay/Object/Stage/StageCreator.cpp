#include "StageCreator.h"
#include "../Data/ObjectData.h"
#include "../Data/ObjectDataReader.h"

// コンストラクタ
StageCreator::StageCreator()
	: mListener( []( SharedPtr< ObjectData > ) { } )
{
	
}

// リスナの追加
void StageCreator::addListener( DataLoadListener listener )
{
	// リスナを保管する。
	const DataLoadListener& prev = mListener;
	
	// リスナを合成する。
	mListener = [ = ]( SharedPtr< ObjectData > objectData ) { prev( objectData ); listener( objectData ); };
}

// ステージの生成
void StageCreator::createStage( const std::string& plistFilePath )
{
	ObjectDataReader						objectDataReader;
	ObjectDataReader::ObjectDataContainer	continer;
	
	// プロパティリストファイルを読み込む。
	continer = objectDataReader.read( plistFilePath );
	
	std::for_each( continer.begin(), continer.end(), [ this ]( SharedPtr< ObjectData > objectData )
	{
		// リスナにコールバックを送信する。
		mListener( objectData );
	} );
}