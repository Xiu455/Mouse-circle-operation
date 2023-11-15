#include <iostream>
#include <windows.h>
#include "FunctionTools.h"

int main()
{
    if(!isRunAsAdmin()){
        MessageBoxA(NULL, "請使用管理員模式開啟", "錯誤訊息", MB_ICONINFORMATION);
        return 0;
    }

    bool sw = false;
    Button K_ESC , K_MBUTTON;

    hideCursor();
    setWindowTop();
    system("cls");
    system("title 愛的魔力轉圈圈");
    system("mode con: cols=30 lines=4");

    while(1){
        if(K_MBUTTON.check_Click(VK_MBUTTON)){
            sw = !sw;
        }

        if(sw){
            mouse_event(MOUSEEVENTF_MOVE, 800, 0, 0, 0);    // 鼠標移動事件
            printf(SET_TEXT_COLOR(0, 255, 0) "開啟" CLE);
        }
        else{
            printf(SET_TEXT_COLOR(255, 0, 0) "關閉" CLE);
        }
        Sleep(1);
    }
    return 0;
}