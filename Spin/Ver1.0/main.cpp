#include <iostream>
#include <windows.h>
#include "FunctionTools.h"

int main()
{
    if(!isRunAsAdmin()){
        MessageBoxA(NULL, "�Шϥκ޲z���Ҧ��}��", "���~�T��", MB_ICONINFORMATION);
        return 0;
    }

    bool sw = false;
    Button K_ESC , K_MBUTTON;

    hideCursor();
    setWindowTop();
    system("cls");
    system("title �R���]�O����");
    system("mode con: cols=30 lines=4");

    while(1){
        if(K_MBUTTON.check_Click(VK_MBUTTON)){
            sw = !sw;
        }

        if(sw){
            mouse_event(MOUSEEVENTF_MOVE, 800, 0, 0, 0);    // ���в��ʨƥ�
            printf(SET_TEXT_COLOR(0, 255, 0) "�}��" CLE);
        }
        else{
            printf(SET_TEXT_COLOR(255, 0, 0) "����" CLE);
        }
        Sleep(1);
    }
    return 0;
}