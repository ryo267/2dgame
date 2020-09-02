#include "Header.h"
#include "enemy.h"
#include "player.h"
#include "map.h"
#include "DxLib.h"

int fonthundle;

//ƒOƒ‰ƒtƒBƒbƒN“™‚Ì“Ç
void Load() {

	background = LoadGraph("./‰æ‘œ‘fŞ/back2.png");

	block[0] = LoadGraph("./‰æ‘œ‘fŞ/Wall 2 NW_2.png");//’n–Ê
	block[1] = LoadGraph("./‰æ‘œ‘fŞ/Wall 4 NE_2.png");//’n–Ê
	block[2] = LoadGraph("./‰æ‘œ‘fŞ/Walkway 1 W_2.png");//“Sœ¶
	block[3] = LoadGraph("./‰æ‘œ‘fŞ/Walkway 2 E_2.png");//“Sœ’†ŠÔ
	block[4] = LoadGraph("./‰æ‘œ‘fŞ/Walkway 1 E_2.png");//“Sœ‰E
	block[5] = LoadGraph("./‰æ‘œ‘fŞ/Wall 1 NW_2.png");
	block[6] = LoadGraph("./‰æ‘œ‘fŞ/Wall 1 NE_2.png");
	block[7] = LoadGraph("./‰æ‘œ‘fŞ/Wall 3 SW_2.png");//’†ŠÔ¶’[16
	block[8] = LoadGraph("./‰æ‘œ‘fŞ/Wall 3 SE_2.png");//’†ŠÔ‰E’[17
	block[9] = LoadGraph("./‰æ‘œ‘fŞ/Wall 2 SE_2.png");//’†ŠÔ‰º’[18
	block[10] = LoadGraph("./‰æ‘œ‘fŞ/Wall 1 SW_2.png");//‰º¶’[19
	block[11] = LoadGraph("./‰æ‘œ‘fŞ/Wall 1 SE_2.png");//‰º‰E’[20
	block[12] = LoadGraph("./‰æ‘œ‘fŞ/Wall 5 NW_2.png");//‚Â‚È‚¬–Ú¶21
	block[13] = LoadGraph("./‰æ‘œ‘fŞ/Wall 5 NE_2.png");//‚Â‚È‚¬–Ú‰E22
	block[14] = LoadGraph("./‰æ‘œ‘fŞ/brock_2.png");//’n‰º30
	block[15] = LoadGraph("./‰æ‘œ‘fŞ/brock_5.png");//’n‰º30‘å31(’ƒF)
	block[16] = LoadGraph("./‰æ‘œ‘fŞ/brock_3.png");//’n‰º32
	block[17] = LoadGraph("./‰æ‘œ‘fŞ/brock_4.png");//’n‰º32‘å33(”Z‚¢ƒOƒŒ[)
	block[18] = LoadGraph("./‰æ‘œ‘fŞ/block96-64.png");
	block[19] = LoadGraph("./‰æ‘œ‘fŞ/block160-256.png");

	tail[0] = LoadGraph("./‰æ‘œ‘fŞ/tail1.png");//24
	tail[1] = LoadGraph("./‰æ‘œ‘fŞ/tail2.png");//25
	tail[3] = LoadGraph("./‰æ‘œ‘fŞ/tail3.png");//27
	tail[4] = LoadGraph("./‰æ‘œ‘fŞ/tail4.png");//28
	tail[5] = LoadGraph("./‰æ‘œ‘fŞ/tail5.png");//’n‰º‰E’[34

	toge[0] = LoadGraph("./‰æ‘œ‘fŞ/toge.png");//ƒgƒQ26
	toge[1] = LoadGraph("./‰æ‘œ‘fŞ/toge2.png");//ƒgƒQ40

	pillar[0] = LoadGraph("./‰æ‘œ‘fŞ/pillar1.png");//35h32
	pillar[1] = LoadGraph("./‰æ‘œ‘fŞ/pillar2.png");//36h64
	pillar[2] = LoadGraph("./‰æ‘œ‘fŞ/pillar3.png");//37h96
	pillar[3] = LoadGraph("./‰æ‘œ‘fŞ/pillar4.png");//38h128
	pillar[4] = LoadGraph("./‰æ‘œ‘fŞ/pillar5.png");//39h160
	pillar[5] = LoadGraph("./‰æ‘œ‘fŞ/pillar6.png");//41h32
	pillar[6] = LoadGraph("./‰æ‘œ‘fŞ/pillar7.png");//42h64
	pillar[7] = LoadGraph("./‰æ‘œ‘fŞ/pillar8.png");//43h96
	pillar[8] = LoadGraph("./‰æ‘œ‘fŞ/pillar9.png");//44h128
	pillar[9] = LoadGraph("./‰æ‘œ‘fŞ/pillar10.png");//45h160
	pillar[10] = LoadGraph("./‰æ‘œ‘fŞ/pillar11.png");//46h160w288
	pillar[11] = LoadGraph("./‰æ‘œ‘fŞ/pillar12.png");//47h160w288

	sinden[0] = LoadGraph("./‰æ‘œ‘fŞ/sinden1.png");//29

	tatemono[0] = LoadGraph("./‰æ‘œ‘fŞ/tatemono1.png");//48

	object6464 = LoadGraph("./‰æ‘œ‘fŞ/object6464.png");//49
	object6496 = LoadGraph("./‰æ‘œ‘fŞ/object6496.png");//50
	object64128 = LoadGraph("./‰æ‘œ‘fŞ/object64128.png");//51
	object64160 = LoadGraph("./‰æ‘œ‘fŞ/object64160.png");//52
	object64192 = LoadGraph("./‰æ‘œ‘fŞ/object64192.png");//53
	object64224 = LoadGraph("./‰æ‘œ‘fŞ/object64224.png");//54
	object64256 = LoadGraph("./‰æ‘œ‘fŞ/object64256.png");//55
	object64288 = LoadGraph("./‰æ‘œ‘fŞ/object64288.png");//56
	object64288_2 = LoadGraph("./‰æ‘œ‘fŞ/object64288_2.png");//57

	taimatu = LoadGraph("./‰æ‘œ‘fŞ/taimatu.png");//58

	warpzone1 = LoadGraph("./‰æ‘œ‘fŞ/warpzone1.png");//59
	warpzone2 = LoadGraph("./‰æ‘œ‘fŞ/warpzone2.png");//60

	img_enemy_totem = LoadGraph("./‰æ‘œ‘fŞ/Totem 1 N_2.png");//12
	img_totem[0] = LoadGraph("./‰æ‘œ‘fŞ/Totem 2 N_2.png");//13
	img_totem[1] = LoadGraph("./‰æ‘œ‘fŞ/Totem 1 S_2.png");
	img_totem[2] = LoadGraph("./‰æ‘œ‘fŞ/Totem 2 S_2.png");

	img_enemy_eff_mado_fire = LoadGraph("./‰æ‘œ‘fŞ/fire2.png");

	img_title = LoadGraph("./‰æ‘œ‘fŞ/./tic_tit06l.png");
	img_gameover = LoadGraph("./‰æ‘œ‘fŞ/./tic_go_01l.png");

	LoadDivGraph("./‰æ‘œ‘fŞ/MoveArea.png", 10, 1, 10, 32, 32, MoveArea);//63
	LoadDivGraph("./‰æ‘œ‘fŞ/MoveArea2.png", 10, 10, 1, 32, 32, MoveArea2);
	LoadDivGraph("./‰æ‘œ‘fŞ/MoveArea3.png", 10, 1, 10, 32, 32, MoveArea3);
	LoadDivGraph("./‰æ‘œ‘fŞ/MoveArea4.png", 10, 1, 10, 32, 32, MoveArea4);
	LoadDivGraph("./‰æ‘œ‘fŞ/MoveArea5.png", 10, 10, 1, 32, 32, MoveArea5);


	LoadDivGraph("./‰æ‘œ‘fŞ/kyarakuta-.png", 6, 3, 2, 30, 32, img_player);
	LoadDivGraph("./‰æ‘œ‘fŞ/p_Attack_8.png", 10, 5, 2, 50, 32, img_player_Attack);
	LoadDivGraph("./‰æ‘œ‘fŞ/p_waza10.png", 20, 1, 20, 50, 50, img_player_waza1);

	LoadDivGraph("./‰æ‘œ‘fŞ/waza_3.png", 13, 1, 13, 128, 96, img_eff_waza1);
	LoadDivGraph("./‰æ‘œ‘fŞ/effect.png", 6, 3, 2, 30, 30, img_eff1);
	LoadDivGraph("./‰æ‘œ‘fŞ/effect_2.png", 6, 3, 2, 30, 30, img_eff2);

	LoadDivGraph("./‰æ‘œ‘fŞ/mon_keru6.png", 8, 4, 2, 85, 60, img_enemy_keru);
	LoadDivGraph("./‰æ‘œ‘fŞ/keru_Attack2.png", 6, 3, 2, 85, 60, img_enemy_keru_Attack);
	LoadDivGraph("./‰æ‘œ‘fŞ/madousi_3.png", 8, 4, 2, 32, 32, img_enemy_mado);
	LoadDivGraph("./‰æ‘œ‘fŞ/kyojinn_4.png", 8, 4, 2, 75, 90, img_enemy_kyoji);
	LoadDivGraph("./‰æ‘œ‘fŞ/kyojinn_5.png", 8, 4, 2, 150, 180, img_enemy_kyoji_red);
	LoadDivGraph("./‰æ‘œ‘fŞ/kyoji_attack5.png", 10, 5, 2, 75, 90, img_enemy_kyoji_Attack);
	LoadDivGraph("./‰æ‘œ‘fŞ/kyoji_attack6.png", 10, 5, 2, 150, 180, img_enemy_kyoji_red_Attack);
	LoadDivGraph("./‰æ‘œ‘fŞ/mon_boss_6.png", 14, 7, 2, 640, 480, img_enemy_boss);
	LoadDivGraph("./‰æ‘œ‘fŞ/mon_boss_7.png", 14, 7, 2, 640, 480, img_enemy_boss2);

	LoadDivGraph("./‰æ‘œ‘fŞ/keru_Attack_effect_5.png", 6, 3, 2, 60, 60, img_enemy_keru_Attack_effect);
	LoadDivGraph("./‰æ‘œ‘fŞ/kyoji_attack_effect3.png", 6, 3, 2, 120, 60, img_enemy_kyoji_Attack_effect);
	LoadDivGraph("./‰æ‘œ‘fŞ/totem_attack_effect_3.png", 31, 31, 1, 32, 128, img_enemy_totem_Attack_effect);
	LoadDivGraph("./‰æ‘œ‘fŞ/mon_boss_effect_6.png", 10, 5, 2, 240, 256, img_enemy_boss_Attack_effect);

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

	fonthundle = CreateFontToHandle("Algerian •W€", 20, 20, DX_FONTTYPE_NORMAL);
}