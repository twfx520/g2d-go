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
\brief ��Ч��ģ��
*/

#pragma once
#include "ggerefcounter.h"
#include "ggevariant.h"

namespace gge
{
	/// ��Ч������
	enum SOUND_EFFECT_TYPE
	{
		EFFECT_NONE,			///< ��
		EFFECT_REVERB,			///< ����
		EFFECT_CHORUS,			///< �ϳ�
		EFFECT_DISTORTION,		///< ʧ��
		EFFECT_ECHO,			///< ����
		EFFECT_FLANGER,			///< ���
		EFFECT_MODULATOR,		///< ����
		EFFECT_COMPRESSOR,		///< ѹ��
		EFFECT_EQUALIZER,		///< ����
		EFFECT_LAST,
		EFFECT_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ��Ч������
	enum SOUND_EFFECT_PARAMETER
	{
		SEP_REVERB_GAIN,		///< ��Χ0~1��Ĭ��0.32
		SEP_REVERB_HFGAIN,		///< ��Χ0~1��Ĭ��0.89
		SEP_REVERB_DENSITY,		///< ��Χ0~1��Ĭ��1
		SEP_REVERB_DIFFUSION,	///< ��Χ0~1��Ĭ��1
		SEP_REVERB_DECAY,		///< ��Χ0.1~20��Ĭ��1.49
		SEP_REVERB_HFDECAY,		///< ��Χ0.1~2��Ĭ��0.83
		SEP_REVERB_EARLYGAIN,	///< ��Χ0~3.16��Ĭ��0.05
		SEP_REVERB_EARLYDELAY,	///< ��Χ0~3��Ĭ��0.007
		SEP_REVERB_LATEGAIN,	///< ��Χ0~10��Ĭ��1.26
		SEP_REVERB_LATEDELAY,	///< ��Χ0~0.1��Ĭ��0.011
		SEP_REVERB_ROLLOFF,		///< ��Χ0~10��Ĭ��0
		SEP_REVERB_AIRHFGAIN,	///< ��Χ0.892~1.0��Ĭ��0.994
		SEP_REVERB_HFLIMITER,	///< ��Χtrue/false��Ĭ��true

		SEP_CHORUS_WAVEFORM,	///< ��Χ WAVE_SINE / WAVE_TRIANGLE��Ĭ�� WAVE_TRIANGLE
		SEP_CHORUS_PHASE,		///< ��Χ(int)-180~180��Ĭ��90
		SEP_CHORUS_RATE,		///< ��Χ0~10��Ĭ��1.1
		SEP_CHORUS_DEPTH,		///< ��Χ0~1��Ĭ��0.1
		SEP_CHORUS_FEEDBACK,	///< ��Χ-1~1��Ĭ��0.25
		SEP_CHORUS_DELAY,		///< ��Χ0~0.016��Ĭ��0.016
									 
		SEP_DISTORTION_GAIN,	///< ��Χ0.01~1��Ĭ��0.05
		SEP_DISTORTION_EDGE,	///< ��Χ0~1��Ĭ��0.2
		SEP_DISTORTION_LOWCUT,	///< ��Χ80~24000��Ĭ��8000
		SEP_DISTORTION_EQCENTER,///< ��Χ80~24000��Ĭ��3600
		SEP_DISTORTION_EQBAND,	///< ��Χ80~24000��Ĭ��3600
									 
		SEP_ECHO_DELAY,			///< ��Χ0~0.2��Ĭ��0.1
		SEP_ECHO_LRDELAY,		///< ��Χ0~0.4��Ĭ��0.1
		SEP_ECHO_DAMPING,		///< ��Χ0~0.99��Ĭ��0.5
		SEP_ECHO_FEEDBACK,		///< ��Χ0~1��Ĭ��0.5
		SEP_ECHO_SPREAD,		///< ��Χ-1~1��Ĭ��-1
									 
		SEP_FLANGER_WAVEFORM,	///< ��Χ WAVE_SINE / WAVE_TRIANGLE��Ĭ�� WAVE_TRIANGLE
		SEP_FLANGER_PHASE,		///< ��Χ(int)-180~180��Ĭ��0
		SEP_FLANGER_RATE,		///< ��Χ0~10��Ĭ��0.27
		SEP_FLANGER_DEPTH,		///< ��Χ0~1��Ĭ��1
		SEP_FLANGER_FEEDBACK,	///< ��Χ-1~1��Ĭ��-0.5
		SEP_FLANGER_DELAY,		///< ��Χ0~0.004��Ĭ��0.002
									 
		SEP_MODULATOR_WAVEFORM,	///< ��Χ WAVE_SINE / WAVE_SAWTOOTH/WAVE_SQUARE��Ĭ�� WAVE_TRIANGLE
		SEP_MODULATOR_FREQ,		///< ��Χ0~8000��Ĭ��440
		SEP_MODULATOR_HIGHCUT,	///< ��Χ0~24000��Ĭ��800
									 
		SEP_COMPRESSOR_ENABLE,	///< ��Χture/false��Ĭ��true
									 
		SEP_EQUALIZER_LOWGAIN,	///< ��Χ0.126~7.943��Ĭ��1
		SEP_EQUALIZER_LOWCUT,	///< ��Χ50~800��Ĭ��200
		SEP_EQUALIZER_MID1GAIN,	///< ��Χ0.126~7.943��Ĭ��1
		SEP_EQUALIZER_MID1FREQ,	///< ��Χ200~3000��Ĭ��500
		SEP_EQUALIZER_MID1BAND,	///< ��Χ0.01~1��Ĭ��1
		SEP_EQUALIZER_MID2GAIN,	///< ��Χ0.126~7.943��Ĭ��1
		SEP_EQUALIZER_MID2FREQ,	///< ��Χ1000~8000��Ĭ��3000
		SEP_EQUALIZER_MID2BAND,	///< ��Χ0.01~1��Ĭ��1
		SEP_EQUALIZER_HIGHGAIN,	///< ��Χ0.126~7.943��Ĭ��1
		SEP_EQUALIZER_HIGHCUT,	///< ��Χ4000~16000��Ĭ��6000

		SEP_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ��Ч����������
	enum SOUND_EFFECT_WAVEFORM
	{
		WAVE_SINE,			///< ���Ҳ�
		WAVE_TRIANGLE,		///< ���ǲ�
		WAVE_SAWTOOTH,		///< ��ݲ�
		WAVE_SQUARE,		///< ����
		WAVE_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ��Ч��ģ��
	class ggeSoundEffect : public ggeRefCounter
	{
	public:
		/**
		@brief ������Ч������
		@param type ��Ч������
		*/
		virtual void				SetType(SOUND_EFFECT_TYPE type) = 0;
		/**
		@brief ������Ч������
		*/
		virtual SOUND_EFFECT_TYPE	GetType() = 0;
		/**
		@brief ������Ч������
		@param par ��Ч������ @see SOUND_EFFECT_PARAMETER
		@param var ��Ч����ֵ 
		*/
		virtual void				SetParameter(SOUND_EFFECT_PARAMETER par, ggeVariant var) = 0;
		/**
		@brief ������Ч������
		*/
		virtual ggeVariant			GetParameter(SOUND_EFFECT_PARAMETER par) = 0;
		/**
		@brief ������Ч������
		@param v ��Ч������
		*/
		virtual void				SetVolume(float v) = 0;
		/**
		@brief ������Ч������
		*/
		virtual float				GetVolume() = 0;
		/**
		@brief �õ�ǰ���õĲ���������Ч��
		@param b Ϊtrueʱ������Ч��,falseΪȡ���������������Ч���������֧�ֵ���Ч������������false @see SoundEffect_GetMaxEffectsSupported
		@note ��Ч�����������õ������Ч�ϣ����������޸�����Ч�������ͻ��������Ҫ���¼���µ����òŻ���Ч
		*/
		virtual bool				SetActive(bool b) = 0;
		/**
		@brief ������Ч���Ƿ񼤻�
		*/
		virtual bool				IsActive() = 0;
	};

	/**
	@brief ������Ч�������������֧����Ч��������0 @see GGE_SOUNDEFFECT
	*/
	GGE_EXPORT ggeSoundEffect* SoundEffect_Create();
	/**
	@brief �����������֧�ֵ���Ч������(�ɼ�����Ч�����������)
	*/
	GGE_EXPORT int SoundEffect_GetMaxEffectsSupported();
	/**
	@brief ���ص�����Դ�����õ������Ч������
	*/
	GGE_EXPORT int SoundEffect_GetMaxEffectsPerSound();
	/**
	@brief ���ص�ǰ�Ѽ������Ч������
	*/
	GGE_EXPORT int SoundEffect_GetActiveEffectCount();
}