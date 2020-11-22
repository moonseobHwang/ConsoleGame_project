#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H

#pragma once
#include <stdio.h>
#include <curses.h>
#include <string>
#include <cstring>
#include <time.h>

int output_start(int nX, int nY);
void print_start(int nX, int nY, char s);
void game_start(int x, int y,int *diff);
#endif