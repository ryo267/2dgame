#include "Header.h"
#include "DxLib.h"


// �L�[�̓��͏�Ԃ��X�V����
int gpUpdateKey() {
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int z = 0; z<256; z++) {
		if (tmpKey[z] != 0) { // z�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[z]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			Key[z] = 0;   // 0�ɂ���
		}
	}
	return 0;
}

void keyUpdate() {
	// ���͏�Ԃ��X�V
	{
		int i;

		// �p�b�h�P�ƃL�[�{�[�h������͂𓾂�
		i = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// �G�b�W����������͂��Z�b�g
		EdgeInput = i & ~Input;

		// ���͏�Ԃ̕ۑ�
		Input = i;
	}
}