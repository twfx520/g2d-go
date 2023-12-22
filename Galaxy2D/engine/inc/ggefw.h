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
\brief Ӧ�ó����ܻ���\n
	Ҫ����һ���򵥵���ϷӦ�ó���ֻ��̳�ggeApplication���ṩһ��ʵ�����ɡ�

	ʾ����
	@code
	class CGameMain : public ggeApplication
	{
	public:
		void OnUpdate(float dt)
		{
		}

		void OnRender()
		{
			Graph_BeginScene();
			Graph_Clear();
			//Draw Something...
			Graph_EndScene();
		}
	};

	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
	{
		CGameMain GameMain;
		GameMain.Start();

		return 0;
	}
	@endcode
*/

#pragma once
#include "ggetypes.h"

namespace gge
{
	/// Ӧ�ó�����
	class ggeApplication
	{
	public:
		ggeApplication()						{ m_bExit = false;  _Init(); }
		virtual ~ggeApplication()				{}

	public:
		/// ��Ϸ����ǰ�ú��������ã��������false��Ϸ�˳�
		virtual bool OnConfig()					{ return true; }

		/// ��Ϸ������ú��������ã��������false��Ϸ�˳�
		virtual bool OnInitiate()				{ return true; }

		/// ��Ϸ�˳�ʱǰ�ú���������
		virtual void OnRelease()				{}

		/// ˢ��
		virtual void OnUpdate(float dt) = 0;

		/// ��Ⱦ
		virtual void OnRender() = 0;

		/// ����Dumpʱ���ã�dirΪDump����Ŀ¼�����Դ˴�д��һЩ������Ϣ��log�������ʾ���ڵ�
		virtual void OnMiniDump(const char *dir){}

	public:
		/// ��ʼ����
		GGE_EXPORT void Start();

		/// �˳���Ϸ
		void Exit()								{ m_bExit = true; }

		/// �Ƿ������˳���Ϸ
		bool IsExiting()						{ return m_bExit; }

		/// ����MiniDump���������MiniDump���뱣֤����Ŀ¼��ϵͳĿ¼�´���"dbghelp.dll"
		GGE_EXPORT void EnableMiniDump();

	private:
		bool m_bExit;

	private:
		GGE_EXPORT void _Init();
		GGE_EXPORT bool _Update(float dt);
		friend class ggeAppInstance;
	};
}