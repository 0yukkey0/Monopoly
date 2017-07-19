#include "help.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

void help(int *x, int *y) {
  char *fname = "help.txt";
  char s[100];
  //int ch;
  FILE *fp;
  int i = 0;
  int key;
  clear();
  attron(COLOR_PAIR(12));

  if ((fp = fopen("help.txt", "r")) == NULL) {
    fprintf(stderr, "txtがファイルがありません。\n");
    exit(0);
    endwin();
  }
  move(i, 0);

while (fscanf(fp,"%s",s) != EOF) {
    
    mvprintw(i,0,"%s",s);
    refresh();
	i = i+2;
  }

  if ((key = getch()) == 'q') {
    fclose(fp);
    return;
  }
}
