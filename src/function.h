#ifndef FUNC_H
#define FUNC_H

#define HSIZE 60
#define LENGTH 75
#define WIDTH 10
#define STARTX 1
#define STARTY 5
#define STATUSX 1
#define STATUSY 25
#define KEY_F1 265

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>


char groups[13][9]; 


int print_menu();
int check_choice(int choice);
void print_byebye();
void create_test_string(char *test_array, int choice);
void print_time(time_t startt, time_t endt, int mistakes);
void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win);


int n_groups;

#endif
