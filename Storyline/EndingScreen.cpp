#include <iostream>
#include <curses.h>
#include <string>
#include <string.h>

using namespace std;

const string blank2 = "                                                                                        ";
string strtext_ending[] = {"Finally, Mr. Jo killed Park, Hwang, and Son.", blank2, blank2,
                           "Mr.Jo learned all C++ and achieved national unification.", blank2, blank2,
                           "To stabilize the country, Mr.Jo should go to the KDC drone center", blank2, blank2,
                           "And he has to get a drone piloting certificate...", blank2, blank2,
                           "However, the KDC director's evil conspiracy was hidden...", blank2, blank2,
                           "Indeed, Will Mr.Jo be able to conquer the KDC?", blank2, blank2,
                           "Will Mr.Jo be able to learn drones???", blank2, blank2,
                           "Continued from Part 2...", blank2, blank2,
                           "to be continued...", blank2, blank2,
                           "--------------------------------------------", blank2, blank2,
                           "Editors...", blank2, blank2,
                           "Project Captain : Mr.Jo", blank2, blank2,
                           "Team Members :  Mr.Jo", blank2, blank2,
                           "Mr.Hwang", blank2, blank2,
                           "Mr.Son", blank2, blank2,
                           "Mr.Park", blank2, blank2,
                           "Story Writer : Mr.Son", blank2, blank2,
                           "The story is fiction", blank2, blank2,
                           "It is stated that the copyright fee belongs to Mr. Son.", blank2, blank2,
                           "Thank you for players."
                           };

int output_ending(int nX, int nY)
{
    int i = 0;
    static int nX1 = nX;
    static int nY1 = nY;

    for (i = 0; i < 57; i++) // 문장의개수
    {
        nX = COLS / 2 - strlen(strtext_ending[i].c_str()) / 2; // x를 절반으로 나누고 글자수를 세서 출력
        move(nY + i, 0);                                       // 위로 한칸
        clrtoeol();                                            // 커서의 처음부터 끝까지 지우기
        mvprintw(nY + i, nX, strtext_ending[i].c_str());       // 출력
    }
    move(nY + i, 0); // 마지막 문장 이후로 지워야해서
    clrtoeol();
    nY1 = nY1 - 1;
    return nY1;
};

void print_ending(int nX, int nY, char q)
{
    int ch = 'y';
    int count = 0;
    if (q == 'q')
    {
        while ((ch != 'q') && (ch != 'Q'))
        {
            count = output_ending(0, nY);
            ch = getch();
            if (count < -4)
                break;
            else
                printf("%d", count);
        }
    }
}

int main()
{
    WINDOW *w;
    w = initscr();
    using namespace std; // start main
    timeout(1000);
    curs_set(0);
    int max_y = LINES - 1, max_x = COLS - 1, move_x = 0, move_y = 0; // define in curses.h
    print_ending(0, max_y, 'q');
    printw("PRESS 'Q' TO QUIT THE GAME");
    endwin();
    return 0;
}