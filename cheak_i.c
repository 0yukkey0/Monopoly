#include "cheak_i.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "build.h"
#include "build.h"
#include "cheak_monopoly.h"
#include "draw.h"
#include "player.h"

void key_inp(int *key) {
  while (1) {
    *key = getch();
    *key = *key - '0';
    if (*key == 1 || *key == 2) break;
  }
}
void draw_cmassage() {
  draw_massage("増築しますか？　はい:1　いいえ：2", 4);
  draw_massage("*はいを選択した場合ゾーン全部が増築されます。", 5);
}
void cheak_1(int *pn) {
  int key;
  static int flag = 0;

  if (X[1].sale_flag == 1 && X[3].sale_flag == 1) {
    if (X[1].sale_player == *pn && X[3].sale_player == *pn) {
      draw_massage("茶色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[1].service = X[1].service * 2;
        X[3].service = X[3].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(1);
        sub_money(X[1].sale_build + X[3].sale_build, *pn);
      }
    }
  }
}
void cheak_2(int *pn) {
  int key;
  static int flag = 0;
  if (X[6].sale_flag == 1 && X[8].sale_flag == 1 && X[9].sale_flag == 1) {
    if (X[6].sale_player == *pn && X[8].sale_player == *pn &&
        X[9].sale_player == *pn) {
      draw_massage("水色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[6].service = X[6].service * 2;
        X[8].service = X[8].service * 2;
        X[9].service = X[9].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(2);
        sub_money(X[6].sale_build + X[8].sale_build + X[9].sale_build, *pn);
      }
    }
  }
}
void cheak_3(int *pn) {
  int key;
 static  int flag = 0;
  if (X[11].sale_flag == 1 && X[13].sale_flag == 1 && X[14].sale_flag == 1) {
    if (X[11].sale_player == *pn && X[13].sale_player == *pn &&
        X[14].sale_player == *pn) {
      draw_massage("ピンク色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[11].service = X[11].service * 2;
        X[13].service = X[13].service * 2;
        X[14].service = X[14].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(3);
        sub_money(X[11].sale_build + X[13].sale_build + X[14].sale_build, *pn);
      }
    }
  }
}
void cheak_4(int *pn) {
  int key;
  static int flag = 0;
  if (X[16].sale_flag == 1 && X[18].sale_flag == 1 && X[19].sale_flag == 1) {
    if (X[16].sale_player == *pn && X[18].sale_player == *pn &&
        X[19].sale_player == *pn) {
      draw_massage("橙色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[16].service = X[16].service * 2;
        X[18].service = X[18].service * 2;
        X[19].service = X[19].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(4);
        sub_money(X[16].sale_build + X[18].sale_build + X[19].sale_build, *pn);
      }
    }
  }
}
void cheak_5(int *pn) {
  int key;
  static int flag = 0;
  if (X[21].sale_flag == 1 && X[23].sale_flag == 1 && X[24].sale_flag == 1) {
    if (X[21].sale_player == *pn && X[23].sale_player == *pn &&
        X[24].sale_player == *pn) {
      draw_massage("赤色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[21].service = X[21].service * 2;
        X[23].service = X[23].service * 2;
        X[24].service = X[24].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(5);
        sub_money(X[21].sale_build + X[23].sale_build + X[24].sale_build, *pn);
      }
    }
  }
}
void cheak_6(int *pn) {
  int key;
  static int flag = 0;
  if (X[26].sale_flag == 1 && X[27].sale_flag == 1 && X[29].sale_flag == 1) {
    if (X[26].sale_player == *pn && X[27].sale_player == *pn &&
        X[29].sale_player == *pn) {
      draw_massage("黃色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[26].service = X[26].service * 2;
        X[27].service = X[27].service * 2;
        X[29].service = X[29].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(6);
        sub_money(X[26].sale_build + X[27].sale_build + X[29].sale_build, *pn);
      }
    }
  }
}
void cheak_7(int *pn) {
  int key;
  static int flag = 0;
  if (X[31].sale_flag == 1 && X[32].sale_flag == 1 && X[34].sale_flag == 1) {
    if (X[31].sale_player == *pn && X[32].sale_player == *pn &&
        X[34].sale_player == *pn) {
      draw_massage("緑色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[31].service = X[31].service * 2;
        X[32].service = X[32].service * 2;
        X[34].service = X[34].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(7);
        sub_money(X[31].sale_build + X[32].sale_build + X[34].sale_build, *pn);
      }
    }
  }
}
void cheak_8(int *pn) {
  int key;
  static int flag = 0;
  if (X[37].sale_flag == 1 && X[39].sale_flag == 1) {
    if (X[37].sale_player == *pn && X[39].sale_player == *pn) {
      draw_massage("青色ゾーンの増築が可能です。 ", 3);
      draw_cmassage();
      if (flag == 0) {
        X[37].service = X[37].service * 2;
        X[39].service = X[39].service * 2;
        flag = 1;
      }
      key_inp(&key);
      if (key == 1) {
        flushinp();
        build(8);
        sub_money(X[37].sale_build + X[39].sale_build, *pn);
      }
    }
  }
}
