#if! defined(_HEADER_H_)
#define _HEADER_

#define DEBUG 1

#define SCREEN_WIDTH     (640)                         // ��ʂ̉���
#define SCREEN_HEIGHT    (480)                          // ��ʂ̏c��

#define G                (0.3F)                         // �L�����Ɋ|����d�͉����x
#define CHAR_SIZE_X        (30)                           // �v���C���[�̉��T�C�Y
#define CHAR_SIZE_Y		   (32)							  //�@�v���C���[�̏c�T�C�Y

enum GameState {
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};
extern GameState g_gamestate;

extern int Input, EdgeInput;      // ���͏��
extern int FrameStartTime;        // �U�O�e�o�r�Œ�p�A���ԕۑ��p�ϐ�
extern int Key[256]; // �L�[��������Ă���t���[�������i�[����

extern int fonthundle;
extern int img_title;
extern int img_gameover;

extern int db;

//�^�C�g�����
int gameTitle();

//�Q�[���N���A���
int gameClear();

//�Q�[���I�[�o�[���
int gameOver();

// �L�����N�^���}�b�v�Ƃ̓����蔻����l�����Ȃ���ړ�����֐�
int CalcPlayer();

// �A�N�V�����T���v���v���O�������C���֐�
int ActMain(void);

//�L�[���͍X�V
int gpUpdateKey();

//�O���t�B�b�N���̓Ǎ�
void Load();

//�Փ˔���
int enemyCollisionCheck();

//�v���C���[�̏Փ˔���
int playerCollisionCheck();

//�L�[���͍X�V
void keyUpdate();

//�f�o�b�O�p
void debug();

//�f�o�b�O�J�n
int debugOn();
#endif