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
		//��������
		ggeTexture *tex = Texture_Load("guiicon.png");
		if (!tex)
			return false;

		//��������
		m_ani = CreateAnimationSprite(tex, 15, 20, 20);
		if (!m_ani)
			return false;
		//���ö���ѭ������
		m_ani->SetMode(ANI_LOOP);
		//������������
		m_ani->Play();

		//�����Ѿ������ˣ�������
		GGE_RELEASE(tex);

		//������ȾĿ������
		m_target = Texture_CreateRenderTarget(640, 480);
		if (!m_target)
			return false;
		//������ȾĿ��Sprite
		m_spr = Sprite_Create(m_target);

		//���PS֧��
		if (System_GetState(GGE_PSVERSION) < PS_2_0) 
			return false;
		//����shader
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
		//������ȾĿ��
		Graph_BeginScene(m_target);
		Graph_Clear();

		//��Ⱦ����
		m_ani->RenderEx(128, 240, 0, 3.0f);

		//������ȾĿ�����
		Graph_EndScene();

		//�ָ�Ĭ����ȾĿ��
		Graph_BeginScene();

		//������ȾĿ������
		m_spr->Render(0, 0);

		//����shader
		Graph_SetCurrentShader(m_shader);
		//����shader�õ�������
		m_shader->SetTexture("uSourcImg", m_target);

		//������ȾĿ������
		m_spr->Render(320, 0);

		//���shader
		Graph_SetCurrentShader(0);

		//������Ⱦ
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