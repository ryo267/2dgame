#include "DxLib.h"
#include "player.h"
#include "Header.h"
#include "map.h"
#include "enemy.h"

int db = 0;

void debug() {
	DrawFormatString(0, 0, GetColor(0, 255, 0), "エリア1=keyX");
	DrawFormatString(0, 30, GetColor(0, 255, 0), "エリア2=keyC");
	DrawFormatString(0, 60, GetColor(0, 255, 0), "エリア3=keyA");
	DrawFormatString(0, 90, GetColor(0, 255, 0), "エリア4=keyS");
	DrawFormatString(0, 120, GetColor(0, 255, 0), "エリア5=keyD");
	
	if ((Input & PAD_INPUT_2) != 0) {
		player.x = warpPoint_x[0];
		player.y = warpPoint_y[0];
	}
	if ((Input & PAD_INPUT_3) != 0) {
		player.x = warpPoint_x[1];
		player.y = warpPoint_y[1];
	}
	if ((Input & PAD_INPUT_4) != 0) {
		player.x = warpPoint_x[2];
		player.y = warpPoint_y[2];
	}
	if ((Input & PAD_INPUT_5) != 0) {
		player.x = warpPoint_x[3];
		player.y = warpPoint_y[3];
	}
	if ((Input & PAD_INPUT_6) != 0) {
		player.x = warpPoint_x[4];
		player.y = warpPoint_y[4];
	}
	player.hp = player.HP_MAX;
	player.mp = player.MP_MAX;
}

int debugOn() {
	if (db == 1) {
		if (Key[KEY_INPUT_RETURN] == 1) {
				db = 0;
				return 0;
		}
		return 1;
	}
	else {
		if (Key[KEY_INPUT_RETURN] == 1) {
				db = 1;
				return 1;
		}
	}
	return 0;
}