#include "FirstScreen.h"
#include "GameInfo.h"

using namespace std;

int main()
{
    // init curses option
    WINDOW *w;
    w=initscr();

    int max_y = LINES-1, max_x =COLS-COLS; // LINES = 가로행 갯수. COLS = 세로열 갯수 둘다 자동으로 할당됨
    int command = 'y';
    int diff = 5;
    gameinit();
    //'start main

    // game start
    print_start(0,max_y,'s');
    move(MAP_Y_MAX/2,MAP_X_MAX/2);
    printf(" 난이도를 입력해주세요 1 ~ 5");
    scanf("%d",&diff);
    diff +=2;
    constrain(&diff,7);
    move(0,0);
   
    // init finished
    struct PlayerInfo Player;    
    struct EnemyInfo Enemys[diff];       
    size_t size = sizeof(Enemys)/sizeof(EnemyInfo);
    EnemyInit(Enemys,size);
<<<<<<< HEAD
   
    // game start
=======
>>>>>>> d30338d1e9c82c5b631be711f7384262caf8cdc8

    // game Play
    int count = 0;
    while(command != 'q' && command !='Q')
    {        
        timeout(200);
        // 플레이어 체력 표기줄로 이동 및 표기
        move(MAP_Y_MAX+3,2);
        printw("HP : %d",Player.HP);  
        // 플레이어 키보드 입력 확인
        command = getch();
        //화면상에 나와있는 표기들로 부터 데미지 계산
        calc_damage(&Player,Enemys,size);     
        //만약 체력이 0 이라면 게임을 종료
        if(Player.HP <=0) {gameSet(); break;};     
        if(checkEnemyHp(Enemys,size)) {gameWin(); break;};                   
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