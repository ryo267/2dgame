#include "DxLib.h"
#include "Header.h"


//ƒQ[ƒ€ƒNƒŠƒA‰æ–Ê
int gameClear() {
	DrawStringToHandle(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.5, "GAME CLEAR", GetColor(255, 255, 255), fonthundle);
	
	if (Key[KEY_INPUT_SPACE] == 1) return 1;    //SPACE‚ª‰Ÿ‚³‚ê‚½‚çTRUE
	return 0;   //SPACE‚ª‰Ÿ‚³‚ê‚È‚¯‚ê‚ÎFALSE
}