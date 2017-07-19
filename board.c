#include "board.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "draw.h"
#include "player.h"

#define BOARD_SIZE 11
#define BOARD_NUM 40

//ボード情報
/*typedef struct {
  char board_name[30];  //ボード名
  int board_flag;  // 0.GO 1.土地 2.チャンス 3.税金 4.刑務所 5.フリー
  int sale_flag;    //購入フラグ 0.未購入 1.購入済み
  int sale_player;  //購入者
  int sale_money;   //販売額
  int service;      //サービス料
  int sale_build;   //建設費
} BOARD_DATA;
*/

void board_init(void) {
  FILE *fp;
  int i, j;

  if ((fp = fopen("board_data.csv", "r")) == NULL) {
    fprintf(stderr, "csvがファイルがありません。\n");
    exit(0);
    endwin();
  }

  for (i = 0; i < BOARD_NUM; i++) {
    fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d\n", X[i].board_name, &X[i].board_flag,
           &X[i].sale_flag, &X[i].sale_player, &X[i].sale_money, &X[i].service,
           &X[i].sale_build);
  }

  fclose(fp);
  
}

int check_land(int map_n, int pn) {
  switch (X[map_n].board_flag) {
    case 1:
      return X[map_n].board_flag;
      break;
    case 2:
      return X[map_n].board_flag;
      break;
    case 3:
      draw_massage("200円の税金を支払います", 4);
      sub_money(200, pn);
	  key_enter();
      break;
    default:
      break;
  }
}

int judge_land() {
  int key;

  draw_massage("土地を購入しますか？　1:はい　2:いいえ", 0);
  while (1) {
    key = getch();
    key = key - '0';
    if (key == 1 || key == 2) break;
  }
  return key;
}

void sale_land(int map_n, int pn) {
  p[pn].player_money = p[pn].player_money - X[map_n].sale_money;
  X[map_n].sale_player = pn;
  X[map_n].sale_flag = 1;
}