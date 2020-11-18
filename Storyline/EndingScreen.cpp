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
    mvprintw(max_y / 2, COLS / 2, "Mr. Jo killed Park, Hwang, and Son. \n Mr.Jo learned all C++ and achieved national unification. \n To stabilize the country, Jojo should go to the KDC drone center \n And he has to get a drone piloting certificate... \n However, the KDC director's evil conspiracy was hidden... \n Indeed, Will Mr.Jo be able to conquer the KDC? \n Will Mr.Jo be able to learn drones??? \n Continued from Part 2... \n to be continued... \n -------------------------------------------- \n Editors... \n Project Captain : Mr.Jo \n Team Members :  Mr.Jo \n Mr.Hwang \n Mr.Son \n Mr.Park \n Story Writer : Mr.Son \n The story is fiction \n It is stated that the copyright fee belongs to Mr. Son. \n Thank you for players.");
    getch(); // end main
}