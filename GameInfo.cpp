#include "GameInfo.h"
#include "stdio.h"
//#include <curses.h>
#include <vector>
#include <cmath>
#include <time.h>


using namespace std;
void delay(clock_t n)
{

  clock_t start = clock();

  while(clock() - start < n);

}

int is_move_ok(int y,int x)
{
    int comp_ch;
    comp_ch = mvinch(y,x);
    return !((comp_ch == 'O'));
}

void constrain(int *val,int max)
{
    if(*val<1) *val = 1;
    else if(*val>max) *val = max;
}

void EnemyInit(EnemyInfo Enemy[],size_t size)
{
    for (int i =0 ; i<size; i++)
    {
        *(&Enemy[i].id) = i;
        *(&Enemy[i].position[0]) = 7-i;
        *(&Enemy[i].position[1]) = i*2;
        

    }
}

void EnemyMove(EnemyInfo Enemy[],size_t size, int move)
{
    for (int i =0;i<size;i++)
    {
        if(Enemy[i].position[0]-move>2) *(&Enemy[i].position[0]) = Enemy[i].position[0]-move;
        else *(&Enemy[i].position[0])=Enemy[i].position[0]+move;
        constrain(&Enemy[i].position[0],MAX_X);
       // printf("Enemy %d : %d, %d\n",i,Enemy[i].position[0],Enemy[i].position[1]);
        mvaddch(Enemy[i].position[1],Enemy[i].position[0],Enemy[i].fig);

    }
}


int main()
{
    // init curses option
    WINDOW *w;
    w=initscr();
    curs_set(0);        //visible cursor
    //'start main
    keypad(stdscr, TRUE);
    timeout(30); //fps 를 30으로 한정 
    int max_y = LINES-1, max_x =COLS-COLS; // LINES = 가로행 갯수. COLS = 세로열 갯수 둘다 자동으로 할당됨
    int command = 'y';
    int move_x=0, move_y=0;
    printw("%d, %d",LINES,COLS);
    // init finished

    EnemyInfo Enemys[4];
    PlayerInfo Player;
    EnemyInit(Enemys,sizeof(Enemys)/sizeof(EnemyInfo));
    while(command != 'q' || command !='Q')
    {
        command = getch();
        delay(500);
        move(0,0);
        
        EnemyMove(Enemys,sizeof(Enemys)/sizeof(EnemyInfo),1);
        
    }

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}