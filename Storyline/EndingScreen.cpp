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
    mvprintw(max_y / 10 * 1, COLS / 3, "Mr. Jo killed Park, Hwang, and Son. ");
    mvprintw(max_y / 10 * 2, COLS / 3, "Mr.Jo learned all C++ and achieved national unification.");
    mvprintw(max_y / 10 * 3, COLS / 3, "To stabilize the country, Jojo should go to the KDC drone center");
    mvprintw(max_y / 10 * 4, COLS / 3, "And he has to get a drone piloting certificate...");
    mvprintw(max_y / 10 * 5, COLS / 3, "However, the KDC director's evil conspiracy was hidden...");
    mvprintw(max_y / 10 * 6, COLS / 3, "Indeed, Will Mr.Jo be able to conquer the KDC?");
    mvprintw(max_y / 10 * 7, COLS / 3, "Will Mr.Jo be able to learn drones???");
    mvprintw(max_y / 10 * 8, COLS / 3, "Continued from Part 2...");
    mvprintw(max_y / 10 * 9, COLS / 3, "to be continued...");
    getch(); // end main
}