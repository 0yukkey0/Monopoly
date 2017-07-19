#define
CC = gcc
LDLIBS=-lncursesw
#
#test.exe : monopoly.c  draw.c player.c board.c draw_name.c player_map_draw.c player_map_clear.c move_player.c cheak_monopoly.c build.c cheak_i.c build_i.c chance_card.c cheak_get_build.c help.c game_system.c cheak_win_lose.c build_all.c draw_color.c draw_menu.c draw_board.c
#	$(CC) -o test.exe monopoly.c draw.c player.c board.c draw_name.c player_map_draw.c player_map_clear.c move_player.c cheak_monopoly.c build.c cheak_i.c build_i.c chance_card.c cheak_get_build.c help.c game_system.c cheak_win_lose.c build_all.c draw_color.c draw_menu.c draw_board.c $(LDLIBS)
monopoly: monopoly.o draw.o player.o
	$(CC) -o monopoly.exe monopoly.o draw.o player.o board.o draw_name.o player_map_draw.o player_map_clear.o move_player.o cheak_monopoly.o build.o cheak_i.o build_i.o chance_card.o cheak_get_build.o help.o game_system.o cheak_win_lose.o build_all.o draw_color.o draw_menu.o draw_board.o draw_sale_money.o $(LDLIBS)
monopoly.o: monopoly.c help.c game_system.c cheak_win_lose.c board.c
	gcc -c monopoly.c help.c game_system.c cheak_win_lose.c board.c $(LDLIBS)
draw.o: draw.c draw_color.c draw_menu.c draw_board.c draw_name.c player_map_draw.c player_map_clear.c draw_sale_money.c
	gcc -c draw.c draw_color.c draw_menu.c draw_board.c draw_name.c player_map_draw.c player_map_clear.c draw_sale_money.c $(LDLIBS)
player.o: player.c move_player.c cheak_monopoly.c build.c cheak_i.c build_i.c chance_card.c cheak_get_build.c build_all.c 
	gcc -c player.c move_player.c cheak_monopoly.c build.c cheak_i.c build_i.c chance_card.c cheak_get_build.c build_all.c $(LDLIBS)
clean:
	rm monopoly.o draw.o player.o board.o draw_name.o player_map_draw.o player_map_clear.o move_player.o cheak_monopoly.o build.o cheak_i.o build_i.o chance_card.o cheak_get_build.o help.o game_system.o cheak_win_lose.o build_all.o draw_color.o draw_menu.o draw_board.o draw_sale_money.o