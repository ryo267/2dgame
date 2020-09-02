#if! defined(_PALYER_H_)
#define _PLAYER_H_
#define JUMP_POWER       (7.0F)                         // �L�����̃W�����v��
#define SPEED            (3.0F)                         // �L�����̈ړ��X�s�[�h

typedef struct PLAYERDATA
{
	int Graphic;//�v���C���[�̎��
	int Graphic_X_size;//�v���C���[�̉��̃T�C�Y
	int Graphic_Y_size;//�v���C���[�̂̏c�̃T�C�Y
	int Graphic_count;//�摜�̗v�f��
	int a_Graphic;//�U���O���t�B�b�N
	int m_pattern;//�ړ��p�^�[��
	int a_pattern;//�U���p�^�[��
	float x, y;//���W
	float DownSp;//�v���C���[�̗������x
	float MoveX, MoveY;//�G�̈ړ���
	float Gravity;//�G�ɂ�����d��
	float draw_x;
	float draw_y;
	int HP_MAX;
	int hp;//�v���C���[��hp
	int MP_MAX;
	int mp;//�v���C���[��hp
	int powor;//�v���C���[�̍U����
	int item;//�v���C���[���������Ă���A�C�e��
	int flame;//�v���C���[�̕`��t���[��
	int direcFlag;//�v���C���[�̌����̃t���O
	int JumpFlag;//�v���C���[�̃W�����v�t���O
	int AttackFlag;//�U�����Ă��邩�̃t���O
	int flag;//�v���C���[�̏o���t���O
	int orb_no;//�������Ă���I�[�u�̔ԍ�
}PLAYERDATA;

extern PLAYERDATA player;

typedef struct ATTACK {
	int att_flag;
	int eff_flag;
	int att_DamegeFlag;
	int att_power;
	int att_Graphic;
	int att_Graphic_size;
	int att_Graphic_count;
	int att_flame;
	int eff_flame;
	float att_x, att_y;
	int Graphic_X_size;
	int Graphic_Y_size;
	int eff_no;
	float eff_x, eff_y;
	int eff_Graphic_X_size;
	int eff_Graphic_Y_size;
	int eff_Graphic_size;
	int eff_Graphic_count;
}ATT;

extern ATT att;

extern int img_player[6]; //�O���t�B�b�N�n���h���i�[�p�z��
extern int img_player_size;
extern int img_player_Attack[10];
extern int img_player_Attack_size;
extern int img_player_waza1[20];
extern int img_player_waza1_size;

extern int img_eff1[6];//�ʏ�U���̃O���t�B�b�N�n���h���i�[�p�z��
extern int img_eff2[6];
extern int img_eff_waza1[13];
extern int img_eff1_size;
extern int img_eff2_size;
extern int img_eff_waza1_size;

//�L�����N�^�[�̕`��
void PlayerDisp();

// �v���C���[�̈ړ�����
void MovePlayer();

//�v���C���[�̍U���֐�
void PlayerAttack();

//�v���C���[�̃G�t�F�N�g�\��
void EffDisp();

//�v���C���[�̏�����
void PlayerCalc(int P, float PlX, float PlY, int direcflag=1);

//�v���C���[�ƃ}�b�v�Ƃ̂����蔻��
int PlayerMapHitCheck(float X, float Y, float *MoveX, float *MoveY);

//�v���C���[�̗̑͂�\��
void DrawHP();

#endif