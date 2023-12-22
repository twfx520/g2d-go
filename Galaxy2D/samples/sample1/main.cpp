/*
**  =======================================================
**  初始化示例
**  =======================================================
*/

#include "ggebase.h"
using namespace gge;

//帧函数
bool Frame()
{
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//创建游戏引擎
	if (!Engine_Create(GGE_VERSION)) return 0;

	System_SetState(GGE_TITLE, "Galaxy2D Game Engine - Initiate");
	//设置帧函数
	System_SetState(GGE_FRAMEFUNC, Frame);
	//设置帧率
	System_SetState(GGE_FPS, 60);

	//系统初始化
	if (System_Initiate()) 
	{
		//开始运行帧函数
		System_Start();
	}

	//关闭引擎，释放资源
	Engine_Release();
	return 0;
}