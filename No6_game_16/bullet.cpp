/*******************************************************************************
* タイトル:		弾
* プログラム名:	bullet.cpp
* 作成者:		GP11B132 16 竹内大翔
* 作成日:		2022/06/12
*******************************************************************************/

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "draw_tile.h"
#include "bullet.h"
#include "player.h"


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
OBJ bullet;     //弾用
OBJ* player_ad; //bulletInitでプレイヤーの情報を入れて
short bullet_tf = 0;//0はスリープ１はアクティブ
short g_bullet_tile[TILE_SIZE][TILE_SIZE] = {
		{0,0,0,0,0,},
		{0,0,4,3,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};

/*******************************************************************************
* 関数
www*******************************************************************************/


void bullet_Init(void) {
	player_ad = GetPlayer();
	for (int i = 0; i < TILE_SIZE; i++) {
		for (int j = 0; j < TILE_SIZE; j++) {
			bullet.tile[i][j] = g_bullet_tile[i][j];
		}
	}
	strcpy(bullet.name, "bullet");

}
void bullet_Uninit(void) {
}


void bullet_set(short tf){//バレットの有効化
	bullet_tf = tf;
}

void bullet_Update(void) {
	if (bullet_tf == 1) {
		bullet.Position.x++;
		bullet_Move();
	}
	else if(bullet_tf == 0) {
		player_ad = GetPlayer();
		bullet.Position = player_ad->Position;
		
	}
	else {
		minus_map(0, bullet);
		bullet_tf = 0;
	}

}
void bullet_Draw(void) {
}

/*******************************************************************************
* void bullet_Move()
* プレイヤーの移動制限
* プレイヤーが前に居た場所をdraw_tileに渡して、表示を消す
* プレイヤーの情報をdraw_tileに渡して、表示するようにする
*******************************************************************************/
void bullet_Move() {
	if (bullet.Position.y < 0) {
		bullet.Position.y = 0;
	}
	else if (bullet.Position.y > DISP_H - 3) {
		bullet.Position.y = DISP_H - 3;
	}
	if (bullet.Position.x < 0) {
		bullet.Position.x = 0;
	}
	else if (bullet.Position.x > DISP_W / 2) {
		bullet.Position.x = DISP_W / 2 - 1;
		bullet_tf = 0;
		minus_map(0, bullet);
	}
	if (bullet.old_Position.x != bullet.Position.x || bullet.old_Position.y != bullet.Position.y) {
		minus_map(0, bullet);
	}

	plus_map(bullet);

	bullet.old_Position.x = bullet.Position.x;
	bullet.old_Position.y = bullet.Position.y;
}
