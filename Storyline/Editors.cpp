#include <iostream>
#include <curses.h>
#include <string>
using namespace std;

int main()
{
    WINDOW *w;
    w = initscr();
    using namespace std;                        // start main
    int max_y = LINES - 1, max_x = COLS - COLS; // define in curses.h
    mvprintw(max_y / 10, COLS / 10, "Editors...");
    mvprintw(max_y / 9, COLS / 9, "Project Captain : Mr.Jo");
    mvprintw(max_y / 8, COLS / 8, "Team Members :  Mr.Jo");
    mvprintw(max_y / 7, COLS / 7, "Mr.Hwang");
    mvprintw(max_y / 6, COLS / 6, "Mr.Son");
    mvprintw(max_y / 5, COLS / 5, "Mr.Park");
    mvprintw(max_y / 4, COLS / 4, "Story Writer : Mr.Son");
    mvprintw(max_y / 3, COLS / 3, "The story is fiction");
    mvprintw(max_y / 2, COLS / 2, "It is stated that the copyright fee belongs to Mr. Son.");
    mvprintw(max_y / 1, COLS / 1, "Thank you for players.");
    getch(); // end main
}