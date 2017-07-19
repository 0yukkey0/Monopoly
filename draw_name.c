#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "draw_name.h"
#include "player.h"

void draw_name() {
  int x, y;
  int i = 0;
  int n=0;
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(2));
  getmaxyx(stdscr, y, x);

//マスナンバー20〜30まで
  mvprintw(0, 0,"%s", X[20].board_name);
  for (i = 21; i <= 30; i++) {
    n = n + (x/11);
	mvprintw(0, 1+n, "%s", X[i].board_name);
  }

//マスナンバー10〜19
  n=0;
  for (i = 19; i >= 10; i--) {
    n = n + (y/10);
	mvprintw(1+n, 0, "%s", X[i].board_name);
	  }
//マスナンバー31~39
  n=0;
  for (i = 31; i <= 39; i++) {
    n = n + (y/10);
	mvprintw(1+n, x-10, " %s", X[i].board_name);
  }
    n=0;
//マスナンバー1~9
for (i = 9; i >= 0; i--) {
    n = n + (x/11);
	mvprintw(y-1, 1+n, "%s", X[i].board_name);
  }


}