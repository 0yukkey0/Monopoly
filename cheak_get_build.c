#include "cheak_get_build.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "cheak_i.h"
#include "draw.h"
#include "player.h"

void key_cheak(int *key, int num) {
  while (1) {
    *key = getch();
    *key = *key - '0';
    if (*key >= 0 && *key < num) break;
  }
}

void cheak_get_build(int pn) {
  int i, j = 0, k;
  int get_num = 0;
  int get_list[20];
  int x, y;
  int key, ckey;

  attron(COLOR_PAIR(12));
  getmaxyx(stdscr, y, x);

  y = y / 10 + 1;  //黒テキストボックスの左上y座標 縦
  x = x / 10;      //黒テキストボック左上x座標　横

  for (i = 0; i < BOARD_NUM; i++) {
    if (X[i].sale_flag == 1 && X[i].sale_player == pn) {
      get_num++;
      get_list[j] = i;
      j++;
    }
  }
  if (get_num != 0) {
    draw_massage("物件を選んでください。", 0);
    for (i = 0; i < get_num; i++) {
      k = get_list[i];
      mvprintw(y + 9 + i, x + 5, "%d:%s", i, X[k].board_name);
      refresh();
    }
    key_cheak(&key, get_num);
    k = get_list[key];
    draw_massage("本当に売却しますか？ 1:はい 2:いいえ", 3);
    key_inp(&ckey);
	if(ckey == 2){
		draw_massage("キャンセルしました。",5);
		refresh();
		return;
	}
    add_money(X[k].sale_money, pn);
    X[k].sale_flag = 0;
    X[k].sale_player = -1;
	draw_massage("売却しました。",5);
  } else {
    draw_massage("売却できる物件がありません。", 0);
    refresh();
  }
}