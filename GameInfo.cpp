#include "stdio.h"
#include "GameInfo.h"

using namespace std;

void constrain(int *val,int max)
{
    if(*val<1) *val = 1;
    else if(*val>max) *val = max;
}

// 미사일 움직임 코드.
void EnemyMissiles(EnemyInfo *Enemys,size_t size, int move)
{
    for (int i =0;i<size;i++)
    {                
        if((Enemys+i)->missile_pos[1]==0 && (Enemys+i)->HP > 0)
        {
            (Enemys+i)->missile_pos[0] = (Enemys+i)->pos[0][0];
            (Enemys+i)->missile_pos[1] = (Enemys+i)->pos[0][1];
        }
        else if((Enemys+i)->missile_pos[1] >= MAP_Y_MAX )
        {
            mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            mvaddch(MAP_Y_MAX,(Enemys+i)->missile_pos[0],E_TRACE);
            if(move>1)
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            else 
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0]-1,E_TRACE);
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
bool is_move_ok(int y,int x)
{
    int comp_ch;
    comp_ch = mvinch(y,x);
    return !((comp_ch == 'O')||(comp_ch == '*')||(comp_ch == '$')||(comp_ch == 'W')||(comp_ch == 'M'));
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
        if ((Enemys+i)->HP >0)
        {
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
}
// 데미지 및 점수 계산
void calc_damage(PlayerInfo *Player,EnemyInfo *Enemys,size_t size)
{
    bool hit=false;
    int player_pos[2] = {Player->position[x],Player->position[y]};    
    for (int i=0;i<size;i++)
    {   
        if( (Enemys+i)->missile_pos[x]==player_pos[0] && (Enemys+i)->missile_pos[y]==player_pos[1] )
        {
            Player->HP -=1;
        }
    }

}

// 플레이어 커맨드 처리
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
            if (Player->mis_on == false)
            {
                Player->mis_on = true;
                Player->missile_pos[x] = Player->position[x];
                Player->missile_pos[y] = Player->position[y]-1;
                mvaddch(Player->missile_pos[y],Player->missile_pos[x],Player->missile[0]);
            }            
            break;
    }

}

void PlayerMissile(PlayerInfo *Player,EnemyInfo *Enemys, size_t size)
{
    static int i = 0;
    mvaddch(MAP_Y_MAX,MAP_X_MAX,char(i));
    if(Player->mis_on == true && Player->missile_pos[y]>(Enemys+(size-1))->pos[0][y]+1)
    {
        mvaddch(Player->missile_pos[y],Player->missile_pos[x],E_TRACE);
        Player->missile_pos[y] -=1;
        mvaddch(Player->missile_pos[y],Player->missile_pos[x],Player->missile[0]);
    }
    else
    {
        if(Player->mis_on == true)
        {
            bool check_move = false;
            
            // && !(mvinch(Player->missile_pos[y],Player->missile_pos[x])=='W')
            check_move |= (Player->missile_pos[y]-1==(Enemys+(size-1)-i)->pos[0][y] && Player->missile_pos[x]-1==(Enemys+(size-1)-i)->pos[0][x]);
            check_move |= (Player->missile_pos[y]-1==(Enemys+(size-1)-i)->pos[0][y] && Player->missile_pos[x]==(Enemys+(size-1)-i)->pos[0][x]);
            check_move |= (Player->missile_pos[y]-1==(Enemys+(size-1)-i)->pos[0][y] && Player->missile_pos[x]+1==(Enemys+(size-1)-i)->pos[0][x]);
            if(check_move)
            {
                Player->mis_on = false;
                mvaddch(Player->missile_pos[y],Player->missile_pos[x],E_TRACE);
                mvaddch((Enemys+(size-1)-i)->pos[0][y],(Enemys+(size-1)-i)->pos[0][x],E_TRACE);
                mvaddch((Enemys+(size-1)-i)->pos[0][y],(Enemys+(size-1)-i)->pos[0][x],E_TRACE);
                Player->missile_pos[x] = 0; Player->missile_pos[y] = 0;                    
                (Enemys+(size-i-1))->HP = 0;
            }
            else if(Player->missile_pos[y]>1)
            {
                mvaddch(Player->missile_pos[y],Player->missile_pos[x],E_TRACE);                    
                mvaddch(Player->missile_pos[y]-1,Player->missile_pos[x],Player->missile[0]);
                Player->missile_pos[y] = Player->missile_pos[y]-1;
            }
            else if(Player->missile_pos[y]<=1)
            {
                Player->mis_on = false;
                mvaddch(Player->missile_pos[y],Player->missile_pos[x],E_TRACE);
                Player->missile_pos[x]=0; Player->missile_pos[y]=0; 

            }
            if(Player->mis_on==true && Player->missile_pos[y] < size && Player->missile_pos[y] > 1)    
                i++;
            if(i>size) i = 0;   
                
            
        }

        
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
    nodelay(stdscr,1);
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
    size_t size = sizeof(Enemys)/sizeof(EnemyInfo);
    EnemyInit(Enemys,size);
    
    // game start

    // game Play
    int count = 0;
    while(command != 'q' && command !='Q')
    {
        
        timeout(200);
        move(19,2);
        printw("HP : %d",Player.HP);    
        command = getch();
        calc_damage(&Player,Enemys,size);        
        if(Player.HP <=0 ) {gameSet(); break;};               
        EnemyMissiles(Enemys,size,1);  
        PlayerMissile(&Player,Enemys,size);  
        if(count > 4)    
            EnemyMove(Enemys,size,1);        
        command_move(command,&Player);
        count++;
        refresh();
     
    }

    //game end 

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}
