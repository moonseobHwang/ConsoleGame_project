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
    mvprintw(max_y / 11 * 1, COLS / 3, "Editors...");
    mvprintw(max_y / 11 * 2, COLS / 3, "Project Captain : Mr.Jo");
    mvprintw(max_y / 11 * 3, COLS / 3, "Team Members");
    mvprintw(max_y / 11 * 4, COLS / 3, "Mr.Jo");
    mvprintw(max_y / 11 * 5, COLS / 3, "Mr.Hwang");
    mvprintw(max_y / 11 * 6, COLS / 3, "Mr.Son");
    mvprintw(max_y / 11 * 7, COLS / 3, "Mr.Park");
    mvprintw(max_y / 11 * 8, COLS / 3, "Story Writer : Mr.Son");
    mvprintw(max_y / 11 * 9, COLS / 3, "The story is fiction");
    mvprintw(max_y / 11 * 10, COLS / 3, "It is stated that the copyright fee belongs to Mr. Son.");
    mvprintw(max_y / 11 * 11, COLS / 3, "Thank you for players.");
    getch(); // end main
}