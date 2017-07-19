#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "draw.h"
#include "player.h"
#include "cheak_monopoly.h"
#include "cheak_i.h"

void cheak_monopoly(int pn,int *x,int *y) {
  cheak_1(&pn);
  retextbox(x,y);
    cheak_2(&pn);
  retextbox(x,y);
    cheak_3(&pn);
  retextbox(x,y);
    cheak_4(&pn);
  retextbox(x,y);
    cheak_5(&pn);
  retextbox(x,y);
    cheak_6(&pn);
  retextbox(x,y);
    cheak_7(&pn);
  retextbox(x,y);
    cheak_8(&pn);
  retextbox(x,y);
}