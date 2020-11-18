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
    mvprintw(max_y / 10, COLS / 10, "Title : JoJo's Bizarre Adventure ");
    mvprintw(max_y / 9, COLS / 9, "AD, 2200, Cho, Hwang, and Son Three Kingdoms.");
    mvprintw(max_y / 8, COLS / 8, "The Three Kingdoms Period continued to be tight.");
    mvprintw(max_y / 7, COLS / 7, "However, Park Kindom, the country established by Park Geon-jin, appeared.");
    mvprintw(max_y / 6, COLS / 6, "It's entering the age of the four Kindoms...");
    mvprintw(max_y / 5, COLS / 5, "Therefore, Jojo was in charge of national unification.");
    mvprintw(max_y / 4, COLS / 4, "Mr.Jo decided to go to RAPA to learn C++.");
    mvprintw(max_y / 3, COLS / 3, "However, Jo, Hwang, and Son were already RAPA...");
    mvprintw(max_y / 2, COLS / 2, "To learn C++, you have to defeat your enemies!");
    mvprintw(max_y / 1, COLS / 1, "Move Jo and kill the enemies!!!");
    getch(); // end main
}