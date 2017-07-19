#include "player.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "draw.h"

#define START_MONEY 1500

void data_init(void) {
  int i;
  extern PLAYER_DATA p[PLAYER_NUM];

  for (i = 0; i < PLAYER_NUM; i++) {
    p[i].player_number = i + 1;
    p[i].player_money = START_MONEY;
    p[i].player_map = 0;
    p[i].player_kflag = 0;
    p[i].player_knum = 0;
  }
  return;
}

void call_player(int *xsize, int *ysize, int n) {
  int x, y;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横

  draw_init();
  attron(COLOR_PAIR(12));
  mvprintw(y + 1, x + 5, "プレイヤー %d　のターンです", p[n].player_number);
  refresh();
  return;
}

int dice(int *xsize, int *ysize, int *zf) {
  int s1, s2;
  char m[50];
  int x, y;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横
  srand((unsigned)time(NULL));
  s1 = rand() % 100 + 1;
  s2 = rand() % 100 + 1;
  s1 = s1 % 6 + 1;
  s2 = s2 % 6 + 1;
  sprintf(m, "サイコロの結果は%dと%dです。", s1, s2);
  mvprintw(y + 6, x + 5, "%s", m);
  if (s1 == s2) {
    *zf = 1;
  }
  return s1 + s2;
}

int redice(int *xsize, int *ysize, int *zf, int *fn) {
  int s1, s2;
  char m[50];
  int x, y;

  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横
  s1 = rand() % 6 + 1;
  s2 = rand() % 6 + 1;
  sprintf(m, "%d回目のサイコロの結果は%dと%dです。", *fn + 2, s1, s2);
  mvprintw(y + 6, x + 5, "%s", m);
  refresh();
  if (s1 == s2) {
    *zf = 1;
    *fn = *fn + 1;
  }
  return s1 + s2;
}

void addmap(int pn, int dn) {
  p[pn].player_map = p[pn].player_map + dn;
  if (p[pn].player_map >= 40) {
    p[pn].player_map = p[pn].player_map - 40;
    draw_massage("Goをすぎたので200円支給されます。", 2);
    p[pn].player_money = p[pn].player_money + 200;
  }
  if (p[pn].player_map < 0) {
    p[pn].player_map = 40 + p[pn].player_map;
  }
}

void move_prison(int pn) {
  p[pn].player_kflag = 1;
  p[pn].player_map = 10;
}

void call_now_board(int *xsize, int *ysize, int pn) {
  char *c;
  int i;
  int x, y;

  i = p[pn].player_map;
  y = *ysize / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = *xsize / 10;      //黒テキストボック左上x座標　横
  c = (char *)malloc(sizeof(char) * 100);

  sprintf(c, "プレイヤー%dの現在地は%sです。", pn + 1, X[i].board_name);
  mvprintw(y + 5, x + 5, "%s", c);
  refresh();
  free(c);
}

void add_money(int money, int pn) {
  p[pn].player_money = p[pn].player_money + money;
}

void sub_money(int money, int pn) {
  p[pn].player_money = p[pn].player_money - money;
}
