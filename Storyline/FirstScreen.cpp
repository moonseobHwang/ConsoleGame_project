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
    mvprintw(max_y / 10 * 1, COLS / 3, "Title : JoJo's Bizarre Adventure ");
    mvprintw(max_y / 10 * 2, COLS / 3, "AD, 2200, Cho, Hwang, and Son Three Kingdoms.");
    mvprintw(max_y / 10 * 3, COLS / 3, "The Three Kingdoms Period continued to be tight.");
    mvprintw(max_y / 10 * 4, COLS / 3, "However, Park Kindom, the country established by Park Geon-jin, appeared.");
    mvprintw(max_y / 10 * 5, COLS / 3, "It's entering the age of the four Kindoms...");
    mvprintw(max_y / 10 * 6, COLS / 3, "Therefore, Jojo was in charge of national unification.");
    mvprintw(max_y / 10 * 7, COLS / 3, "Mr.Jo decided to go to RAPA to learn C++.");
    mvprintw(max_y / 10 * 8, COLS / 3, "However, Jo, Hwang, and Son were already RAPA...");
    mvprintw(max_y / 10 * 9, COLS / 3, "To learn C++, you have to defeat your enemies!");
    mvprintw(max_y / 10 * 10, COLS / 3, "Move Jo and kill the enemies!!!");
    getch(); // end main
}