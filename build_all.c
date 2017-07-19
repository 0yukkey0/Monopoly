#include "build_all.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "chance_card.h"
#include "cheak_get_build.h"
#include "cheak_monopoly.h"
#include "draw.h"
#include "player.h"

void build_all(int *x, int *y, int player_n) {
  int board_flag = 0;
  char *m;

  board_flag = check_land(p[player_n].player_map, player_n);
  if (board_flag == 1) {
    if (X[p[player_n].player_map].sale_flag == 0) {
      switch (judge_land()) {
        case 1:
          retextbox(x, y);
          sale_land(p[player_n].player_map, player_n);
          draw_money(x, y);
          draw_massage("購入しました。", 0);
          key_enter();
        case 2:
          cheak_monopoly(player_n, x, y);
          break;
      }
    } else if (X[p[player_n].player_map].sale_flag == 1) {
      if (player_n != X[p[player_n].player_map].sale_player) {
        m = (char *)malloc(sizeof(char) * 100);
        sprintf(m, "プレイヤー%dに%d円支払います",
                X[p[player_n].player_map].sale_player + 1,
                X[p[player_n].player_map].service);
        draw_massage(m, 1);
        sub_money(X[p[player_n].player_map].service, player_n);
        add_money(X[p[player_n].player_map].service,
                  X[p[player_n].player_map].sale_player);
        refresh();
        key_enter();
      }
    }
  } else if (board_flag == 2) {
    chance_card(player_n);
    refresh();
    key_enter();
    cheak_monopoly(player_n, x, y);
  }
}