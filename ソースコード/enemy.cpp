#include "Header.h"
#include "enemy.h"
#include "map.h"
#include "DxLib.h"
#include "player.h"
#include "camera.h"

const int enemy_max = 60;

ENEMYDATA enemy[enemy_max] = { 0 };

int img_enemy_keru_size = 0;
int img_enemy_keru_Attack_size = 0;
int img_enemy_keru_Attack_effect_size = 0;
int img_enemy_mado_size = 0;
int img_enemy_kyoji_size = 0;
int img_enemy_kyoji_Attack_size = 0;
int img_enemy_kyoji_Attack_effect_size = 0;
int img_enemy_kyoji_red_size = 0;
int img_enemy_kyoji_red_Attack_size = 0;
int img_enemy_totem_Attack_effect_size = 0;
int img_enemy_boss_size = 0;
int img_enemy_boss_Attack_effect_size = 0;
int img_enemy_totem_Attack_effect[31] = { 0 };
int img_enemy_keru[8] = { 0 };
int img_enemy_keru_Attack[6] = { 0 };
int img_enemy_keru_Attack_effect[6] = { 0 };
int img_enemy_mado[8] = { 0 };
int img_enemy_kyoji[8] = { 0 };
int img_enemy_kyoji_Attack[10] = { 0 };
int img_enemy_kyoji_Attack_effect[6] = { 0 };
int img_enemy_kyoji_red[8] = { 0 };
int img_enemy_kyoji_red_Attack[10] = { 0 };
int img_enemy_eff_mado_fire = 0;
int img_enemy_totem = 0;
int img_enemy_boss[14] = { 0 };
int img_enemy_boss2[14] = { 0 };
int img_enemy_boss_Attack_effect[10] = { 0 };
int StartTime = 0;
int Time = 0;

//敵の初期化
void enemyInit() {
	int i, j;
	float EnX, EnY;
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			EnX = (float)j*CHIP_SIZE;
			EnY = (float)i*CHIP_SIZE;

			if (MapData[i][j] == 2) 
			{
				EnemyCalc(2, EnX, EnY);
			}
			else if (MapData[i][j] == 3)
			{
				EnemyCalc(3, EnX, EnY);
			}
			else if (MapData[i][j] == 4)
			{
				EnemyCalc(4, EnX, EnY);
			}
			else if (MapData[i][j] == 5)
			{
				EnemyCalc(5, EnX, EnY);
			}

			else if (MapData[i][j] == 66)
			{
				EnemyCalc(赤巨人, EnX, EnY);
			}
			else if (MapData[i][j] == 67)
			{
				EnemyCalc(赤巨人, EnX, EnY, 1);
			}
			else if (MapData[i][j] == 70)
			{
				EnemyCalc(BOSS, EnX, EnY, 1);
			}
			else if (MapData[i][j] == 78)
			{
				EnemyCalc(ケルベロス, EnX, EnY, 1);
			}
			else if (MapData[i][j] == 79)
			{
				EnemyCalc(魔導士, EnX, EnY, 1);
			}
			
		}
	}
}

//敵の初期化
void EnemyCalc(int i, float EnX, float EnY, int direcflag)
{
	int j;
	for (j = 0; j < enemy_max; j++) {
		if (enemy[j].flag == 0) {
			break;
		}
	}
	switch (i) {
	case 2:
		enemy[j].flag = 1;
		enemy[j].Graphic = 2;
		enemy[j].Graphic_X_size = 85;
		enemy[j].Graphic_Y_size = 60;
		enemy[j].Graphic_size = img_enemy_keru_size / 2;
		enemy[j].Graphic_count = img_enemy_keru_size * 10;
		enemy[j].a_Graphic = 2;
		enemy[j].m_pattern = 2;
		enemy[j].a_pattern = 2;
		enemy[j].hp = 80;
		enemy[j].powor = 20;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = G;
		enemy[j].flame = 0;
		enemy[j].direcFlag = direcflag;
		enemy[j].AttackFlag = 0;
		break;

	case 3:
		enemy[j].flag = 1;
		enemy[j].Graphic = 3;
		enemy[j].Graphic_X_size = 32;
		enemy[j].Graphic_Y_size = 32;
		enemy[j].Graphic_size = img_enemy_mado_size;
		enemy[j].Graphic_count = enemy[j].Graphic_size * 30;
		enemy[j].a_Graphic = 3;
		enemy[j].m_pattern = 3;
		enemy[j].a_pattern = 3;
		enemy[j].hp = 50;
		enemy[j].powor = 30;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = G;
		enemy[j].flame = 0;
		enemy[j].direcFlag = direcflag;
		enemy[j].AttackFlag = 0;
		break;

	case 4:
		enemy[j].flag = 1;
		enemy[j].Graphic = 4;
		enemy[j].Graphic_X_size = 60;
		enemy[j].Graphic_Y_size = 90;
		enemy[j].Graphic_size = img_enemy_kyoji_size / 2;
		enemy[j].Graphic_count = img_enemy_kyoji_size * 40;
		enemy[j].a_Graphic = 4;
		enemy[j].m_pattern = 4;
		enemy[j].a_pattern = 4;
		enemy[j].hp = 120;
		enemy[j].powor = 40;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = G;
		enemy[j].flame = 0;
		enemy[j].direcFlag = direcflag;
		enemy[j].AttackFlag = 0;
		break;

	case 5:
		enemy[j].flag = 1;
		enemy[j].Graphic = 5;
		enemy[j].Graphic_X_size = 32;
		enemy[j].Graphic_Y_size = 32;
		enemy[j].Graphic_size = 1;
		enemy[j].Graphic_count = 1;
		enemy[j].a_Graphic = 5;
		enemy[j].m_pattern = 5;
		enemy[j].a_pattern = 5;
		enemy[j].hp = INT_MAX;
		enemy[j].powor = 30;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = 0;
		enemy[j].flame = 0;
		enemy[j].item = 5;
		enemy[j].direcFlag = 0;
		enemy[j].AttackFlag = 0;
		break;

	case 赤巨人:
		enemy[j].flag = 1;
		enemy[j].Graphic = 赤巨人;
		enemy[j].Graphic_X_size = 120;
		enemy[j].Graphic_Y_size = 180;
		enemy[j].Graphic_size = img_enemy_kyoji_red_size / 2;
		enemy[j].Graphic_count = img_enemy_kyoji_red_Attack_size * 40;
		enemy[j].a_Graphic = 赤巨人;
		enemy[j].m_pattern = 赤巨人;
		enemy[j].a_pattern = 赤巨人;
		enemy[j].hp = 500;
		enemy[j].powor = 100;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = G;
		enemy[j].flame = 0;
		enemy[j].direcFlag = direcflag;
		enemy[j].AttackFlag = 0;
		break;

	case BOSS:
		enemy[j].flag = 1;
		enemy[j].Graphic = BOSS;
		enemy[j].Graphic_X_size = 640;
		enemy[j].Graphic_Y_size = 480;
		enemy[j].Graphic_size = img_enemy_boss_size / 2;
		enemy[j].Graphic_count = img_enemy_boss_size * 40;
		enemy[j].a_Graphic = BOSS;
		enemy[j].m_pattern = BOSS;
		enemy[j].a_pattern = BOSS;
		enemy[j].hp = 1000;
		enemy[j].powor = 200;
		enemy[j].x = EnX;
		enemy[j].y = EnY;
		enemy[j].DownSp = 0;
		enemy[j].MoveX = 0;
		enemy[j].MoveY = 0;
		enemy[j].Gravity = G;
		enemy[j].flame = 0;
		enemy[j].direcFlag = direcflag;
		enemy[j].AttackFlag = 0;
		break;
	default:
		break;
	}
}


//敵のマップとのあたり判定
void CalcEnemy()
{

	float Dummy = 0.0F;

	// キャラクタの左上、右上、左下、右下部分が当たり判定のある
	// マップに衝突しているか調べ、衝突していたら補正する

	for (int i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			// 先ず上下移動成分だけでチェック
			{
				// 左下のチェック、もしブロックの上辺に着いていたら落下を止める
				if (MapHitCheck(enemy[i].x, enemy[i].y + enemy[i].Graphic_Y_size, &Dummy, &enemy[i].MoveY) == 3) enemy[i].DownSp = 0.0F;

				// 右下のチェック、もしブロックの上辺に着いていたら落下を止める
				if (MapHitCheck(enemy[i].x + enemy[i].Graphic_X_size, enemy[i].y + enemy[i].Graphic_Y_size, &Dummy, &enemy[i].MoveY) == 3) enemy[i].DownSp = 0.0F;

				// 左上のチェック、もしブロックの下辺に当たっていたら落下させる
				if (MapHitCheck(enemy[i].x, enemy[i].y, &Dummy, &enemy[i].MoveY) == 4) enemy[i].DownSp *= -1.0F;

				// 右上のチェック、もしブロックの下辺に当たっていたら落下させる
				if (MapHitCheck(enemy[i].x + enemy[i].Graphic_X_size, enemy[i].y, &Dummy, &enemy[i].MoveY) == 4) enemy[i].DownSp *= -1.0F;

				// 上下移動成分を加算
				enemy[i].y += enemy[i].MoveY;

				// 後に左右移動成分だけでチェック
				{
					// 左下のチェック
					if (MapHitCheck(enemy[i].x, enemy[i].y + enemy[i].Graphic_Y_size, &enemy[i].MoveX, &Dummy) == 2) enemy[i].direcFlag = 1;

					// 右下のチェック
					if (MapHitCheck(enemy[i].x + enemy[i].Graphic_X_size, enemy[i].y + enemy[i].Graphic_Y_size, &enemy[i].MoveX, &Dummy) == 1) enemy[i].direcFlag = 2;

					// 左上のチェック
					MapHitCheck(enemy[i].x, enemy[i].y, &enemy[i].MoveX, &Dummy);

					// 右上のチェック
					MapHitCheck(enemy[i].x + enemy[i].Graphic_X_size, enemy[i].y, &enemy[i].MoveX, &Dummy);

					// 左右移動成分を加算
					enemy[i].x += enemy[i].MoveX;
				}

				// 接地判定
				{
					// キャラクタの左下と右下の下に地面があるか調べる
					if (GetChipParam(enemy[i].x, enemy[i].y + enemy[i].Graphic_Y_size + 1.0F) == 0 &&
						GetChipParam(enemy[i].x + enemy[i].Graphic_X_size, enemy[i].y + enemy[i].Graphic_Y_size + 1.0F) == 0)
					{
						// 足場が無かったらジャンプ中にする
						enemy[i].JumpFlag = TRUE;
					}
					else
					{
						// 足場が在ったら接地中にする
						enemy[i].JumpFlag = FALSE;
					}
				}

			}
		}
	}

}

//敵のマップとのあたり判定
int MapHitCheck(float X, float Y, float *MoveX, float *MoveY)
{
	float afX, afY;

	// 移動量を足す
	afX = X + *MoveX;
	afY = Y + *MoveY;

	// 当たり判定のあるブロックに当たっているかチェック
	if (GetChipParam(afX, afY) == 1 || GetChipParam(afX, afY) == 7 || GetChipParam(afX, afY) == 8 || GetChipParam(afX, afY) == 9 || GetChipParam(afX, afY) == 6 || GetChipParam(afX, afY) == 10 || GetChipParam(afX, afY) == 11 || GetChipParam(afX, afY) == 80 || GetChipParam(afX, afY) == 25 || GetChipParam(afX, afY) == 27 || GetChipParam(afX, afY) == 28 || GetChipParam(afX, afY) == 34 || GetChipParam(afX, afY) == 46)
	{
		float blx, bty, brx, bby;

		// 当たっていたら壁から離す処理を行う

		// ブロックの上下左右の座標を算出
		blx = (float)((int)afX / CHIP_SIZE) * CHIP_SIZE;        // 左辺の X 座標
		brx = (float)((int)afX / CHIP_SIZE + 1) * CHIP_SIZE;    // 右辺の X 座標

		bty = (float)((int)afY / CHIP_SIZE) * CHIP_SIZE;        // 上辺の Y 座標
		bby = (float)((int)afY / CHIP_SIZE + 1) * CHIP_SIZE;    // 下辺の Y 座標

																// 上辺に当たっていた場合
		if (*MoveY > 0.0F)
		{
			// 移動量を補正する
			*MoveY = bty - Y - 1.0F;

			// 上辺に当たったと返す
			return 3;
		}

		// 下辺に当たっていた場合
		if (*MoveY < 0.0F)
		{
			// 移動量を補正する
			*MoveY = bby - Y + 1.0F;

			// 下辺に当たったと返す
			return 4;
		}

		// 左辺に当たっていた場合
		if (*MoveX > 0.0F)
		{
			// 移動量を補正する
			*MoveX = blx - X - 1.0F;

			// 左辺に当たったと返す
			return 1;
		}

		// 右辺に当たっていた場合
		if (*MoveX < 0.0F)
		{
			// 移動量を補正する
			*MoveX = brx - X + 1.0F;

			// 右辺に当たったと返す
			return 2;
		}

		// ここに来たら適当な値を返す
		return 4;
	}

	// どこにも当たらなかったと返す
	return 0;
}


//敵の移動量計算
void MoveEnemy()
{
	for (int i = 0; i < enemy_max; i++)
	{
		if (enemy[i].flag == 1)
		{
			enemy[i].MoveX = 0;
			enemy[i].MoveY = 0;

			// 落下速度を移動量に加える
			enemy[i].MoveY = enemy[i].DownSp += enemy[i].Gravity;
		}
	}
}

//ケルベロスのエフェクトパターン
void EnemyPattern2(int i)
{
	if (enemy[i].DamegeFlag == 0)
	{
		if (enemy[i].direcFlag == 2)
		{
			enemy[i].MoveX = 0;

			enemy[i].MoveX -= 0.5F;
		}
		else if (enemy[i].direcFlag == 1)
		{
			enemy[i].MoveX = 0;

			enemy[i].MoveX += 0.5F;
		}
	}
}

//巨人の移動パターン
void EnemyPattern4(int i)
{
	if (enemy[i].DamegeFlag == 0)
	{
		if (enemy[i].direcFlag == 2)
		{
			enemy[i].MoveX = 0;

			enemy[i].MoveX -= 0.1F;
		}
		else if (enemy[i].direcFlag == 1)
		{
			enemy[i].MoveX = 0;

			enemy[i].MoveX += 0.1F;
		}
	}
}

//赤巨人の移動パターン
void EnemyPattern66(int i)
{
	if (enemy[i].direcFlag == 2)
	{
		enemy[i].MoveX = 0;

		enemy[i].MoveX -= 4;
	}
	else if (enemy[i].direcFlag == 1)
	{
		enemy[i].MoveX = 0;

		enemy[i].MoveX += 4;
	}
}

//敵の行動を管理
void EnemyControl()
{
	int i;
	for (i = 0; i < enemy_max; i++)
	{
		if (enemy[i].flag == 1)
		{
			if (enemy[i].AttackDrawFlag != 1 && enemy[i].AttackFlag != 1) {
				switch (enemy[i].m_pattern)
				{
				case 2:
					EnemyPattern2(i);
					break;
				case 4:
					EnemyPattern4(i);
					break;
				case 赤巨人:
					EnemyPattern66(i);
					break;

				}
			}
		}
	}

}

//敵の攻撃タイミングを管理
void EnemyAttackCheck()
{
	for (int i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].eff_flag != 1) {
				if (enemy[i].direcFlag == 1) {
					switch (enemy[i].a_pattern) {
					case 2:
						if (enemy[i].draw_x < player.draw_x && player.draw_x < enemy[i].draw_x + enemy[i].Graphic_X_size + 30 && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							if (enemy[i].flame  == 0) {
								enemy[i].AttackDrawFlag = 1;
								//printfDx("1");
							}
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					case 3:
						if (player.draw_x > enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							enemy[i].AttackDrawFlag = 1;
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					case 4:
						if (enemy[i].draw_x  < player.draw_x && player.draw_x < enemy[i].draw_x + enemy[i].Graphic_X_size + 30 && enemy[i].y < player.draw_y + player.Graphic_Y_size) {
							if (enemy[i].flame  == 0) {
								enemy[i].AttackDrawFlag = 1;
								//printfDx("1");
							}
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;

					case BOSS:
						
						enemy[i].AttackFlag = 1;
						break;
					}
				}
				else if (enemy[i].direcFlag == 2) {
					switch (enemy[i].a_pattern) {
					case 2:
						if (enemy[i].draw_x - 60 < player.draw_x && player.draw_x < enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							if (enemy[i].flame  == 0) {
								enemy[i].AttackDrawFlag = 1;
								//printfDx("1");
							}
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					case 3:
						if (player.draw_x < enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							enemy[i].AttackDrawFlag = 1;
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					case 4:
						if (enemy[i].draw_x - 60 < player.draw_x && player.draw_x < enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							if (enemy[i].flame  == 0) {
								enemy[i].AttackDrawFlag = 1;
								//printfDx("1");
							}
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					}
				}
				else {
					switch (enemy[i].a_pattern) {
						//トーテム
					case 5:
						if (enemy[i].draw_x - 60 < player.draw_x && player.draw_x < enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size
							|| enemy[i].draw_x + enemy[i].Graphic_X_size + 60 > player.draw_x && player.draw_x > enemy[i].draw_x && enemy[i].draw_y < player.draw_y + player.Graphic_Y_size) {
							Time = GetNowCount() - StartTime;
							if (Time >= 2000) {
								enemy[i].AttackFlag = 1;
								StartTime = GetNowCount();
							}
							else {
								enemy[i].AttackFlag = 0;
							}
						}
						else {
							enemy[i].AttackDrawFlag = 0;
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
}

//敵を表示
void EnemyDisp()
{
	for (int i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].AttackDrawFlag == 0) {
				if (enemy[i].direcFlag == 1) {
					switch (enemy[i].Graphic) {
					case 2:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_keru[enemy[i].flame % (img_enemy_keru_size / 2 * 10) / 10 + enemy[i].Graphic_size], TRUE);
						break;
					case 3:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_mado[4], TRUE);
						break;
					case 4:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji[enemy[i].flame % (img_enemy_kyoji_size / 2 * 40) / 40 + enemy[i].Graphic_size], TRUE);
						break;
					case 赤巨人:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji_red[enemy[i].flame % (img_enemy_kyoji_red_size / 2 * 10) / 10 + enemy[i].Graphic_size], TRUE);
						break;
					case BOSS:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_boss[enemy[i].flame % (img_enemy_boss_size / 2 * 40) / 40 + enemy[i].Graphic_size], TRUE);
						break;
					}
				}
				else if (enemy[i].direcFlag == 2) {
					switch (enemy[i].Graphic) {
					case 2:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_keru[enemy[i].flame % (img_enemy_keru_size / 2 * 10) / 10], TRUE);
						break;
					case 3:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_mado[0], TRUE);
						break;
					case 4:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji[enemy[i].flame % (img_enemy_kyoji_size / 2 * 40) / 40], TRUE);
						break;
					case 赤巨人:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji_red[enemy[i].flame % (img_enemy_kyoji_red_size / 2 * 10) / 10], TRUE);
						break;
					case BOSS:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_boss[enemy[i].flame % (img_enemy_boss_size / 2 * 40) / 40], TRUE);
						break;
					}
				}
				else {
					switch (enemy[i].Graphic) {
					case 5:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_totem, TRUE);
						break;
					}
				}
			}
			else if (enemy[i].AttackDrawFlag == 1) {
				if (enemy[i].direcFlag == 1)
				{
					switch (enemy[i].a_Graphic) {
					case 2:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_keru_Attack[enemy[i].flame % (img_enemy_keru_Attack_size / 2 * 5) / 5 + 3], TRUE);
						if (enemy[i].flame % (img_enemy_keru_Attack_size / 2 * 5) == 14) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case 3:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_mado[enemy[i].flame % (img_enemy_mado_size / 2 * 30) / 30 + 4], TRUE);
						if (enemy[i].flame % (img_enemy_mado_size / 2 * 30) == 119) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case 4:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji_Attack[enemy[i].flame % (img_enemy_kyoji_Attack_size / 2 * 30) / 30 + 5], TRUE);
						if (enemy[i].flame % (img_enemy_kyoji_Attack_size / 2 * 30) == 149) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case BOSS:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_boss2[enemy[i].flame % (img_enemy_boss_size / 2 * 40) / 40 + enemy[i].Graphic_size], TRUE);
						break;
					}
				}
				else if (enemy[i].direcFlag == 2) {
					switch (enemy[i].a_Graphic) {
					case 2:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_keru_Attack[enemy[i].flame % (img_enemy_keru_Attack_size / 2 * 5) / 5], TRUE);
						if (enemy[i].flame % (img_enemy_keru_Attack_size / 2 * 5) == 14) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case 3:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_mado[enemy[i].flame % (img_enemy_mado_size / 2 * 30) / 30], TRUE);
						if (enemy[i].flame % (img_enemy_mado_size / 2 * 30) == 119) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case 4:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_kyoji_Attack[enemy[i].flame % (img_enemy_kyoji_Attack_size / 2 * 30) / 30], TRUE);
						if (enemy[i].flame % (img_enemy_kyoji_Attack_size / 2 * 30) == 149) {
							enemy[i].AttackFlag = 1;
							enemy[i].AttackDrawFlag = 0;
						}
						else {
							enemy[i].AttackFlag = 0;
						}
						break;
					case BOSS:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_boss2[enemy[i].flame % (img_enemy_boss_size / 2 * 40) / 40], TRUE);
						break;
					}
				}
				else {
					switch (enemy[i].a_Graphic) {
					case 5:
						DrawGraph(enemy[i].draw_x, enemy[i].draw_y, img_enemy_totem, TRUE);
						enemy[i].AttackFlag = 1;
						enemy[i].AttackDrawFlag = 0;
						break;
					}
				}
			}
			enemy[i].flame++;
			if (enemy[i].flame == enemy[i].Graphic_count)
			{
				enemy[i].flame = 0;
			}
		}
	}
}

//敵の攻撃エフェクトをセットする
void EnemyEffectSet()
{
	int i;
	for (i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].AttackFlag == 1) {
				if (enemy[i].eff_flag == 0) {
					if (enemy[i].direcFlag == 2) {
						switch (enemy[i].a_Graphic) {
						case 2:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 2;
							enemy[i].eff_Graphic_X_size = 60;
							enemy[i].eff_Graphic_Y_size = 60;
							enemy[i].eff_x = enemy[i].x - enemy[i].eff_Graphic_X_size;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - 40;
							enemy[i].eff_Graphic_size = 6;
							enemy[i].eff_hit_flag = 0;
							break;
						case 3:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 3;
							enemy[i].eff_Graphic_X_size = 20;
							enemy[i].eff_Graphic_Y_size = 20;
							enemy[i].eff_x = enemy[i].x;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size*0.5 - enemy[i].eff_Graphic_Y_size*0.5;
							enemy[i].eff_Graphic_size = 0;
							enemy[i].eff_hit_flag = 0;
							break;
						case 4:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 4;
							enemy[i].eff_Graphic_X_size = 120;
							enemy[i].eff_Graphic_Y_size = 60;
							enemy[i].eff_x = enemy[i].x - 30;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - enemy[i].eff_Graphic_Y_size;
							enemy[i].eff_Graphic_size = 6;
							enemy[i].eff_hit_flag = 0;
							break;
						case BOSS:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = BOSS;
							enemy[i].eff_Graphic_X_size = 64;
							enemy[i].eff_Graphic_Y_size = 256;
							enemy[i].eff_x = enemy[i].x;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - enemy[i].eff_Graphic_Y_size;
							enemy[i].eff_Graphic_size = img_enemy_boss_Attack_effect_size;
							enemy[i].eff_hit_flag = 0;
							break;
						}
					}
					else if (enemy[i].direcFlag == 1) {
						switch (enemy[i].a_Graphic) {
						case 2:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 2;
							enemy[i].eff_Graphic_X_size = 60;
							enemy[i].eff_Graphic_Y_size = 60;
							enemy[i].eff_x = enemy[i].x + enemy[i].Graphic_X_size;
							//enemy_eff[i].eff_draw_x = enemy_eff[i].eff_x -20;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - 40;
							enemy[i].eff_Graphic_size = 6;
							enemy[i].eff_hit_flag = 0;
							break;
						case 3:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 3;
							enemy[i].eff_Graphic_X_size = 20;
							enemy[i].eff_Graphic_Y_size = 20;
							enemy[i].eff_x = enemy[i].x + enemy[i].Graphic_X_size;
							//enemy_eff[i].eff_draw_x = enemy_eff[i].eff_x - camerax;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size*0.5 - enemy[i].eff_Graphic_Y_size*0.5;
							enemy[i].eff_Graphic_size = 0;
							enemy[i].eff_hit_flag = 0;
							break;
						case 4:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 4;
							enemy[i].eff_Graphic_X_size = 120;
							enemy[i].eff_Graphic_Y_size = 60;
							enemy[i].eff_x = enemy[i].x + 30;
							//enemy_eff[i].eff_draw_x = enemy_eff[i].eff_x -20;
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - enemy[i].eff_Graphic_Y_size;
							enemy[i].eff_Graphic_size = 6;
							enemy[i].eff_hit_flag = 0;
							break;
						case BOSS:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = BOSS;
							enemy[i].eff_Graphic_X_size = 240;
							enemy[i].eff_Graphic_Y_size = 256;
							enemy[i].eff_x = enemy[i].x-320 + (rand() % 1040 );
							enemy[i].eff_y = enemy[i].y + enemy[i].Graphic_Y_size - enemy[i].eff_Graphic_Y_size;
							enemy[i].eff_Graphic_size = img_enemy_boss_Attack_effect_size;
							enemy[i].eff_hit_flag = 0;
							break;
						}
					}
					else {
						switch (enemy[i].a_Graphic) {
						case 5:
							enemy[i].eff_flag = 1;
							enemy[i].eff_flame = 0;
							enemy[i].eff_no = 5;
							enemy[i].eff_Graphic_X_size = 32;
							enemy[i].eff_Graphic_Y_size = 128;
							enemy[i].eff_x = enemy[i].x;
							enemy[i].eff_y = enemy[i].y;
							enemy[i].eff_Graphic_size = 31;
							enemy[i].eff_hit_flag = 0;
							break;
						}
					}
				}
			}
		}
	}
}

//敵の攻撃エフェクトを表示
void EnemyEffectDisp()
{
	for (int i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].eff_flag == 1) {
				if (enemy[i].direcFlag == 1) {
					switch (enemy[i].a_Graphic) {
					case 2:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_keru_Attack_effect[enemy[i].eff_flame % (img_enemy_keru_Attack_size / 2 * 10) / 10 + 3], TRUE);
						break;
					case 3:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_eff_mado_fire, TRUE);
						break;
					case 4:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_kyoji_Attack_effect[enemy[i].eff_flame % (img_enemy_kyoji_Attack_effect_size / 2 * 10) / 10], TRUE);
						break;
					case BOSS:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_boss_Attack_effect[enemy[i].eff_flame % (img_enemy_boss_Attack_effect_size * 5) / 5], TRUE);
						break;
					default:
						printfDx("error");
						break;
					}
				}
				else if (enemy[i].direcFlag == 2) {
					switch (enemy[i].a_Graphic) {
					case 2:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_keru_Attack_effect[enemy[i].eff_flame % (img_enemy_keru_Attack_effect_size / 2 * 10) / 10], TRUE);
						break;
					case 3:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_eff_mado_fire, TRUE);
						break;
					case 4:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_kyoji_Attack_effect[enemy[i].eff_flame % (img_enemy_kyoji_Attack_effect_size * 10) / 10], TRUE);
						break;
					default:
						printfDx("error");
						break;
					}
				}
				else {
					switch (enemy[i].a_Graphic) {
					case 5:
						DrawGraph(enemy[i].eff_draw_x, enemy[i].eff_draw_y, img_enemy_totem_Attack_effect[enemy[i].eff_flame % img_enemy_totem_Attack_effect_size], TRUE);
						DrawFormatString(0, 0, GetColor(0, 0, 0), "1");
						break;
					default:
						printfDx("error");
						break;
					}
				}
			}
			enemy[i].eff_flame++;
		}
	}
}

//敵のエフェクトを管理
void EnemyEffectControl()
{
	for (int i = 0; i < enemy_max; i++) {
		if (enemy[i].flag == 1) {
			if (enemy[i].eff_flag == 1) {
				switch (enemy[i].eff_no)
				{
				case 2:
					EffectPattern2(i);
					break;
				case 3:
					EffectPattern3(i);
					break;
				case 4:
					EffectPattern4(i);
					break;
				case 5:
					EffectPattern5(i);
					break;
				case BOSS:
					EffectPatternBoss(i);
					break;
				}
			}
		}
	}
}

//魔導士のエフェクトパターン
void EffectPattern3(int i)
{
	if (enemy[i].direcFlag == 2)
	{
		enemy[i].eff_x -= 2;

		if (enemy[i].eff_flame == 200) {
			enemy[i].eff_flag = 0;
			enemy[i].AttackFlag = 0;
		}
	}
	if (enemy[i].direcFlag == 1)
	{
		enemy[i].eff_x += 2;

		if (enemy[i].eff_flame == 200) {
			enemy[i].eff_flag = 0;
			enemy[i].AttackFlag = 0;
		}
	}
}

//ケルベロスのエフェクトパターン
void EffectPattern2(int i)
{
	if (enemy[i].flame % (img_enemy_keru_Attack_effect_size / 2 * 5) == 14) {
		enemy[i].eff_flag = 0;
		enemy[i].AttackFlag = 0;
	}

}

//巨人のエフェクトパターン
void EffectPattern4(int i)
{
	if (enemy[i].eff_flame % (img_enemy_kyoji_Attack_effect_size * 10) == (img_enemy_kyoji_Attack_effect_size * 10) - 1) {
		enemy[i].eff_flag = 0;
		enemy[i].AttackFlag = 0;
	}

}

//トーテムのエフェクトパターン
void EffectPattern5(int i) {
	if (enemy[i].eff_flame % img_enemy_totem_Attack_effect_size == img_enemy_totem_Attack_effect_size - 1) {
		enemy[i].eff_flag = 0;
		enemy[i].AttackFlag = 0;
	}
}

//ボスのエフェクトパターン
void EffectPatternBoss(int i) {
	if (enemy[i].eff_flame % ( img_enemy_boss_Attack_effect_size * 5) / 5 == img_enemy_boss_Attack_effect_size - 1) {
		enemy[i].eff_flag = 0;
		enemy[i].AttackFlag = 0;
	}
}