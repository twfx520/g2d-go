/*
**  =======================================================
**  ��ʼ��ʾ��
**  =======================================================
*/

#include "ggebase.h"
using namespace gge;

//֡����
bool Frame()
{
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//������Ϸ����
	if (!Engine_Create(GGE_VERSION)) return 0;

	System_SetState(GGE_TITLE, "Galaxy2D Game Engine - Initiate");
	//����֡����
	System_SetState(GGE_FRAMEFUNC, Frame);
	//����֡��
	System_SetState(GGE_FPS, 60);

	//ϵͳ��ʼ��
	if (System_Initiate()) 
	{
		//��ʼ����֡����
		System_Start();
	}

	//�ر����棬�ͷ���Դ
	Engine_Release();
	return 0;
}