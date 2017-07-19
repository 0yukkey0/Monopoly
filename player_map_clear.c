#include "player_map_clear.h"
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "player.h"



void player_map_clear(int pn) {
  int x, y;
  int key = p[pn].player_map;
  int n = 0;
  int i;

  attron(COLOR_PAIR(11));
  getmaxyx(stdscr, y, x);
// Go〜岩手
  if (0 <= key && key <= 9) {
    key = 10 - key;
    for (i = 0; i <= key; i++) {
      n = n + (x / 11);
    }
    mvprintw(y - 1, n - 2, "● ");
    refresh();
  }
  n = 0;
  // 11〜20
  if (10 <= key && key <= 19) {
    key = 20 - key;
    for (i = 0; i <= key; i++) {
      n = n + (y / 10);
    }
    mvprintw(n - 1, 0, "● ");
    refresh();
  }
  n = 0;
  // 21〜31
  if (20 <= key && key <= 30) {
    key = key - 20 ;
    for (i = 0; i <= key; i++) {
      n = n + (x / 11);
    }
    mvprintw(0, n-2, "● ");
    refresh();
  }
  n = 0;
  // 31〜39
  if (31 <= key && key <= 39) {
    key = key - 30;
    for (i = 0; i <= key; i++) {
      n = n + (y / 10);
    }
    mvprintw(n - 1, x - 3, "● ");
    refresh();
  }

  
}