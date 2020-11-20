#include "stdio.h"
#include "GameInfo.h"

using namespace std;

void constrain(int *val,int max)
{
    if(*val<1) *val = 1;
    else if(*val>max) *val = max;
}

// 미사일 크래싱 체크 코드.
void missiles(PlayerInfo *Player, EnemyInfo *Enemys,size_t size, int move)
{
    for (int i =0;i<size;i++)
    {                
        
        if((Enemys+i)->missile_pos[1]==0)
        {
            (Enemys+i)->missile_pos[0] = (Enemys+i)->pos[0][0];
            (Enemys+i)->missile_pos[1] = (Enemys+i)->pos[0][1];
        }
        else if((Enemys+i)->missile_pos[1] >= MAP_Y_MAX)
        {
            mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            mvaddch(MAP_Y_MAX,(Enemys+i)->missile_pos[0],E_TRACE);
            if(move>1)
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            else mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0]-1,E_TRACE);
            (Enemys+i)->missile_pos[0] = 0;
            (Enemys+i)->missile_pos[1] = 0;           
        }
        else
        {
            (Enemys+i)->missile_pos[y] = (Enemys+i)->missile_pos[y]+move;
            constrain(&(Enemys+i)->missile_pos[y],MAP_Y_MAX);
            mvaddch((Enemys+i)->missile_pos[y],(Enemys+i)->missile_pos[x],(Enemys+i)->missile);
            mvaddch((Enemys+i)->missile_pos[y]+1,(Enemys+i)->missile_pos[x],E_TRACE);
            if((Enemys+i)->missile_pos[y]-move > MAP_Y_MAX)
                
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[x],E_TRACE);
            else 
                mvaddch((Enemys+i)->missile_pos[y]-move,(Enemys+i)->missile_pos[x],E_TRACE);    
        }   
    }
}
// 객체 이동가능여부 확인
int is_move_ok(int y,int x)
{
    int comp_ch;
    comp_ch = mvinch(y,x);
    return !((comp_ch == 'O')||(comp_ch == '*')||(comp_ch == '$'));
}
// 적 객체 초기위치 설정
void EnemyInit(EnemyInfo *Enemys,size_t size)
{
    for (int i =0 ; i<size; i++)
    {
        (Enemys+i)->id = i;
        (Enemys+i)->pos[0][0] = int(MAP_X_MAX/2)-i;
        (Enemys+i)->pos[0][1] = i+1;
    }
}
// 적 움직임 자동 관리
void EnemyMove(EnemyInfo *Enemys, size_t size, int move)
{
    for (int i =0;i<size;i++)
    {
        move = rand()%(move)+1;
        if (!(Enemys+i)->move_sign)
        {
            
            (Enemys+i)->pos[0][0] = (Enemys+i)->pos[0][0]-move;
            constrain(&((Enemys+i)->pos[0][0]),MAP_X_MAX);
            mvaddch((Enemys+i)->pos[1][1], (Enemys+i)->pos[1][0],E_TRACE); 
            mvaddch((Enemys+i)->pos[0][1], (Enemys+i)->pos[0][0] ,(Enemys+i)->fig );
             

            if((Enemys+i)->pos[0][0] - move < 1)
                (Enemys+i)->move_sign = true;
        }           
        else if( (Enemys+i)->move_sign)
        {
            
            (Enemys+i)->pos[0][0] = (Enemys+i)->pos[0][0]+move;
            constrain(&(Enemys+i)->pos[0][0],MAP_X_MAX);
            mvaddch((Enemys+i)->pos[1][1],(Enemys+i)->pos[1][0],E_TRACE);
            mvaddch((Enemys+i)->pos[0][1],(Enemys+i)->pos[0][0],(Enemys+i)->fig);
            
            if((Enemys+i)->pos[0][0] == MAP_X_MAX)
                (Enemys+i)->move_sign = false;
        }
        (Enemys+i)->pos[1][0] = (Enemys+i)->pos[0][0];
            (Enemys+i)->pos[1][1] = (Enemys+i)->pos[0][1];
    }
}
//
bool calc_damage(PlayerInfo *Player)
{
    int comp_ch='y';
    comp_ch = mvinch(Player->position[y]+1,Player->position[x]);
    switch(comp_ch)
    {
        case '*' :
            Player->HP -=1;
            if(Player->HP == 0) return 0;
            break;
        case '$' :
            Player->HP +=1;
            constrain(&Player->HP,10);
            break;
    }
}
//
void command_move(int command,PlayerInfo *Player)
{
    
    switch (command)
    {
        case  KEY_LEFT:     
            if(is_move_ok(Player->position[y],Player->position[x]-1) && Player->position[x] != 1)
            {
                Player->position[x] -=1;                
                constrain(&Player->position[x] ,MAP_X_MAX);            
                mvaddch(Player->position[y],Player->position[x],Player->fig);
                mvaddch(Player->position[y],Player->position[x]+1,E_TRACE);  
            }                
            break;
        case  KEY_RIGHT:
         if( is_move_ok(Player->position[y],Player->position[x]+1))
            {    
                Player->position[x] +=1; 
                constrain(&Player->position[x],MAP_X_MAX);
                mvaddch(Player->position[y],Player->position[x],Player->fig);
                mvaddch(Player->position[y],Player->position[x]-1,E_TRACE);  
            }
            break;
        case  'a': 
        case  'A':   
            break;
    }

}

void gameSet()
{
    clear(); 
    move(MAP_Y_MAX/2,MAP_X_MAX/2); 
    printw("GAME OVER"); 
    move(MAP_Y_MAX/2+1,MAP_X_MAX/2-6); 
    printw("Press Q for quit Game"); 
    while(getch()!='q'); 
    endwin();
}

void gameinit()
{
    curs_set(0);        //visible cursor
    noecho();
    nodelay(stdscr,0);
    keypad(stdscr, TRUE);
    timeout(30); //fps 를 30으로 한정 
}

int main()
{
    // init curses option
    WINDOW *w;
    w=initscr();
    gameinit();
    //'start main
    
    int max_y = LINES-1, max_x =COLS-COLS; // LINES = 가로행 갯수. COLS = 세로열 갯수 둘다 자동으로 할당됨
    int command = 'y';
    int move_x=0, move_y=0;
    printw("%d, %d",LINES,COLS);
    // init finished

    struct EnemyInfo Enemys[5];  
    struct PlayerInfo Player;

    EnemyInit(Enemys,sizeof(Enemys)/sizeof(EnemyInfo));
    
    // game start

    // game Play
    while(command != 'q' && command !='Q')
    {
        timeout(200);
        move(19,2);
        printw("HP : %d ",Player.HP);
        command = getch();
        calc_damage(&Player);        
        if(Player.HP <=0 ) {gameSet(); break;};               
        missiles(&Player,Enemys,sizeof(Enemys)/sizeof(EnemyInfo),1);        
        EnemyMove(Enemys,sizeof(Enemys)/sizeof(EnemyInfo),3);
        command_move(command,&Player); 
    }

    //game end 

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}