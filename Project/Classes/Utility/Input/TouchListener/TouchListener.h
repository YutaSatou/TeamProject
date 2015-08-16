//
//  AddEventListener.h
//  Chess
//
//  Created by 星共法 on 2014/11/11.
//
//  イベントリスナーを対象のオブジェクトと紐づけて登録するための補助関数

#ifndef __Sub_AddEventListener__
#define __Sub_AddEventListener__

#include "cocos2d.h"

namespace Utility{
typedef cocos2d::Touch Touch;
typedef cocos2d::Event Event;
typedef cocos2d::EventKeyboard EventKeyboard;
typedef cocos2d::EventListenerKeyboard EventListenerKeyboard;
typedef cocos2d::EventListenerTouchOneByOne EventListenerTouchOneByOne;
typedef cocos2d::EventListenerTouchAllAtOnce EventListenerTouchAllAtOnce;

//--------------------------------------------------------
//  @brief  タッチイベントコールバック関数の型をtypedef宣言しておく。
//--------------------------------------------------------
namespace TouchEvent{
    //  シングルタッチ用
    namespace SingleTouch{
        typedef std::function<bool(Touch*, Event*)> TouchBegan;
        typedef std::function<void(Touch*, Event*)> TouchMoved;
        typedef std::function<void(Touch*, Event*)> TouchEnded;
        typedef std::function<void(Touch*, Event*)> TouchCancel;
    }
    //  マルチタッチ用
    namespace MultiTouch{
        typedef std::function<void(const std::vector<Touch*>&, Event*)> TouchesBegan;
        typedef std::function<void(const std::vector<Touch*>&, Event*)> TouchesMoved;
        typedef std::function<void(const std::vector<Touch*>&, Event*)> TouchesEnded;
        typedef std::function<void(const std::vector<Touch*>&, Event*)> TouchesCancel;
    }
}

//--------------------------------------------------------
//  @brief  キーボード入力イベントコールバック関数の型をtypedef宣言しておく。
//--------------------------------------------------------
namespace KeyInputEvent{
    typedef std::function<void(EventKeyboard::KeyCode keyCode, Event* event)> KeyInputPressed;
    typedef std::function<void(EventKeyboard::KeyCode keyCode, Event* event)> KeyInputReleased;
}

/**
 *  @brief  シングルタッチリスナーを作成するためのデータをまとめた構造体
 */
struct SingleTouchEventDesc{
public:
    TouchEvent::SingleTouch::TouchBegan began;
    TouchEvent::SingleTouch::TouchMoved moved;
    TouchEvent::SingleTouch::TouchEnded ended;
    TouchEvent::SingleTouch::TouchCancel cancel;
    
public:
    SingleTouchEventDesc()
    : began(nullptr)
    , moved(nullptr)
    , ended(nullptr)
    , cancel(nullptr){
        
    }
};

/**
 *  @brief  マルチタッチリスナーを作成するためのデータをまとめた構造体
 */
struct MultiTouchEventDesc{
public:
    TouchEvent::MultiTouch::TouchesBegan began;
    TouchEvent::MultiTouch::TouchesMoved moved;
    TouchEvent::MultiTouch::TouchesEnded ended;
    TouchEvent::MultiTouch::TouchesCancel cancel;
    
public:
    MultiTouchEventDesc()
    : began(nullptr)
    , moved(nullptr)
    , ended(nullptr)
    , cancel(nullptr){
        
    }
};

class TouchLinstener{
public:
    /**
     *  @brief  タッチイベントをディスパッチャーに登録する
     *  @param  began       押された瞬間に実行する関数オブジェクト
     *  @param  moved       スライドされた時に実行する関数オブジェクト
     *  @param  ended       離された瞬間に実行する関数オブジェクト
     *  @param  cancelled   何らかの理由(システム的な事とか)でタッチが終了した時に実行する関数オブジェクト
     *  @param  target      タッチイベントに関連づける対象のcocosオブジェクト
     *  @sum    これによって、使いもしないbeganをわざわざcreateせず済む。
    */
    static void TouchOneByOne(TouchEvent::SingleTouch::TouchBegan began,
                              TouchEvent::SingleTouch::TouchMoved moved,
                              TouchEvent::SingleTouch::TouchEnded ended,
                              TouchEvent::SingleTouch::TouchCancel cancelled,
                              cocos2d::Node* target);
    
    /**
     *  @brief  タッチイベントをディスパッチャーに登録する
     *  @param  desc    イベントリスナーの作成に必要なデータ構造体
     *  @param  obj     イベントを関連付けるオブジェクト
     */
    static void TouchOneByOne(SingleTouchEventDesc& desc, cocos2d::Node* obj);
    
    /**
     *  @brief  タッチイベントをディスパッチャーに登録する
     *  @param  listener    タッチイベントを既に格納済みのリスナー
     *  @param  target      タッチイベントに関連づける対象のcocosオブジェクト
    */
    static void TouchOneByOne(EventListenerTouchOneByOne* listener, cocos2d::Node* target);
    
    /**
     *  @brief  マルチタッチ用のイベントリスナー
     *  @param  began       押された瞬間に実行する関数オブジェクト
     *  @param  moved       スライドされた時に実行する関数オブジェクト
     *  @param  ended       離された瞬間に実行する関数オブジェクト
     *  @param  cancelled   何らかの理由(システム的な事とか)でタッチが終了した時に実行する関数オブジェクト
     *  @param  target      タッチイベントに関連づける対象のcocosオブジェクト
     *  @sum    一応、一本指の時から反応を開始する。
                というより、タッチした本数だけタッチ情報を含んだvectorを受け取ってくるので、
                書き方次第では全てのタッチはこの関数で対処できる。
     */
    static void TouchAllAtOnce(TouchEvent::MultiTouch::TouchesBegan began,
                               TouchEvent::MultiTouch::TouchesMoved moved,
                               TouchEvent::MultiTouch::TouchesEnded ended,
                               TouchEvent::MultiTouch::TouchesCancel cancelled,
                               cocos2d::Node* target);
    
    /**
     *  @brief  タッチイベントをディスパッチャーに登録する
     *  @param  desc    イベントリスナーの作成に必要なデータ構造体
     *  @param  obj     イベントを関連付けるオブジェクト
     */
    static void TouchAllAtOnce(MultiTouchEventDesc& desc, cocos2d::Node* obj);
    
    /**
     *  @brief  タッチイベントをディスパッチャーに登録する
     *  @param  pressed     押下された時に実行する関数オブジェクト
     *  @param  released    離された時に実行する関数オブジェクト
     *  @param  target      イベントに関連付けるオブジェクト
     */
    static void KeyBoard(KeyInputEvent::KeyInputPressed pressed,
                         KeyInputEvent::KeyInputReleased released,
                         cocos2d::Node* target);
    
private:
    TouchLinstener();
    ~TouchLinstener();
};
}


#endif /* defined(__Chess__AddEventListener__) */
