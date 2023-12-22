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
\brief ��Чģ��
*/

#pragma once
#include "ggerefcounter.h"
#include "ggemath.h"
#include "ggecommon.h"

namespace gge
{
	/// ��Чģ��
	class ggeSound : public ggeRefCounter
	{
	public:
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
		@brief ����ʱ��(��λ:��)
		*/
		virtual float	GetDuration() = 0;

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
		@brief ����Ƶ��
		@param pitch ����Ƶ�ʣ���Χ0��10��1��ʾԭʼƵ��
		*/
		virtual void	SetPitch(float pitch) = 0;
		/**
		@brief ����Ƶ��
		*/
		virtual float	GetPitch() = 0;

		/**
		@brief ������Դ�����Ƿ���������� 
		@param bRelative ��Ϊtrueʱ��Դ����Ϊ����ڼ�����������
		*/
		virtual void	SetRelativeToListener(bool bRelative) = 0;
		/**
		@brief ������Դ�����Ƿ����������
		*/
		virtual bool	IsRelativeToListener() = 0;
		/**
		@brief ������Դ���� 
		@param position ��Դ����
		*/
		virtual void	SetPosition(const ggeVector3 &position) = 0;
		/**
		@brief ������Դ����
		*/
		virtual const ggeVector3& GetPosition() = 0;
		/**
		@brief ������Դ�ٶ�
		@param velocity ��Դ�ٶ�
		*/
		virtual void	SetVelocity(const ggeVector3 &velocity) = 0;
		/**
		@brief ������Դ�ٶ�
		*/
		virtual const ggeVector3& GetVelocity() = 0;
		/**
		@brief ������Դ����
		@param direction ��Դ����
		*/
		virtual void	SetDirection(const ggeVector3 &direction) = 0;
		/**
		@brief ������Դ����
		*/
		virtual const ggeVector3& GetDirection() = 0;
		/**
		@brief ������׶����
		@param innerAngle ��׶�Ƕȣ�Ĭ��360
		@param outerAngle ��׶�Ƕȣ�Ĭ��360
		@param outerVolume ��׶��������Χ0��1��Ĭ��0
		@param outerHighGain ��Ƶ��������Χ0��10��Ĭ��1
		*/
		virtual void	SetCone(float innerAngle, float outerAngle, float outerVolume, float outerHighGain = 1.0f) = 0;
		/**
		@brief ������׶����
		@param innerAngle ��׶�Ƕ�
		@param outerAngle ��׶�Ƕ�
		@param outerVolume ��׶����
		@param outerHighGain ��Ƶ����
		*/
		virtual void	GetCone(float &innerAngle, float &outerAngle, float &outerVolume, float &outerHighGain) = 0;
		/**
		@brief ������Դ��С����
		@param distance ��Դ��С����
		*/
		virtual void	SetMinDistance(float distance) = 0;
		/**
		@brief ������Դ��С����
		*/
		virtual float	GetMinDistance() = 0;
		/**
		@brief ������Դ������
		@param distance ��Դ������
		*/
		virtual void	SetMaxDistance(float distance) = 0;
		/**
		@brief ������Դ������
		*/
		virtual float	GetMaxDistance() = 0;
		/**
		@brief ������Դ����˥���ٶ�
		@param factor ��Դ˥���ٶȣ�Խ��˥��Խ�죬Ĭ��1
		*/
		virtual void	SetRolloffFactor(float factor) = 0;
		/**
		@brief ������Դ����˥���ٶ�
		*/
		virtual float	GetRolloffFactor() = 0;
		/**
		@brief ������Դ����������
		@param factor ��Դ���������ʣ�Խ���Ƶ˥��Խ�죬��Χ0~10��Ĭ��0
		*/
		virtual	void	SetAirAbsorptionFactor(float factor) = 0;
		/**
		@brief ������Դ����������
		*/
		virtual float	GetAirAbsorptionFactor() = 0;

		/**
		@brief �����Ч��
		@param effect ��Ч�����������������������Ч������������false @see SoundEffect_GetMaxEffectsPerSound
		*/
		virtual	bool	AddEffect(ggeSoundEffect *effect) = 0;
		/**
		@brief �Ƴ���Ч��
		@param effect ��Ч��
		*/
		virtual bool	RemoveEffect(ggeSoundEffect *effect) = 0;
		/**
		@brief �����Ч��
		*/
		virtual void	ClearEffect() = 0;
		/**
		@brief ������Ч������
		*/
		virtual int		GetEffectCount() = 0;
		/**
		@brief ������Ч��
		*/
		virtual ggeSoundEffect*	GetEffect(int n) = 0;
	};

	/**
	@brief ������Ч�ļ�
	@param filename ��Ч�ļ�����֧���ļ���ʽ��wav, ogg, mp3
	@param size �ڴ��С��Ϊ0ʱ���ļ�������Ч������filename��Ϊ��Ч�ļ����ڴ��еĵ�ַ����ֵָʾ����ڴ�Ĵ�С�����ڴ���������Ч
	@return �ɹ�����ggeSoundָ�룬���򷵻�0
	@note	1.��Чģ�鲥��������Ӧ�ٶȿ���ͬʱ���Բ��Ŷ�Σ�����ռ�ñȽϴ���ڴ棬�����ڲ����ӵ���ʱ���϶̣���Ҫʵʱ�����ҿ���ͬʱ���Ŷ�ε������ļ�
			2.�����ǵ�������Ч�ļ��ſ���ʹ��3D��Ч����\n
			3.3D��Ч����ʹ�õ�����������ϵ
	*/
	GGE_EXPORT ggeSound* Sound_Load(const char *filename, guint32 size = 0);
}