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
        // 플레이어 체력 표기줄로 이동 및 표기
        move(Player.position[y]+3,2);
        printw("HP : %d",Player.HP);  
        // 플레이어 키보드 입력 확인
        command = getch();

        //화면상에 나와있는 표기들로 부터 데미지 계산
        calc_damage(&Player,Enemys,size);     
        //만약 체력이 0 이라면 게임을 종료    
        if(Player.HP <=0) {gameSet(); break;};                      
        PlayerMissile(&Player,Enemys,size);  
        command_move(command,&Player);

        if(count > 2){
            EnemyMissiles(Enemys,size,1);  
            EnemyMove(Enemys,size,3);     
            count = 0;
        }  
        count++;
        refresh();
    }

    //game end 

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}