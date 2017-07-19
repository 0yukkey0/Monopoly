#include "draw_sale_money.h"
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "player.h"


int sale_money;  //販売額
int service;

void draw_sale_money() {
  int x, y;
  int i = 0;
  int n = 0;
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(2));
  getmaxyx(stdscr, y, x);

  //マスナンバー20〜30まで
  for (i = 21; i <= 30; i++) {
    n = n + (x / 11);
    if (X[i].board_flag == 1) {
      if (X[i].sale_flag == 0) {
        mvprintw(1, 1 + n, "%d円", X[i].sale_money);
      } else if (X[i].sale_flag == 1) {
        mvprintw(1, 1 + n, "%d円", X[i].service);
      }
    }
  }

  //マスナンバー10〜19
  n = 0;
  for (i = 19; i >= 10; i--) {
    n = n + (y / 10);
    if (X[i].board_flag == 1) {
      if (X[i].sale_flag == 0) {
        mvprintw(2 + n, 0, "%d円", X[i].sale_money);
      } else if (X[i].sale_flag == 1) {
        mvprintw(2 + n, 0, "%d円", X[i].service);
      }
    }
  }

  //マスナンバー31~39
  n = 0;
  for (i = 31; i <= 39; i++) {
    n = n + (y / 10);

    if (X[i].board_flag == 1) {
      if (X[i].sale_flag == 0) {
        mvprintw(2 + n, x - 8, "%d円", X[i].sale_money);
      } else if (X[i].sale_flag == 1) {
        mvprintw(2 + n, x - 8, "%d円", X[i].service);
      }
    }
  }

  n = 0;
  //マスナンバー1~9
  for (i = 9; i >= 0; i--) {
    n = n + (x / 11);

    if (X[i].board_flag == 1) {
      if (X[i].sale_flag == 0) {
        mvprintw(y - 2, 1 + n, "%d円", X[i].sale_money);
      } else if (X[i].sale_flag == 1) {
        mvprintw(y - 2, 1 + n, "%d円", X[i].service);
      }
    }
  }
}