#include "player.h"
#include "Header.h"
#include "DxLib.h"
#include "map.h"

PLAYERDATA player = {0};
ATT att = { 0 };

int img_player_size = sizeof img_player / sizeof img_player[0];
int img_player_Attack_size = sizeof img_player_Attack / sizeof img_player_Attack[0];
int img_player_waza1_size = sizeof img_player_waza1 / sizeof img_player_waza1[0];
int img_eff_waza1_size = sizeof img_eff_waza1 / sizeof img_eff_waza1[0];
int img_eff1_size = sizeof img_eff1 / sizeof img_eff1[0];
int img_eff2_size = sizeof img_eff2 / sizeof img_eff2[0];

int img_player[6] = { 0 }; //グラフィックハンドル格納用配列
int img_player_Attack[10] = { 0 };
int img_player_waza1[20] = { 0 };
int img_eff1[6] = { 0 };//通常攻撃のグラフィックハンドル格納用配列
int img_eff2[6] = { 0 };
int img_eff_waza1[13] = { 0 };
int hp = 100;
int hpMax = 100;
int mp = 100;
int mpMax = 100;

// プレイヤーの移動処理
void MovePlayer()
{
	player.MoveX = 0;
	player.MoveY = 0;

	if (att.att_flag != 1 && att.eff_flag != 1)
	{
		// 左右の移動を見る
		if ((Input & PAD_INPUT_LEFT) != 0) {
			if (player.direcFlag == 1) {
				player.direcFlag = 2;
			}
			player.flame++;
			//result = abs(player.frame) % 30 / 10;
			player.MoveX -= SPEED;
		}
		if ((Input & PAD_INPUT_RIGHT) != 0) {
			if (player.direcFlag == 2) {
				player.direcFlag = 1;
			}
			player.flame++;
			//result = abs(xcount) % 30 / 10 + 3;
			player.MoveX += SPEED;
		}

		// 地に足が着いている場合のみジャンプボタン(ボタン１ or Ｚキー)を見る
		if (player.JumpFlag == 0 && (EdgeInput & PAD_INPUT_A) != 0)
		{
			player.DownSp = -JUMP_POWER;
			player.JumpFlag = 1;
		}
	}
	// 落下処理
	player.MoveY = player.DownSp += G;

}

// キャラクタをマップとの当たり判定を考慮しながら移動する
int CalcPlayer()
{
	float Dummy = 0.0F;

	// キャラクタの左上、右上、左下、右下部分が当たり判定のある
	// マップに衝突しているか調べ、衝突していたら補正する

	//中央のチェック
	if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size / 2, &Dummy, &player.MoveY) == 5) {
		return 1;
	}
	//中央のチェック
	if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size / 2, &player.MoveX, &Dummy) == 5) {
		return 1;
	}


	// 先ず上下移動成分だけでチェック
	{
		// 左下のチェック、もしブロックの上辺に着いていたら落下を止める
		if (PlayerMapHitCheck(player.x, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 3) {
			player.DownSp = 0.0F;
		}

		// 右下のチェック、もしブロックの上辺に着いていたら落下を止める
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size - 1, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 3) {
			player.DownSp = 0.0F;
		}
		
		//中央下のチェック
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 5) {
			return 1;
		}

		// 左上のチェック、もしブロックの下辺に当たっていたら落下させる
		if (PlayerMapHitCheck(player.x + 1, player.y, &Dummy, &player.MoveY) == 4) {
			player.DownSp *= -1.0F;
		}

		// 右上のチェック、もしブロックの下辺に当たっていたら落下させる
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y, &Dummy, &player.MoveY) == 4) {
			player.DownSp *= -1.0F;
		}

		//中央上のチェック
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y, &Dummy, &player.MoveY) == 5) {
			return 1;
		}

		// 上下移動成分を加算
		player.y += player.MoveY;
	}

	// 後に左右移動成分だけでチェック
	{
		// 左下のチェック
		PlayerMapHitCheck(player.x, player.y + player.Graphic_Y_size, &player.MoveX, &Dummy);

		// 右下のチェック
		PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y + player.Graphic_Y_size, &player.MoveX, &Dummy);

		// 左上のチェック
		PlayerMapHitCheck(player.x, player.y, &player.MoveX, &Dummy);

		// 右上のチェック
		PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y, &player.MoveX, &Dummy);

		// 左右移動成分を加算
		player.x += player.MoveX;
	}

	// 接地判定
	{
		// キャラクタの左下と右下の下に地面があるか調べる
		if (GetChipParam(player.x, player.y + player.Graphic_Y_size + 1.0F) == 0 &&
			GetChipParam(player.x + player.Graphic_X_size, player.y + player.Graphic_Y_size + 1.0F) == 0)
		{
			// 足場が無かったらジャンプ中にする
			player.JumpFlag = 1;
		}
		else
		{
			// 足場が在ったら接地中にする
			player.JumpFlag = 0;
		}
	}

	// 終了
	return 0;
}


// マップとの当たり判定( 戻り値 0:当たらなかった  1:左辺に当たった  2:右辺に当たった
//                                                3:上辺に当たった  4:下辺に当たった
int PlayerMapHitCheck(float X, float Y, float *MoveX, float *MoveY)
{
	float afX, afY;

	// 移動量を足す
	afX = X + *MoveX;
	afY = Y + *MoveY;

	// 当たり判定のあるブロックに当たっているかチェック
	if (GetChipParam(afX, afY) == 1 || GetChipParam(afX, afY) == 7 || GetChipParam(afX, afY) == 8 || GetChipParam(afX, afY) == 9 || GetChipParam(afX, afY) == 6 || GetChipParam(afX, afY) == 10 || GetChipParam(afX, afY) == 11 || GetChipParam(afX, afY) == 80 || GetChipParam(afX, afY) == 25 || GetChipParam(afX, afY) == 27 || GetChipParam(afX, afY) == 28 || GetChipParam(afX, afY) == 34 || GetChipParam(afX, afY) == 46 || GetChipParam(afX, afY) == 72 || GetChipParam(afX, afY) == 74 )
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
	else if (GetChipParam(afX, afY) == 26) {
		player.hp -= 10;
		if (player.hp < 0) {
			player.hp = 0;
			player.flag = 0;
			return 5;
		}
	}
	else if (GetChipParam(afX, afY) == 40) {
		player.hp -= 10;
		if (player.hp < 0) {
			player.hp = 0;
			player.flag = 0;
			return 5;
		}
	}
	else if (GetChipParam(afX, afY) == 59) {
		player.x = warpPoint_x[0];
		player.y = warpPoint_y[0];
	}
	else if (GetChipParam(afX, afY) == 61) {
		player.x = warpPoint_x[1];
		player.y = warpPoint_y[1];
	}
	else if (GetChipParam(afX, afY) == 63) {
		player.x += 1;
	}
	else if (GetChipParam(afX, afY) == 64) {
		player.x = warpPoint_x[2];
		player.y = warpPoint_y[2];
	}
	else if (GetChipParam(afX, afY) == 69) {
		player.x = warpPoint_x[3];
		player.y = warpPoint_y[3];
	}
	else if (GetChipParam(afX, afY) == 71) {
		player.DownSp = -13;
		player.JumpFlag = 1;
	}
	else if (GetChipParam(afX, afY) == 77) {
		player.DownSp = 5;
	}
	else if (GetChipParam(afX, afY) == 82) {
		player.x = warpPoint_x[4];
		player.y = warpPoint_y[4];
	}
	// どこにも当たらなかったと返す
	return 0;
}

//プレイヤー初期化
void PlayerCalc(int P, float PlX, float PlY, int direcflag)
{
	if (player.flag != 1)
	{
		player.Graphic = P;//プレイヤーの種類
		player.Graphic_X_size = 30;//プレイヤーの横のサイズ
		player.Graphic_Y_size = 30;//敵の縦のサイズ
		player.Graphic_count = img_player_size;//画像の要素数
		player.a_Graphic;//攻撃グラフィック
		player.m_pattern;//移動パターン
		player.a_pattern;//攻撃パターン
		player.x = PlX;//プレイヤーのX座標
		player.y = PlY;//プレイヤーのY座標
		player.DownSp = 0;//プレイヤーの落下速度
		player.MoveX = 0;//プレイヤーの横の移動量
		player.MoveY = 0;//プレイヤーの縦の移動量
		player.Gravity = G;//プレイヤーにかかる重力
		player.HP_MAX = 100000;//プレイヤーの最大hp
		player.hp = player.HP_MAX;//プレイヤーのhp
		player.MP_MAX = 100;//プレイヤーの最大mp
		player.mp = 100;//プレイヤーのmp
		player.powor = 10;//プレイヤーの攻撃力
		player.item;//プレイヤーが所持しているアイテム
		player.flame = 0;//プレイヤーの描画フレーム
		player.direcFlag = direcflag;//プレイヤーの向きのフラグ
		player.JumpFlag = 0;//プレイヤーのジャンプフラグ
		player.AttackFlag = 0;//プレイヤーが攻撃してるかのフラグ
		player.flag = 1;//プレイヤーの出現フラグ
	}
}

//プレイヤーの攻撃エフェクトをセット
void PlayerAttack()
{
	if (att.att_flag != 1 && att.eff_flag != 1)
	{
		if (player.direcFlag == 1 && CheckHitKey(KEY_INPUT_V) == 1)
		{
			att.att_flag = 1;
			att.eff_flag = 1;
			att.att_DamegeFlag = 0;
			att.att_power = 10;
			att.att_Graphic_size = img_player_Attack_size / 2;
			att.att_Graphic_count = att.att_Graphic_size * 3;
			att.att_flame = 0;
			att.eff_flame = 0;
			att.att_x = player.draw_x;
			att.att_y = player.draw_y;
			att.Graphic_X_size = 40;
			att.Graphic_Y_size = 32;
			att.eff_no = 1;
			att.eff_Graphic_X_size = 30;
			att.eff_Graphic_Y_size = 30;
			att.eff_x = att.att_x + player.Graphic_X_size;
			att.eff_y = att.att_y;
			att.eff_Graphic_size = img_eff1_size;
			att.eff_Graphic_count = att.eff_Graphic_size * 3;
		}

		else if (player.direcFlag == 2 && CheckHitKey(KEY_INPUT_V) == 1)
		{
			att.att_flag = 1;
			att.eff_flag = 1;
			att.att_DamegeFlag = 0;
			att.att_power = 10;
			att.att_Graphic_size = img_player_Attack_size / 2;
			att.att_Graphic_count = att.att_Graphic_size * 3;
			att.att_flame = 0;
			att.eff_flame = 0;
			att.att_x = player.draw_x - 20;
			att.att_y = player.draw_y;
			att.Graphic_X_size = 40;
			att.Graphic_Y_size = 32;
			att.eff_no = 2;
			att.eff_Graphic_X_size = 30;
			att.eff_Graphic_Y_size = 30;
			att.eff_x = att.att_x - 20;
			att.eff_y = att.att_y;
			att.eff_Graphic_size = img_eff2_size;
			att.eff_Graphic_count = att.eff_Graphic_size * 3;
		}

		else if (player.direcFlag == 1 && player.mp >= 20 && CheckHitKey(KEY_INPUT_F) == 1)
		{
			att.att_flag = 1;
			att.eff_flag = 1;
			att.att_DamegeFlag = 0;
			att.att_power = 200;
			att.att_Graphic_size = img_player_waza1_size / 2;
			att.att_Graphic_count = att.att_Graphic_size * 10;
			att.att_flame = 0;
			att.eff_flame = 0;
			att.att_x = player.draw_x;
			att.att_y = player.draw_y + player.Graphic_Y_size - 50;
			att.Graphic_X_size = 50;
			att.Graphic_Y_size = 50;
			att.eff_no = 3;
			att.eff_Graphic_X_size = 128;
			att.eff_Graphic_Y_size = 96;
			att.eff_x = player.draw_x + player.Graphic_X_size + 40;
			att.eff_y = player.draw_y + player.Graphic_Y_size - att.eff_Graphic_Y_size;
			att.eff_Graphic_size = img_eff_waza1_size;
			att.eff_Graphic_count = (att.eff_Graphic_size * 10);
			player.mp -= 20;
		}

		else if (player.direcFlag == 2 && player.mp >= 20 && CheckHitKey(KEY_INPUT_F) == 1)
		{
			att.att_flag = 1;
			att.eff_flag = 1;
			att.att_DamegeFlag = 0;
			att.att_power = 200;
			att.att_Graphic_size = img_player_waza1_size / 2;
			att.att_Graphic_count = att.att_Graphic_size * 10;
			att.att_flame = 0;
			att.eff_flame = 0;
			att.att_x = player.draw_x - 20;
			att.att_y = player.draw_y + player.Graphic_Y_size - 50;
			att.Graphic_X_size = 50;
			att.Graphic_Y_size = 50;
			att.eff_no = 4;
			att.eff_Graphic_X_size = 128;
			att.eff_Graphic_Y_size = 96;
			att.eff_x = att.att_x - player.Graphic_X_size - player.Graphic_X_size - 80;
			att.eff_y = player.draw_y + player.Graphic_Y_size - att.eff_Graphic_Y_size;
			att.eff_Graphic_size = img_eff_waza1_size;
			att.eff_Graphic_count = (att.eff_Graphic_size * 10);
			player.mp -= 20;
		}
	}

}

//プレイヤーの攻撃エフェクト表示
void EffDisp() {
	if (att.eff_flag == 1) {
		switch (att.eff_no) {
		case 1:
			DrawGraph(att.eff_x, att.eff_y, img_eff1[att.eff_flame% att.eff_Graphic_count / 3], TRUE);
			break;
		case 2:
			DrawGraph(att.eff_x, att.eff_y, img_eff2[att.eff_flame% att.eff_Graphic_count / 3], TRUE);
			break;
		case 3:
			DrawGraph(att.eff_x, att.eff_y, img_eff_waza1[att.eff_flame% att.eff_Graphic_count / 10], TRUE);
			break;
		case 4:
			DrawGraph(att.eff_x, att.eff_y, img_eff_waza1[att.eff_flame% att.eff_Graphic_count / 10], TRUE);
			break;
		default:
			printfDx("Error.");
			break;
		}
		att.eff_flame++;
		if (att.eff_flame == att.eff_Graphic_count /2) { att.att_DamegeFlag = 1; }
		else att.att_DamegeFlag = 0;
		if (att.eff_flame == att.eff_Graphic_count) {att.eff_flag = 0;}
	}
}

//キャラクターの描画
void PlayerDisp()
{
	if (att.att_flag == 0)
	{
		if (player.direcFlag == 1)
		{
			DrawGraph(player.draw_x, player.draw_y, img_player[player.flame % 30 / 10 + 3], TRUE);
		}
		else
		{
			DrawGraph(player.draw_x, player.draw_y, img_player[player.flame % 30 / 10], TRUE);
		}
	}
	else
	{
		if (player.direcFlag == 1)
		{
			switch (att.eff_no)
			{
			case 1:
				DrawGraph(att.att_x, att.att_y, img_player_Attack[att.att_flame % att.att_Graphic_count / 3], TRUE);
				break;
			case 3:
				DrawGraph(att.att_x, att.att_y, img_player_waza1[att.att_flame % att.att_Graphic_count / 10], TRUE);
				break;
			}

		}
		else
		{
			switch (att.eff_no)
			{
			case 2:
				DrawGraph(att.att_x, att.att_y, img_player_Attack[att.att_flame % att.att_Graphic_count / 3 + 5], TRUE);
				break;
			case 4:
				DrawGraph(att.att_x, att.att_y, img_player_waza1[att.att_flame % att.att_Graphic_count / 10 + 10], TRUE);
				break;
			}
		}
		att.att_flame++;
		if (att.att_flame == att.att_Graphic_count) {
			att.att_flag = 0;
		}
	}
}

//プレイヤーのHP表示
void DrawHP()
{
	if (player.hp < 0) {
		player.hp = 0;
	}
	DrawBox(25, 450, 25 + 200, 450 + 10, GetColor(255, 255, 255), FALSE);
	DrawBox(25, 450, 25 + 200 * player.hp / player.HP_MAX, 450 + 10, GetColor(0, 255, 0), TRUE);
	DrawBox(25, 460, 25 + 200, 460 + 10, GetColor(255, 255, 255), FALSE);
	DrawBox(25, 460, 25 + 200 * player.mp / player.MP_MAX, 460 + 10, GetColor(0, 0, 255), TRUE);

}
