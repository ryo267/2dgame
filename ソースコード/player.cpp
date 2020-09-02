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

int img_player[6] = { 0 }; //�O���t�B�b�N�n���h���i�[�p�z��
int img_player_Attack[10] = { 0 };
int img_player_waza1[20] = { 0 };
int img_eff1[6] = { 0 };//�ʏ�U���̃O���t�B�b�N�n���h���i�[�p�z��
int img_eff2[6] = { 0 };
int img_eff_waza1[13] = { 0 };
int hp = 100;
int hpMax = 100;
int mp = 100;
int mpMax = 100;

// �v���C���[�̈ړ�����
void MovePlayer()
{
	player.MoveX = 0;
	player.MoveY = 0;

	if (att.att_flag != 1 && att.eff_flag != 1)
	{
		// ���E�̈ړ�������
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

		// �n�ɑ��������Ă���ꍇ�̂݃W�����v�{�^��(�{�^���P or �y�L�[)������
		if (player.JumpFlag == 0 && (EdgeInput & PAD_INPUT_A) != 0)
		{
			player.DownSp = -JUMP_POWER;
			player.JumpFlag = 1;
		}
	}
	// ��������
	player.MoveY = player.DownSp += G;

}

// �L�����N�^���}�b�v�Ƃ̓����蔻����l�����Ȃ���ړ�����
int CalcPlayer()
{
	float Dummy = 0.0F;

	// �L�����N�^�̍���A�E��A�����A�E�������������蔻��̂���
	// �}�b�v�ɏՓ˂��Ă��邩���ׁA�Փ˂��Ă�����␳����

	//�����̃`�F�b�N
	if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size / 2, &Dummy, &player.MoveY) == 5) {
		return 1;
	}
	//�����̃`�F�b�N
	if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size / 2, &player.MoveX, &Dummy) == 5) {
		return 1;
	}


	// �悸�㉺�ړ����������Ń`�F�b�N
	{
		// �����̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
		if (PlayerMapHitCheck(player.x, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 3) {
			player.DownSp = 0.0F;
		}

		// �E���̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size - 1, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 3) {
			player.DownSp = 0.0F;
		}
		
		//�������̃`�F�b�N
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y + player.Graphic_Y_size, &Dummy, &player.MoveY) == 5) {
			return 1;
		}

		// ����̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
		if (PlayerMapHitCheck(player.x + 1, player.y, &Dummy, &player.MoveY) == 4) {
			player.DownSp *= -1.0F;
		}

		// �E��̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y, &Dummy, &player.MoveY) == 4) {
			player.DownSp *= -1.0F;
		}

		//������̃`�F�b�N
		if (PlayerMapHitCheck(player.x + player.Graphic_X_size / 2, player.y, &Dummy, &player.MoveY) == 5) {
			return 1;
		}

		// �㉺�ړ����������Z
		player.y += player.MoveY;
	}

	// ��ɍ��E�ړ����������Ń`�F�b�N
	{
		// �����̃`�F�b�N
		PlayerMapHitCheck(player.x, player.y + player.Graphic_Y_size, &player.MoveX, &Dummy);

		// �E���̃`�F�b�N
		PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y + player.Graphic_Y_size, &player.MoveX, &Dummy);

		// ����̃`�F�b�N
		PlayerMapHitCheck(player.x, player.y, &player.MoveX, &Dummy);

		// �E��̃`�F�b�N
		PlayerMapHitCheck(player.x + player.Graphic_X_size, player.y, &player.MoveX, &Dummy);

		// ���E�ړ����������Z
		player.x += player.MoveX;
	}

	// �ڒn����
	{
		// �L�����N�^�̍����ƉE���̉��ɒn�ʂ����邩���ׂ�
		if (GetChipParam(player.x, player.y + player.Graphic_Y_size + 1.0F) == 0 &&
			GetChipParam(player.x + player.Graphic_X_size, player.y + player.Graphic_Y_size + 1.0F) == 0)
		{
			// ���ꂪ����������W�����v���ɂ���
			player.JumpFlag = 1;
		}
		else
		{
			// ���ꂪ�݂�����ڒn���ɂ���
			player.JumpFlag = 0;
		}
	}

	// �I��
	return 0;
}


// �}�b�v�Ƃ̓����蔻��( �߂�l 0:������Ȃ�����  1:���ӂɓ�������  2:�E�ӂɓ�������
//                                                3:��ӂɓ�������  4:���ӂɓ�������
int PlayerMapHitCheck(float X, float Y, float *MoveX, float *MoveY)
{
	float afX, afY;

	// �ړ��ʂ𑫂�
	afX = X + *MoveX;
	afY = Y + *MoveY;

	// �����蔻��̂���u���b�N�ɓ������Ă��邩�`�F�b�N
	if (GetChipParam(afX, afY) == 1 || GetChipParam(afX, afY) == 7 || GetChipParam(afX, afY) == 8 || GetChipParam(afX, afY) == 9 || GetChipParam(afX, afY) == 6 || GetChipParam(afX, afY) == 10 || GetChipParam(afX, afY) == 11 || GetChipParam(afX, afY) == 80 || GetChipParam(afX, afY) == 25 || GetChipParam(afX, afY) == 27 || GetChipParam(afX, afY) == 28 || GetChipParam(afX, afY) == 34 || GetChipParam(afX, afY) == 46 || GetChipParam(afX, afY) == 72 || GetChipParam(afX, afY) == 74 )
	{
		float blx, bty, brx, bby;

		// �������Ă�����ǂ��痣���������s��

		// �u���b�N�̏㉺���E�̍��W���Z�o
		blx = (float)((int)afX / CHIP_SIZE) * CHIP_SIZE;        // ���ӂ� X ���W
		brx = (float)((int)afX / CHIP_SIZE + 1) * CHIP_SIZE;    // �E�ӂ� X ���W

		bty = (float)((int)afY / CHIP_SIZE) * CHIP_SIZE;        // ��ӂ� Y ���W
		bby = (float)((int)afY / CHIP_SIZE + 1) * CHIP_SIZE;    // ���ӂ� Y ���W

																// ��ӂɓ������Ă����ꍇ
		if (*MoveY > 0.0F)
		{
			// �ړ��ʂ�␳����
			*MoveY = bty - Y - 1.0F;

			// ��ӂɓ��������ƕԂ�
			return 3;
		}

		// ���ӂɓ������Ă����ꍇ
		if (*MoveY < 0.0F)
		{
			// �ړ��ʂ�␳����
			*MoveY = bby - Y + 1.0F;

			// ���ӂɓ��������ƕԂ�
			return 4;
		}

		// ���ӂɓ������Ă����ꍇ
		if (*MoveX > 0.0F)
		{
			// �ړ��ʂ�␳����
			*MoveX = blx - X - 1.0F;

			// ���ӂɓ��������ƕԂ�
			return 1;
		}

		// �E�ӂɓ������Ă����ꍇ
		if (*MoveX < 0.0F)
		{
			// �ړ��ʂ�␳����
			*MoveX = brx - X + 1.0F;

			// �E�ӂɓ��������ƕԂ�
			return 2;
		}

		// �����ɗ�����K���Ȓl��Ԃ�
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
	// �ǂ��ɂ�������Ȃ������ƕԂ�
	return 0;
}

//�v���C���[������
void PlayerCalc(int P, float PlX, float PlY, int direcflag)
{
	if (player.flag != 1)
	{
		player.Graphic = P;//�v���C���[�̎��
		player.Graphic_X_size = 30;//�v���C���[�̉��̃T�C�Y
		player.Graphic_Y_size = 30;//�G�̏c�̃T�C�Y
		player.Graphic_count = img_player_size;//�摜�̗v�f��
		player.a_Graphic;//�U���O���t�B�b�N
		player.m_pattern;//�ړ��p�^�[��
		player.a_pattern;//�U���p�^�[��
		player.x = PlX;//�v���C���[��X���W
		player.y = PlY;//�v���C���[��Y���W
		player.DownSp = 0;//�v���C���[�̗������x
		player.MoveX = 0;//�v���C���[�̉��̈ړ���
		player.MoveY = 0;//�v���C���[�̏c�̈ړ���
		player.Gravity = G;//�v���C���[�ɂ�����d��
		player.HP_MAX = 100000;//�v���C���[�̍ő�hp
		player.hp = player.HP_MAX;//�v���C���[��hp
		player.MP_MAX = 100;//�v���C���[�̍ő�mp
		player.mp = 100;//�v���C���[��mp
		player.powor = 10;//�v���C���[�̍U����
		player.item;//�v���C���[���������Ă���A�C�e��
		player.flame = 0;//�v���C���[�̕`��t���[��
		player.direcFlag = direcflag;//�v���C���[�̌����̃t���O
		player.JumpFlag = 0;//�v���C���[�̃W�����v�t���O
		player.AttackFlag = 0;//�v���C���[���U�����Ă邩�̃t���O
		player.flag = 1;//�v���C���[�̏o���t���O
	}
}

//�v���C���[�̍U���G�t�F�N�g���Z�b�g
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

//�v���C���[�̍U���G�t�F�N�g�\��
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

//�L�����N�^�[�̕`��
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

//�v���C���[��HP�\��
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
