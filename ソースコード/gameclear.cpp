#include "DxLib.h"
#include "Header.h"


//ゲームクリア画面
int gameClear() {
	DrawStringToHandle(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.5, "GAME CLEAR", GetColor(255, 255, 255), fonthundle);
	
	if (Key[KEY_INPUT_SPACE] == 1) return 1;    //SPACEが押されたらTRUE
	return 0;   //SPACEが押されなければFALSE
}