/*******************************************************************************
* タイトル:		ゲームマネージャー
* プログラム名:	GM.h
* 作成者:		GP11B132 16 竹内大翔
* 作成日:		2022/06/10
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS


/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define		TILE_SIZE		(5)
#define		ENEMY_MAX		(5)


enum {
	GAME_TITLE,

	GAME_MODE,

	GAME_RESULT,

	GAME_END,

};

enum {
	SCORE_PLUS,

	SCORE_MINUS,

	SCORE_ZERO,
};

#define		DISP_H		(24)	// 表示画面の縦サイズ
#define		DISP_W		(80)	// 表示画面の横サイズ

#define		GAME_OVER	(3)     //ゲームオーバーラインの値（ｘ）

/*******************************************************************************
* 構造体定義
*******************************************************************************/
struct POSITION
{
	short x=6;
	short y=6;
};
struct OBJ
{
	POSITION Position;
	POSITION old_Position;
	short tile[TILE_SIZE][TILE_SIZE]
	{
		{1,1,1,1,1,},
		{1,1,1,1,1,},
		{1,1,1,1,1,},
		{1,1,1,1,1,},
		{1,1,1,1,1,},
	};
	short tf = 1;
	char name[256];
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
int  GetMode(void);
void SetMode(int mode);

int  GetScore(void);
void SetScore(short mode,int Score);

char GetEnemy_ud(void);
void SetEnemy_ud(char enemy);

void GM_Update(void);