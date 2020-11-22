#include "FirstScreen.h"
using namespace std;

int output_start(int nX, int nY)
{
    static const std::string blank = "                                                                                        ";
    static std::string strtext_start[] = {"Title : JoJo's Bizarre Adventure", blank, blank,
                    "AD, 2200, Cho, Hwang, and Son Three Kingdoms.", blank, blank,
                    "The Three Kingdoms Period continued to be tight.", blank, blank,
                    "However, Park Kindom, the country established by Park Geon-jin, appeared.", blank, blank,
                    "It's entering the age of the four Kindoms...", blank, blank,
                    "Therefore, Mr.Jo was in charge of national unification.", blank, blank,
                    "Mr.Jo decided to go to RAPA to learn C++.", blank, blank,
                    "However, Jo, Hwang, and Son were already RAPA...", blank, blank,
                    "To learn C++, Mr.Jo have to defeat your enemies!", blank, blank,
                    "Move Jo and kill the enemies!!!"};

    int i = 0;
    static int nX1 = nX;
    static int nY1 = nY;

    for (i = 0; i < 28; i++) // 문장의 개수
    {
        nX1 = COLS / 2 - strlen(strtext_start[i].c_str()) / 2; // x를 절반으로 나누고 글자수를 세서 출력
        move(nY1 + i, 0);                                // 위로 한칸
        clrtoeol();                                      // 커서의 처음부터 끝까지 지우기
        mvaddstr(nY1 + i, nX1, strtext_start[i].c_str());      // 출력
    }
    move(nY + i, 0); // 마지막 문장 이후로 지워야해서
    clrtoeol();
    nY1 = nY1 - 1;
    return nY1;
}

void print_start(int nX, int nY, char s)
{
    int ch = 'y';
    int count = 0;
    if (s == 's')
    {
        while ((ch != 's') && (ch != 'S'))
        {
            count = output_start(nX, nY);
            ch = getch();
            timeout(300);
            if (count < -4)
                break;
            
                //printf("%d", count);
        }
    clear();
    refresh();
    }
   

}

