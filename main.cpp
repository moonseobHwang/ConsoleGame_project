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
    int diff = 0;
    while(1)
    {
        diff = 5;
        gameinit();
        //'start main

        // game start
        game_start(&diff);    
        struct PlayerInfo Player;    
        struct EnemyInfo Enemys[diff];       
        size_t size = sizeof(Enemys)/sizeof(EnemyInfo);
        EnemyInit(Enemys,size);
        // init finished

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
            EnemyMissiles(Enemys,size,1); 
            if(count > 2){                 
                EnemyMove(Enemys,size,3);     
                count = 0;
            }  
            count++;
            refresh();
        }
        // delete &Player;
        // delete[] Enemys;
        clear();       
        move(MAP_Y_MAX/2,MAP_X_MAX/2); 
        refresh();
        printf("재도전? press S with start or Q with quit");
        char c = 's';
        scanf("%s",&c);
        if(c == 'q' || c == 'Q') break;
    }   
    //game end 

    endwin(); //자원 반납으로 종료시킴
    return 0;
    
}