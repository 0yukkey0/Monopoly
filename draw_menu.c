#include "draw_menu.h"
#include "draw.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "player.h"

int draw_main_menu(int *xs, int *ys) {
  int key;

  erase();
  draw_init();
  bkgd(COLOR_PAIR(1));
  attron(COLOR_PAIR(12));

  mvprintw(
      1, *xs / 2 - 33,
      "mm   mm  ooooooo nn    n ooooooo pppppp ooooooo ll       yy   yy   \n");
  mvprintw(
      2, *xs / 2 - 33,
      "m m m m  o     o n n   n o     o p    p o     o ll        yy yy    \n");
  mvprintw(
      3, *xs / 2 - 33,
      "m  m  m  o     o n  n  n o     o pppppp o     o ll          y      \n");
  mvprintw(
      4, *xs / 2 - 33,
      "m     m  o     o n   n n o     o p      o     o ll          y      \n");
  mvprintw(
      5, *xs / 2 - 33,
      "m     m  ooooooo n    nn ooooooo p      ooooooo llllllll    y       \n");

  mvprintw(*ys / 2, *xs / 2 - 3, "1.Game");
  mvprintw(*ys / 2 + 2, *xs / 2 - 3, "2.Help");
  mvprintw(*ys / 2 + 4, *xs / 2 - 3, "3.exit");
  refresh();

  while ((key = getch()) != 'q') {
    key = key - '0';  //キーボード０の数値
    switch (key) {
      case 1:
        return key;
        break;
      case 2:
        return key;
        break;
      case 3:
        return key;
        break;
      default:
        break;
    }
  }

  erase();
  refresh();
  endwin();
  exit(0);
}

void play_menu(int *xsize, int *ysize) {
  draw_init();
  attron(COLOR_PAIR(12));
  int y;
  int x;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横

  mvprintw(y + 3, x + 5, "1:ダイス　2:売却 3:終了");

  return;
}