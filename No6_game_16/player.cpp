/*******************************************************************************
* タイトル:		プレイヤー
* プログラム名:	player.cpp
* 作成者:		GP11B132 16 竹内大翔
* 作成日:		2022/06/10
*******************************************************************************/

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"

#include "draw_tile.h"
#include "player.h"
#include "bullet.h"
/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/
OBJ player;
short g_player_tile[TILE_SIZE][TILE_SIZE] = {
		{2,0,0,0,0,},
		{2,2,0,0,0,},
		{2,0,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};





void player_Init(void) {
	for (int i = 0; i < TILE_SIZE; i++) {
		for (int j = 0; j < TILE_SIZE; j++) {
			player.tile[i][j] = g_player_tile[i][j];
		}
	}
	strcpy(player.name, "player");
	player.Position.x = 1;
	player.Position.y = 10;
	player_Move();
}
void player_Uninit(void) {
}
void player_Update(void) {
	if (_kbhit() == 0){ // Key入力がない？
		// Key入力がないからここでリターンする
		Sleep(1);
		player_Move();
		return;
	}


	// キー入力待ち
	
	int key = _getch();
	if (key == 119) {
		player.Position.y--;
	}
	else if (key == 115){
		player.Position.y++;
	}
	else if (key == 32) {
		bullet_set(1);
	}
	
	player_Move();

}
void player_Draw(void) {
}

/*******************************************************************************
* void player_Move()
* プレイヤーの移動制限
* プレイヤーが前に居た場所をdraw_tileに渡して、表示を消す
* プレイヤーの情報をdraw_tileに渡して、表示するようにする
*******************************************************************************/
void player_Move() {
	if (player.Position.y < 1) {
		player.Position.y = 1;
	}
	else if (player.Position.y > DISP_H-3) {
		player.Position.y = DISP_H - 3;
	}
	if (player.Position.x < 0) {
		player.Position.x = 0;
	}
	else if (player.Position.x > DISP_W / 2) {
		player.Position.x = DISP_W / 2 - 1;
	}
	if (player.old_Position.x != player.Position.x || player.old_Position.y != player.Position.y) {
		minus_map(0, player);
	}
	
	plus_map(player);

	player.old_Position.x = player.Position.x;
	player.old_Position.y = player.Position.y;
}


OBJ* GetPlayer() {
	return &player;
}