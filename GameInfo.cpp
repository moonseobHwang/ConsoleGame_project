#include "GameInfo.h"

using namespace std;

void constrain(int *val,int max)
{
    if(*val<MIN) *val = MIN;
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
        else if((Enemys+i)->missile_pos[1] >= MAP_Y_MAX-1 )
        {
            mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            mvaddch(MAP_Y_MAX,(Enemys+i)->missile_pos[0],E_TRACE);
            if(move>1)
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0],E_TRACE);
            else 
                mvaddch(MAP_Y_MAX-1,(Enemys+i)->missile_pos[0]-1,E_TRACE);
            (Enemys+i)->missile_pos[0] = -1;
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
    for (int i =0;i<size;i++)   // 적 갯수만큼 for문 실행하는 코드
    {
        move = rand()%(move)+1; // 2를 넣었다면 2만큼 만 움직일 수 있음
        if ((Enemys+i)->HP >0)
        {
            if (!(Enemys+i)->move_sign) // 적 아이콘 왼쪽 움직임
            {
                // 적 위치 이동 포인트 계산
                (Enemys+i)->pos[0][0] = (Enemys+i)->pos[0][0]-move;
                // 적 이동 최대,최소값 제한 
                constrain(&((Enemys+i)->pos[0][0]),MAP_X_MAX);
                // 적 아이콘 위치 이동 
                mvaddch((Enemys+i)->pos[1][1], (Enemys+i)->pos[1][0],E_TRACE); 
                mvaddch((Enemys+i)->pos[0][1], (Enemys+i)->pos[0][0] ,(Enemys+i)->fig );
                // 최소값보다 작은 위치로 이동할 경우 반대방향으로 이동 
                if((Enemys+i)->pos[0][0] - move < MIN)
                    (Enemys+i)->move_sign = true;
            }           
            else if( (Enemys+i)->move_sign) // 적 아이콘이 오른쪽으로 움직임
            {
                
                (Enemys+i)->pos[0][0] = (Enemys+i)->pos[0][0]+move;
                constrain(&(Enemys+i)->pos[0][0],MAP_X_MAX);
                mvaddch((Enemys+i)->pos[1][1],(Enemys+i)->pos[1][0],E_TRACE);
                mvaddch((Enemys+i)->pos[0][1],(Enemys+i)->pos[0][0],(Enemys+i)->fig);
                
                if((Enemys+i)->pos[0][0] == MAP_X_MAX)
                    (Enemys+i)->move_sign = false;
            }
            // 현재 위치의 x,y 좌표를 기존 위치 좌표로 업데이트 
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

//플레이어 미사일 위치 이동
void PlayerMissile(PlayerInfo *Player,EnemyInfo *Enemys, size_t size)
{
    static int i = 0;
    //mvaddstr(MAP_Y_MAX+1,MAP_X_MAX+1,(std::to_string(i)).c_str());
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
            check_move |= (Player->missile_pos[y]-1==(Enemys+(size-1)-i)->pos[0][y] && Player->missile_pos[x]==(Enemys+(size-1)-i)->pos[0][x]);
            if(check_move)
            {
                Player->mis_on = false;
                mvaddch(Player->missile_pos[y],Player->missile_pos[x],E_TRACE);
                mvaddch((Enemys+(size-1)-i)->pos[0][y],(Enemys+(size-1)-i)->pos[0][x],E_TRACE);
                mvaddch((Enemys+(size-1)-i)->pos[0][y],(Enemys+(size-1)-i)->pos[0][x],E_TRACE);
                Player->missile_pos[x] = 0; Player->missile_pos[y] = 0;                    
                (Enemys+(size-i-1))->HP = 0;i=0;
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
                i= 0;

            }                                 
        }    
    }

    if(Player->mis_on==true && Player->missile_pos[y] < size+1)
    {
        i++;
        if( i>= size)  i = 0;
    }    
}

// 게임 종료
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

// 게임 초기설정 함수 
void gameinit()
{
    curs_set(0);        //visible cursor
    noecho();
    nodelay(stdscr,1);
    keypad(stdscr, TRUE);
    timeout(30); //fps 를 30으로 한정 
    for (int i=0;i==MAP_X_MAX;i++)
    {
        
    }
}

// 적 HP 체크 
bool checkEnemyHp(EnemyInfo *Enemys,size_t size)
{
    int EnemysHP = 0;
    for(int i=0; i<size; i++)
    {
        if((Enemys+i)->HP == 0){
            EnemysHP += 1;
        }
    }
    if(EnemysHP >= size)
    {
        return true;
    }
    return false;
}
// 적HP 확인 
void gameWin()
{
    clear(); 
    move(MAP_Y_MAX/2,MAP_X_MAX/2); 
    printw("GAME Win!!"); 
    move(MAP_Y_MAX/2+1,MAP_X_MAX/2-6); 
    printw("Press Q for quit Game"); 
    while(getch()!='q'); 
    clear();
    refresh();
}