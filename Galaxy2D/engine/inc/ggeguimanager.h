/*
**  =======================================================
**              Galaxy2D Game Engine       
**                                
**       ��Ȩ����(c) 2005 ����. ��������Ȩ��.
**    ��ҳ��ַ: http://www.cnblogs.com/jianguhan/
**			 ��������: jianguhan@126.com
**  =======================================================
*/

/** \file
\brief GUI������
*/

#pragma once
#include "ggecommon.h"

namespace gge
{
	/**
	@brief ˢ��GUIϵͳ
	@param dt ��һ֡����ʱ�䣬����Timer_GetDelta()���
	*/
	GGE_EXPORT void			GUI_Update(float dt);
	/**
	@brief ��ȾGUIϵͳ
	*/
	GGE_EXPORT void			GUI_Render();

	/**
	@brief ���ö��㴰��
	@param wnd ���㴰��
	*/
	GGE_EXPORT void			GUI_SetRootWindow(ggeGuiWindow *wnd);
	/**
	@brief ���ض��㴰��
	@return ���㴰��
	*/
	GGE_EXPORT ggeGuiWindow* GUI_GetRootWindow();
	/**
	@brief �Ƿ�������꣬Ĭ������
	*/
	GGE_EXPORT void			GUI_EnableMouse(bool b);
	/**
	@brief ���ý���ؼ������Ϊ0�������ǰ����ؼ��Ľ���״̬
	*/
	GGE_EXPORT void			GUI_SetFocusCtrl(ggeGuiWindow *ctrl = 0);
	/**
	@brief ���ص�ǰ����ؼ�
	*/
	GGE_EXPORT ggeGuiWindow* GUI_GetFocusCtrl();
	/**
	@brief ����������ʾToolTip�Ŀؼ����ÿؼ������и�����
	*/
	GGE_EXPORT void			GUI_SetToolTipCtrl(ggeGuiRichText *ctrl);
	/**
	@brief ����������ʾToolTip�Ŀؼ�
	*/
	GGE_EXPORT ggeGuiRichText* GUI_GetToolTipCtrl();
	/**
	@brief ������ʾToolTip��ʱ����λ����
	*/
	GGE_EXPORT void			GUI_SetToolTipDelay(float t);
	/**
	@brief ������ʾToolTip��ʱ
	*/
	GGE_EXPORT float		GUI_GetToolTipDelay();

	/**
	@brief ���ģ̬����(ע�⣺ģ̬���ڲ����и����ڣ����ڹر�ʱ��Ҫ����RemoveModalWnd()�����Ƴ��ô���)
	*/
	GGE_EXPORT void			GUI_AddModalWnd(ggeGuiWindow *wnd);
	/**
	@brief �Ƴ�ģ̬����
	*/
	GGE_EXPORT void			GUI_RemoveModalWnd(ggeGuiWindow *wnd);
	/**
	@brief �Ƴ�����ģ̬����
	*/
	GGE_EXPORT void			GUI_RemoveAllModalWnd();
	/**
	@brief �Ƴ����д���
	*/
	GGE_EXPORT void			GUI_Clear();
}