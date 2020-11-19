#pragma once

#include <curses.h>
#define MAP_X_MAX 15
#define MAP_Y_MAX 20
#define MIN 1
#define MAX_X COLS-COLS
#define MAX_Y  15
#define OPPONENT 'O'
#define PLAYER '*'
#define WALL 'W'
#define E_TRACE ' '


enum Postion {x,y};     

struct EnemyInfo
{
    int HP = 1;
    int position[2];
    int id=0;
    char fig = 'W';
    char missile = '*';

};    


struct PlayerInfo
{
    int HP = 10;
    int position[2]={0};
    int id=0;
    char fig = 'M';
    char missile[3] = {'*','^','A'};
    int score=0;
};

struct ItemInfo
{
    char item_fig[4] = {'E','P','$','O'};
    int item_info[4] = {1,1,1,-1};
    int position[4][2]= {{0,0},{0,0},{0,0},{0,0}};

};

struct MapInfo
{
    char fig[2] = {'_','|'};
};
