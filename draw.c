#include "draw.h"
#include "draw_color.h"
#include "draw_menu.h"
#include "draw_board.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "player.h"

void draw_init(void) {
  init_pair(11, COLOR_WHITE, COLOR_WHITE);  // 白字／白地
  init_pair(1, COLOR_BLACK, COLOR_BLACK);   // 黒字／黒地
  init_pair(2, COLOR_BLACK, COLOR_WHITE);   // 黒字／白地
  init_pair(12, COLOR_WHITE, COLOR_BLACK);  // 白字／黒地

  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_GREEN, COLOR_GREEN);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);  //オレンジ
  init_pair(6, COLOR_BLUE, COLOR_BLUE);
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(8, COLOR_CYAN, COLOR_CYAN);
  init_pair(9, 94, 94);     //茶色
  init_pair(10, 214, 214);  //黄色

  init_pair(20, COLOR_RED, COLOR_WHITE);
  init_pair(21, COLOR_GREEN, COLOR_WHITE);
  init_pair(22, COLOR_BLUE, COLOR_WHITE);
  init_pair(23, COLOR_YELLOW, COLOR_WHITE);
}

void draw_money(int *xsize, int *ysize) {
  draw_init();
  attron(COLOR_PAIR(12));
  int y;
  int x;
  int i;
  int pi = 1;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横

  for (i = 0; i < PLAYER_NUM; i++) {
    mvprintw(y + i + pi, *xsize - x * 4, "プレイヤー %d     %d円",
             p[i].player_number, p[i].player_money);
    pi++;
  }
  return;
}

void draw_massage(char m[], int n) {
  int x, y;
  move(0, 0);
  attron(COLOR_PAIR(12));
  getmaxyx(stdscr, y, x);

  y = y / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = x / 10;      //黒テキストボック左上x座標　横

  mvprintw(y + 8 + n, x + 5, "%s", m);
  refresh();
  return;
}
void draw_clear(char m[], int n) {
  int x, y;
  move(0, 0);
  attron(COLOR_PAIR(1));
  getmaxyx(stdscr, y, x);

  y = y / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = x / 10;      //黒テキストボック左上x座標　横

  mvprintw(y + 8 + n, x + 5, "%s", m);
  refresh();
  return;
}


void retextbox(int *xsize, int *ysize) {
  int x, y;
  int i = 0, j = 0;
  int key;
  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横

  // sleep(1);
  attron(COLOR_PAIR(1));
  move(y, x);
  for (i = y + 5; i < y + 20; i++) {
    for (j = x; j < x + 60; j++) {
      mvprintw(i, j, " ");
      refresh();
    }
  }
  attron(COLOR_PAIR(12));
  return;
}

void reall(int *xsize, int *ysize) {
  int x, y;
  int i = 0, j = 0;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横
  attron(COLOR_PAIR(1));
  move(y, x);
  for (i = y; i < y + 20; i++) {
    for (j = x; j < x + 105; j++) {
      mvprintw(i, j, " ");
      refresh();
    }
  }
  attron(COLOR_PAIR(12));
  return;
}

void key_enter() {
  int key;

  draw_massage("enterを押してください。", 18);
  while (1) {
    key = getch();
    if (key == '\n') break;
  }
  draw_clear("***************************************************",18);
}