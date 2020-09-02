#include "Header.h"
#include "DxLib.h"


// キーの入力状態を更新する
int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int z = 0; z<256; z++) {
		if (tmpKey[z] != 0) { // z番のキーコードに対応するキーが押されていたら
			Key[z]++;     // 加算
		}
		else {              // 押されていなければ
			Key[z] = 0;   // 0にする
		}
	}
	return 0;
}

void keyUpdate() {
	// 入力状態を更新
	{
		int i;

		// パッド１とキーボードから入力を得る
		i = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// エッジを取った入力をセット
		EdgeInput = i & ~Input;

		// 入力状態の保存
		Input = i;
	}
}