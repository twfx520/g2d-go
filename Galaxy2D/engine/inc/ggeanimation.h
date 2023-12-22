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
\brief ����ģ��
*/

#pragma once
#include "ggecommon.h"
#include "ggerefcounter.h"

namespace gge
{
	/// ����ģ��
	class ggeAnimation : public ggeRefCounter
	{
	public:
		/**
		@brief ���ƶ���
		@param ani Դ����
		*/
		virtual void		Copy(ggeAnimation *ani) = 0;
		/**
		@brief ���ص�ǰ������һ������
		@return ��ǰ������һ������
		*/
		virtual ggeAnimation*	Clone() = 0;

		/**
		@brief ��ʼ���Ŷ���
		*/
		virtual void		Play() = 0;
		/**
		@brief ֹͣ���Ŷ���
		*/
		virtual void		Stop() = 0;
		/**
		@brief �������Ŷ���
		*/
		virtual void		Resume() = 0;
		/**
		@brief ˢ�¶���
		@param dt ��һ֡����ʱ�䣬����Timer_GetDelta()���
		*/
		virtual void		Update(float dt) = 0;
		/**
		@brief �Ƿ����ڲ���
		@return ���ڲ��ŷ���true�����򷵻�false
		*/
		virtual bool		IsPlaying() = 0;

		/**
		@brief ���ò���ģʽ
		@param mode ����ģʽ������"|"��ϣ�Ĭ��Ϊ��ANI_FORWARD|ANI_LOOP
		$see ANIMATION_MODE
		*/
		virtual void		SetMode(int mode) = 0;
		/**
		@brief ��ò���ģʽ
		@return ����ģʽ
		*/
		virtual int			GetMode() = 0;
		/**
		@brief ����֡��
		@param fps ֡��
		*/
		virtual void		SetSpeed(int fps) = 0;
		/**
		@brief ���֡�� 
		@return ֡��
		*/
		virtual int			GetSpeed() = 0;
		/**
		@brief ���õ�ǰ����֡
		@param n ��ǰ����֡
		*/
		virtual void		SetFrame(int n) = 0;
		/**
		@brief ��õ�ǰ����֡
		@return ��ǰ����֡
		*/
		virtual int			GetFrame() = 0;

		/**
		@brief ��Ⱦ
		@param x x����
		@param y y����
		*/
		virtual void		Render(float x, float y) = 0;
		/**
		@brief ��Ⱦ
		@param x x����
		@param y y����
		@param rotation ��ת������
		@param hscale ˮƽ����ϵ��
		@param vscale ��ֱ����ϵ��������ֵΪ0.0f����ȡhscale
		*/
		virtual void		RenderEx(float x, float y, float rotation, float hscale = 1.0f, float vscale = 0.0f) = 0;
		/**
		@brief ��Ⱦ
		@param x1 ���Ͻ�x����
		@param y1 ���Ͻ�y����
		@param x2 ���½�x����
		@param y2 ���½�y����
		*/
		virtual void		RenderStretch(float x1, float y1, float x2, float y2) = 0;
		/**
		@brief ��Ⱦ
		@param x0 ���Ͻ�x����
		@param y0 ���Ͻ�y����
		@param x1 ���Ͻ�x����
		@param y1 ���Ͻ�y����
		@param x2 ���½�x����
		@param y2 ���½�y����
		@param x3 ���½�x����
		@param y3 ���½�y����
		*/
		virtual void		Render4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3) = 0;

		/**
		@brief ���֡����
		@param spr ����
		@param n ֡����-1��ʾ������һ֡
		*/
		virtual void		AddFrameSprite(ggeSprite *spr, int n = -1) = 0;
		/**
		@brief ����֡����
		@param n ֡��
		@return ����֡���飬���ȡ��������0
		*/
		virtual ggeSprite*	GetFrameSprite(int n) = 0;
		/**
		@brief ɾ��֡����
		@param n ֡��,-1��ʾɾ��ȫ������
		*/
		virtual void		DelFrameSprite(int n = -1) = 0;
		/**
		@brief ���ض���֡����  
		@return ���ض���֡����
		*/
		virtual int			GetFrameCount() = 0;

		/**
		@brief ��ö������
		@return �������
		*/
		virtual float		GetWidth() = 0;
		/**
		@brief ��ö����߶�
		@return �����߶�
		*/
		virtual float		GetHeight() = 0;

		/**
		@brief ��ö����İ�Χ��
		@param rect �����Χ�о������ò���
		@param x ��Χ�����ĵ�x����
		@param y ��Χ�����ĵ�y����
		@return ��Χ�о���
		*/
		virtual ggeRect*	GetBoundingBox(ggeRect *rect, float x, float y) = 0;
		/**
		@brief �����ת�ͷ�ת��Ķ�����Χ��
		@param rect �����Χ�о������ò���
		@param x ��Χ�����ĵ�x����
		@param y ��Χ�����ĵ�y����
		@param rotation ��ת������,0.0f��ΪĬ��
		@param hscale ˮƽ����ϵ��,1.0f��ΪĬ��
		@param vscale ��ֱ����ϵ��,1.0f��ΪĬ��
		@return ��Χ�о���
		*/
		virtual ggeRect*	GetBoundingBoxEx(ggeRect *rect, float x, float y, float rotation, float hscale, float vscale) = 0;
	};

	/**
	@brief ��������
	@return �ɹ�����ggeAnimationָ�룬���򷵻�0
	*/
	GGE_EXPORT ggeAnimation*  Animation_Create();
}