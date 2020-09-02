#include "DxLib.h"
#include "Header.h"
#include "enemy.h"
#include "player.h"

//Õ“Ë”»’è
int enemyCollisionCheck()
{
	for (int i = 0; i < enemy_max; i++)
	{
		if (enemy[i].flag == 1) {

			if (att.att_DamegeFlag == 1 && enemy[i].draw_x < att.att_x + att.Graphic_X_size && att.att_x + att.Graphic_X_size < enemy[i].draw_x + enemy[i].Graphic_X_size
				&& enemy[i].draw_y < att.att_y + att.Graphic_Y_size*0.5 && att.att_y + att.Graphic_Y_size*0.5 < enemy[i].draw_y + enemy[i].Graphic_Y_size)
			{
				enemy[i].hp -= att.att_power;
				DrawFormatString(enemy[i].draw_x + enemy[i].Graphic_X_size, enemy[i].draw_y, GetColor(0, 0, 255), "%d", att.att_power);
				if (enemy[i].hp < 0)
				{
					enemy[i].hp = 0;
					enemy[i].flag = 0;
					if (enemy[i].Graphic == BOSS) {
						player.flag = 0;
						return 1;
					}
				}
			}
			else if (att.att_DamegeFlag == 1 && enemy[i].draw_x < att.att_x  && att.att_x < enemy[i].draw_x + enemy[i].Graphic_X_size
				&& enemy[i].draw_y < att.att_y + att.Graphic_Y_size*0.5 && att.att_y + att.Graphic_Y_size*0.5 < enemy[i].draw_y + enemy[i].Graphic_Y_size)
			{
				enemy[i].hp -= att.att_power;
				DrawFormatString(enemy[i].draw_x + enemy[i].Graphic_X_size, enemy[i].draw_y, GetColor(0, 0, 255), "%d", att.att_power);
				if (enemy[i].hp < 0)
				{
					enemy[i].hp = 0;
					enemy[i].flag = 0;
					if (enemy[i].Graphic == BOSS) {
						player.flag = 0;
						return 1;
					}
				}
			}

			if (att.att_DamegeFlag == 1 && att.eff_x < enemy[i].draw_x + enemy[i].Graphic_X_size && enemy[i].draw_x + enemy[i].Graphic_X_size < att.eff_x + att.eff_Graphic_X_size
				&& att.eff_y < enemy[i].draw_y + enemy[i].Graphic_Y_size*0.5 && enemy[i].draw_y + enemy[i].Graphic_Y_size*0.5 < att.eff_y + att.eff_Graphic_Y_size)
			{
				enemy[i].hp -= att.att_power;
				DrawFormatString(enemy[i].draw_x, enemy[i].draw_y, GetColor(0, 0, 255), "%d", att.att_power);
				if (enemy[i].hp < 0)
				{
					enemy[i].hp = 0;
					enemy[i].flag = 0;
					if (enemy[i].Graphic == BOSS) {
						player.flag = 0;
						return 1;
					}
				}
			}
			else if (att.att_DamegeFlag == 1 && att.eff_x < enemy[i].draw_x && enemy[i].draw_x < att.eff_x + att.eff_Graphic_X_size
				&& att.eff_y < enemy[i].draw_y + enemy[i].Graphic_Y_size*0.5 && enemy[i].draw_y + enemy[i].Graphic_Y_size*0.5 < att.eff_y + att.eff_Graphic_Y_size)
			{
				enemy[i].hp -= att.att_power;
				DrawFormatString(enemy[i].draw_x, enemy[i].draw_y, GetColor(0, 0, 255), "%d", att.att_power);
				if (enemy[i].hp < 0)
				{
					enemy[i].hp = 0;
					enemy[i].flag = 0;
					if (enemy[i].Graphic == BOSS) {
						player.flag = 0;
						return 1;
					}
				}
			}
	
		}
	}
	return 0;
}


int playerCollisionCheck() {
	for (int i = 0; i < enemy_max; i++)
	{
		if (enemy[i].flag == 1) {

			if (enemy[i].Graphic != BOSS) {
				if (att.att_flag == 0 && enemy[i].draw_x < player.draw_x + player.Graphic_X_size && player.draw_x + player.Graphic_X_size < enemy[i].draw_x + enemy[i].Graphic_X_size
					&& enemy[i].draw_y < player.draw_y + player.Graphic_Y_size*0.5 && player.draw_y + player.Graphic_Y_size*0.5 < enemy[i].draw_y + enemy[i].Graphic_Y_size)
				{
					player.x -= 5;
					player.hp -= 10;
					DrawFormatString(player.draw_x + player.Graphic_X_size, player.draw_y, GetColor(255, 0, 0), "10");
					if (player.hp < 0)
					{
						player.hp = 0;
						player.flag = 0;
						return 1;
					}

				}
				else if (att.att_flag == 0 && enemy[i].draw_x < player.draw_x  && player.draw_x < enemy[i].draw_x + enemy[i].Graphic_X_size
					&& enemy[i].draw_y < player.draw_y + player.Graphic_Y_size*0.5 && player.draw_y + player.Graphic_Y_size*0.5 < enemy[i].draw_y + enemy[i].Graphic_Y_size)
				{
					player.x += 5;
					player.hp -= 10;
					DrawFormatString(player.draw_x + player.Graphic_X_size, player.draw_y, GetColor(255, 0, 0), "10");
					if (player.hp < 0)
					{
						player.hp = 0;
						player.flag = 0;
						return 1;
					}
				}
			}

			if (enemy[i].eff_flag == 1 &&
				(enemy[i].eff_draw_x < (player.draw_x + player.Graphic_X_size)) &&
				((player.draw_x + player.Graphic_X_size) < (enemy[i].eff_draw_x + enemy[i].eff_Graphic_X_size)) &&
				enemy[i].eff_draw_y < player.draw_y + player.Graphic_Y_size*0.5 &&
				player.draw_y + player.Graphic_Y_size*0.5 < enemy[i].eff_draw_y + enemy[i].eff_Graphic_Y_size
				)
			{
				player.hp -= enemy[i].powor;
				DrawFormatString(player.draw_x + player.Graphic_X_size, player.draw_y, GetColor(255, 0, 0), "%d", enemy[i].powor);
				if (player.hp < 0)
				{
					player.hp = 0;
					player.flag = 0;
					return 1;
				}

			}

			else if (enemy[i].eff_flag == 1 &&
				enemy[i].eff_draw_x < player.draw_x  &&
				player.draw_x  < enemy[i].eff_draw_x + enemy[i].eff_Graphic_X_size &&
				enemy[i].eff_draw_y < player.draw_y + player.Graphic_Y_size*0.5 &&
				player.draw_y + player.Graphic_Y_size*0.5 < enemy[i].eff_draw_y + enemy[i].eff_Graphic_Y_size)
			{
				player.hp -= enemy[i].powor;
				DrawFormatString(player.draw_x + player.Graphic_X_size, player.draw_y, GetColor(255, 0, 0), "%d", enemy[i].powor);
				if (player.hp < 0)
				{
					player.hp = 0;
					player.flag = 0;
					return 1;
				}
			}

		}
	}
	return 0;
}
