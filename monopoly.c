#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "build_all.h"
#include "chance_card.h"
#include "cheak_get_build.h"
#include "cheak_monopoly.h"
#include "cheak_win_lose.h"
#include "draw.h"
#include "draw_name.h"
#include "draw_sale_money.h"
#include "game_system.h"
#include "help.h"
#include "player.h"
#include "player_map_clear.h"
#include "player_map_draw.h"
#include "draw_color.h"
#include "draw_menu.h"
#include "draw_board.h"

//#define XSIZE 110
//#define YSIZE 31

void game(int *x, int *y);
void move_player(int *x, int *y, int *zf, int *fn, int *pn);

int main(int argc, char **argv) {
  screen_size_check();
  main_init();
  game_menu();
  return 0;
}

void game(int *x, int *y) {
  int key;
  int board_flag;

  int player_n = 0;   //プレイヤー番号
  int dnum;           //ダイス結果格納
  int zoro_flag = 0;  //ゾロ目フラグ
  int flag_num = 0;   //フラグ回数
  int i;
  char *m;
  data_init();
  board_init();

  while (1) {
    draw_board(x, y);
    draw_money(x, y);
    draw_name();
	draw_sale_money();
    timeout(1);

    while ((key = getch()) != 'q') {
      call_now_board(x, y, player_n);
      player_map_draw(player_n);
      draw_money(x, y);
      call_player(x, y, player_n);
      play_menu(x, y);
      cheak_win_lose(player_n, x, y);

      key = key - '0';  //キーボード０の数値
      if (p[player_n].player_kflag == 1) {
        retextbox(x, y);
        draw_massage("刑務所にいるためターンを終了します。", 0);
        key_enter();
        p[player_n].player_knum = p[player_n].player_knum + 1;
        if (p[player_n].player_knum > 2) {
          p[player_n].player_knum = 0;
          p[player_n].player_kflag = 0;
        }
        turnend(&player_n);
        reall(x, y);
        key = 7;
      }
      switch (key) {
        case 1:
          flushinp();
          //ダイス関連一式
          dnum = dice(x, y, &zoro_flag);
          player_map_clear(player_n);
          attron(COLOR_PAIR(12));
          addmap(player_n, dnum);
          player_map_draw(player_n);

          refresh();
          key_enter();
          if (zoro_flag == 1) {
            move_player(x, y, &zoro_flag, &flag_num, &player_n);
          }
          retextbox(x, y);
          call_now_board(x, y, player_n);

          flag_num = 0;
          if (p[player_n].player_map == 30) {
            move_prison(player_n);
            draw_massage("刑務所に移動します", 0);
            key_enter();
          }
          //ここまで
          flushinp();

          build_all(x, y, player_n);
          player_map_draw(player_n);
          retextbox(x, y);
          draw_massage("ターンを終了します。", 0);
		  key_enter();
          turnend(&player_n);
          reall(x, y);
          draw_money(x, y);
          flushinp();
          break;
        case 2:
          cheak_get_build(player_n);
          flushinp();
          key_enter();
          reall(x, y);
          break;
        case 3:
          game_exit(x, y);
          break;
        default:
          break;
        case 7:
          break;
      }
    }
    game_exit(x, y);
	reall(x, y);
  }
  return;
}
