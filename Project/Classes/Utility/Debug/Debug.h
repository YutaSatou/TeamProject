//
//  Debug.h
//  Chess
//
//  Created by 星共法 on 2014/12/03.
//
//

#ifndef __Sub_Debug_h
#define __Sub_Debug_h

namespace Utility{
    namespace Debug{
        /**
         @brief  可変長引数を取るログ
         */
        static void Log(const char * format, ...){
            va_list args;
            va_start(args, format);
            
            //  ログの最大文字数
            const int MAX_LENGTH = 16 * 1024;
            char buf[MAX_LENGTH];
            
            vsnprintf(buf, MAX_LENGTH - 3, format, args);
            strcat(buf, "\n");
            
            fprintf(stdout, "MyGame : %s", buf);
            fflush(stdout);
            
            va_end(args);
        }

        /**
         @breif  ASSERT用に３つの引数を取るログ
         */
        //static void Log(const char* fileName, int line, const char* message){
        //    Log("MyGame : %s:%d : ... %s", fileName, line, message );
        //}

        /**
         @brief  マクロを呼び出しているファイルのパス、行と任意のメッセージを出力する
         */
        //#define ASSERT(message) (Log(__FILE__, __FILE__, #message))
            
        #define ASSERT(message){  \
            Log("MyGame : %s:%d : ... %s", __FILE__, __LINE__, message ); \
        }

    }//debug
}//utility

#endif










