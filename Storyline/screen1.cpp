#include <stdio.h>
#include <curses.h>
// #include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#ifndef DWORD
#define WINAPI
typedef unsigned long DWORD;
typedef short WCHAR;
typedef void * HANDLE;
#define MAX_PATH    PATH_MAX
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int BOOL;
#endif

void init();
void titleStart();
void gotoxy(int, int);

void init(){
    system("mode con cols=25    lines=10 | title Game Title")
}
void titleStart(){
    printf("\n\n\n\n");
    printf("    #####       #       #       #    #####      #####   #####      #      #####   ##### \n");
    printf("    #          # #      # #    ##    #          #         #       # #     #   #     #   \n");
    printf("    # ###     #####     #  # #  #    #####      #####     #      #####    #####     #   \n");
    printf("    #   #    #     #    #   #   #    #              #     #     #     #   # #       #   \n");
    printf("    #####    #     #    #   #   #    #####      #####     #     #     #   #   ##    #   \n");
    return 0;
}

void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_output_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int main(){
    init();
    titleStart();
    return 0;
}