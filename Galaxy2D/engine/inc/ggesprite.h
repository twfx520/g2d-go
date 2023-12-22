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
	class ggeSprite : public ggeRefCounter
	{
	public:
		/**
		@brief ���ƾ���
		@param spr Դ����
		*/
		virtual void		Copy(ggeSprite *spr) = 0;
		/**
		@brief ���ص�ǰ�����һ������
		@return ��ǰ�����һ������
		*/
		virtual ggeSprite*	Clone() = 0;

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
		@brief ������Ⱦ����
		@param x x����
		@param y y����
		*/
		virtual void		SetPosition(float x, float y) = 0;
		/**
		@brief ������Ⱦ����
		@param x x����
		@param y y����
		@param rotation ��ת������
		@param hscale ˮƽ����ϵ��
		@param vscale ��ֱ����ϵ��������ֵΪ0.0f����ȡhscale
		*/
		virtual void		SetPositionEx(float x, float y, float rotation, float hscale = 1.0f, float vscale = 0.0f) = 0;
		/**
		@brief ������Ⱦ����
		@param x1 ���Ͻ�x����
		@param y1 ���Ͻ�y����
		@param x2 ���½�x����
		@param y2 ���½�y����
		*/
		virtual void		SetPositionStretch(float x1, float y1, float x2, float y2) = 0;
		/**
		@brief ������Ⱦ����
		@param x0 ���Ͻ�x����
		@param y0 ���Ͻ�y����
		@param x1 ���Ͻ�x����
		@param y1 ���Ͻ�y����
		@param x2 ���½�x����
		@param y2 ���½�y����
		@param x3 ���½�x����
		@param y3 ���½�y����
		*/
		virtual void		SetPosition4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3) = 0;
		/**
		@brief ��Ⱦ��SetPosition()�Ⱥ������ú�ľ��飬������鲻�Ǿ����仯λ�ã������ַ�ʽ��Ⱦ���������ȾЧ��
		*/
		virtual void		RenderPosition() = 0;

		/**
		@brief ������Ⱦ�������ú����������Զ���Ϊ��������
		@param texture ��Ⱦ����
		*/
		virtual void		SetTexture(ggeTexture *texture) = 0;
		/**
		@brief ���������Ⱦ������ָ��
		@return ������Ⱦ������ָ��
		*/
		virtual ggeTexture*	GetTexture() = 0;
		/**
		@brief ������Ⱦ��������
		@param x x����
		@param y y����
		@param width ���
		@param height �߶�
		*/
		virtual void		SetTextureRect(float x, float y, float width, float height) = 0;
		/**
		@brief ���������Ⱦ����������
		@param x x����
		@param y y����
		@param width ���
		@param height �߶�
		*/
		virtual void		GetTextureRect(float *x, float *y, float *width, float *height) = 0;
		/**
		@brief ������Ⱦ��ɫ
		@param color ��Ⱦ��ɫ
		@param i Ҫ���õĶ���(0~3)��-1���ĸ����㶼����Ϊ��ֵ
		*/
		virtual void		SetColor(guint32 color, int i = -1) = 0;
		/**
		@brief ���ָ���Ķ�����ɫ
		@param i �������
		@return ������ɫ
		*/
		virtual guint32		GetColor(int i = 0) = 0;	
		/**
		@brief ����Z��
		@param z 0.0f��1.0f��0��ʾ���ϲ㣬1��ʾ���²�
		@param i Ҫ���õĶ���(0~3)��-1���ĸ����㶼����Ϊ��ֵ
		*/
		virtual void		SetZ(float z, int i = -1) = 0;
		/**
		@brief ���Z��
		@param i �������
		@return Z��
		*/
		virtual float		GetZ(int i = 0) = 0;
		/**
		@brief ���û��ģʽ
		@param blend ���ģʽ������"|"���
		@see BLEND_MODE
		*/
		virtual void		SetBlendMode(int blend) = 0;
		/**
		@brief ��û��ģʽ
		@return ���ģʽ
		*/
		virtual int			GetBlendMode() = 0;
		/**
		@brief ����ê��
		@param x x����
		@param y y����
		*/
		virtual void		SetHotSpot(float x, float y) = 0;
		/**
		@brief ���ê������
		@param x x����
		@param y y����
		*/
		virtual void		GetHotSpot(float *x, float *y) = 0;
		/**
		@brief ��������ת����
		@param bX ˮƽ��ת
		@param bY ��ֱ��ת
		@param bHotSpot �Ƿ�תԭ��
		*/
		virtual void		SetFlip(bool bX, bool bY, bool bHotSpot = false) = 0;
		/**
		@brief ��÷�תģʽ����
		@param bX ˮƽ��ת
		@param bY ��ֱ��ת
		*/
		virtual void		GetFlip(bool *bX, bool *bY) = 0;
		
		/**
		@brief ��ÿ��
		@return ���
		*/
		virtual float		GetWidth() = 0;
		/**
		@brief ��ø߶�
		@return �߶�
		*/
		virtual float		GetHeight() = 0;
		/**
		@brief ����ı�������
		@return �ı�������
		*/
		virtual ggeQuad&	GetQuad() = 0;

		/**
		@brief ��þ���İ�Χ��
		@param rect �����Χ�о������ò���
		@param x ��Χ�����ĵ�x����
		@param y ��Χ�����ĵ�y����
		@return ��Χ�о���
		*/
		virtual ggeRect*	GetBoundingBox(ggeRect *rect, float x, float y) = 0;
		/**
		@brief �����ת�ͷ�ת��ľ����Χ��
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
	@param texture ����ʹ�õ�����
	@param x ����x����
	@param y ����y����
	@param width ������
	@param height ����߶�
	@return �ɹ�����ggeSpriteָ�룬���򷵻�0
	*/
	GGE_EXPORT ggeSprite*	 Sprite_Create(ggeTexture *texture, float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f);
}