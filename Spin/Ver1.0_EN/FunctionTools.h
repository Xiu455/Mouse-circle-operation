#ifndef FunctionTools
#define FunctionTools

#include <windows.h>

#define SET_TEXT_COLOR(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
#define CLE                     "\033[0m\r"

// Button Control
class Button{
public:
    bool state;

    Button(){
        state = false;
    }

    bool check_Click(int button_name){
        if((GetAsyncKeyState(button_name) & 0x8000) && !state) {
            state = true;
            return true;
        }
        else if(!(GetAsyncKeyState(button_name) & 0x8000) && state){
            state = false;
        }
        return false;
    }
};

// Hide Cursor
void hideCursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Check if run by admin mode
bool isRunAsAdmin(){
    bool isAdmin = false;
    HANDLE tokenHandle = nullptr;

    if(OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &tokenHandle)){
        TOKEN_ELEVATION tokenElevation;
        DWORD bytesRead;

        if(GetTokenInformation(tokenHandle, TokenElevation, &tokenElevation, sizeof(tokenElevation), &bytesRead)){
            isAdmin = tokenElevation.TokenIsElevated != 0;
        }

        CloseHandle(tokenHandle);
    }

    return isAdmin;
}

// The window is always on top
void setWindowTop(){
    HWND hWnd = ::GetForegroundWindow();
    ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
}

#endif