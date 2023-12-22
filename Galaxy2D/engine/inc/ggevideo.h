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
\brief ��Ƶģ��
*/

#pragma once
#include "ggerefcounter.h"
#include "ggetypes.h"

namespace gge
{
	class ggeVideo : public ggeRefCounter
	{
	public:
		/**
		@brief ��Ⱦ
		@param x x����
		@param y y����
		*/
		virtual void	Render(float x, float y) = 0;
		/**
		@brief ��Ⱦ
		@param x x����
		@param y y����
		@param rotation ��ת������
		@param hscale ˮƽ����ϵ��
		@param vscale ��ֱ����ϵ��������ֵΪ0.0f����ȡhscale
		*/
		virtual void	RenderEx(float x, float y, float rotation, float hscale, float vscale) = 0;
		/**
		@brief ��Ⱦ
		@param x1 ���Ͻ�x����
		@param y1 ���Ͻ�y����
		@param x2 ���½�x����
		@param y2 ���½�y����
		*/
		virtual void	RenderStretch(float x1, float y1, float x2, float y2) = 0;
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
		virtual void	Render4V(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3) = 0;

		/**
		@brief ����
		*/
		virtual void	Play() = 0;
		/**
		@brief ��ͣ����
		*/
		virtual void	Pause() = 0;
		/**
		@brief ��������
		*/
		virtual void	Resume() = 0;
		/**
		@brief ֹͣ����
		*/
		virtual void	Stop() = 0;
		/**
		@brief �����Ƿ����ڲ���
		*/
		virtual bool	IsPlaying() = 0;
		/**
		@brief ���ص�ǰ����ʱ��(��λ:��)
		*/
		virtual float	GetPlayingTime() = 0;

		/**
		@brief �����ظ�����
		@param bLoop ��Ϊtrueʱ�ظ�����
		*/
		virtual void	SetLoop(bool bLoop) = 0;
		/**
		@brief �����Ƿ��ظ�����
		*/
		virtual bool	IsLoop() = 0;
		/**
		@brief ��������
		@param volume ������������Χ0��100
		*/
		virtual void	SetVolume(float volume) = 0;
		/**
		@brief ��������
		*/
		virtual float	GetVolume() = 0;
		
		/**
		@brief ����Z��
		@param z 0.0f��1.0f��0��ʾ���ϲ㣬1��ʾ���²�
		*/
		virtual void	SetZ(float z) = 0;
		/**
		@brief ���Z��
		@return Z��
		*/
		virtual float	GetZ() = 0;
		/**
		@brief ���û��ģʽ
		@param blend ���ģʽ������"|"���
		@see BLEND_MODE
		*/
		virtual void	SetBlendMode(int blend) = 0;
		/**
		@brief ��û��ģʽ
		@return ���ģʽ
		*/
		virtual int		GetBlendMode() = 0;
		/**
		@brief ����ê��
		@param x x����
		@param y y����
		*/
		virtual void	SetHotSpot(float x, float y) = 0;
		/**
		@brief ���ê������
		@param x x����
		@param y y����
		*/
		virtual void	GetHotSpot(float *x, float *y) = 0;

		/**
		@brief ��ÿ��
		@return ���
		*/
		virtual int		GetWidth() = 0;
		/**
		@brief ��ø߶�
		@return �߶�
		*/
		virtual int		GetHeight() = 0;
	};

	/**
	@brief ������Ƶ�ļ�
	@param filename ��Ч�ļ�����֧���ļ���ʽ��.ogv
	@return �ɹ�����ggeVideoָ�룬���򷵻�0
	@note	���Ҫ���ļ�����������Ƶ�ļ�����Ƶ�ļ��ĺ�׺��������".ogv"������ʹ�������Դ����ļ�������ߣ����򽫶�ȡʧ��
	*/
	GGE_EXPORT ggeVideo* Video_Load(const char *filename);
}