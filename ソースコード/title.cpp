#include "DxLib.h"
#include "Header.h"

int img_title;

//ƒ^ƒCƒgƒ‹‰æ–Ê
int gameTitle() {
		DrawGraph(0, 0, img_title, TRUE);
		DrawStringToHandle(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.75, "Please Push Enter", GetColor(255, 255, 255), fonthundle);
		
		if (Key[KEY_INPUT_RETURN] == 1) return 1;    //Enter‚ª‰Ÿ‚³‚ê‚½‚çTRUE
		return 0;   //Enter‚ª‰Ÿ‚³‚ê‚È‚¯‚ê‚ÎFALSE
}