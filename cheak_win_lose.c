#include "cheak_win_lose.h"
#include <ncurses.h>
#include <stdio.h>
#include "draw.h"
#include "game_system.h"
#include "player.h"

#define WIN_MONEY 2500

void cheak_win_lose(int pn, int *x, int *y) {
  int cheak_money;

  pn = 0;
  cheak_money = p[pn].player_money;
  attron(COLOR_PAIR(1));
  if (cheak_money < 0) {
    bkgd(1);
    clear();
    erase();
    attron(COLOR_PAIR(12));
    mvprintw(*y / 2, *x / 2 - 4, "あなたの負けです");
    key_enter();
    refresh();
    game_menu();
  } else if (cheak_money >= WIN_MONEY) {
    bkgd(1);
    erase();
    clear();
    attron(COLOR_PAIR(12));
    mvprintw(*y / 2, *x / 2 - 4, "あなたの勝ちです");
    key_enter();
    refresh();
    game_menu();
  }
  attron(COLOR_PAIR(12));
}