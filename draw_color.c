#include "draw.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "player.h"
#include "draw_color.h"

void draw_color(int x, int y) {
  int h, w;
  int i;
  int uw;      //下ｙ座標格納
  int tf = 1;  //段数
  int tw;
  h = x / 11 - 1;
  w = y / 10 - 1;
  uw = y - w - 1;
  tw = w + 2;
  //オレンジ描画
  attron(COLOR_PAIR(5));
  for (i = 0; i < w; i++) {
    move(tw * tf + i, h - 1);
    printw("*");
    move(tw * tf + i, h);
    printw("*");
    refresh();
  }
  tf++;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, h);
    printw("*");
    refresh();
  }
  tf = 4;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, h);
    printw("*");
    refresh();
  }

  //ピンク描画
  attron(COLOR_PAIR(7));
  tf = 6;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, h);
    printw("*");
    refresh();
  }
  tf++;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, h);
    printw("*");
    refresh();
  }
  tf = 9;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, h);
    printw("*");
    refresh();
  }
  tf = 1;
  //緑描画
  attron(COLOR_PAIR(4));
  for (i = 0; i < w; i++) {
    move(tw * tf + i, x - h - 1);
    printw("*");
    move(tw * tf + i, x - h);
    printw("*");
    refresh();
  }
  tf++;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, x - h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, x - h);
    printw("*");
    refresh();
  }
  tf = 4;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, x - h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, x - h);
    printw("*");
    refresh();
  }

  //青描画
  attron(COLOR_PAIR(6));
  tf = 7;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, x - h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, x - h);
    printw("*");
    refresh();
  }
  tf = 9;
  for (i = 0; i < w; i++) {
    move(tw * tf - tf + 1 + i, x - h - 1);
    printw("*");
    move(tw * tf - tf + 1 + i, x - h);
    printw("*");
    refresh();
  }

  //赤描画
  attron(COLOR_PAIR(3));
  move(w, h + 2);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(w, h * 3 + 4);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(w, h * 4 + 5);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }

  //黄色描画
  attron(COLOR_PAIR(10));
  move(w, h * 6 + 7);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(w, h * 7 + 8);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(w, h * 9 + 10);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }

  //水色描画
  attron(COLOR_PAIR(8));
  move(uw, h + 2);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(uw, h * 2 + 3);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(uw, h * 4 + 5);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }

  //茶色描画
  attron(COLOR_PAIR(9));

  move(uw, h * 7 + 8);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
  move(uw, h * 9 + 10);
  for (i = 0; i < h; i++) {
    printw("*");
    refresh();
  }
}