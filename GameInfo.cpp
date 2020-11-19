#include "GameInfo.h"
#include "stdio.h"
//#include <curses.h>



using namespace std;


// for check crash 
void missiles(PlayerInfo *Player, EnemyInfo *Enemys,size_t size, int move)
{
    for (int i =0;i<size;i++)
    {
        if (!(Enemys+i)->move_sign)
        {
            (Enemys+i)->pos[1] = (Enemys+i)->pos[1]-move;
            constrain(&((Enemys+i)->pos[1]),MAP_Y_MAX);
            mvaddch( (Enemys+i)->pos[0] , (Enemys+i)->pos[1] ,(Enemys+i)->missile);
            mvaddch((Enemys+i)->pos[0],(Enemys+i)->pos[1]+move,E_TRACE);
            if((Enemys+i)->pos[1] - move < 1)
                (Enemys+i)->move_sign = true;
        }           
        else if( (Enemys+i)->move_sign)
        {
            (Enemys+i)->pos[1] = (Enemys+i)->pos[1]+move;
            constrain(&(Enemys+i)->pos[1],MAP_Y_MAX);
            mvaddch((Enemys+i)->pos[0],(Enemys+i)->pos[1],(Enemys+i)->missile);
            mvaddch((Enemys+i)->pos[0],(Enemys+i)->pos[1]-move,E_TRACE);
            if((Enemys+i)->pos[1] == MAP_Y_MAX)
                (Enemys+i)->move_sign = false;
        }
    }
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

void EnemyInit(EnemyInfo *Enemys,size_t size)
{
    for (int i =0 ; i<size; i++)
    {
        (Enemys+i)->id = i;
        (Enemys+i)->pos[0] = int(MAP_X_MAX/2)-i;
        (Enemys+i)->pos[1] = i*2+1;
    }
}

void EnemyMove(EnemyInfo *Enemys, size_t size, int move)
{
    for (int i =0;i<size;i++)
    {
        if (!(Enemys+i)->move_sign)
        {
            (Enemys+i)->pos[0] = (Enemys+i)->pos[0]-move;
            constrain(&((Enemys+i)->pos[0]),MAP_X_MAX);
            mvaddch( (Enemys+i)->pos[1] , (Enemys+i)->pos[0] ,(Enemys+i)->fig );
            mvaddch((Enemys+i)->pos[1],(Enemys+i)->pos[0]+move,E_TRACE);
            if((Enemys+i)->pos[0] - move < 1)
                (Enemys+i)->move_sign = true;
        }           
        else if( (Enemys+i)->move_sign)
        {
            (Enemys+i)->pos[0] = (Enemys+i)->pos[0]+move;
            constrain(&(Enemys+i)->pos[0],MAP_X_MAX);
            mvaddch((Enemys+i)->pos[1],(Enemys+i)->pos[0],(Enemys+i)->fig);
            mvaddch((Enemys+i)->pos[1],(Enemys+i)->pos[0]-move,E_TRACE);
            if((Enemys+i)->pos[0] == MAP_X_MAX)
                (Enemys+i)->move_sign = false;
        }
    }
}

void command_move(int command,int *x,int *y)
{
    switch (command)
    {
        case  KEY_LEFT:     
            if(is_move_ok(*y,*x-1) && *x != 1)
            {
                *x -=1;
                constrain(x,100);            
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y,*x+1,E_TRACE);  
            }
                
            break;
        case  KEY_RIGHT:
         if( is_move_ok(*y,*x+1))
            {    
                *x +=1; 
                constrain(x,100);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y,*x-1,E_TRACE);  
            }
            break;
        case  KEY_UP: 
            if( is_move_ok(*y-1,*x))
            {      
                *y -=1; 
                constrain(y,MAX_Y);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y+1,*x,E_TRACE);  
            }
            break;
        case  KEY_DOWN: 
            if( is_move_ok(*y+1,*x))
            {    
                *y +=1; 
                constrain(y,MAX_Y);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y-1,*x,E_TRACE);  
            }
            break;    
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

    struct EnemyInfo Enemys[3];  
    struct PlayerInfo Player;

    EnemyInit(Enemys,sizeof(Enemys)/sizeof(EnemyInfo));

    while(command != 'q' && command !='Q')
    {
        command = getch();
        timeout(200);
        move(0,0);        
        EnemyMove(Enemys,sizeof(Enemys)/sizeof(EnemyInfo),2);        
    }

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}