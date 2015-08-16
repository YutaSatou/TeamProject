
#include "WebStorage.h"
#include "external/tinyxml2/tinyxml2.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::network;
using namespace tinyxml2;

namespace Utility{
namespace Network{
    
WebStorage::WebStorage(){
    
}

WebStorage::~WebStorage(){
    
}

void WebStorage::start(const std::string& url){
    HttpRequest *request = new HttpRequest();
    //  urlの指定
    request->setUrl(url.c_str());
    //  データを取得する設定
    request->setRequestType(HttpRequest::Type::GET);
    //  通信結果のコールバック設定
    request->setResponseCallback(CC_CALLBACK_2(WebStorage::callback, this));
    //  開始
    HttpClient::getInstance()->send(request);
    request->release();
}
    
void WebStorage::callback(HttpClient *sender, HttpResponse *response){
    //  通信に失敗していれば何もせず返す
    if (!response->isSucceed()) {
        return;
    }
    //  文字の配列でデータを取得
    std::vector<char> *buffer = response->getResponseData();
    //  データを文字列に変換
    std::string _xml = std::string(buffer->begin(), buffer->end());
    
    XMLDocument doc;
    
    //  文字列をxml形式にパースしてエラーが出なければ
    if (doc.Parse(_xml.c_str()) == XML_NO_ERROR) {
        if(!doc.FirstChildElement("root")){
            log("Data Error : Not Found RootNode");
            return ;
        }
        
//        //  内容をログ出力
//        doc.Print();
        
        ResponseData resData;
        
        //  docオブジェクト/rootを取得
        XMLElement *root = doc.FirstChildElement();
        
        //  root/dataの要素を取得
        XMLElement *node_data = root->FirstChildElement("data");
        
        /**
         @brief xmlのツリー構造を読み込むための関数を定義
         @sum 関数化したのは再帰的処理を行ないxmlの内容を走査するため
         */
        std::function<void(ResponseData *data, XMLElement *node)> read = [&, root](ResponseData *data, XMLElement *node){
            //  ノードに子がいるか
            if(node->FirstChildElement("Element0")){
                //  子ノードが存在する場合、最初に子ノードの数をカウントする
                int childCount = 0;
                //  子ノードが見つからなくなるまでsiblingを実行
                while(node->FirstChildElement(StringUtils::format("Element%i", childCount).c_str())){
                    childCount++;
                }
                //  NextSiblingがnullを検出したタイミングでカウント分だけバッファを作成する
                data->createBuffer(childCount);
                
                //  数えた子ノードの数分readを実行する
                for(int i = 0; i < childCount; i++){
                    //  前回読み込んだ子ノードの次を読み込む
                    XMLElement *childNode = node->FirstChildElement(StringUtils::format("Element%i", i).c_str());
                    //  バッファにインスタンスを作成して追加する
                    data->createChild("null", "null");
                    //  各種データを引き渡して再帰的にreadを実行
                    read(data->getChild(i), childNode);
                }
            }
            //  子がいない場合、要素からkeyとvalueを取得する
            else{
                data->mKey = node->FirstChildElement("key")->GetText();
                data->mValue = node->FirstChildElement("value")->GetText();
            }
        };
        
        read(&resData, node_data);
    }
    //  エラーが発生している場合
    else{
        log("Connect Failed : not get xml data");
    }
    
    log("Success : Read on XML");
}
    
}
}