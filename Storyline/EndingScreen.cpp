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
    mvprintw(max_y / 9, COLS / 9, "Mr. Jo killed Park, Hwang, and Son. ");
    mvprintw(max_y / 8, COLS / 8, "Mr.Jo learned all C++ and achieved national unification.");
    mvprintw(max_y / 7, COLS / 7, "To stabilize the country, Jojo should go to the KDC drone center");
    mvprintw(max_y / 6, COLS / 6, "And he has to get a drone piloting certificate...");
    mvprintw(max_y / 5, COLS / 5, "However, the KDC director's evil conspiracy was hidden...");
    mvprintw(max_y / 4, COLS / 4, "Indeed, Will Mr.Jo be able to conquer the KDC?");
    mvprintw(max_y / 3, COLS / 3, "Will Mr.Jo be able to learn drones???");
    mvprintw(max_y / 2, COLS / 2, "Continued from Part 2...");
    mvprintw(max_y / 1, COLS / 1, "to be continued...");
    getch(); // end main
}