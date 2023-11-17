#include <iostream>
#include <windows.h>
#include "FunctionTools.h"

int main()
{
    if(!isRunAsAdmin()){
        MessageBoxA(NULL, "Please use administrator mode to execute", "error message", MB_ICONINFORMATION);
        return 0;
    }

    bool sw = false;
    Button K_ESC , K_MBUTTON;

    hideCursor();
    setWindowTop();
    system("cls");
    system("title love circle");
    system("mode con: cols=30 lines=4");

    while(1){
        if(K_MBUTTON.check_Click(VK_MBUTTON)){
            sw = !sw;
        }

        if(sw){
            mouse_event(MOUSEEVENTF_MOVE, 800, 0, 0, 0);    // mouse move event
            printf(SET_TEXT_COLOR(0, 255, 0) "ON" CLE);
        }
        else{
            printf(SET_TEXT_COLOR(255, 0, 0) "OFF" CLE);
        }
        Sleep(1);
    }
    return 0;
}