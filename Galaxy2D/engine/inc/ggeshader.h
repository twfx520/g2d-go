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
\brief Shaderģ��

Shader��չģ��Ŀǰֻ֧��PixelShader
*/

#pragma once
#include "ggecommon.h"
#include "ggerefcounter.h"

namespace gge
{
	/// ����״̬
	enum TEXTURE_STATE
	{
		TEXSTATE_WRAP		= 1,	///< �ص�ӳ��Ѱַ
		TEXSTATE_MIRROR		= 2,	///< ��������Ѱַ
		TEXSTATE_CLAMP		= 3,	///< ��ȡ����Ѱַ
		TEXSTATE_BORDER		= 4,	///< �߿���ɫѰַ
		TEXSTATE_FILTER		= 8,	///< ������ˣ�������Ѱַ������"|"���ʹ��
		TEXSTATE_FORCE32BIT = 0x7FFFFFFF,
	};

	/// Shaderģ��
	class ggeShader : public ggeRefCounter
	{
	public:
		/**
		@brief ������������Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param name ������
		@param tex ����
		@param texState ����״̬
		@param borderColor �߿���ɫѰַ���õı߿���ɫ
		@see TEXTURE_STATE
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetTexture(const char *name, ggeTexture *tex, guint32 texState = TEXSTATE_WRAP, guint32 borderColor = 0) = 0;
		/**
		@brief ����float����ֵ������Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param name ������
		@param f ����ֵ
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetFloat(const char *name, float f) = 0;
		/**
		@brief ����float�������飬����Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param name ������
		@param pf ��������
		@param count ��������
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetFloatArray(const char *name, const float *pf, guint32 count) = 0;

		/**
		@brief ������������Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param startRegister ��ʼ�Ĵ���
		@param tex ����
		@param texState ����״̬
		@param borderColor �߿���ɫѰַ���õı߿���ɫ
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetTextureEx(guint32 startRegister, ggeTexture *tex, guint32 texState = TEXSTATE_WRAP, guint32 borderColor = 0) = 0;
		/**
		@brief ����float����ֵ������Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param startRegister ��ʼ�Ĵ���
		@param f ����ֵ
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetFloatEx(guint32 startRegister, float f) = 0;
		/**
		@brief ����float�������飬����Graph_SetCurrentShader()��������Ϊ��ǰShader��ú�����Ч
		@param startRegister ��ʼ�Ĵ���
		@param pf ��������
		@param count ��������
		@return �ɹ�����true��ʧ�ܷ���false
		*/
		virtual bool SetFloatArrayEx(guint32 startRegister, const float *pf, guint32 count) = 0;
	};

	/**
	@brief ����Shader�ļ�
	@param filename �ļ���
	@param function ��ں�������Ϊ0ʱ��ʾ�����ѱ���Ĵ���
	@param psVersion PixelShader�汾
	@return �ɹ�����ggeShader*��ʧ�ܷ���0
	*/
	GGE_EXPORT ggeShader*	 Shader_Load(const char *filename, const char *function = 0, PIXEL_SHADER_VERSION psVersion = PS_1_1);
	/**
	@brief ���ַ�������Shader
	@param shaderstr shader�ַ���
	@param function ��ں�������Ϊ0ʱ��ʾ�����ѱ���Ĵ���
	@param psVersion PixelShader�汾
	@return �ɹ�����ggeShaderָ�룬ʧ�ܷ���0
	*/
	GGE_EXPORT ggeShader*	 Shader_Create(const char *shaderstr, const char *function = 0, PIXEL_SHADER_VERSION psVersion = PS_1_1);
}