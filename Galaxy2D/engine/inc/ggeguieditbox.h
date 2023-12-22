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
\brief EditBox�ؼ�
*/

#pragma once
#include "ggeguiwindow.h"

namespace gge
{
	/// EditBox �ؼ�
	class ggeGuiEditBox : public ggeGuiWindow
	{
	public:
		ggeGuiEditBox(int id = -1, const ggeRect &rect = ggeRect(0, 0, 32.0f, 32.0f)) : ggeGuiWindow(id, rect)
		{
			m_bFocused = false;
			m_bMouseOver = false;
			m_cursorDt = 0;
			m_curPos = -1;
			m_maxChar = 65535;
			m_cColor = 0xFF000000;
			m_bPasswordMode = false;
			_CreateEditBoxData();
		}

		~ggeGuiEditBox()
		{
			_DeleteEditBoxData();
		}

		/// �����ı�
		virtual void			SetText(const char *text)	{ _SetText(text); }
		/// �����ı�
		virtual const char*		GetText()					{ return _GetText(); }
		/// ����ı�
		GGE_EXPORT void			Clear();
		/// ������Ƿ�Ϊ��
		GGE_EXPORT bool			IsEmpty();
		/// ������ַ�����
		GGE_EXPORT guint32		GetTextLength();

		/// ��������ַ���
		void					SetMaxCharNum(guint32 maxChar){ m_maxChar = maxChar; }
		/// ��������ַ���
		guint32					GetMaxCharNum()				{ return m_maxChar; }
		/// ���ù����ɫ
		void					SetCursorColor(guint32 color)	{ m_cColor = color; }
		/// ���ع����ɫ
		guint32					GetCursorColor()			{ return m_cColor; }
		/// ������������ģʽ
		void					SetPasswordMode(bool b)		{ m_bPasswordMode = b; }
		/// �Ƿ���������ģʽ
		bool					IsPasswordMode()			{ return m_bPasswordMode; }

		virtual void			SetFontState(const ggeGuiFontState &fontRS) { ggeGuiWindow::SetFontState(fontRS); ggeGuiWindow::SetAlignMode(TEXT_LEFT); }
		virtual void			SetFont(ggeFont *font)						{ if (font) font = font->Clone(); ggeGuiWindow::SetFont(font); }
		virtual void			OnUpdate(float dt)							{ if (m_bFocused) m_cursorDt += dt; }
		virtual void			OnRender()									{ _OnRender(); }
		virtual void			OnKeyClick(int key, const char *str)		{ _OnKeyClick(key, str); }
		virtual void			OnMouseLButton(bool bDown, float x, float y){ _OnMouseLButton(bDown, x, y); }
		virtual void			OnFocus(bool bFocused)						{ m_bFocused = bFocused; }
		virtual void			OnMouseOver(bool bOver)						{ m_bMouseOver = bOver; }
		virtual int				GetType()									{ return GGT_EditBox; }

		virtual void SetRenderState(GUI_RENDER_STATE_TYPE rt, const ggeGuiRenderState &rs)
		{
			switch (rt)
			{
			case GRST_PRESS:
				m_pressRS = rs;
				break;

			case GRST_MOUSEOVER:
				m_mouseOverRS = rs;
				break;

			default:
				ggeGuiWindow::SetRenderState(rt, rs);
				break;
			}
		}

		virtual ggeGuiRenderState* GetRenderState(GUI_RENDER_STATE_TYPE rt)
		{
			switch (rt)
			{
			case GRST_PRESS:
				return &m_pressRS;

			case GRST_MOUSEOVER:
				return &m_mouseOverRS;
			}

			return ggeGuiWindow::GetRenderState(rt);
		}

		virtual ggeGuiRenderState* GetCurRenderState()
		{
			if (!IsEnabled())
			{
				return GetRenderState(GRST_DISABLE);
			}
			else if (m_bFocused)
			{
				return GetRenderState(GRST_PRESS);
			}
			else if (m_bMouseOver)
			{
				return GetRenderState(GRST_MOUSEOVER);
			}
			
			return GetRenderState(GRST_NORMAL);
		}

	private:
		bool m_bMouseOver;
		ggeGuiRenderState m_pressRS;
		ggeGuiRenderState m_mouseOverRS;

		guint32	m_maxChar;
		guint32	m_cColor;
		bool	m_bFocused;
		float	m_cursorDt;
		int		m_curPos;
		bool	m_bPasswordMode;
		void	*m_edtData;

	private:
		GGE_EXPORT	void		_CreateEditBoxData();
		GGE_EXPORT	void		_DeleteEditBoxData();
		GGE_EXPORT	void		_SetText(const char *text);
		GGE_EXPORT	const char* _GetText();
		GGE_EXPORT	void		_OnRender();
		GGE_EXPORT	void		_OnKeyClick(int key, const char *str);
		GGE_EXPORT	void		_OnMouseLButton(bool bDown, float x, float y);
	};
}