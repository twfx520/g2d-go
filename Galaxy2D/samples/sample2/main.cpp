/*
**  =======================================================
**  资源管理器，粒子，轨迹带的使用
**  =======================================================
*/

#include "ggebase.h"
#include "ggeresmanager.h"
#include "ggeparticle.h"
#include "ggetexture.h"
#include "ggeribbontrail.h"
using namespace gge;

ggeParticle	*par;
ggeParticle *par2;
ggeRibbonTrail *trail;

ggeVector vec(100.0f, 0);
float rot = 5.0f;

bool Frame()
{
	if (Input_IsKeyDown(GGEK_ESCAPE)) return true;

	Graph_BeginScene();
	Graph_Clear();

	//刷新粒子系统
	par->Update(Timer_GetDelta());
	par2->Update(Timer_GetDelta());
	//渲染粒子系统
	par2->Render();
	par->Render();

	//刷新轨迹带
	ggeRect rect;
	vec.Rotate(rot * Timer_GetDelta());
	trail->MoveTo(320 + vec.x, 240 + vec.y);
	trail->Update(Timer_GetDelta());
	//渲染轨迹带
	trail->Render();

	Graph_EndScene();

	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!Engine_Create(GGE_VERSION)) return 0;

	System_SetState(GGE_TITLE, "Galaxy2D Game Engine - ResManager, Particle, Ribbontrail");
	System_SetState(GGE_FRAMEFUNC, Frame);
	System_SetState(GGE_FPS, 60);

	if (System_Initiate())
	{
		//创建资源管理器
		ggeResManager *resmgr = ResManager_Create();
		//载入资源文件
		resmgr->LoadResFile("res.res");

		//创建粒子系统
		par = resmgr->CreateParticle("par");
		par2 = resmgr->CreateParticle("par2");

		//在指定的位置开始运行粒子系统
		par->FireAt(320, 240);
		par2->FireAt(320, 240);

		//创建轨迹带
		trail = RibbonTrail_Create(0xFFFFCC00, 0x00FF8000, 32.0f);
		ggeTexture *tex = resmgr->CreateTexture("partex");
		trail->SetTexture(tex);
		trail->SetTextureRect(0, 0, 32, 32);

		System_Start();

		//释放资源
		GGE_RELEASE(par);
		GGE_RELEASE(par2);
		GGE_RELEASE(tex);
		GGE_RELEASE(resmgr);
	}

	Engine_Release();
	return 0;
}