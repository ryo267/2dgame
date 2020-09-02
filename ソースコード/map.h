#if! defined(_MAP_H_)
#define _MAP_H_
#define MAP_PIXEL_WIDTH (6400)
#define MAP_PIXEL_HEIGHT (2560)

#define CHIP_SIZE        (32)                           // ��̃`�b�v�̃T�C�Y
#define MAP_WIDTH        (MAP_PIXEL_WIDTH / CHIP_SIZE)     // �}�b�v�̉���
#define MAP_HEIGHT       (MAP_PIXEL_HEIGHT / CHIP_SIZE)    // �}�b�v�̏c�� 

// �}�b�v�f�[�^
extern char MapData[MAP_HEIGHT][MAP_WIDTH];
extern char MapDate[640][480];

extern int view_chipx;//�}�b�v�̕\���ʒu�B���̍��W�Ƀ}�b�v��draw����B
extern int view_chipy;

extern int block[30];//�u���b�N�̃O���t�B�b�N�ԍ����L�����Ă����ϐ�
extern int tail[20];
extern int sinden[10];
extern int back[4];
extern int toge[2];
extern int pillar[15];
extern int tatemono[10];
extern int img_totem[3];

extern int object6464;
extern int object6496;
extern int object64128;
extern int object64160;
extern int object64192;
extern int object64224;
extern int object64256;
extern int object64288;
extern int object64288_2;

extern int taimatu;

//�w�i�O���t�B�b�N�ԍ����L�����Ă����ϐ�
extern int background;

extern int warpzone1;
extern int warpzone2;
extern int warpPoint_x[10];
extern int warpPoint_y[10];

extern int MoveArea[10];
extern int MoveArea2[10];
extern int MoveArea3[10];
extern int MoveArea4[10];
extern int MoveArea5[10];
extern int n;

extern int blockcount;

//�}�b�v�Ɣw�i��`�悷��֐�
int DrawMap(float *camerax, float *cameray);

// �}�b�v�`�b�v�̒l���擾����֐�
int GetChipParam(float X, float Y);

#endif
