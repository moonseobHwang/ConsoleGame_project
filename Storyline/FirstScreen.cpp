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
    mvprintw(max_y / 2, COLS / 2, "Title : JoJo's Bizarre Adventure \n AD, 2200, Cho, Hwang, and Son Three Kingdoms. \n The Three Kingdoms Period continued to be tight. \n However, Park Kindom, the country established by Park Geon-jin, appeared. \n It's entering the age of the four Kindoms... \n Therefore, Jojo was in charge of national unification. \n Mr.Jo decided to go to RAPA to learn C++. \n However, Jo, Hwang, and Son were already RAPA... \n To learn C++, you have to defeat your enemies! \n Move Jo and kill the enemies!!! \n PRESS START \n GAME START");
    getch(); // end main
}