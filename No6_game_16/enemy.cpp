/*******************************************************************************
* タイトル:		弾
* プログラム名:	enemy_1.cpp
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
#include "enemy.h"
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
//表示するタイルが違うからエネミーの変数を３つに分ける
OBJ enemy_1[ENEMY_MAX];//エネミー１の変数
OBJ enemy_2[ENEMY_MAX];//エネミー２の変数
OBJ enemy_3[ENEMY_MAX];//エネミー３の変数
int old_time;
int draw_time;
int enemy_1_score = 300;
int enemy_2_score = 200;
int enemy_3_score = 100;

short enemy_1_tf[ENEMY_MAX];//0はスリープ１はアクティブ
short enemy_2_tf[ENEMY_MAX];//0はスリープ１はアクティブ
short enemy_3_tf[ENEMY_MAX];//0はスリープ１はアクティブ
short g_enemy_1_tile[TILE_SIZE][TILE_SIZE] = {
		{0,5,0,0,0,},
		{5,5,0,0,0,},
		{0,5,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};
short g_enemy_2_tile[TILE_SIZE][TILE_SIZE] = {
		{0,6,0,0,0,},
		{6,6,0,0,0,},
		{0,6,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};
short g_enemy_3_tile[TILE_SIZE][TILE_SIZE] = {
		{0,7,0,0,0,},
		{7,7,0,0,0,},
		{0,7,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};





/*******************************************************************************
* 関数
*******************************************************************************/


void enemy_Init(void) {
	//エネミー１
	for (int no = 0; no < ENEMY_MAX; no++) {
		enemy_1_tf[no] = 1;//全てのenemy_1を表示するようにする
		for (int i = 0; i < TILE_SIZE; i++) {
			for (int j = 0; j < TILE_SIZE; j++) {
				enemy_1[no].tile[i][j] = g_enemy_1_tile[i][j];
			}
		}
		strcpy(enemy_1[no].name, "enemy_1");
		enemy_1[no].Position.x = 30;
		enemy_1[no].Position.y = (no * 3) + 1 + no;
	}
	//エネミー２
	for (int no = 0; no < ENEMY_MAX; no++) {
		enemy_2_tf[no] = 1;//全てのenemy_1を表示するようにする
		for (int i = 0; i < TILE_SIZE; i++) {
			for (int j = 0; j < TILE_SIZE; j++) {
				enemy_2[no].tile[i][j] = g_enemy_2_tile[i][j];
			}
		}
		strcpy(enemy_2[no].name, "enemy_2");
		enemy_2[no].Position.x = 25;
		enemy_2[no].Position.y = (no * 3) + 1 + no;
	}
	//エネミー３
	for (int no = 0; no < ENEMY_MAX; no++) {
		enemy_3_tf[no] = 1;//全てのenemy_1を表示するようにする
		for (int i = 0; i < TILE_SIZE; i++) {
			for (int j = 0; j < TILE_SIZE; j++) {
				enemy_3[no].tile[i][j] = g_enemy_3_tile[i][j];
			}
		}
		strcpy(enemy_3[no].name, "enemy_3");
		enemy_3[no].Position.x = 20;
		enemy_3[no].Position.y = (no * 3) + 1 + no;
	}
	enemy_Move();
	old_time = time(NULL);
}
void enemy_Uninit(void) {
}




void enemy_Update(void) {
	//エネミー１
	for (int no = 0; no <= ENEMY_MAX; no++) {
		if (enemy_1_tf[no] == 1) {
			//当たり判定
			POSITION temp_Position[3];//判定を行う場所の数
			for (short i = 0; i < 3; i++) {
				temp_Position[i].x = enemy_1[no].Position.x;
				temp_Position[i].y = enemy_1[no].Position.y + i;
				if (GetMap_Position(temp_Position[i]) == 3) {//弾の判定が３
					bullet_set(2);
					enemy_1_tf[no] = 0;
					minus_map(0, enemy_1[no]);
					SetScore(SCORE_PLUS, enemy_1_score + (enemy_1[no].Position.x - 30) * 5);
					break;
				}
			}
		}
		if (enemy_1[no].Position.x - 1 <= GAME_OVER) {
			enemy_1_tf[no] = 3;
			}

	}

	//エネミー２
	for (int no = 0; no <= ENEMY_MAX; no++) {
		if (enemy_2_tf[no] == 1) {
			//弾との当たり判定
			POSITION temp_Position[3];//判定を行う場所の数
			for (short i = 0; i < 3; i++) {
				temp_Position[i].x = enemy_2[no].Position.x;
				temp_Position[i].y = enemy_2[no].Position.y + i;
				if (GetMap_Position(temp_Position[i]) == 3) {//弾の判定が３
					bullet_set(2);
					enemy_2_tf[no] = 0;
					minus_map(0, enemy_2[no]);
					SetScore(SCORE_PLUS, enemy_2_score + (enemy_2[no].Position.x - 25) * 5);
					break;
				}
			}
		}
		if (enemy_2[no].Position.x - 1 <= GAME_OVER) {
			enemy_2_tf[no] = 3;
		}
	}
	//エネミー3
	for (int no = 0; no <= ENEMY_MAX; no++) {
		if (enemy_3_tf[no] == 1) {
			//弾との当たり判定
			POSITION temp_Position[3];//判定を行う場所の数
			for (short i = 0; i < 3; i++) {
				temp_Position[i].x = enemy_3[no].Position.x;
				temp_Position[i].y = enemy_3[no].Position.y + i;
				if (GetMap_Position(temp_Position[i]) == 3) {//弾の判定が３
					bullet_set(2);
					enemy_3_tf[no] = 0;
					minus_map(0, enemy_3[no]);
					SetScore(SCORE_PLUS, enemy_3_score + -((enemy_3[no].Position.x - 20) * 5));
					break;
				}
			}
		}
		if (enemy_3[no].Position.x - 1 == GAME_OVER) {
			enemy_3_tf[no] = 3;
		}
	}


	if (old_time == time(NULL) - 1) {
		//エネミー１
		for (int no = 0; no < ENEMY_MAX; no++) {
			if (enemy_1_tf[no] == 1) {

				if (GetEnemy_ud() == 'd') {
					old_time = time(NULL);
					enemy_1[no].Position.y++;
				}
				else {
					old_time = time(NULL);
					enemy_1[no].Position.y--;
				}
			}
		}

		//エネミー２
		for (int no = 0; no < ENEMY_MAX; no++) {
			if (enemy_2_tf[no] == 1) {

				if (GetEnemy_ud() == 'd') {
					old_time = time(NULL);
					enemy_2[no].Position.y++;
				}
				else {
					old_time = time(NULL);
					enemy_2[no].Position.y--;
				}
			}
		}
		//エネミー３
		for (int no = 0; no < ENEMY_MAX; no++) {
			if (enemy_3_tf[no] == 1) {

				if (GetEnemy_ud() == 'd') {
					old_time = time(NULL);
					enemy_3[no].Position.y++;
				}
				else {
					old_time = time(NULL);
					enemy_3[no].Position.y--;
				}
			}
		}
	}
	enemy_Move();
}






void enemy_Draw(void) {

}

/*******************************************************************************
* void enemy_Move()
* プレイヤーの移動制限
* プレイヤーが前に居た場所をdraw_tileに渡して、表示を消す
* プレイヤーの情報をdraw_tileに渡して、表示するようにする
*******************************************************************************/
void enemy_Move() {
	//エネミー１
	for (int no = 0; no < ENEMY_MAX; no++) {
		if (enemy_1_tf[no] == 1) {
			if (enemy_1[no].Position.y < 1) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_1[no1].Position.y += 1;
					enemy_1[no1].Position.x--;
					//
					enemy_2[no1].Position.y += 1;
					enemy_2[no1].Position.x--;
					//
					enemy_3[no1].Position.y += 1;
					enemy_3[no1].Position.x--;
				}
				SetEnemy_ud('d');
			}
			else if (enemy_1[no].Position.y > DISP_H - 3) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_1[no1].Position.y -= 1;
					enemy_1[no1].Position.x--;
					//
					enemy_2[no1].Position.y -= 1;
					enemy_2[no1].Position.x--;
					//
					enemy_3[no1].Position.y -= 1;
					enemy_3[no1].Position.x--;

				}
				SetEnemy_ud('u');
			}
			if (enemy_1[no].Position.x < 0) {
				enemy_1[no].Position.x = 0;
			}
			else if (enemy_1[no].Position.x > DISP_W / 2) {
				enemy_1[no].Position.x = DISP_W / 2 - 1;
			}

			if (enemy_1[no].old_Position.x != enemy_1[no].Position.x || enemy_1[no].old_Position.y != enemy_1[no].Position.y) {
				minus_map(0, enemy_1[no]);
			}

			plus_map(enemy_1[no]);

			enemy_1[no].old_Position.x = enemy_1[no].Position.x;
			enemy_1[no].old_Position.y = enemy_1[no].Position.y;
		}
	}

	//エネミー２
	for (int no = 0; no < ENEMY_MAX; no++) {
		if (enemy_2_tf[no] == 1) {
			if (enemy_2[no].Position.y < 1) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_2[no1].Position.y += 1;
					enemy_2[no1].Position.x--;
					//
					enemy_1[no1].Position.y += 1;
					enemy_1[no1].Position.x--;
				}
				SetEnemy_ud('d');
			}
			else if (enemy_2[no].Position.y > DISP_H - 3) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_2[no1].Position.y -= 1;
					enemy_2[no1].Position.x--;
					//
					enemy_1[no1].Position.y -= 1;
					enemy_1[no1].Position.x--;

				}
				SetEnemy_ud('u');
			}
			if (enemy_2[no].Position.x < 0) {
				enemy_2[no].Position.x = 0;
			}
			else if (enemy_2[no].Position.x > DISP_W / 2) {
				enemy_2[no].Position.x = DISP_W / 2 - 1;
			}

			if (enemy_2[no].old_Position.x != enemy_2[no].Position.x || enemy_2[no].old_Position.y != enemy_2[no].Position.y) {
				minus_map(0, enemy_2[no]);
			}

			plus_map(enemy_2[no]);

			enemy_2[no].old_Position.x = enemy_2[no].Position.x;
			enemy_2[no].old_Position.y = enemy_2[no].Position.y;
		}
	}
	//エネミー３
	for (int no = 0; no < ENEMY_MAX; no++) {
		if (enemy_3_tf[no] == 1) {
			if (enemy_3[no].Position.y < 1) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_3[no1].Position.y += 1;
					enemy_3[no1].Position.x--;
					//
					enemy_1[no1].Position.y += 1;
					enemy_1[no1].Position.x--;
					//
					enemy_2[no1].Position.y += 1;
					enemy_2[no1].Position.x--;

				}
				SetEnemy_ud('d');
			}
			else if (enemy_3[no].Position.y > DISP_H - 3) {
				for (int no1 = 0; no1 < ENEMY_MAX; no1++) {
					enemy_3[no1].Position.y -= 1;
					enemy_3[no1].Position.x--;
					//
					enemy_1[no1].Position.y -= 1;
					enemy_1[no1].Position.x--;
					//
					enemy_2[no1].Position.y -= 1;
					enemy_2[no1].Position.x--;


				}
				SetEnemy_ud('u');
			}
			if (enemy_3[no].Position.x < 0) {
				enemy_3[no].Position.x = 0;
			}
			else if (enemy_3[no].Position.x > DISP_W / 2) {
				enemy_3[no].Position.x = DISP_W / 2 - 1;
			}

			if (enemy_3[no].old_Position.x != enemy_3[no].Position.x || enemy_3[no].old_Position.y != enemy_3[no].Position.y) {
				minus_map(0, enemy_3[no]);
			}

			plus_map(enemy_3[no]);

			enemy_3[no].old_Position.x = enemy_3[no].Position.x;
			enemy_3[no].old_Position.y = enemy_3[no].Position.y;
		}
	}
}

short* GetEnemy1() {
	return enemy_1_tf;
}
short* GetEnemy2() {
	return enemy_2_tf;
}
short* GetEnemy3() {
	return enemy_3_tf;
}