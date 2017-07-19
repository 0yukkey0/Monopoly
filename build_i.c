#include "build_i.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "build.h"
#include "draw.h"
#include "player.h"

void build1() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2;
  if (flag == 0) {
    tmp1 = X[1].service;
    tmp2 = X[3].service;
    flag = 1;
  }
  X[1].service = tmp1 * 3 * build_num;
  X[3].service = tmp2 * 3 * build_num;
  build_num++;
}
void build2() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;
  if (flag == 0) {
    tmp1 = X[6].service;
    tmp2 = X[8].service;
    tmp3 = X[9].service;
    flag = 1;
  }
  X[6].service = tmp1 * 3 * build_num;
  X[8].service = tmp2 * 3 * build_num;
  X[9].service = tmp3 * 3 * build_num;
  build_num++;
}
void build3() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;
  if (flag == 0) {
    tmp1 = X[11].service;
    tmp2 = X[13].service;
    tmp3 = X[14].service;
    flag = 1;
  }
  X[11].service = tmp1 * 3 * build_num;
  X[13].service = tmp2 * 3 * build_num;
  X[14].service = tmp3 * 3 * build_num;
  build_num++;
}
void build4() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;

  if (flag == 0) {
    tmp1 = X[16].service;
    tmp2 = X[18].service;
    tmp3 = X[19].service;
    flag = 1;
  }
  X[16].service = tmp1 * 3 * build_num;
  X[18].service = tmp2 * 3 * build_num;
  X[19].service = tmp3 * 3 * build_num;
  build_num++;
}
void build5() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;

  if (flag == 0) {
    tmp1 = X[21].service;
    tmp2 = X[23].service;
    tmp3 = X[24].service;
    flag = 1;
  }
  X[21].service = tmp1 * 3 * build_num;
  X[23].service = tmp2 * 3 * build_num;
  X[24].service = tmp3 * 3 * build_num;

  build_num++;
}
void build6() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;

  if (flag == 0) {
    tmp1 = X[26].service;
    tmp2 = X[27].service;
    tmp3 = X[29].service;
    flag = 1;
  }
  X[26].service = tmp1 * 3 * build_num;
  X[27].service = tmp2 * 3 * build_num;
  X[29].service = tmp3 * 3 * build_num;
  build_num++;
}
void build7() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2, tmp3;

  if (flag == 0) {
    tmp1 = X[31].service;
    tmp2 = X[32].service;
    tmp3 = X[34].service;
    flag = 1;
  }
  X[31].service = tmp1 * 3 * build_num;
  X[32].service = tmp2 * 3 * build_num;
  X[34].service = tmp2 * 3 * build_num;
  build_num++;
}
void build8() {
  int flag = 0;
  int build_num = 1;
  int tmp1, tmp2;

  if (flag == 0) {
    tmp1 = X[37].service;
    tmp2 = X[39].service;
    flag = 1;
  }
  X[37].service = tmp1 * 3 * build_num;
  X[39].service = tmp2 * 3 * build_num;
  build_num++;
}
