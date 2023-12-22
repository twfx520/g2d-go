/*
**  =======================================================
**  GUI��ʹ��
**  =======================================================
*/

#include <iostream>
#include <string>
#include <cassert>
#include <map>
using namespace std;

#include "ggebase.h"
#include "ggetexture.h"
#include "ggesprite.h"
#include "ggeanimation.h"
#include "ggeguiwindow.h"
#include "ggeguimanager.h"
#include "ggeguibutton.h"
#include "ggeguieditbox.h"
#include "ggeguislider.h"
#include "ggeguilistbox.h"
#include "ggeguirichtext.h"
#include "ggeguiLoader.h"
#include "ggeresmanager.h"
#include "ggefont.h"
#include "animation.h"
using namespace gge;

//GuiLoader
ggeGuiLoader *g_guiLoader = 0;

//��Դ������
ggeResManager *g_resMgr = 0;

//�˳�״̬
bool g_bExit = false;

//�Զ���Gui��Ϣ
enum CustomGuiMessage
{
	CGM_Initiate,
	CGM_MsgBoxOk,
	CGM_MsgBoxCancel,
	CGM_ShowMenuWnd,
	CGM_CloseMenuWnd,
};

//�˵�����
enum GuiMenuType
{
	GMT_FileMenu,
	GMT_HelpMenu,
};

//-----------------------------------------------------------------------------------

#define DeclearGuiCreateFunc(x) static ggeGuiWindow* CreateWnd(ggeGuiCreateInfo& info) { return new x(info.GetID(), info.GetRect()); }

//MessageBox
class CMessageBox : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CMessageBox);

	//�ӿؼ�ID
	enum MessageBoxCtrlType
	{
		MBCT_OkBtn1,
		MBCT_OkBtn2,
		MBCT_CancelBtn,
		MBCT_Text,
	};

	CMessageBox(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
		m_callbackWnd = 0;
		m_srcWnd = 0;
	}

	//��ʼ��
	void Init(const char*str, bool bHasCancelBtn, ggeGuiWindow *callbackWnd, ggeGuiWindow *srcWnd)
	{
		//���ñ�������
		assert(str);
		FindCtrl(MBCT_Text)->SetText(str);

		//�Ƿ���ȡ����ť
		if (bHasCancelBtn)
		{
			FindCtrl(MBCT_OkBtn1)->SetVisible(false);
		}
		else
		{
			FindCtrl(MBCT_OkBtn2)->SetVisible(false);
			FindCtrl(MBCT_CancelBtn)->SetVisible(false);
		}

		//����Դ���ںͻص�����
		m_callbackWnd = callbackWnd;
		m_srcWnd = srcWnd;
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		//����а�ť����
		if (msgType == CMT_BUTTON_CLICKED)
		{
			//����лص�����
			if (m_callbackWnd)
			{
				switch (ctrl->GetID())
				{
				case 0:
				case 1:
					m_callbackWnd->OnMessage(m_srcWnd, CGM_MsgBoxOk);	//����ȷ����Ϣ
					break;

				case 2:
					m_callbackWnd->OnMessage(m_srcWnd, CGM_MsgBoxCancel);	//����ȡ����Ϣ
					break;
				}
			}

			//������ˣ����Լ��ɵ�
			Release();
			return true;
		}

		return false;
	}

private:
	ggeGuiWindow *m_callbackWnd;
	ggeGuiWindow *m_srcWnd;
};

//����MessageBox
CMessageBox* CreateMessageBox(const char*str, bool bHasCancelBtn = false, ggeGuiWindow *callbackWnd = 0, ggeGuiWindow *srcWnd = 0)
{
	//��GuiLoader����MessageBox
	CMessageBox *msgbox = (CMessageBox*)g_guiLoader->CreateControl("MessageBox");
	assert(msgbox);

	//��ʼ��
	msgbox->Init(str, bHasCancelBtn, callbackWnd, srcWnd);
	//����Ϊģ̬����
	GUI_AddModalWnd(msgbox);
	//GuiManager�Ѿ��������ˣ���������Ҫ�ͷŵ�
	msgbox->Release();

	return msgbox;
}

//�϶�����
class CDragArea : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CDragArea);

	CDragArea(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
		m_bDrag = false;
	}

	//����������ʱ��¼ԭʼλ�ò������϶�״̬
	void OnMouseLButton(bool bDown, float x, float y) 
	{
		m_bDrag = bDown;
		m_lastPosX = x;
		m_lastPosY = y;
	}

	//����ƶ�ʱ������϶�״̬�򽫸������ƶ�����λ��
	void OnMouseMove(float x, float y) 
	{
		ggeGuiWindow *parWnd = GetParent();
		if (m_bDrag && parWnd)
		{
			float posx = parWnd->GetPosX() + (x - m_lastPosX);
			float posy = parWnd->GetPosY() + (y - m_lastPosY);
			parWnd->SetPos(posx, posy);
			m_lastPosX = x;
			m_lastPosY = y;
		}
	}

private:
	bool m_bDrag;
	float m_lastPosX;
	float m_lastPosY;
};

//����������
class CSliderWnd : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CSliderWnd);

	//�ӿؼ�ID
	enum SliderCtrlType
	{
		SCT_LeftBtn,
		SCT_RightBtn,
		SCT_Slider,
	};

	CSliderWnd(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		switch (msgType)
		{
		//����а�ť����
		case CMT_BUTTON_CLICKED:
			switch (ctrl->GetID())
			{
			case SCT_LeftBtn:
				{
					//��߰�ť���£�ֵ-1
					ggeGuiSlider *sld = (ggeGuiSlider*)FindCtrl(SCT_Slider);
					assert(sld);
					sld->SetValue(sld->GetValue() - 1.0f);
					NotifyParent(CMT_SLIDER_BAR_MOVED);
				}
				break;

			case SCT_RightBtn:
				{
					//�ұ߰�ť���£�ֵ+1
					ggeGuiSlider *sld = (ggeGuiSlider*)FindCtrl(SCT_Slider);
					assert(sld);
					sld->SetValue(sld->GetValue() + 1.0f);
					NotifyParent(CMT_SLIDER_BAR_MOVED);
				}
				break;
			}
			break;

		case CMT_SLIDER_BAR_MOVED:
			//�������϶���֪ͨ������
			if (GetParent()) GetParent()->OnChildMsg(msgType, ctrl);
			break;

		case CMT_SLIDER_VALUE_CHANGED:
			//ֵ�仯��֪ͨ������
			if (GetParent()) GetParent()->OnChildMsg(msgType, ctrl);
			break;
		}

		return false;
	}
};

//-----------------------------------------------------------------------------------

//�˵�����
class CMenuWnd : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CMenuWnd);

	//�ӿؼ�ID
	enum FileMenuBtnType
	{
		FMBT_OpenFile,
		FMBT_Save,
		FMBT_SaveAs,
		FMBT_Exit,
	};

	//�ӿؼ�ID
	enum HelpMenuBtnType
	{
		HMBT_About,
	};

	CMenuWnd(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
		m_FileMenuWnd = 0;
		m_HelpMenuWnd = 0;
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		switch (msgType)
		{
		case CMT_BUTTON_CLICKED:
			if (ctrl->GetParent() == m_FileMenuWnd)
			{
				switch (ctrl->GetID())
				{
				case FMBT_OpenFile:
					CreateMessageBox("#p1ѡ�С��ļ����˵���");
					break;

				case FMBT_Save:
					CreateMessageBox("#p1ѡ�С����桱�˵���");
					break;

				case FMBT_SaveAs:
					CreateMessageBox("#p1ѡ�С����Ϊ���˵���");
					break;

				case FMBT_Exit:
					CreateMessageBox("#p1ȷ��Ҫ�˳���", true, this, ctrl);
					break;
				}
			}
			else if (ctrl->GetParent() == m_HelpMenuWnd)
			{
				switch (ctrl->GetID())
				{
				case HMBT_About:
					CreateMessageBox("#p1Galaxy2D Game Engine\nGUI��ʾ����");
					break;
				}
			}

			//���Լ��ص�
			SetVisible(false);
			return true;
		}

		return false;
	}

	bool OnMessage(ggeGuiWindow *ctrl, int msgType, void *msgData = 0)
	{
		switch (msgType)
		{
		case CGM_Initiate:
			//��ʼ��
			m_FileMenuWnd = FindCtrl("FileMenuWnd");
			m_HelpMenuWnd = FindCtrl("HelpMenuWnd");

			assert(m_FileMenuWnd);
			assert(m_HelpMenuWnd);

			m_FileMenuWnd->SetVisible(false);
			m_HelpMenuWnd->SetVisible(false);
			break;

		case CGM_MsgBoxOk:
			//�յ�MessageBoxȷ����ť��Ϣ��������˳��ؼ������ľ������˳�״̬Ϊtrue
			if (ctrl->GetParent() == m_FileMenuWnd && ctrl->GetID() == FMBT_Exit) g_bExit = true;
			return true;

		case CGM_ShowMenuWnd:
			{
				int menuID = (int)msgData;
				switch (menuID)
				{
				case GMT_FileMenu:
					m_FileMenuWnd->SetVisible(true);
					m_HelpMenuWnd->SetVisible(false);
					SetVisible(true);
					break;

				case GMT_HelpMenu:
					m_FileMenuWnd->SetVisible(false);
					m_HelpMenuWnd->SetVisible(true);
					SetVisible(true);
					break;
				}
			}
		}

		return false;
	}

	//���û������κΰ�ť��رղ˵�
	void OnMouseLButton(bool bDown, float x, float y)
	{
		SetVisible(false);
	}

private:
	ggeGuiWindow *m_FileMenuWnd;
	ggeGuiWindow *m_HelpMenuWnd;
};

//�˵���
class CMenuBar : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CMenuBar);

	CMenuBar(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
		m_FileMenuBtn = 0;
		m_HelpMenuBtn = 0;
		m_MenuWnd = 0;
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		switch (msgType)
		{
		case CMT_MOUSE_ENTER:
			//���������ʾ�Ӳ˵������ݵ�ǰ�ؼ�����Ҫ��ʾ���Ӳ˵�
			if (m_MenuWnd->IsVisible())
			{
				if (ctrl == m_FileMenuBtn)
				{
					m_MenuWnd->OnMessage(0, CGM_ShowMenuWnd, (void*)GMT_FileMenu);
				}
				else if (ctrl == m_HelpMenuBtn)
				{
					m_MenuWnd->OnMessage(0, CGM_ShowMenuWnd, (void*)GMT_HelpMenu);
				}
			}
			break;

		case CMT_BUTTON_CLICKED:
			if (!m_MenuWnd->IsVisible())
			{
				if (ctrl == m_FileMenuBtn)
				{
					m_MenuWnd->OnMessage(0, CGM_ShowMenuWnd, (void*)GMT_FileMenu);
				}
				else if (ctrl == m_HelpMenuBtn)
				{
					m_MenuWnd->OnMessage(0, CGM_ShowMenuWnd, (void*)GMT_HelpMenu);
				}
			}
			break;
		}

		return false;
	}

	//���û������κΰ�ť��رղ˵�
	void OnMouseLButton(bool bDown, float x, float y)
	{
		m_MenuWnd->SetVisible(false);
	}

	bool OnMessage(ggeGuiWindow *ctrl, int msgType, void *msgData = 0) 
	{
		switch (msgType)
		{
		case CGM_Initiate:
			//��ʼ��
			m_FileMenuBtn = FindCtrl("FileMenuBtn");
			m_HelpMenuBtn = FindCtrl("HelpMenuBtn");
			m_MenuWnd = GetParent()->FindCtrl("MenuWnd");

			assert(m_FileMenuBtn);
			assert(m_HelpMenuBtn);
			assert(m_MenuWnd);

			m_MenuWnd->SetVisible(false);
			break;
		}

		return false;
	}

private:
	ggeGuiWindow *m_FileMenuBtn;
	ggeGuiWindow *m_HelpMenuBtn;
	ggeGuiWindow *m_MenuWnd;
};

//-----------------------------------------------------------------------------------

//Tab�ڶ�ҳ
class CTabFunc2 : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CTabFunc2);

	//�ӿؼ�ID
	enum TabFunc2CtrlType
	{
		TF2CT_ListBox,
		TF2CT_EditBox,
		TF2CT_Slider,
	};

	CTabFunc2(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		switch (msgType)
		{
		case CMT_BUTTON_CLICKED:
			{
				//�����Ӱ�ť���²��ұ༭���ǿյģ��򽫱༭��������ӵ��б����
				if (!m_editbox->IsEmpty())
				{
					m_listbox->AddItem(m_editbox->GetText());
					m_editbox->Clear();

					//���ù�������Χ�͵�ǰֵ
					m_slider->SetRange( 0, (float)(max(0, m_listbox->GetNumItems() - m_listbox->GetNumRows())) );
					m_slider->SetValue((float)m_listbox->GetTopItem());
				}
			}
			break;

		case CMT_SLIDER_BAR_MOVED:
			//�������ƶ���ˢ���б�򶥲���Ŀ�Թ����б��
			m_listbox->SetTopItem((int)m_slider->GetValue());
			break;

		case CMT_LIST_ITEM_ROLL:
		case CMT_LIST_ITEM_CHANGED:
			//�б�������ѡ����ı䣬ͬ����������
			m_slider->SetValue((float)m_listbox->GetTopItem());
			break;
		}

		return false;
	}

	bool OnMessage(ggeGuiWindow *ctrl, int msgType, void *msgData = 0) 
	{
		switch (msgType)
		{
		case CGM_Initiate:
			//��ʼ��
			m_slider = (ggeGuiSlider*)(FindCtrl(TF2CT_Slider)->FindCtrl(CSliderWnd::SCT_Slider));
			m_editbox = (ggeGuiEditBox*)FindCtrl(TF2CT_EditBox);
			m_listbox = (ggeGuiListBox*)FindCtrl(TF2CT_ListBox);

			assert(m_slider);
			assert(m_editbox);
			assert(m_listbox);
			break;
		}

		return false;
	}

private:
	ggeGuiSlider	*m_slider;
	ggeGuiEditBox	*m_editbox;
	ggeGuiListBox	*m_listbox;
};

//Tab��
class CTabBar : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CTabBar);

	//�ӿؼ�ID
	enum TabBarCtrlType
	{
		TBCT_Tab1,
		TBCT_Tab2,
		TBCT_TabCount,
		
		TBCT_TabWnd1 = 1000,
		TBCT_TabWnd2,
	};

	CTabBar(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		switch (msgType)
		{
		case CMT_BUTTON_CLICKED:
			//�л�Tabҳ
			if (ctrl->GetParent() == this && ctrl->GetType() == GGT_CheckButton)
			{
				for (int i = 0; i < TBCT_TabCount; i++)
				{
					if (i != ctrl->GetID())
					{
						//ȡ����ť����״̬
						ggeGuiCheckButton *chkbtn = (ggeGuiCheckButton*)FindCtrl(i);
						assert(chkbtn);
						chkbtn->SetChecked(false);

						//��������ҳ
						ggeGuiWindow *funcWnd = FindCtrl(i + TBCT_TabWnd1);
						assert(funcWnd);
						funcWnd->SetVisible(false);
					}
				}

				//����ʾѡ��ҳ
				ggeGuiWindow *funcWnd = FindCtrl(ctrl->GetID() + TBCT_TabWnd1);
				assert(funcWnd);
				funcWnd->SetVisible(true);
			}
			else
			{
				//����ģ̬�Ի���
				if (string(ctrl->GetName()) == "ModalWndText")
				{
					CMessageBox *msgbox = CreateMessageBox("ģ̬�Ի���1", true, this, ctrl);

					msgbox = CreateMessageBox("ģ̬�Ի���2", true, this, ctrl);
					msgbox->SetPos(msgbox->GetPosX() + 16.0f, msgbox->GetPosY() + 16.0f);

					msgbox = CreateMessageBox("ģ̬�Ի���3", true, this, ctrl);
					msgbox->SetPos(msgbox->GetPosX() + 32.0f, msgbox->GetPosY() + 32.0f);
				}
			}
			break;

		case CMT_MOUSE_LBUTTON_DOWN:
		case CMT_MOUSE_LBUTTON_UP:
			{
				//����Tab��ť���ظ���
				ggeGuiCheckButton *chkbtn = (ggeGuiCheckButton*)ctrl;
				if (chkbtn->IsChecked()) return true;
			}
			break;

		case CMT_SLIDER_VALUE_CHANGED:
			{
				//������ֵ�ı䣬ͬ�����ı�����
				ggeGuiWindow *text = ctrl->GetParent()->FindCtrl("SliderText");
				assert(text);
				ggeGuiSlider *sld = (ggeGuiSlider*)ctrl;
				text->SetText(ggeVariant((int)sld->GetValue()).GetString());
			}
			break;

		case CMT_RICH_TEXT_HYPER_LINK:
			{
				//���������
				ggeGuiRichText *rctxt = (ggeGuiRichText*)ctrl;
				switch (rctxt->GetHyperLinkID())
				{
				case 100:
					System_Launch("http://www.163.com");
					break;

				case 200:
					System_Launch("http://www.sohu.com");
					break;
				}
			}
		}
		return false;
	}

	bool OnMessage(ggeGuiWindow *ctrl, int msgType, void *msgData = 0) 
	{
		switch (msgType)
		{
		case CGM_Initiate:
			//��ʼ��
			ggeGuiRichText *rchText = (ggeGuiRichText*)(FindCtrl("RichText", true));
			assert(rchText);

			ggeTexture *tex = g_resMgr->CreateTextureFromFile("guiicon.png", "guiicon.png");
			ggeFont *fnt = g_resMgr->CreateCustomFont("MyFont", "DejaVuSans.ttf", 14, FONT_MODE_BORDER);

			ggeSprite *spr = Sprite_Create(tex, 0, 0, 20.0f, 20.0f);
			ggeAnimation *ani = CreateAnimationSprite(tex, 15, 20, 20, false);
			rchText->InsertSprite(1, spr);
			rchText->InsertAnimation(1, ani);
			rchText->InsertFont(1, fnt);

			//�ͷ���Դ
			GGE_RELEASE(spr);
			GGE_RELEASE(ani);
			GGE_RELEASE(tex);
			GGE_RELEASE(fnt);
			break;
		}

		return false;
	}
};

//-----------------------------------------------------------------------------------


bool Frame()
{
	//ˢ��Gui
	GUI_Update(Timer_GetDelta());

	//��ʼ��Ⱦ
	Graph_BeginScene();
	//����
	Graph_Clear();

	//��ȾGui
	GUI_Render();

	//������Ⱦ
	Graph_EndScene();

	//�����˳�״̬
	return g_bExit;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!Engine_Create(GGE_VERSION)) return 0;

	System_SetState(GGE_FPS,		100);
	System_SetState(GGE_VSYNC,		true);
	System_SetState(GGE_FRAMEFUNC,	Frame);
	System_SetState(GGE_HIDEMOUSE,	false);
	System_SetState(GGE_TITLE,		"Galaxy2D Game Engine - GUI Sample");

	if (System_Initiate()) 
	{
		g_resMgr = ResManager_Create();				 //������Դ������
		
		g_guiLoader = GUI_CreateGuiLoader();		//����GuiLoader
		g_guiLoader->SetResManager(g_resMgr);		//������Դ������

		//�����Զ���ؼ���������
		g_guiLoader->AddCreateFunc("MessageBox",	CMessageBox::CreateWnd);
		g_guiLoader->AddCreateFunc("DragArea",		CDragArea::CreateWnd);
		g_guiLoader->AddCreateFunc("MenuBar",		CMenuBar::CreateWnd);
		g_guiLoader->AddCreateFunc("TabBar",		CTabBar::CreateWnd);
		g_guiLoader->AddCreateFunc("MenuWnd",		CMenuWnd::CreateWnd);
		g_guiLoader->AddCreateFunc("SliderWnd",		CSliderWnd::CreateWnd);
		g_guiLoader->AddCreateFunc("FuncWnd2",		CTabFunc2::CreateWnd);

		//����Gui�ļ������ļ���Gui�༭������
		bool bLoad = g_guiLoader->Load("newgui.gui"); 
		assert(bLoad);

		 //����������
		ggeGuiWindow *mainWnd = g_guiLoader->CreateControl("MainWnd");
		assert(mainWnd);
		mainWnd->SendChildMsg(CGM_Initiate, 0, true);

		//���������ڵ�Gui������
		GUI_SetRootWindow(mainWnd);

		//����ToolTip����
		ggeGuiRichText *tooltip = (ggeGuiRichText*)g_guiLoader->CreateControl("ToolTip");
		assert(tooltip);

		//����ToolTip���ڵ�Gui������
		GUI_SetToolTipCtrl(tooltip);

		//���һ�������Ƿ񴴽��ɹ�������������ɹ��򵯳���ʾ��
		//��Ϊ����ֻ����ʾGUI��ʹ�ã������˶�������һ������ȥ�����Բ���Ҫ��飬
		//�������ʽ������Ϸ��Ӧ�ð������ļ�һ�������Ա������Ҳ������������������Ϸ�����
		ggeFont *fnt = g_resMgr->CreateFont("GuiFont");
		if (!fnt)
		{
			MessageBox(NULL, "�Ҳ�����c:\\windows\\fonts\\simkai.ttf���ļ���\n����GUI�༭���޸�GUI�ļ��е��������ã�\n���������滻��һ�����ڵ������ļ���", "����", MB_OK);
			return 0;
		}
		else
		{
			GGE_RELEASE(fnt);
		}

		//��ʼ���г���
		System_Start();

		//ɾ�����ִ���
		GUI_SetRootWindow(0);
		GUI_SetToolTipCtrl(0);
		GUI_RemoveAllModalWnd();
		GGE_RELEASE(mainWnd);
		GGE_RELEASE(tooltip);
	}

	//�ͷ���Դ
	GGE_RELEASE(g_guiLoader);
	GGE_RELEASE(g_resMgr);

	Engine_Release();
	return 0;
}