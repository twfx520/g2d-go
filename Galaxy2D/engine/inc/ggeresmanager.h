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
\brief ��Դ������
*/

#pragma once
#include "ggecommon.h"
#include "ggerefcounter.h"

namespace gge
{
	/// ��Դ����
	enum GGE_RES_TYPE
	{
		GRT_TEXTURE,		///< ����
		GRT_SOUND,			///< ��Ч
		GRT_MUSIC,			///< ����
		GRT_SPRITE,			///< ����
		GRT_ANIMATION,		///< ����
		GRT_FONT,			///< ����
		GRT_PARTICLE,		///< ����
		GRT_MESH,			///< ����
		GRT_STRING,			///< �ַ���
		GRT_CUSTOMRES,		///< �Զ�����Դ
		GRT_LAST,
		GRT_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ��Դ������������Դ�ص�
	class ggeTraversalResCallBack
	{
	public:
		virtual ~ggeTraversalResCallBack() {}
		/**
		@brief ������Դ�ص�
		@param name ��Դ��
		@param type ��Դ����
		@return ���Ҫ�ж�ö�ٷ���true
		*/
		virtual bool OnTraversalRes(const char *name, GGE_RES_TYPE type) { return false; }
	};

	/// ��Դ������
	class ggeResManager : public ggeRefCounter
	{
	public:
		/**
		@brief ������Դ�ļ���������������Դ�ļ������������Դ�ļ�����������Դ��������
		@param filename ��Դ�ļ���
		@return ����ɹ�true,���򷵻�false
		*/
		virtual bool	LoadResFile(const char *filename) = 0;
		/**
		@brief Ԥ������Դ
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool	PrepareCache() = 0;
		/**
		@brief ��ʼ������Դ
		@return ������Դ����
		*/
		virtual int		BeginLoadRes() = 0;
		/**
		@brief �����¸���Դ
		@return �ɹ�����true��ʧ�ܷ���false
		@note ʾ����\n
		int ResCount = ResMgr->BeginLoadRes();\n
		for (int i = 1; i <= ResCount; i++) \n
		{\n
			ResMgr->LoadNextRes();\n
			printf("�������:%d\n", i * 100 / ResCount);\n
		}\n
		*/
		virtual bool	LoadNextRes() = 0;
		/**
		@brief �����Դ�ļ��Լ����������Դ
		*/
		virtual void	Clear() = 0;
		/**
		@brief ������������ʱ��
		@param gcTime ��������ʱ��(��λ:��),��gcTime>0ʱ������Զ����ճ���gcTimeδʹ�õ���Դ�����gcTime=0����Ҫ�ֶ�������������,Ĭ��gcTime=60
		*/
		virtual void	SetGarbageCollectTime(float gcTime) = 0;
		/**
		@brief �ֶ���������
		@param bForce Ϊtrueʱ��������δ���õ���Դ������ֻ�����ѹ�����Դ
		@note �����ֶ��������δ���õ���Դ���������ⲿ����ģʽ���ֶ�������Դ
		*/
		virtual	void	 GarbageCollect(bool bForce = false) = 0;
		/**
		@brief ������Դ�������е���Դ
		@param callback ��Դ������������Դ�ص�
		*/
		virtual void	TraversalRes(ggeTraversalResCallBack *callback) = 0;

		/**
		@brief ����ָ����Դ��������
		@param name ��Դ��
		@return �ɹ���������ʧ�ܷ���0
		*/
		virtual ggeTexture*		CreateTexture(const char *name) = 0;
		/**
		@brief ����ָ����Դ�����������û�ҵ�����ָ���Ĳ�������һ��
		@param name ��Դ��
		@param filename �ļ���
		@param colorKey ��ɫ��
		@return �ɹ���������ʧ�ܷ���0
		*/
		virtual ggeTexture*		CreateTextureFromFile(const char *name, const char *filename, guint32 colorKey = 0) = 0;
		/**
		@brief ����ָ����Դ������Ч
		@param name ��Դ��
		@return �ɹ�������Ч��ʧ�ܷ���0
		*/
		virtual ggeSound*		CreateSound(const char *name) = 0;
		/**
		@brief ����ָ����Դ������Ч�����û�ҵ��ʹ���һ��
		@param name ��Դ��
		@param filename �ļ���
		@return �ɹ�������Ч��ʧ�ܷ���0
		*/
		virtual ggeSound*		CreateSoundFromFile(const char *name, const char *filename) = 0;
		/**
		@brief ����ָ����Դ��������
		@param name ��Դ��
		@return �ɹ��������֣�ʧ�ܷ���0
		*/
		virtual ggeMusic*		CreateMusic(const char *name) = 0;
		/**
		@brief ����ָ����Դ�������֣����û�ҵ��ʹ���һ��
		@param name ��Դ��
		@param filename �ļ���
		@return �ɹ�������Ч��ʧ�ܷ���0
		*/
		virtual ggeMusic*		CreateMusicFromFile(const char *name, const char *filename) = 0;
		/**
		@brief ����ָ����Դ���ľ���
		@param name ��Դ��
		@return �ɹ����ؾ��飬ʧ�ܷ���0
		*/
		virtual ggeSprite*		CreateSprite(const char *name) = 0;
		/**
		@brief ����ָ����Դ���Ķ���
		@param name ��Դ��
		@return �ɹ����ض�����ʧ�ܷ���0
		*/
		virtual ggeAnimation*	CreateAnimation(const char *name) = 0;
		/**
		@brief ����ָ����Դ��������
		@param name ��Դ��
		@return �ɹ��������壬ʧ�ܷ���0
		*/
		virtual ggeFont*		CreateFont(const char *name) = 0;
		/**
		@brief ����ָ����Դ�������壬���û�ҵ�����ָ���Ĳ�������һ��
		@param name ��Դ��
		@param filename �����ļ���(*.ttf/*.ttc)
		@param size �����С����λ������
		@param createMode ���崴��ģʽ������"|"��� @see FONT_CREATE_MODE
		@return �ɹ��������壬ʧ�ܷ���0
		*/
		virtual ggeFont*		CreateCustomFont(const char *name, const char *filename, int size = 16, int createMode = FONT_MODE_DEFAULT) = 0;
		/**
		@brief ����ָ����Դ�������壬���û�ҵ�����ָ���Ĳ�������һ��
		@param name ��Դ��
		@param filename ���������ļ�
		@return �ɹ��������壬ʧ�ܷ���0
		*/
		virtual ggeFont*		CreateCustomFontFromImage(const char *name, const char *filename) = 0;
		/**
		@brief ����ָ����Դ��������ϵͳ
		@param name ��Դ��
		@return �ɹ���������ϵͳ��ʧ�ܷ���0
		*/
		virtual ggeParticle*	CreateParticle(const char *name) = 0;
		/**
		@brief ����ָ����Դ��������
		@param name ��Դ��
		@return �ɹ���������ʧ�ܷ���0
		*/
		virtual ggeMesh*		CreateMesh(const char *name) = 0;
		/**
		@brief ����ָ����Դ�����ַ���
		@param name ��Դ��
		@return �ɹ������ַ�����ʧ�ܷ���0
		*/
		virtual const char*		GetString(const char *name) = 0;
		/**
		@brief ����йܵ��Զ�����Դ
		@param name ��Դ��
		@param res �йܵ���Դ
		@note �ú������������ü���
		*/
		virtual void			AddCustomRes(const char *name, ggeRefCounter *res) = 0;
		/**
		@brief �����йܵ��Զ�����Դ
		@param name ��Դ��
		@return �ɹ������Զ�����Դ��ʧ�ܷ���0
		@note �����Դ�������������������ջ��ƣ��йܵ���ԴҲ�ᱻ���ա�
		����й���Դ�����գ��ú���������0���ⲿ��Ҫ�ٴδ�������Դ������AddCustomRes()������ӵ���Դ������
		*/
		virtual ggeRefCounter*	CreateCustomRes(const char *name) = 0;
	};

	/**
	@brief ������Դ������
	@return �����ɹ�����ggeResManagerָ�룬���򷵻�0
	*/
	GGE_EXPORT ggeResManager*	 ResManager_Create();
}