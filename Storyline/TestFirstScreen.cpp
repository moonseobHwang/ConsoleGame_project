#include <iostream>
#include <curses.h>
#include <string>
#include <string.h>

using namespace std;


string strtext[] ={ "Title : JoJo's Bizarre Adventure",
                    "AD, 2200, Cho, Hwang, and Son Three Kingdoms.",
                    "The Three Kingdoms Period continued to be tight.",
                    "However, Park Kindom, the country established by Park Geon-jin, appeared.",
                    "It's entering the age of the four Kindoms...",
                    "Therefore, Jojo was in charge of national unification.",
                    "Mr.Jo decided to go to RAPA to learn C++.",
                    "However, Jo, Hwang, and Son were already RAPA...",
                    "To learn C++, you have to defeat your enemies!",
                    "Move Jo and kill the enemies!!!"};

void output(int nX, int nY)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        nX = COLS / 2 - strlen(strtext[i].c_str()) / 2;
        mvprintw(nY+i, nX, strtext[i].c_str());
    }
};

int main()
{
    WINDOW *w;
    int nX = 0;
    int nY = 0;
    
    w = initscr();
    using namespace std;                        // start main
    timeout(1000);
    int max_y = LINES - 1, max_x = COLS - 1, move_x = 0, move_y = 0; // define in curses.h
    int ch = 'y';
    nY = max_y;
    nX = 0;
    while ((ch != 'q') && (ch != 'Q'))
    {
        output(nX, nY);
        nY = nY - 1;
        ch = getch();
    }
    endwin();
    return 0;
}