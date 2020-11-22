#include "util.h"

void init(){
	system("mode con cols=56 lines=20 | title Game title"); 
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; 
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
}


void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
} 



