#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "build_all.h"
#include "draw.h"
#include "player.h"
#include "player_map_clear.h"
#include "player_map_draw.h"
void move_player(int *x, int *y, int *zf, int *fn, int *pn) {
  int ekey;
  char pmassage[] = "刑務所に移動します";

  do {
    attron(COLOR_PAIR(12));

    call_now_board(x, y, *pn);

    mvprintw(*y / 10 + 13, *x / 10,
             "  ゾロ目なのでもう一度サイコロを振ります:");
    mvprintw(*y / 10 + 14, *x / 10, "  speaceを押してください");
    //build_all(x, y, *pn);
    player_map_draw(*pn);
    ekey = getch();
    if (ekey == ' ') {
      flushinp();
      player_map_clear(*pn);
      retextbox(x, y);
      *zf = 0;
      addmap(*pn, redice(x, y, zf, fn));
      key_enter();
      flushinp();
      call_now_board(x, y, *pn);
      player_map_draw(*pn);
      if (p[*pn].player_map == 30) {
        move_prison(*pn);
        draw_massage(pmassage, 0);
        *zf = 0;
      }
      if (*fn == 2) {
        retextbox(x, y);
        move_prison(*pn);
        *zf = 0;
        draw_massage(pmassage, 0);
        refresh();
        key_enter();
      }
    }
  } while (*zf == 1);

  return;
}