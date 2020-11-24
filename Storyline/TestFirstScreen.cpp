#include <iostream>
#include <curses.h>
#include <string>
using namespace std;

int main()
{
    WINDOW *w;
    w = initscr();
    using namespace std;                        // start main
    int max_y = LINES - 1, max_x = COLS - COLS, move_x = 0, move_y = 0; // define in curses.h
    int ch = 'y';
    mvaddstr(max_y , COLS / 3, "Title : JoJo's Bizarre Adventure");
    timeout(1000);
    while ((ch != 'q') && (ch != 'Q'))
    {
        timeout(1000); 
        mvaddstr(max_y , COLS / 3, "                                                                                             ");
        max_y = max_y - 2 ;
        mvaddstr(max_y , COLS / 3, "AD, 2200, Cho, Hwang, and Son Three Kingdoms.");     
        mvaddstr(max_y , COLS / 3, "                                                                                             ");
        max_y = max_y - 2 ;
        mvaddstr(max_y , COLS / 3, "The Three Kingdoms Period continued to be tight.");
        ch = getch();
        
    }
    endwin();
    return 0;
}