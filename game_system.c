#include "game_system.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "draw_board.h"
#include "draw_color.h"
#include "draw_menu.h"
#include "draw_name.h"
#include "draw_sale_money.h"
#include "help.h"
#include "player.h"
#include "player_map_draw.h"
#define XSIZE 133
#define YSIZE 45

void main_init() {
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  curs_set(0);  // カーソルを表示しない
  noecho();     // 入力されたキーを表示しない
  cbreak();     // 入力バッファを使わない(Enter 不要の入力)
  keypad(stdscr, TRUE);  // カーソルキーを使用可能にする

  return;
}

void screen_size_check(void) {
  int x, y;
  main_init();
  getmaxyx(stdscr, y, x);
  if (x != XSIZE || y != YSIZE) {
    fprintf(stderr,
            "画面サイズを%d×%dに変更してください。現在の画面サイズ:%d×%d\n",
            XSIZE, YSIZE, x, y);
    sleep(3);
    endwin();
    exit(1);
  }
  endwin();
  return;
}

void game_exit(int *x, int *y) {
  int key;

  mvprintw(*y - (*y / 10) - 5, (*x / 10),
           "ゲームを終了しますか？  1:はい 2:いいえ");
  refresh();
  while (1) {
    key = getch();
    key = key - '0';
    if (key == 1) {
      game_menu();
    } else if (key == 2) {
      return;
      break;
    } else {
      continue;
    }
  }

  return;
}

void turnend(int *pn) {
  int x, y;
  getmaxyx(stdscr, y, x);
    draw_board(&x, &y);
  draw_money(&x, &y);
  draw_name();
  draw_sale_money();
  player_map_draw(*pn);
  (*pn)++;
  if (*pn >= PLAYER_NUM) {
    *pn = 0;
  }

  return;
}

void game_menu(void) {
  int xsize;     //画面横幅
  int ysize;     //画面縦幅
  int main_key;  //メイン番号

  while (1) {
    erase();
    getmaxyx(stdscr, ysize, xsize);
    main_key = draw_main_menu(&xsize, &ysize);

    switch (main_key) {
      case 1:
        game(&xsize, &ysize);
        break;
      case 2:
        help(&xsize, &ysize);
        break;
      case 3:
        endwin();
        exit(0);
    }
  }
  return;
}
