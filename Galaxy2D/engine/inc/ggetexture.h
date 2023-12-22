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
	/// ��ȾĿ����������
	enum TARGET_TYPE
	{
		TARGET_DEFAULT = 0,		///< Ĭ������
		TARGET_ZBUFFER = 1,		///< ����ZBuffer
		TARGET_LOCKABLE = 2,	///< ��ȾĿ��������Ա�����
		TARGET_ALPHA = 4,		///< ��ȾĿ�������Alphaͨ��(��ͨ��ϵͳ״̬ GGE_ALPHARENDERTARGET ����Կ��Ƿ�֧�ִ�����Alphaͨ������ȾĿ������)
		TARGET_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ����
	class ggeTexture : public ggeRefCounter
	{
	public:
		/**
		@brief ��������
		@param bReadOnly �Ƿ�ֻ��(�������Ҫд�����ݣ��ɽ���ֵ��Ϊtrue�����Ч��)
		@param left ���������������λ��
		@param top �������������Ϸ�λ��
		@param width ��������������
		@param height ������������߶�
		@param pitch һ�����ݵĳ���
		@return �ɹ������������ݣ����򷵻�0
		@note 1.δ������������ʱ��������������Ϊ�����Ч����������ʱӦ����ָ����������\n
		2.���������ʽ��ʹ�ö�Ӧ�����ݽṹ��ȡ��������ɫֵ�����統�����ʽ��TEXFMT_A8R8G8B8ʱ������������ȡ��������ɫֵ��\n
		\code
		guint32 *buf = tex->Lock();
		guint32 color = buf[y * textureWidth + x]; 
		buf[y * textureWidth + x] = newColor; 
		\endcode
		����textureWidth����GetWidth()������á�\n
		3.������ȾĿ������ʱ���ָ����TARGET_LOCKABLE���������Ҳ����Lock
		*/
		virtual guint32* Lock(bool bReadOnly = true, int left = 0, int top = 0, int width = 0, int height = 0, int *pitch = 0) = 0;
		/**
		@brief �����������
		*/
		virtual void	Unlock() = 0;

		/**
		@brief ���������
		@param bOrginal Ϊtrueʱ��������ԭʼ��ȣ�Ϊfalseʱ�����������Դ���
		@return ������
		*/
		virtual int		GetWidth(bool bOrginal = false) = 0;
		/**
		@brief �������߶�
		@param bOrginal Ϊtrueʱ��������ԭʼ�߶ȣ�Ϊfalseʱ�����������Դ�߶�
		@return ����߶�
		*/
		virtual int		GetHeight(bool bOrginal = false) = 0;
		/**
		@brief ��������ʽ
		*/
		virtual TEXTURE_FORMAT GetFormat() = 0;

		/**
		@brief ���浽�ļ�
		@param filename �ļ���
		@param imageFormat �ļ���ʽ��Ĭ�ϱ���ΪPNG��ʽͼƬ
		@return ���ر����Ƿ�ɹ�
		*/
		virtual bool	SaveToFile(const char *filename, GGE_IMAGE_FORMAT imageFormat = IMAGE_PNG) = 0;
	};

	/**
	@brief ��������
	@param width ������
	@param height ����߶�
	@param format �����ʽ @see TEXTURE_FORMAT
	@return �ɹ�����ggeTextureָ�룬ʧ�ܷ���0
	*/
	GGE_EXPORT ggeTexture*	 Texture_Create(int width, int height, TEXTURE_FORMAT format = TEXFMT_A8R8G8B8);
	/**
	@brief ������ȾĿ������
	@param width ������
	@param height ����߶�
	@param targetType ��ȾĿ���������ͣ�����"|"��� @see TARGET_TYPE
	@return �ɹ�����ggeTextureָ�룬ʧ�ܷ���0
	*/
	GGE_EXPORT ggeTexture*	 Texture_CreateRenderTarget(int width, int height, int targetType = TARGET_DEFAULT);
	/**
	@brief ��������
	@param filename �����ļ�����֧���ļ����ͣ�bmp, png, jpg, tga, dds(DXT1-DXT5)
	@param colorKey ��ɫ��
	@param size �ڴ��С��Ϊ0ʱ���ļ�������������filename��Ϊ�����ļ����ڴ��еĵ�ַ����ֵָʾ����ڴ�Ĵ�С�����ڴ�����������
	@param format �����ʽ�����ͼƬ�����Ըø�ʽ���룬���Զ�ת��ΪTEXFMT_A8R8G8B8��ʽ�����ò���ΪTEXFMT_UNKNOWNʱ���δ����ǿ������ת���������ͼƬ��ʽ�Զ�����Ϊ����ʵĸ�ʽ
	@return �ɹ�����ggeTextureָ�룬ʧ�ܷ���0
	*/
	GGE_EXPORT ggeTexture*	 Texture_Load(const char *filename, guint32 colorKey = 0x00000000, guint32 size = 0, TEXTURE_FORMAT format = TEXFMT_UNKNOWN);
}