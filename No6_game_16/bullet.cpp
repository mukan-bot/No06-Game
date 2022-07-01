/*******************************************************************************
* �^�C�g��:		�e
* �v���O������:	bullet.cpp
* �쐬��:		GP11B132 16 �|������
* �쐬��:		2022/06/12
*******************************************************************************/

/*******************************************************************************
* scanf ��warning�h�~
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "draw_tile.h"
#include "bullet.h"
#include "player.h"


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
OBJ bullet;     //�e�p
OBJ* player_ad; //bulletInit�Ńv���C���[�̏�������
short bullet_tf = 0;//0�̓X���[�v�P�̓A�N�e�B�u
short g_bullet_tile[TILE_SIZE][TILE_SIZE] = {
		{0,0,0,0,0,},
		{0,0,4,3,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
		{0,0,0,0,0,},
};

/*******************************************************************************
* �֐�
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


void bullet_set(short tf){//�o���b�g�̗L����
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
* �v���C���[�̈ړ�����
* �v���C���[���O�ɋ����ꏊ��draw_tile�ɓn���āA�\��������
* �v���C���[�̏���draw_tile�ɓn���āA�\������悤�ɂ���
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
