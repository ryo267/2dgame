#if! defined(_ENEMY_H_)
#define _ENEMY_H_

#include "DxLib.h"

enum enemy {
	ケルベロス = 2,
	魔導士 = 3,
	巨人 = 4,
	赤巨人 = 66,
	BOSS = 70
};

typedef struct ENEMYDATA
{
	int Graphic;//敵の種類
	int Graphic_X_size;//敵の横のサイズ
	int Graphic_Y_size;//敵の縦のサイズ
	int Graphic_size;
	int Graphic_count;//敵の画像の要素数
	int a_Graphic;//攻撃グラフィック
	int m_pattern;//移動パターン
	int a_pattern;//攻撃パターン
	float x, y;//座標
	float DownSp; // 敵の落下速度
	float MoveX, MoveY;//敵の移動量
	float Gravity;//敵にかかる重力
	float draw_x;
	float draw_y;
	int hp;//敵のhp
	int powor;//敵の攻撃力
	int item;//敵が所持しているアイテム
	int flame;//敵の描画フレーム
	int direcFlag;//敵の向きのフラグ
	int JumpFlag;//敵のジャンプフラグ
	int AttackFlag;
	int AttackDrawFlag;
	int DamegeFlag;
	int flag;//敵の出現フラグ
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

void enemyInit();				//敵の初期化

void EnemyEffectControl();		//敵のエフェクトを管理

void EnemyCalc(int i, float x, float y, int direcflag = 2);		//敵の初期化		

void EnemyControl();			//敵の行動を管理

void EnemyDisp();				//敵を表示

void MoveEnemy();				//敵の移動量計算

void CalcEnemy();				//敵のマップとのあたり判定

int MapHitCheck(float X, float Y, float *MoveX, float *MoveY);

void EnemyAttackCheck();		//敵の攻撃を管理

void EnemyPattern2(int i);		//ケルベロスの移動パターン

void EnemyPattern66(int i);		//赤巨人の移動パターン

void EffectPattern3(int i);		//魔導士のエフェクトパターン

void EffectPattern2(int i);		//ケルベロスのエフェクトパターン

void EffectPattern4(int i);		//巨人のエフェクトパターン

void EffectPattern5(int i);		//トーテムのエフェクトパターン

void EffectPatternBoss(int i);	//ボスのエフェクトパターン

void EnemyEffectSet();			//敵のエフェクトをセット

void EnemyEffectDisp();			//敵の攻撃エフェクトを表示

#endif