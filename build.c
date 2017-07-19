#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "build.h"
#include "build_i.h"


void build(int i) {
  draw_massage("増築されました。", 7);
  draw_massage("増築前の料金の3倍になります。", 8);
  key_enter();
  switch (i) {
    case 1:
      build1();
      break;
    case 2:
      build2();
      break;
    case 3:
      build3();
      break;
    case 4:
      build4();
      break;
    case 5:
      build5();
      break;
    case 6:
      build6();
      break;
    case 7:
      build7();
      break;
    case 8:
      build8();
      break;
  }
}