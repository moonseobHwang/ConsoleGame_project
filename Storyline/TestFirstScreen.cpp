#include <iostream>
#include <curses.h>
#include <string>
using namespace std;

int main()
{
    WINDOW *w;
    w = initscr();
    using namespace std;                        // start main
    timeout(1000);
    int max_y = LINES - 1, max_x = COLS - COLS, move_x = 0, move_y = 0; // define in curses.h
    int ch = 'y';
    while ((ch != 'q') && (ch != 'Q'))
    {
        mvaddstr(max_y - 1, COLS / 3, "                                 ");
        max_y = max_y - 3 ;
        mvaddstr(max_y - 1, COLS / 3, "Title : JoJo's Bizarre Adventure ");
        ch = getch();
    }
    endwin();
    return 0;
}