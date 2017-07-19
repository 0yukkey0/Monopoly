#define BOARD_NUM 40


typedef struct {
  char board_name[50];  //ボード名
  int board_flag;  // 0.GO 1.土地 2.チャンス 3.税金 4.刑務所 5.フリー
  int sale_flag;    //購入フラグ 0.未購入 1.購入済み
  int sale_player;  //購入者
  int sale_money;   //販売額
  int service;      //サービス料
  int sale_build;   //建設費
} BOARD_DATA;
 
BOARD_DATA X[BOARD_NUM];

void board_init(void);
int check_land(int map_n,int pn);
int judge_land();
void sale_land(int map_n, int pn) ;