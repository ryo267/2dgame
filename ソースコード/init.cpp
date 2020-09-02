#include "Header.h"
#include "enemy.h"
#include "player.h"
#include "map.h"
#include "DxLib.h"

int fonthundle;

//�O���t�B�b�N���̓Ǎ�
void Load() {

	background = LoadGraph("./�摜�f��/back2.png");

	block[0] = LoadGraph("./�摜�f��/Wall 2 NW_2.png");//�n��
	block[1] = LoadGraph("./�摜�f��/Wall 4 NE_2.png");//�n��
	block[2] = LoadGraph("./�摜�f��/Walkway 1 W_2.png");//�S����
	block[3] = LoadGraph("./�摜�f��/Walkway 2 E_2.png");//�S������
	block[4] = LoadGraph("./�摜�f��/Walkway 1 E_2.png");//�S���E
	block[5] = LoadGraph("./�摜�f��/Wall 1 NW_2.png");
	block[6] = LoadGraph("./�摜�f��/Wall 1 NE_2.png");
	block[7] = LoadGraph("./�摜�f��/Wall 3 SW_2.png");//���ԍ��[16
	block[8] = LoadGraph("./�摜�f��/Wall 3 SE_2.png");//���ԉE�[17
	block[9] = LoadGraph("./�摜�f��/Wall 2 SE_2.png");//���ԉ��[18
	block[10] = LoadGraph("./�摜�f��/Wall 1 SW_2.png");//�����[19
	block[11] = LoadGraph("./�摜�f��/Wall 1 SE_2.png");//���E�[20
	block[12] = LoadGraph("./�摜�f��/Wall 5 NW_2.png");//�Ȃ��ڍ�21
	block[13] = LoadGraph("./�摜�f��/Wall 5 NE_2.png");//�Ȃ��ډE22
	block[14] = LoadGraph("./�摜�f��/brock_2.png");//�n��30
	block[15] = LoadGraph("./�摜�f��/brock_5.png");//�n��30��31(���F)
	block[16] = LoadGraph("./�摜�f��/brock_3.png");//�n��32
	block[17] = LoadGraph("./�摜�f��/brock_4.png");//�n��32��33(�Z���O���[)
	block[18] = LoadGraph("./�摜�f��/block96-64.png");
	block[19] = LoadGraph("./�摜�f��/block160-256.png");

	tail[0] = LoadGraph("./�摜�f��/tail1.png");//24
	tail[1] = LoadGraph("./�摜�f��/tail2.png");//25
	tail[3] = LoadGraph("./�摜�f��/tail3.png");//27
	tail[4] = LoadGraph("./�摜�f��/tail4.png");//28
	tail[5] = LoadGraph("./�摜�f��/tail5.png");//�n���E�[34

	toge[0] = LoadGraph("./�摜�f��/toge.png");//�g�Q26
	toge[1] = LoadGraph("./�摜�f��/toge2.png");//�g�Q40

	pillar[0] = LoadGraph("./�摜�f��/pillar1.png");//35h32
	pillar[1] = LoadGraph("./�摜�f��/pillar2.png");//36h64
	pillar[2] = LoadGraph("./�摜�f��/pillar3.png");//37h96
	pillar[3] = LoadGraph("./�摜�f��/pillar4.png");//38h128
	pillar[4] = LoadGraph("./�摜�f��/pillar5.png");//39h160
	pillar[5] = LoadGraph("./�摜�f��/pillar6.png");//41h32
	pillar[6] = LoadGraph("./�摜�f��/pillar7.png");//42h64
	pillar[7] = LoadGraph("./�摜�f��/pillar8.png");//43h96
	pillar[8] = LoadGraph("./�摜�f��/pillar9.png");//44h128
	pillar[9] = LoadGraph("./�摜�f��/pillar10.png");//45h160
	pillar[10] = LoadGraph("./�摜�f��/pillar11.png");//46h160w288
	pillar[11] = LoadGraph("./�摜�f��/pillar12.png");//47h160w288

	sinden[0] = LoadGraph("./�摜�f��/sinden1.png");//29

	tatemono[0] = LoadGraph("./�摜�f��/tatemono1.png");//48

	object6464 = LoadGraph("./�摜�f��/object6464.png");//49
	object6496 = LoadGraph("./�摜�f��/object6496.png");//50
	object64128 = LoadGraph("./�摜�f��/object64128.png");//51
	object64160 = LoadGraph("./�摜�f��/object64160.png");//52
	object64192 = LoadGraph("./�摜�f��/object64192.png");//53
	object64224 = LoadGraph("./�摜�f��/object64224.png");//54
	object64256 = LoadGraph("./�摜�f��/object64256.png");//55
	object64288 = LoadGraph("./�摜�f��/object64288.png");//56
	object64288_2 = LoadGraph("./�摜�f��/object64288_2.png");//57

	taimatu = LoadGraph("./�摜�f��/taimatu.png");//58

	warpzone1 = LoadGraph("./�摜�f��/warpzone1.png");//59
	warpzone2 = LoadGraph("./�摜�f��/warpzone2.png");//60

	img_enemy_totem = LoadGraph("./�摜�f��/Totem 1 N_2.png");//12
	img_totem[0] = LoadGraph("./�摜�f��/Totem 2 N_2.png");//13
	img_totem[1] = LoadGraph("./�摜�f��/Totem 1 S_2.png");
	img_totem[2] = LoadGraph("./�摜�f��/Totem 2 S_2.png");

	img_enemy_eff_mado_fire = LoadGraph("./�摜�f��/fire2.png");

	img_title = LoadGraph("./�摜�f��/./tic_tit06l.png");
	img_gameover = LoadGraph("./�摜�f��/./tic_go_01l.png");

	LoadDivGraph("./�摜�f��/MoveArea.png", 10, 1, 10, 32, 32, MoveArea);//63
	LoadDivGraph("./�摜�f��/MoveArea2.png", 10, 10, 1, 32, 32, MoveArea2);
	LoadDivGraph("./�摜�f��/MoveArea3.png", 10, 1, 10, 32, 32, MoveArea3);
	LoadDivGraph("./�摜�f��/MoveArea4.png", 10, 1, 10, 32, 32, MoveArea4);
	LoadDivGraph("./�摜�f��/MoveArea5.png", 10, 10, 1, 32, 32, MoveArea5);


	LoadDivGraph("./�摜�f��/kyarakuta-.png", 6, 3, 2, 30, 32, img_player);
	LoadDivGraph("./�摜�f��/p_Attack_8.png", 10, 5, 2, 50, 32, img_player_Attack);
	LoadDivGraph("./�摜�f��/p_waza10.png", 20, 1, 20, 50, 50, img_player_waza1);

	LoadDivGraph("./�摜�f��/waza_3.png", 13, 1, 13, 128, 96, img_eff_waza1);
	LoadDivGraph("./�摜�f��/effect.png", 6, 3, 2, 30, 30, img_eff1);
	LoadDivGraph("./�摜�f��/effect_2.png", 6, 3, 2, 30, 30, img_eff2);

	LoadDivGraph("./�摜�f��/mon_keru6.png", 8, 4, 2, 85, 60, img_enemy_keru);
	LoadDivGraph("./�摜�f��/keru_Attack2.png", 6, 3, 2, 85, 60, img_enemy_keru_Attack);
	LoadDivGraph("./�摜�f��/madousi_3.png", 8, 4, 2, 32, 32, img_enemy_mado);
	LoadDivGraph("./�摜�f��/kyojinn_4.png", 8, 4, 2, 75, 90, img_enemy_kyoji);
	LoadDivGraph("./�摜�f��/kyojinn_5.png", 8, 4, 2, 150, 180, img_enemy_kyoji_red);
	LoadDivGraph("./�摜�f��/kyoji_attack5.png", 10, 5, 2, 75, 90, img_enemy_kyoji_Attack);
	LoadDivGraph("./�摜�f��/kyoji_attack6.png", 10, 5, 2, 150, 180, img_enemy_kyoji_red_Attack);
	LoadDivGraph("./�摜�f��/mon_boss_6.png", 14, 7, 2, 640, 480, img_enemy_boss);
	LoadDivGraph("./�摜�f��/mon_boss_7.png", 14, 7, 2, 640, 480, img_enemy_boss2);

	LoadDivGraph("./�摜�f��/keru_Attack_effect_5.png", 6, 3, 2, 60, 60, img_enemy_keru_Attack_effect);
	LoadDivGraph("./�摜�f��/kyoji_attack_effect3.png", 6, 3, 2, 120, 60, img_enemy_kyoji_Attack_effect);
	LoadDivGraph("./�摜�f��/totem_attack_effect_3.png", 31, 31, 1, 32, 128, img_enemy_totem_Attack_effect);
	LoadDivGraph("./�摜�f��/mon_boss_effect_6.png", 10, 5, 2, 240, 256, img_enemy_boss_Attack_effect);

	img_enemy_keru_size = sizeof img_enemy_keru / sizeof img_enemy_keru[0];
	img_enemy_keru_Attack_size = sizeof img_enemy_keru_Attack / sizeof img_enemy_keru_Attack[0];
	img_enemy_keru_Attack_effect_size = sizeof img_enemy_keru_Attack_effect / sizeof img_enemy_keru_Attack_effect[0];
	img_enemy_mado_size = sizeof img_enemy_mado / sizeof img_enemy_mado[0];
	img_enemy_kyoji_size = sizeof img_enemy_kyoji / sizeof img_enemy_kyoji[0];
	img_enemy_kyoji_Attack_size = sizeof img_enemy_kyoji_Attack / sizeof img_enemy_kyoji_Attack[0];
	img_enemy_kyoji_Attack_effect_size = sizeof img_enemy_kyoji_Attack_effect / sizeof img_enemy_kyoji_Attack_effect[0];
	img_enemy_kyoji_red_size = sizeof img_enemy_kyoji_red / sizeof img_enemy_kyoji_red[0];
	img_enemy_kyoji_red_Attack_size = sizeof img_enemy_kyoji_red_Attack / sizeof img_enemy_kyoji_red_Attack[0];
	img_enemy_totem_Attack_effect_size = sizeof img_enemy_totem_Attack_effect / sizeof img_enemy_totem_Attack_effect[0];
	img_enemy_boss_size = sizeof img_enemy_boss / sizeof img_enemy_boss[0];
	img_enemy_boss_Attack_effect_size = sizeof img_enemy_boss_Attack_effect / sizeof img_enemy_boss_Attack_effect[0];

	fonthundle = CreateFontToHandle("Algerian �W��", 20, 20, DX_FONTTYPE_NORMAL);
}