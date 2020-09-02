#if! defined(_ENEMY_H_)
#define _ENEMY_H_

#include "DxLib.h"

enum enemy {
	�P���x���X = 2,
	�����m = 3,
	���l = 4,
	�ԋ��l = 66,
	BOSS = 70
};

typedef struct ENEMYDATA
{
	int Graphic;//�G�̎��
	int Graphic_X_size;//�G�̉��̃T�C�Y
	int Graphic_Y_size;//�G�̏c�̃T�C�Y
	int Graphic_size;
	int Graphic_count;//�G�̉摜�̗v�f��
	int a_Graphic;//�U���O���t�B�b�N
	int m_pattern;//�ړ��p�^�[��
	int a_pattern;//�U���p�^�[��
	float x, y;//���W
	float DownSp; // �G�̗������x
	float MoveX, MoveY;//�G�̈ړ���
	float Gravity;//�G�ɂ�����d��
	float draw_x;
	float draw_y;
	int hp;//�G��hp
	int powor;//�G�̍U����
	int item;//�G���������Ă���A�C�e��
	int flame;//�G�̕`��t���[��
	int direcFlag;//�G�̌����̃t���O
	int JumpFlag;//�G�̃W�����v�t���O
	int AttackFlag;
	int AttackDrawFlag;
	int DamegeFlag;
	int flag;//�G�̏o���t���O
	int eff_no;
	int eff_flag;
	float eff_x, eff_y;
	float eff_draw_x;
	float eff_draw_y;
	int eff_Graphic_X_size;
	int eff_Graphic_Y_size;
	int eff_Graphic_size;
	int eff_Graphic_count;
	int eff_hit_flag;
	int eff_flame;
}ENEMYDATA;

extern ENEMYDATA enemy[60];

extern int const enemy_max;
extern int img_enemy_keru[8];
extern int img_enemy_keru_Attack[6];
extern int img_enemy_keru_Attack_effect[6];
extern int img_enemy_mado[8];
extern int img_enemy_kyoji[8];
extern int img_enemy_kyoji_Attack[10];
extern int img_enemy_kyoji_Attack_effect[6];
extern int img_enemy_kyoji_red[8];
extern int img_enemy_kyoji_red_Attack[10];
extern int img_enemy_keru_size;
extern int img_enemy_keru_Attack_size;
extern int img_enemy_keru_Attack_effect_size;
extern int img_enemy_mado_size;
extern int img_enemy_eff_mado_fire;
extern int img_enemy_kyoji_size;
extern int img_enemy_kyoji_Attack_size;
extern int img_enemy_kyoji_Attack_effect_size;
extern int img_enemy_kyoji_red_size;
extern int img_enemy_kyoji_red_Attack_size;
extern int img_enemy_totem_Attack_effect[31];
extern int img_enemy_totem_Attack_effect_size;
extern int img_enemy_totem;
extern int img_enemy_boss[14];
extern int img_enemy_boss2[14];
extern int img_enemy_boss_size;
extern int img_enemy_boss_Attack_effect[10];
extern int img_enemy_boss_Attack_effect_size;

void enemyInit();				//�G�̏�����

void EnemyEffectControl();		//�G�̃G�t�F�N�g���Ǘ�

void EnemyCalc(int i, float x, float y, int direcflag = 2);		//�G�̏�����		

void EnemyControl();			//�G�̍s�����Ǘ�

void EnemyDisp();				//�G��\��

void MoveEnemy();				//�G�̈ړ��ʌv�Z

void CalcEnemy();				//�G�̃}�b�v�Ƃ̂����蔻��

int MapHitCheck(float X, float Y, float *MoveX, float *MoveY);

void EnemyAttackCheck();		//�G�̍U�����Ǘ�

void EnemyPattern2(int i);		//�P���x���X�̈ړ��p�^�[��

void EnemyPattern66(int i);		//�ԋ��l�̈ړ��p�^�[��

void EffectPattern3(int i);		//�����m�̃G�t�F�N�g�p�^�[��

void EffectPattern2(int i);		//�P���x���X�̃G�t�F�N�g�p�^�[��

void EffectPattern4(int i);		//���l�̃G�t�F�N�g�p�^�[��

void EffectPattern5(int i);		//�g�[�e���̃G�t�F�N�g�p�^�[��

void EffectPatternBoss(int i);	//�{�X�̃G�t�F�N�g�p�^�[��

void EnemyEffectSet();			//�G�̃G�t�F�N�g���Z�b�g

void EnemyEffectDisp();			//�G�̍U���G�t�F�N�g��\��

#endif