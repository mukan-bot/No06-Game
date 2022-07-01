#pragma once
/*******************************************************************************
* タイトル:		弾
* プログラム名:	enemy_1.h
* 作成者:		GP11B132 16 竹内大翔
* 作成日:		2022/06/12
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "GM.h"


/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void enemy_Init(void);
void enemy_Uninit(void);
void enemy_Update(void);
void enemy_Draw(void);

void enemy_Move(void);

short* GetEnemy1();
short* GetEnemy2();
short* GetEnemy3();