#include "DxLib.h"
#include "Header.h"
#include "map.h"
#include "enemy.h"
#include "camera.h"
#include "player.h"

// 入力状態の初期化
int Input = 0;
int EdgeInput = 0;
int FrameStartTime = 0;
int Key[256]; // キーが押されているフレーム数を格納する
GameState g_gamestate = GAME_TITLE;


// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;							// ＤＸライブラリの初期化

	SetDrawScreen(DX_SCREEN_BACK);								// 描画先を裏画面にセット

	SetWaitVSyncFlag(FALSE);									// 垂直同期信号を待たない

	FrameStartTime = GetNowCount();								// ６０ＦＰＳ固定用、時間保存用変数を現在のカウント値にセット

	Load();														//グラフィックを読込む

	PlaySound("./bgm_maoudamashii_fantasy08.mp3", DX_PLAYTYPE_LOOP);//BGM再生

	enemyInit();												//敵の初期化

	// メインループ開始、ＥＳＣキーで外に出る
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && gpUpdateKey() == 0)
	{
		ClsDrawScreen();										// 画面のクリア

		while (GetNowCount() - FrameStartTime < 1000 / 60) {}	// １/６０秒立つまで待つ

		FrameStartTime = GetNowCount();							// 現在のカウント値を保存

		switch (g_gamestate) {
		case GAME_TITLE:
			if (gameTitle() == 1) {								//タイトル画面の関数を呼ぶ
				g_gamestate = GAME_MAIN;
			}
			break;
		case GAME_MAIN:
			if (ActMain() == 1) {								// ゲーム本編の関数を呼ぶ
				
				enemyInit();									//終わったら敵の初期化(2回目からの初期化がうまくいかない)
			}
			break;
		case GAME_CLEAR:
			if (gameClear() == 1) {								//ゲームクリア画面の関数を呼ぶ
				g_gamestate = GAME_TITLE;
			}
		case GAME_OVER:
			if (gameOver() == 1) {								//ゲームオーバー画面の関数を呼ぶ
				g_gamestate = GAME_TITLE;
			}
			break;
		}
		
		ScreenFlip();											// 画面の更新
	}

	StopSound();												//音楽の再生を止める

	// ＤＸライブラリの後始末
	DxLib_End();

	// 終了
	return 0;
}

// アクションサンプルプログラムメイン
int ActMain(void)
{
		keyUpdate();											//キー入力の更新

		DrawMap(&camerax, &cameray);							//マップと背景の描画

		MoveEnemy();											//敵の移動処理とその管理
		EnemyControl();

		CalcEnemy();											//敵のマップとのあたり判定						

		if (CalcPlayer() == 1){									// プレイヤーのマップとのあたり判定
			g_gamestate = GAME_OVER;
			return 1;
		}

		MoveCamera();											//カメラスクロール
		
		if (playerCollisionCheck() == 1) {						//プレイヤーの衝突判定
			g_gamestate = GAME_OVER;
			return 1;
		}

		if (enemyCollisionCheck() == 1) {						//敵の衝突判定
			g_gamestate = GAME_CLEAR;
			return 1;
		}

		EnemyAttackCheck();										//敵の攻撃を管理
		EnemyDisp();											//敵の表示
		EnemyEffectSet();										//敵のエフェクトをセット
		EnemyEffectDisp();										//敵のエフェクト表示
		EnemyEffectControl();									//敵のエフェクトを管理
		
		MovePlayer();											//プレイヤーの移動処理
		PlayerAttack();											//プレイヤーの攻撃
		PlayerDisp();											//キャラクター描画
		EffDisp();												//プレイヤーのエフェクトを表示
		DrawHP();												//プレイヤーのHPを表示

		if (debugOn() == 1) {									//デバッグモード開始
			debug();
		}
		
	// 終了
	return 0;
}