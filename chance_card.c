#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "player.h"
#include "chance_card.h"
#include "player_map_clear.h"


void chance_card(int pn) {
  int card;

  srand((unsigned int)time(NULL));
  card = rand() % 10 + 1;

  switch (card) {
    case 1:
      draw_massage("銀行から150円受け取る。", 2);
      add_money(150, pn);
      break;
    case 2:
      draw_massage("次の人から100円貰う。", 2);
      add_money(100, pn);
      if (pn + 1 == PLAYER_NUM) sub_money(100, PLAYER_NUM - (pn + 1));
      sub_money(100, pn + 1);
      break;
    case 3:
      draw_massage("Goへ(200円も貰える)", 2);
      add_money(200, pn);
      player_map_clear(pn);
      p[pn].player_map = 0;
      break;
    case 4:
      draw_massage("銀行に200円支払う。", 2);
      sub_money(200, pn);
      break;
    case 5:
      player_map_clear(pn);
      draw_massage("刑務所へ行く", 2);
      move_prison(pn);
      break;
    case 6:
      draw_massage("銀行から50円受け取る。", 2);
      add_money(50, pn);
      break;
    case 7:
      player_map_clear(pn);
      draw_massage("2マス進む(購入＆支払い不可)", 2);
      addmap(pn, 2);
      break;
    case 8:
      player_map_clear(pn);
      draw_massage("3マス戻る(購入＆支払い不可)", 2);
      addmap(pn, -3);
      break;
    case 9:
      draw_massage("次の人に150円払う。", 2);
      sub_money(150, pn);
      if (pn + 1 == PLAYER_NUM) add_money(150, PLAYER_NUM - (pn + 1));
      add_money(150, pn + 1);
      break;
    case 10:
      player_map_clear(pn);
      draw_massage("駐車場へ(200円は貰えない)", 2);
      p[pn].player_map = 20;
  }
}