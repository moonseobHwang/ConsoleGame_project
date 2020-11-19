// #include <iostream>
// #include <string>
// #include <curses.h>
// #include "GameInfo.h"
// #include <stdlib.h>

// using namespace std;
// #define WALL 'W' 
// #define E_TRACE ' '

// int main(){
//     WINDOW *w;
//     w = initscr();
//     curs_set(0);

//     int y = 10, x = 10; // start main
//     int ch = 'y';
//     PlayerInfo position;
//     int move_info = 1;

//     while ((ch != 'q') && (ch != 'Q')) {
//         ch = getch();
//         // position.appear(y, x);
//         // string ch_var=to_string(position[0])+","+to_string(position[1]);
//         // mvprintw(20, 30, ch_var.c_str());
//         switch (ch) { 
//             case KEY_UP:
//             case 'w': y = y - 1; break;
//             case KEY_DOWN: y = y + 1; break;
//             case KEY_LEFT: x = x - 1; break;
//             case KEY_RIGHT: x = x + 1; mvaddch(y, x - 1, E_TRACE);mvscanw(y, x, "%d", move_info);break;

//     }
//     endwin();
//     return 0;
// }
// }


#include <iostream>
#include <curses.h>
#include <cstring>
#include "GameInfo.h"
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

#define PLAYER '*' 
#define WALL 'W' 
#define OPPONENT 'O' 
#define E_TRACE ' '

void delay(clock_t n)
{

  clock_t start = clock();

  while(clock() - start < n);

}
int main() {
    WINDOW *w;
    w = initscr();
    curs_set(0);
    keypad(stdscr, TRUE); timeout(30); // control game speed
    int count = 0,y = LINES-1, x = COLS-COLS, move_x = 0, move_y = 0; // start main
    int ch = 'y'; // define integer for compare with define
    while ((ch != 'q') && (ch != 'Q')) {
        // mvaddch(10, 5, WALL); 
        // mvaddch(11, 5, OPPONENT);
        if(count >= 0 && count <= 15){ 
            count += 1;
            mvaddch(move_y, ++move_x, OPPONENT);
            mvaddch(move_y, move_x - 1, E_TRACE);
            mvaddch(y, x, PLAYER); 
            timeout(1000);
            ch = getch();
        }else if(count >= 16 && count <= 31){
            count += 1;
            mvaddch(move_y, --move_x, OPPONENT);
            mvaddch(move_y, move_x + 1, E_TRACE);
            mvaddch(y, x, PLAYER); 
            timeout(1000);
            ch = getch();
            if(count == 32){count = 0;}
        }
        switch (ch) {
            case KEY_UP:
            case 'w': y = y - 1; break;
            case KEY_DOWN: y = y + 1; break;
            case KEY_LEFT: x = x - 1; mvaddch(y, x - 1, E_TRACE); break;
            case KEY_RIGHT: x = x + 1; mvaddch(y, x - 1, E_TRACE); break;
        }
    } // end main
    endwin();
    return 0;
}

