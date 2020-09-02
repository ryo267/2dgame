#if! defined(_PALYER_H_)
#define _PLAYER_H_
#define JUMP_POWER       (7.0F)                         // キャラのジャンプ力
#define SPEED            (3.0F)                         // キャラの移動スピード

typedef struct PLAYERDATA
{
	int Graphic;//プレイヤーの種類
	int Graphic_X_size;//プレイヤーの横のサイズ
	int Graphic_Y_size;//プレイヤーのの縦のサイズ
	int Graphic_count;//画像の要素数
	int a_Graphic;//攻撃グラフィック
	int m_pattern;//移動パターン
	int a_pattern;//攻撃パターン
	float x, y;//座標
	float DownSp;//プレイヤーの落下速度
	float MoveX, MoveY;//敵の移動量
	float Gravity;//敵にかかる重力
	float draw_x;
	float draw_y;
	int HP_MAX;
	int hp;//プレイヤーのhp
	int MP_MAX;
	int mp;//プレイヤーのhp
	int powor;//プレイヤーの攻撃力
	int item;//プレイヤーが所持しているアイテム
	int flame;//プレイヤーの描画フレーム
	int direcFlag;//プレイヤーの向きのフラグ
	int JumpFlag;//プレイヤーのジャンプフラグ
	int AttackFlag;//攻撃しているかのフラグ
	int flag;//プレイヤーの出現フラグ
	int orb_no;//所持しているオーブの番号
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

extern int img_player[6]; //グラフィックハンドル格納用配列
extern int img_player_size;
extern int img_player_Attack[10];
extern int img_player_Attack_size;
extern int img_player_waza1[20];
extern int img_player_waza1_size;

extern int img_eff1[6];//通常攻撃のグラフィックハンドル格納用配列
extern int img_eff2[6];
extern int img_eff_waza1[13];
extern int img_eff1_size;
extern int img_eff2_size;
extern int img_eff_waza1_size;

//キャラクターの描画
void PlayerDisp();

// プレイヤーの移動処理
void MovePlayer();

//プレイヤーの攻撃関数
void PlayerAttack();

//プレイヤーのエフェクト表示
void EffDisp();

//プレイヤーの初期化
void PlayerCalc(int P, float PlX, float PlY, int direcflag=1);

//プレイヤーとマップとのあたり判定
int PlayerMapHitCheck(float X, float Y, float *MoveX, float *MoveY);

//プレイヤーの体力を表示
void DrawHP();

#endif