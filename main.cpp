#include "GameInfo.h"

using namespace std;

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
        move(Player.position[y]+3,2);
        printw("HP : %d",Player.HP);    
        command = getch();
        calc_damage(&Player,Enemys,size);        
        if(Player.HP <=0) {gameSet(); break;};               
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