#include "DxLib.h"
#include "camera.h"
#include "Header.h"
#include "enemy.h"
#include "map.h"
#include "player.h"

//スクロールフラグを倒す;
int ScrollFlag = 0;
float camerax = 0;
float cameray = 0;

//カメラスクロール
void MoveCamera()
{
	//カメラ位置を計算
	camerax = player.x - SCREEN_WIDTH / 2;
	cameray = player.y - SCREEN_HEIGHT *0.8;

	//左右の補正
	if (camerax < 0) {
		camerax = 0;
		ScrollFlag = 0;
	}
	if(cameray < 0 ){
		cameray = 0;
		ScrollFlag = 0;
	}
	else
	{
		ScrollFlag = 1;
	}

	if (camerax >(MAP_PIXEL_WIDTH - SCREEN_WIDTH)) {
		camerax = (MAP_PIXEL_WIDTH - SCREEN_WIDTH);
		ScrollFlag = 0;
	}
	else if (cameray >(MAP_PIXEL_HEIGHT - SCREEN_HEIGHT)) {
		cameray = (MAP_PIXEL_HEIGHT - SCREEN_HEIGHT);
		ScrollFlag = 0;
	}


	//画面内の位置を求める。
	player.draw_x = player.x - camerax;
	player.draw_y = player.y - cameray;

	for (int i = 0; i < enemy_max; i++)
	{
		enemy[i].draw_x = enemy[i].x - camerax;
		enemy[i].eff_draw_x = enemy[i].eff_x - camerax;
		enemy[i].draw_y = enemy[i].y - cameray;
		enemy[i].eff_draw_y = enemy[i].eff_y - cameray;
	}

}