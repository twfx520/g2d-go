/*
**  =======================================================
**  RenderTarget,Sharder
**  =======================================================
*/

#include "ggebase.h"
#include "ggefw.h"
#include "ggetexture.h"
#include "ggesprite.h"
#include "ggeanimation.h"
#include "ggeshader.h"
#include "../sample4/animation.h"
using namespace gge;

class CGameMain : public ggeApplication
{
public:
	CGameMain()
	{
		m_shader = 0;
		m_spr = 0;
		m_target = 0;
		m_ani = 0;
	}

	bool OnConfig()					
	{ 
		System_SetState(GGE_TITLE, "Galaxy2D Game Engine - RenderTarget,Sharder");
		return true; 
	}

	bool OnInitiate()				
	{ 
		//载入纹理
		ggeTexture *tex = Texture_Load("guiicon.png");
		if (!tex)
			return false;

		//创建动画
		m_ani = CreateAnimationSprite(tex, 15, 20, 20);
		if (!m_ani)
			return false;
		//设置动画循环播放
		m_ani->SetMode(ANI_LOOP);
		//开启动画播放
		m_ani->Play();

		//纹理已经不用了，减引用
		GGE_RELEASE(tex);

		//创建渲染目标纹理
		m_target = Texture_CreateRenderTarget(640, 480);
		if (!m_target)
			return false;
		//创建渲染目标Sprite
		m_spr = Sprite_Create(m_target);

		//检查PS支持
		if (System_GetState(GGE_PSVERSION) < PS_2_0) 
			return false;
		//载入shader
		m_shader = Shader_Load("shader.fx", "main", PS_2_0);
		if (!m_shader) 
			return false;

		return true; 
	}

	void OnRelease()				
	{
		GGE_RELEASE(m_shader);
		GGE_RELEASE(m_spr);
		GGE_RELEASE(m_target);
		GGE_RELEASE(m_ani);
	}

	void OnUpdate(float dt)
	{
		m_ani->Update(dt);

		if (Input_IsKeyDown(GGEK_ESCAPE))
			Exit();
	}

	void OnRender()
	{
		//启用渲染目标
		Graph_BeginScene(m_target);
		Graph_Clear();

		//渲染动画
		m_ani->RenderEx(128, 240, 0, 3.0f);

		//结束渲染目标绘制
		Graph_EndScene();

		//恢复默认渲染目标
		Graph_BeginScene();

		//绘制渲染目标纹理
		m_spr->Render(0, 0);

		//设置shader
		Graph_SetCurrentShader(m_shader);
		//设置shader用到的纹理
		m_shader->SetTexture("uSourcImg", m_target);

		//绘制渲染目标纹理
		m_spr->Render(320, 0);

		//清除shader
		Graph_SetCurrentShader(0);

		//结束渲染
		Graph_EndScene();
	}

private:
	ggeShader		*m_shader;
	ggeTexture		*m_target;
	ggeSprite		*m_spr;
	ggeAnimation	*m_ani;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	CGameMain GameMain;
	GameMain.Start();
	return 0;
}