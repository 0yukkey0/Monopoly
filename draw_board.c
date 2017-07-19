#include "draw.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "player.h"
#include "draw_board.h"
#include "draw_color.h"
void draw_board(int *xsize, int *ysize) {
  draw_init();
  erase();
  bkgd(COLOR_PAIR(11));

  int x = *xsize;
  int y = *ysize;
  int i, j;
  int h, w;

  int key;

  //横線
  for (i = 1; i < 11; i++) {
    attron(COLOR_PAIR(2));
    move(y / 10 * i, 0);
    hline(ACS_HLINE, x);
    refresh();
  }

  //縦線
  for (i = 1; i < 12; i++) {
    attron(COLOR_PAIR(2));
    move(0, x / 11 * i);
    vline(ACS_VLINE, y);
    refresh();
  }

  //テキストボックス塗りつぶし
  for (i = y / 10 + 1; i < y - y / 10 - 1; i++) {
    for (j = x / 10; j < x - x / 10; j++) {
      attron(COLOR_PAIR(1));
      mvprintw(i, j, "*");
      refresh();
    }
  }

  draw_color(x, y);

  return;
}