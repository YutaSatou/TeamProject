
//
//  NetworkLayer.cpp
//  MyProject36
//
//  Created by 星共法 on 2015/07/24.
//
//

#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_

#include <stdlib.h>
#include "network/HttpClient.h"

namespace Utility{
namespace Network{

/**
 @breif ウェブストレージから取得したデータを確保、管理するための構造体
 */
struct ResponseData{
public:
    ResponseData()
    : mKey()
    , mValue()
    , mChildList(0)
    , mChildCount(0)
    , mChildCountMax(0){
    }
    
    ResponseData(std::string key, std::string value)
    : mKey(key)
    , mValue(value)
    , mChildList(0)
    , mChildCount(0)
    , mChildCountMax(0){
    }
    
    ~ResponseData(){
        for(auto child : mChildList){
            if(child){
                delete child;
                child = 0;
            }
        }
        mChildList.clear();
    }
    
    /**
     @brief 子ノード管理用配列作成関数
     @param size 子ノードの最大格納可能数
     @ret 既にリストが作成済みであればfalseを返却
     */
    bool createBuffer(int size){
        if(mChildCountMax == 0){
            mChildCountMax = size;
            mChildList.resize(size);
            return true;
        }
        return false;
    }
    
    /**
     @brief dataを自身の子ノードとして管理対象に生成する
     @param data 子ノードのインスタンス
     @ret 管理数が最大数を超えていた場合falseを返却
     */
    bool createChild(const std::string& key, const std::string& value){
        if(mChildCount < mChildCountMax){
            mChildList.at(mChildCount) = new ResponseData(key, value);
            mChildCount++;
            return true;
        }
        return false;
    }
    /**
     @brief 管理している子ノードを返却する
     @param index 　取得したい子ノードの格納されているインデックス
     @ret indexに対応した位置に格納されている子ノードを返却する
     */
    ResponseData *getChild(int index) const{
        return mChildList.at(index);
    }
    
    /**
     @brief キーを元に子ノードを取得する
     @param key キー
     @ret keyと合致したキーを持つ子ノードを返却する
     */
    ResponseData *getForKey(const std::string& key){
        for(auto child : mChildList){
            if(child->mKey == key){
                return child;
            }
        }
        return nullptr;
    }
    
    /**
     @brief 自身の管理している子ノードを全て開放する
     @sum このコードが管理している子ノードは連鎖的に全て開放される
     */
    void destroy(){
        if(mChildList.empty()){
            return;
        }
        for(auto child : mChildList){
            if(child){
                child->destroy();
                delete child;
                child = 0;
            }
        }
        mChildList.clear();
    }
    
public:
    //  ノードとしてのキー
    std::string mKey;
    //  ノードとしての値
    std::string mValue;
    
private:
    /**
     @brief 子ノードの管理リストとの兼ね合いでコピー禁止
     */
    ResponseData(const ResponseData& data){
    }
    
    ResponseData& operator=(const ResponseData&){
        return (*this);
    }
    
private:
    //  子ノード管理用配列
    std::vector<ResponseData*> mChildList;
    //  子ノードの追加数カウンター
    int mChildCount;
    //  子ノードの追加可能最大数
    int mChildCountMax;
};
    
class WebStorage{
public:
    WebStorage();
    
    virtual ~WebStorage();
    
    /**
     @brief サーバーとの通信開始
     @param url 取得したいファイルのURL
     */
    void start(const std::string& url);
    
private:
    void callback(cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response);
};
}//network
}//utility

#endif