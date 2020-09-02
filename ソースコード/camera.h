#if! defined(__)
#define _CAMERA_H_
extern int ScrollFlag;//スクロールさせるフラグ
extern float camerax; //カメラ左上の座標
extern float cameray; 

//カメラをスクロールする関数
void MoveCamera();

#endif