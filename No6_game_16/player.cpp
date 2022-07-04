/*******************************************************************************
* �^�C�g��:		�v���C���[
* �v���O������:	player.cpp
* �쐬��:		GP11B132 16 �|������
* �쐬��:		2022/06/10
*******************************************************************************/

/*******************************************************************************
* scanf ��warning�h�~
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"

#include "draw_tile.h"
#include "player.h"
#include "bullet.h"
/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
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
	if (_kbhit() == 0){ // Key���͂��Ȃ��H
		// Key���͂��Ȃ����炱���Ń��^�[������
		Sleep(1);
		player_Move();
		return;
	}


	// �L�[���͑҂�
	
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
* �v���C���[�̈ړ�����
* �v���C���[���O�ɋ����ꏊ��draw_tile�ɓn���āA�\��������
* �v���C���[�̏���draw_tile�ɓn���āA�\������悤�ɂ���
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