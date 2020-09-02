#include "DxLib.h"
#include "Header.h"
#include "map.h"
#include "enemy.h"
#include "camera.h"
#include "player.h"

// ���͏�Ԃ̏�����
int Input = 0;
int EdgeInput = 0;
int FrameStartTime = 0;
int Key[256]; // �L�[��������Ă���t���[�������i�[����
GameState g_gamestate = GAME_TITLE;


// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;							// �c�w���C�u�����̏�����

	SetDrawScreen(DX_SCREEN_BACK);								// �`���𗠉�ʂɃZ�b�g

	SetWaitVSyncFlag(FALSE);									// ���������M����҂��Ȃ�

	FrameStartTime = GetNowCount();								// �U�O�e�o�r�Œ�p�A���ԕۑ��p�ϐ������݂̃J�E���g�l�ɃZ�b�g

	Load();														//�O���t�B�b�N��Ǎ���

	PlaySound("./bgm_maoudamashii_fantasy08.mp3", DX_PLAYTYPE_LOOP);//BGM�Đ�

	enemyInit();												//�G�̏�����

	// ���C�����[�v�J�n�A�d�r�b�L�[�ŊO�ɏo��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && gpUpdateKey() == 0)
	{
		ClsDrawScreen();										// ��ʂ̃N���A

		while (GetNowCount() - FrameStartTime < 1000 / 60) {}	// �P/�U�O�b���܂ő҂�

		FrameStartTime = GetNowCount();							// ���݂̃J�E���g�l��ۑ�

		switch (g_gamestate) {
		case GAME_TITLE:
			if (gameTitle() == 1) {								//�^�C�g����ʂ̊֐����Ă�
				g_gamestate = GAME_MAIN;
			}
			break;
		case GAME_MAIN:
			if (ActMain() == 1) {								// �Q�[���{�҂̊֐����Ă�
				
				enemyInit();									//�I�������G�̏�����(2��ڂ���̏����������܂������Ȃ�)
			}
			break;
		case GAME_CLEAR:
			if (gameClear() == 1) {								//�Q�[���N���A��ʂ̊֐����Ă�
				g_gamestate = GAME_TITLE;
			}
		case GAME_OVER:
			if (gameOver() == 1) {								//�Q�[���I�[�o�[��ʂ̊֐����Ă�
				g_gamestate = GAME_TITLE;
			}
			break;
		}
		
		ScreenFlip();											// ��ʂ̍X�V
	}

	StopSound();												//���y�̍Đ����~�߂�

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �I��
	return 0;
}

// �A�N�V�����T���v���v���O�������C��
int ActMain(void)
{
		keyUpdate();											//�L�[���͂̍X�V

		DrawMap(&camerax, &cameray);							//�}�b�v�Ɣw�i�̕`��

		MoveEnemy();											//�G�̈ړ������Ƃ��̊Ǘ�
		EnemyControl();

		CalcEnemy();											//�G�̃}�b�v�Ƃ̂����蔻��						

		if (CalcPlayer() == 1){									// �v���C���[�̃}�b�v�Ƃ̂����蔻��
			g_gamestate = GAME_OVER;
			return 1;
		}

		MoveCamera();											//�J�����X�N���[��
		
		if (playerCollisionCheck() == 1) {						//�v���C���[�̏Փ˔���
			g_gamestate = GAME_OVER;
			return 1;
		}

		if (enemyCollisionCheck() == 1) {						//�G�̏Փ˔���
			g_gamestate = GAME_CLEAR;
			return 1;
		}

		EnemyAttackCheck();										//�G�̍U�����Ǘ�
		EnemyDisp();											//�G�̕\��
		EnemyEffectSet();										//�G�̃G�t�F�N�g���Z�b�g
		EnemyEffectDisp();										//�G�̃G�t�F�N�g�\��
		EnemyEffectControl();									//�G�̃G�t�F�N�g���Ǘ�
		
		MovePlayer();											//�v���C���[�̈ړ�����
		PlayerAttack();											//�v���C���[�̍U��
		PlayerDisp();											//�L�����N�^�[�`��
		EffDisp();												//�v���C���[�̃G�t�F�N�g��\��
		DrawHP();												//�v���C���[��HP��\��

		if (debugOn() == 1) {									//�f�o�b�O���[�h�J�n
			debug();
		}
		
	// �I��
	return 0;
}