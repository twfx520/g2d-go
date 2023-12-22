/*
**  =======================================================
**  GUI的使用
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

//资源管理器
ggeResManager *g_resMgr = 0;

//退出状态
bool g_bExit = false;

//自定义Gui消息
enum CustomGuiMessage
{
	CGM_Initiate,
	CGM_MsgBoxOk,
	CGM_MsgBoxCancel,
	CGM_ShowMenuWnd,
	CGM_CloseMenuWnd,
};

//菜单类型
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

	//子控件ID
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

	//初始化
	void Init(const char*str, bool bHasCancelBtn, ggeGuiWindow *callbackWnd, ggeGuiWindow *srcWnd)
	{
		//设置标题文字
		assert(str);
		FindCtrl(MBCT_Text)->SetText(str);

		//是否有取消按钮
		if (bHasCancelBtn)
		{
			FindCtrl(MBCT_OkBtn1)->SetVisible(false);
		}
		else
		{
			FindCtrl(MBCT_OkBtn2)->SetVisible(false);
			FindCtrl(MBCT_CancelBtn)->SetVisible(false);
		}

		//设置源窗口和回调窗口
		m_callbackWnd = callbackWnd;
		m_srcWnd = srcWnd;
	}

	bool OnChildMsg(int msgType, ggeGuiWindow *ctrl)
	{
		//如果有按钮按下
		if (msgType == CMT_BUTTON_CLICKED)
		{
			//如果有回调窗口
			if (m_callbackWnd)
			{
				switch (ctrl->GetID())
				{
				case 0:
				case 1:
					m_callbackWnd->OnMessage(m_srcWnd, CGM_MsgBoxOk);	//发送确定消息
					break;

				case 2:
					m_callbackWnd->OnMessage(m_srcWnd, CGM_MsgBoxCancel);	//发送取消消息
					break;
				}
			}

			//活干完了，把自己干掉
			Release();
			return true;
		}

		return false;
	}

private:
	ggeGuiWindow *m_callbackWnd;
	ggeGuiWindow *m_srcWnd;
};

//创建MessageBox
CMessageBox* CreateMessageBox(const char*str, bool bHasCancelBtn = false, ggeGuiWindow *callbackWnd = 0, ggeGuiWindow *srcWnd = 0)
{
	//从GuiLoader创建MessageBox
	CMessageBox *msgbox = (CMessageBox*)g_guiLoader->CreateControl("MessageBox");
	assert(msgbox);

	//初始化
	msgbox->Init(str, bHasCancelBtn, callbackWnd, srcWnd);
	//设置为模态窗口
	GUI_AddModalWnd(msgbox);
	//GuiManager已经加引用了，所以这里要释放掉
	msgbox->Release();

	return msgbox;
}

//拖动区域
class CDragArea : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CDragArea);

	CDragArea(int id, const ggeRect &rect) : ggeGuiWindow(id, rect)
	{
		m_bDrag = false;
	}

	//鼠标左键按下时记录原始位置并设置拖动状态
	void OnMouseLButton(bool bDown, float x, float y) 
	{
		m_bDrag = bDown;
		m_lastPosX = x;
		m_lastPosY = y;
	}

	//鼠标移动时如果是拖动状态则将父窗口移动到新位置
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

//滚动条窗口
class CSliderWnd : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CSliderWnd);

	//子控件ID
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
		//如果有按钮按下
		case CMT_BUTTON_CLICKED:
			switch (ctrl->GetID())
			{
			case SCT_LeftBtn:
				{
					//左边按钮按下，值-1
					ggeGuiSlider *sld = (ggeGuiSlider*)FindCtrl(SCT_Slider);
					assert(sld);
					sld->SetValue(sld->GetValue() - 1.0f);
					NotifyParent(CMT_SLIDER_BAR_MOVED);
				}
				break;

			case SCT_RightBtn:
				{
					//右边按钮按下，值+1
					ggeGuiSlider *sld = (ggeGuiSlider*)FindCtrl(SCT_Slider);
					assert(sld);
					sld->SetValue(sld->GetValue() + 1.0f);
					NotifyParent(CMT_SLIDER_BAR_MOVED);
				}
				break;
			}
			break;

		case CMT_SLIDER_BAR_MOVED:
			//滚动条拖动，通知父窗口
			if (GetParent()) GetParent()->OnChildMsg(msgType, ctrl);
			break;

		case CMT_SLIDER_VALUE_CHANGED:
			//值变化，通知父窗口
			if (GetParent()) GetParent()->OnChildMsg(msgType, ctrl);
			break;
		}

		return false;
	}
};

//-----------------------------------------------------------------------------------

//菜单窗口
class CMenuWnd : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CMenuWnd);

	//子控件ID
	enum FileMenuBtnType
	{
		FMBT_OpenFile,
		FMBT_Save,
		FMBT_SaveAs,
		FMBT_Exit,
	};

	//子控件ID
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
					CreateMessageBox("#p1选中“文件”菜单！");
					break;

				case FMBT_Save:
					CreateMessageBox("#p1选中“保存”菜单！");
					break;

				case FMBT_SaveAs:
					CreateMessageBox("#p1选中“另存为”菜单！");
					break;

				case FMBT_Exit:
					CreateMessageBox("#p1确定要退出吗？", true, this, ctrl);
					break;
				}
			}
			else if (ctrl->GetParent() == m_HelpMenuWnd)
			{
				switch (ctrl->GetID())
				{
				case HMBT_About:
					CreateMessageBox("#p1Galaxy2D Game Engine\nGUI演示程序");
					break;
				}
			}

			//把自己关掉
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
			//初始化
			m_FileMenuWnd = FindCtrl("FileMenuWnd");
			m_HelpMenuWnd = FindCtrl("HelpMenuWnd");

			assert(m_FileMenuWnd);
			assert(m_HelpMenuWnd);

			m_FileMenuWnd->SetVisible(false);
			m_HelpMenuWnd->SetVisible(false);
			break;

		case CGM_MsgBoxOk:
			//收到MessageBox确定按钮消息，如果是退出控件发出的就设置退出状态为true
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

	//如果没点击到任何按钮则关闭菜单
	void OnMouseLButton(bool bDown, float x, float y)
	{
		SetVisible(false);
	}

private:
	ggeGuiWindow *m_FileMenuWnd;
	ggeGuiWindow *m_HelpMenuWnd;
};

//菜单栏
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
			//如果正在显示子菜单，根据当前控件设置要显示的子菜单
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

	//如果没点击到任何按钮则关闭菜单
	void OnMouseLButton(bool bDown, float x, float y)
	{
		m_MenuWnd->SetVisible(false);
	}

	bool OnMessage(ggeGuiWindow *ctrl, int msgType, void *msgData = 0) 
	{
		switch (msgType)
		{
		case CGM_Initiate:
			//初始化
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

//Tab第二页
class CTabFunc2 : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CTabFunc2);

	//子控件ID
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
				//如果添加按钮按下并且编辑框不是空的，则将编辑框文字添加到列表框中
				if (!m_editbox->IsEmpty())
				{
					m_listbox->AddItem(m_editbox->GetText());
					m_editbox->Clear();

					//重置滚动条范围和当前值
					m_slider->SetRange( 0, (float)(max(0, m_listbox->GetNumItems() - m_listbox->GetNumRows())) );
					m_slider->SetValue((float)m_listbox->GetTopItem());
				}
			}
			break;

		case CMT_SLIDER_BAR_MOVED:
			//滚动条移动，刷新列表框顶部项目以滚动列表框
			m_listbox->SetTopItem((int)m_slider->GetValue());
			break;

		case CMT_LIST_ITEM_ROLL:
		case CMT_LIST_ITEM_CHANGED:
			//列表框滚动或选中项改变，同步到滚动条
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
			//初始化
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

//Tab条
class CTabBar : public ggeGuiWindow
{
public:
	DeclearGuiCreateFunc(CTabBar);

	//子控件ID
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
			//切换Tab页
			if (ctrl->GetParent() == this && ctrl->GetType() == GGT_CheckButton)
			{
				for (int i = 0; i < TBCT_TabCount; i++)
				{
					if (i != ctrl->GetID())
					{
						//取消按钮按下状态
						ggeGuiCheckButton *chkbtn = (ggeGuiCheckButton*)FindCtrl(i);
						assert(chkbtn);
						chkbtn->SetChecked(false);

						//隐藏所有页
						ggeGuiWindow *funcWnd = FindCtrl(i + TBCT_TabWnd1);
						assert(funcWnd);
						funcWnd->SetVisible(false);
					}
				}

				//再显示选中页
				ggeGuiWindow *funcWnd = FindCtrl(ctrl->GetID() + TBCT_TabWnd1);
				assert(funcWnd);
				funcWnd->SetVisible(true);
			}
			else
			{
				//处理模态对话框
				if (string(ctrl->GetName()) == "ModalWndText")
				{
					CMessageBox *msgbox = CreateMessageBox("模态对话框1", true, this, ctrl);

					msgbox = CreateMessageBox("模态对话框2", true, this, ctrl);
					msgbox->SetPos(msgbox->GetPosX() + 16.0f, msgbox->GetPosY() + 16.0f);

					msgbox = CreateMessageBox("模态对话框3", true, this, ctrl);
					msgbox->SetPos(msgbox->GetPosX() + 32.0f, msgbox->GetPosY() + 32.0f);
				}
			}
			break;

		case CMT_MOUSE_LBUTTON_DOWN:
		case CMT_MOUSE_LBUTTON_UP:
			{
				//避免Tab按钮被重复按
				ggeGuiCheckButton *chkbtn = (ggeGuiCheckButton*)ctrl;
				if (chkbtn->IsChecked()) return true;
			}
			break;

		case CMT_SLIDER_VALUE_CHANGED:
			{
				//滚动条值改变，同步到文本窗口
				ggeGuiWindow *text = ctrl->GetParent()->FindCtrl("SliderText");
				assert(text);
				ggeGuiSlider *sld = (ggeGuiSlider*)ctrl;
				text->SetText(ggeVariant((int)sld->GetValue()).GetString());
			}
			break;

		case CMT_RICH_TEXT_HYPER_LINK:
			{
				//点击超链接
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
			//初始化
			ggeGuiRichText *rchText = (ggeGuiRichText*)(FindCtrl("RichText", true));
			assert(rchText);

			ggeTexture *tex = g_resMgr->CreateTextureFromFile("guiicon.png", "guiicon.png");
			ggeFont *fnt = g_resMgr->CreateCustomFont("MyFont", "DejaVuSans.ttf", 14, FONT_MODE_BORDER);

			ggeSprite *spr = Sprite_Create(tex, 0, 0, 20.0f, 20.0f);
			ggeAnimation *ani = CreateAnimationSprite(tex, 15, 20, 20, false);
			rchText->InsertSprite(1, spr);
			rchText->InsertAnimation(1, ani);
			rchText->InsertFont(1, fnt);

			//释放资源
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
	//刷新Gui
	GUI_Update(Timer_GetDelta());

	//开始渲染
	Graph_BeginScene();
	//清屏
	Graph_Clear();

	//渲染Gui
	GUI_Render();

	//结束渲染
	Graph_EndScene();

	//返回退出状态
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
		g_resMgr = ResManager_Create();				 //创建资源管理器
		
		g_guiLoader = GUI_CreateGuiLoader();		//创建GuiLoader
		g_guiLoader->SetResManager(g_resMgr);		//设置资源管理器

		//设置自定义控件创建函数
		g_guiLoader->AddCreateFunc("MessageBox",	CMessageBox::CreateWnd);
		g_guiLoader->AddCreateFunc("DragArea",		CDragArea::CreateWnd);
		g_guiLoader->AddCreateFunc("MenuBar",		CMenuBar::CreateWnd);
		g_guiLoader->AddCreateFunc("TabBar",		CTabBar::CreateWnd);
		g_guiLoader->AddCreateFunc("MenuWnd",		CMenuWnd::CreateWnd);
		g_guiLoader->AddCreateFunc("SliderWnd",		CSliderWnd::CreateWnd);
		g_guiLoader->AddCreateFunc("FuncWnd2",		CTabFunc2::CreateWnd);

		//载入Gui文件，该文件由Gui编辑器生成
		bool bLoad = g_guiLoader->Load("newgui.gui"); 
		assert(bLoad);

		 //创建主窗口
		ggeGuiWindow *mainWnd = g_guiLoader->CreateControl("MainWnd");
		assert(mainWnd);
		mainWnd->SendChildMsg(CGM_Initiate, 0, true);

		//设置主窗口到Gui管理器
		GUI_SetRootWindow(mainWnd);

		//创建ToolTip窗口
		ggeGuiRichText *tooltip = (ggeGuiRichText*)g_guiLoader->CreateControl("ToolTip");
		assert(tooltip);

		//设置ToolTip窗口到Gui管理器
		GUI_SetToolTipCtrl(tooltip);

		//检查一下字体是否创建成功，如果创建不成功则弹出提示，
		//因为这里只是演示GUI的使用，不想把硕大的字体一起打包出去，所以才需要检查，
		//如果是正式发布游戏，应该把字体文件一起打包，以避免因找不到字体而不能运行游戏的情况
		ggeFont *fnt = g_resMgr->CreateFont("GuiFont");
		if (!fnt)
		{
			MessageBox(NULL, "找不到“c:\\windows\\fonts\\simkai.ttf”文件，\n请用GUI编辑器修改GUI文件中的字体设置，\n将该字体替换成一个存在的字体文件。", "错误", MB_OK);
			return 0;
		}
		else
		{
			GGE_RELEASE(fnt);
		}

		//开始运行程序
		System_Start();

		//删除各种窗口
		GUI_SetRootWindow(0);
		GUI_SetToolTipCtrl(0);
		GUI_RemoveAllModalWnd();
		GGE_RELEASE(mainWnd);
		GGE_RELEASE(tooltip);
	}

	//释放资源
	GGE_RELEASE(g_guiLoader);
	GGE_RELEASE(g_resMgr);

	Engine_Release();
	return 0;
}