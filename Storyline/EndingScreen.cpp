#include <iostream>
#include <curses.h>
#include <string>
#include <string.h>

using namespace std;

const string blank = "                                                                                        ";
string strtext[] ={ "Finally, Mr. Jo killed Park, Hwang, and Son.",blank,blank,
                    "Mr.Jo learned all C++ and achieved national unification.",blank,blank,
                    "To stabilize the country, Mr.Jo should go to the KDC drone center",blank,blank,
                    "And he has to get a drone piloting certificate...",blank,blank,
                    "However, the KDC director's evil conspiracy was hidden...",blank,blank,
                    "Indeed, Will Mr.Jo be able to conquer the KDC?",blank,blank,
                    "Will Mr.Jo be able to learn drones???",blank,blank,
                    "Continued from Part 2...",blank,blank,
                    "to be continued...",blank,blank,
                    "Editors...",blank,blank,
                    "Project Captain : Mr.Jo",blank,blank,
                    "Team Members :  Mr.Jo",blank,blank,
                    "Mr.Hwang",blank,blank,
                    "Mr.Son",blank,blank,
                    "Mr.Park",blank,blank,
                    "Story Writer : Mr.Son",blank,blank,
                    "The story is fiction",blank,blank,
                    "It is stated that the copyright fee belongs to Mr. Son.",blank,blank,
                    "Thank you for players."};

void output(int nX, int nY)
{
    int i = 0;
    for (i = 0; i < 55; i++)                        // 10문장이라
    {
        nX = COLS / 2 - strlen(strtext[i].c_str()) / 2;         // x를 절반으로 나누고 글자수를 세서 출력
        move(nY+i, 0);                                          // 위로 한칸
        clrtoeol();                                             // 커서의 처음부터 끝까지 지우기
        mvprintw(nY+i, nX, strtext[i].c_str());                 // 출력
    }
    move(nY+i, 0);                                                  // 마지막 문장 이후로 지워야해서
    clrtoeol();
};

int main()
{
    WINDOW *w;
    int nX = 0;
    int nY = 0;
    w = initscr();
    using namespace std;                        // start main
    timeout(1000);
    curs_set(0);
    int max_y = LINES - 1, max_x = COLS - 1, move_x = 0, move_y = 0; // define in curses.h
    int ch = 'y';
    nY = max_y;
    nX = 0;
    printw("PRESS 'Q' TO QUIT THE GAME");
    while ((ch != 'q') && (ch != 'Q'))
    {
        output(nX, nY);
        nY = nY - 1;
        ch = getch();
    }
    endwin();
    return 0;
}