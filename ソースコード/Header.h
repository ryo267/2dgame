#if! defined(_HEADER_H_)
#define _HEADER_

#define DEBUG 1

#define SCREEN_WIDTH     (640)                         // 画面の横幅
#define SCREEN_HEIGHT    (480)                          // 画面の縦幅

#define G                (0.3F)                         // キャラに掛かる重力加速度
#define CHAR_SIZE_X        (30)                           // プレイヤーの横サイズ
#define CHAR_SIZE_Y		   (32)							  //　プレイヤーの縦サイズ

enum GameState {
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};
extern GameState g_gamestate;

extern int Input, EdgeInput;      // 入力状態
extern int FrameStartTime;        // ６０ＦＰＳ固定用、時間保存用変数
extern int Key[256]; // キーが押されているフレーム数を格納する

extern int fonthundle;
extern int img_title;
extern int img_gameover;

extern int db;

//タイトル画面
int gameTitle();

//ゲームクリア画面
int gameClear();

//ゲームオーバー画面
int gameOver();

// キャラクタをマップとの当たり判定を考慮しながら移動する関数
int CalcPlayer();

// アクションサンプルプログラムメイン関数
int ActMain(void);

//キー入力更新
int gpUpdateKey();

//グラフィック等の読込
void Load();

//衝突判定
int enemyCollisionCheck();

//プレイヤーの衝突判定
int playerCollisionCheck();

//キー入力更新
void keyUpdate();

//デバッグ用
void debug();

//デバッグ開始
int debugOn();
#endif