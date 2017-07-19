#include "player_map_draw.h"
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "player.h"

void player_map_draw(int pn) {
  int x, y;
  int key;
  int n = 0;
  int i;

  key = p[pn].player_map;
  switch(pn){
	  case 0:
	    attron(COLOR_PAIR(20));
	  break;
	  case 1:
	    attron(COLOR_PAIR(21));
	  break;
	  case 2:
	    attron(COLOR_PAIR(22));
	  break;
	  case 3:
	  attron(COLOR_PAIR(23));
	  break;
  }

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
  key = p[pn].player_map;
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
  key = p[pn].player_map;
  n = 0;
  // 21〜31
  if (20 <= key && key <= 30) {
    key = key - 20;
    for (i = 0; i <= key; i++) {
      n = n + (x / 11);
    }
    mvprintw(0, n - 2, "● ");
    refresh();
  }
  key = p[pn].player_map;
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