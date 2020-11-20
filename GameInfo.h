#pragma once

#include <curses.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <string>

#define MAP_X_MAX 25
#define MAP_Y_MAX 10
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
    int pos[2][2];
    int id=0;
    char fig = 'W';
    char missile = '*';
    int missile_pos[2] = {0,0};
    bool move_sign = false;
    
};    


struct PlayerInfo
{
    int HP = 10;
    int position[2]={0,MAP_Y_MAX-1};
    int id=0;
    char fig = 'M';
    const char missile[3] = {'|','^','A'};
    int missile_pos[2] = {0,0};
    bool mis_on = false;
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
