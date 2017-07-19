
#define PLAYER_NUM 2

typedef struct {
  int player_number;  //プレイヤー番合
  int player_money;   //所持金
  int player_map; //プレーヤー位置
  int player_kflag;  //刑務所フラグ
  int player_knum; //監獄ターン数
} PLAYER_DATA;

PLAYER_DATA p[PLAYER_NUM];

void data_init(void);
void call_player(int *xsize, int *ysize,int n) ;
int dice(int *xsize, int *ysize,int *zf);
int redice(int *xsize, int *ysize, int *zf,int *fn);
void addmap(int pn, int dn);
void move_prison(int pn);
void call_now_board(int *xsize,int *ysize,int pn);
void add_money(int money,int pn);
void sub_money(int money,int pn);