#include "DxLib.h"
#include "Header.h"

int img_gameover;

//�Q�[���I�[�o�[���
int gameOver() {
	DrawGraph(0, 0, img_gameover, TRUE);
	DrawStringToHandle(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.75, "Please Push SPACE", GetColor(255, 255, 255), fonthundle);

	if (Key[KEY_INPUT_SPACE] == 1) return 1;    //SPACE�������ꂽ��TRUE
	return 0;   //SPACE��������Ȃ����FALSE
}