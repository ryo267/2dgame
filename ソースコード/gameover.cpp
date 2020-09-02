#include "DxLib.h"
#include "Header.h"

int img_gameover;

//ゲームオーバー画面
int gameOver() {
	DrawGraph(0, 0, img_gameover, TRUE);
	DrawStringToHandle(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.75, "Please Push SPACE", GetColor(255, 255, 255), fonthundle);

	if (Key[KEY_INPUT_SPACE] == 1) return 1;    //SPACEが押されたらTRUE
	return 0;   //SPACEが押されなければFALSE
}