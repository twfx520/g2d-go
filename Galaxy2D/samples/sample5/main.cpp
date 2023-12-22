/*
**  =======================================================
**  Sprite，动画，音乐，音效
**  =======================================================
*/

#include "ggebase.h"
#include "ggefw.h"
#include "ggetexture.h"
#include "ggesprite.h"
#include "ggeanimation.h"
#include "ggesound.h"
#include "ggemusic.h"
#include "ggesoundeffect.h"
#include "ggefont.h"
#include "ggemath.h"
#include "../sample4/animation.h"
using namespace gge;



//继承应用程序框架，以简化代码
class CGameMain : public ggeApplication
{
public:
	CGameMain()
	{
		m_spr = 0;
		m_ani = 0;
		m_sound = 0;
		m_music = 0;
		m_font = 0;
		m_effect = 0;

		m_soundPos = ggeVector(100.0f, 0);
		m_soundLastPos = ggeVector(100.0f, 0);
		m_listenerPos = ggeVector(320.0f, 240.0f);

		m_dir		= 0;
		m_scale		= 1.0f;
		m_scaleDt	= 0.4f;
	}

	//初始化配置信息，例如设置各种系统状态等
	bool OnConfig()					
	{ 
		System_SetState(GGE_TITLE, "Galaxy2D Game Engine - Sprite, Animation, Sound");

		//绑定文件包
		if (!Resource_AttachPack("data.dat", "123"))
			return false;

		return true; 
	}

	//游戏启动成功后回调该函数，可在此初始化各种资源等
	bool OnInitiate()				
	{ 
		//载入纹理
		ggeTexture *tex = Texture_Load("guiicon.png");
		if (!tex)
			return false;

		//创建Sprite
		m_spr = Sprite_Create(tex, 0, 0, 20.0f, 20.0f);
		if (!m_spr)
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

		//载入音效
		m_sound = Sound_Load("sound.ogg");
		if (!m_sound)
			return false;

		//载入音乐
		m_music = Music_Load("music.ogg");
		if (!m_music)
			return false;

		//初始化音频数据
		Audio_SetListenerPosition(ggeVector3(m_listenerPos.x, 0, m_listenerPos.y));
		Audio_SetDopplerScale(0.4f);

		//创建音效器
		if (System_GetState(GGE_SOUNDEFFECT))
		{
			m_effect = SoundEffect_Create();
			m_effect->SetType(EFFECT_FLANGER);
			m_effect->SetParameter(SEP_FLANGER_RATE, 4);
			m_effect->SetActive(true);
		}

		//创建字体
		m_font = Font_Create("DejaVuSans.ttf", 16, FONT_MODE_BORDER);
		if (!m_font)
			return false;
		//设置字体颜色
		m_font->SetBorderColor(0xFF0000FF);

		return true; 
	}

	void OnRelease()				
	{
		GGE_RELEASE(m_spr);
		GGE_RELEASE(m_ani);
		GGE_RELEASE(m_sound);
		GGE_RELEASE(m_music);
		GGE_RELEASE(m_font);
		GGE_RELEASE(m_effect);
	}

	void OnUpdate(float dt)
	{
		m_dir += dt;
		if (m_scale > 1.5f)
		{
			m_scale = 1.5f;
			m_scaleDt = -m_scaleDt;
		}
		else if (m_scale < 0.5f)
		{
			m_scale = 0.5f;
			m_scaleDt = -m_scaleDt;
		};

		m_scale += m_scaleDt * dt;

		//刷新动画
		m_ani->Update(dt);

		//刷新音效位置等数据
		m_soundPos.Rotate(Timer_GetDelta() * 4);
		ggeVector curpos = m_soundPos + m_listenerPos + ggeVector(0, 50);
		ggeVector soundVelocity = m_soundPos - m_soundLastPos;
		m_soundLastPos = m_soundPos;

		m_sound->SetPosition(ggeVector3(curpos.x, 0, curpos.y));
		m_sound->SetMinDistance(50);
		m_sound->SetVelocity(ggeVector3(soundVelocity.x, 0, soundVelocity.y));

		//可以用Input_GetKey()函数拿到当前按键的键值
		switch (Input_GetKey())
		{
		case 'Q':
			m_music->Play(true); //循环播放音乐
			break;

		case 'W':
			m_music->Stop();
			break;

		case 'A':
			m_music->Pause();
			break;

		case 'S':
			m_music->Resume();
			break;

		case 'Z':
			m_music->SetVolume(m_music->GetVolume() - 1.0f);
			break;

		case 'X':
			m_music->SetVolume(m_music->GetVolume() + 1.0f);
			break;

		case 'D':
			m_music->SetLoop(!m_music->IsLoop());
			break;

		case 'E':
			m_sound->SetVolume(m_sound->GetVolume() - 1.0f);
			break;

		case 'R':
			m_sound->SetVolume(m_sound->GetVolume() + 1.0f);
			break;

		case 'C':
			m_sound->SetPitch(m_sound->GetPitch() - dt * 10.0f);
			break;

		case 'V':
			m_sound->SetPitch(m_sound->GetPitch() + dt * 10.0f);
			break;

		case 'T':
			if (m_effect)
				m_sound->AddEffect(m_effect);
			break;

		case 'Y':
			m_sound->ClearEffect();
			break;

		case VK_SPACE:
			m_sound->Play(); //播放音效
			break;
		}

		//如果按下Esc键则退出，与Input_GetKey不同，Input_IsKeyDown()可以同时检测多个按键
		if (Input_IsKeyDown(GGEK_ESCAPE))
			Exit();
	}

	void OnRender()
	{
		//开始渲染
		Graph_BeginScene();
		//清除屏幕
		Graph_Clear();

		//渲染Sprite
		m_spr->Render(0, 0);

		//渲染动画
		m_ani->Render(32.0f, 10.0f);
		m_ani->RenderStretch(50.0f, 0.0f, 90.0f, 64.0f);
		m_ani->Render4V(120.0f, 0.0f, 140.0f, 0.0f, 160.0f, 40.0f, 180.0f, 40.0f);
		m_ani->RenderEx(200.0f, 20.0f, m_dir, m_scale);

		m_soundPos.Rotate(Timer_GetDelta() * 4);
		ggeVector curpos = m_soundPos + m_listenerPos + ggeVector(0, 50);
		ggeVector vel = m_soundPos - m_soundLastPos;
		m_soundLastPos = m_soundPos;

		Graph_RenderRect(m_listenerPos.x - 4, m_listenerPos.y - 4, m_listenerPos.x + 4, m_listenerPos.y + 4, 0xFFFF0000);
		Graph_RenderRect(curpos.x - 4, curpos.y - 4, curpos.x + 4, curpos.y + 4, 0xFF0000FF);

		//渲染字体
		m_font->Print(0, 100, "Q/W:  Play/Stop Music\nA/S:   Pause/Resume Music\nD:     Music Loop\nZ/X:  -/+ Music Volume\nMusic Volume:  %f\n%s\n%s\n\nSpace:  Play Sound\nE/R:  -/+ Sound Volume\nC/V:  -/+ Sound Pitch\n\nSound Volume:  %f\nSound Pitch:  %f\n\nT/Y:  Add/Remove Sound Effect", 
			m_music->GetVolume(), m_music->IsPlaying() ? "Music Playing..." : "Music Stop", m_music->IsLoop() ? "Music Looping..." : "Music Not Loop", m_sound->GetVolume(), m_sound->GetPitch());

		//结束渲染
		Graph_EndScene();
	}

private:
	ggeSprite		*m_spr;
	ggeAnimation	*m_ani;
	ggeSound		*m_sound;
	ggeMusic		*m_music;
	ggeFont			*m_font;
	ggeSoundEffect	*m_effect;

	ggeVector		m_soundPos;
	ggeVector		m_soundLastPos;
	ggeVector		m_listenerPos;

	float m_dir;
	float m_scale;
	float m_scaleDt;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	CGameMain GameMain;
	GameMain.Start();
	return 0;
}