#include <iostream>
#include <curses.h>
#include <string>
#include <string.h>

using namespace std;

const string blank = "                                                                                        ";
string strtext_ending[] = {"Finally, Mr. Jo killed Park, Hwang, and Son.", blank, blank,
                           "Mr.Jo learned all C++ and achieved national unification.", blank, blank,
                           "To stabilize the country, Mr.Jo should go to the KDC drone center", blank, blank,
                           "And he has to get a drone piloting certificate...", blank, blank,
                           "However, the KDC director's evil conspiracy was hidden...", blank, blank,
                           "Indeed, Will Mr.Jo be able to conquer the KDC?", blank, blank,
                           "Will Mr.Jo be able to learn drones???", blank, blank,
                           "Continued from Part 2...", blank, blank,
                           "to be continued...", blank, blank,
                           "--------------------------------------------", blank, blank,
                           "Editors...", blank, blank,
                           "Project Captain : Mr.Jo", blank, blank,
                           "Team Members :  Mr.Jo", blank, blank,
                           "Mr.Hwang", blank, blank,
                           "Mr.Son", blank, blank,
                           "Mr.Park", blank, blank,
                           "Story Writer : Mr.Son", blank, blank,
                           "The story is fiction", blank, blank,
                           "It is stated that the copyright fee belongs to Mr. Son.", blank, blank,
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
            if (count < 0)
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
    timeout(500);
    curs_set(0);
    int max_y = LINES - 1, max_x = COLS - 1, move_x = 0, move_y = 0; // define in curses.h
    print_ending(0, max_y, 'q');
    printw("PRESS 'Q' TO QUIT THE GAME");
    endwin();
    return 0;
}