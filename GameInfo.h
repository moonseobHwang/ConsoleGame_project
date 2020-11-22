#ifndef GAMEINFO_H
#define GAMEINFO_H

#pragma once
#include <stdio.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <curses.h>


#define MAP_X_MAX 27
#define MAP_Y_MAX 12
#define MIN 3
#define MAX_X COLS-COLS
#define MAX_Y  15
#define OPPONENT 'O'
#define PLAYER '*'
#define WALL {'_','|'}
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

void constrain(int *val,int max);
void EnemyMissiles(EnemyInfo *Enemys,size_t size, int move);
bool is_move_ok(int y,int x);
void EnemyInit(EnemyInfo *Enemys,size_t size);
void EnemyMove(EnemyInfo *Enemys, size_t size, int move);
void calc_damage(PlayerInfo *Player,EnemyInfo *Enemys,size_t size);
void command_move(int command,PlayerInfo *Player);
void PlayerMissile(PlayerInfo *Player,EnemyInfo *Enemys,size_t size);
bool checkEnemyHp(EnemyInfo *Enemys,size_t size);
void gameSet();
void gameWin();
void gameinit();
bool checkEnemyHp(EnemyInfo *Enemys,size_t size);
void gameWin();
#endif