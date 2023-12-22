/*
**  =======================================================
**                Galaxy2D Game Engine       
**                                
**       ��Ȩ����(c) 2005 ����. ��������Ȩ��.
**    ��ҳ��ַ: http://www.cnblogs.com/jianguhan/
**			 ��������: jianguhan@126.com
**  =======================================================
*/

/** \file
\brief ��������
*/

#pragma once
#include "ggecommon.h"

namespace gge
{
	/// ����汾��
	#define GGE_VERSION 42

	/** @name ��������
	*  @{
	*/

	/**
	@brief ��������
	@param ver �汾��
	@return �ɹ�����true��ʧ�ܷ���false
	*/
	GGE_EXPORT bool			 Engine_Create(int ver = GGE_VERSION);
	/**
	@brief �ͷ�����
	*/
	GGE_EXPORT void			 Engine_Release();

	/**
	@brief ��ʼ��ϵͳ
	@return �ɹ�����true��ʧ�ܷ���false
	@note ϵͳδ��ʼ��ǰֻ��System_SetState������Ч
	*/
	GGE_EXPORT bool			 System_Initiate();
	/**
	@brief ϵͳ��ʼ����
	@return ������������true�����򷵻�false
	@note ���иú���ǰ��������֡����
	*/
	GGE_EXPORT bool			 System_Start();

	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	@param value ״ֵ̬
	*/
	GGE_EXPORT void			 System_SetState(GGE_STATE_INT state, int value);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	@param value ״ֵ̬
	*/
	GGE_EXPORT void			 System_SetState(GGE_STATE_BOOL state, bool value);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	@param value ״ֵ̬
	*/
	GGE_EXPORT void			 System_SetState(GGE_STATE_CHAR state, const char *value);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	@param value ״ֵ̬
	*/
	GGE_EXPORT void			 System_SetState(GGE_STATE_BOOL_FUN state, GGE_BOOLFUN value);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	@param value ״ֵ̬
	*/
	GGE_EXPORT void			 System_SetState(GGE_STATE_SYS_VAL state, const void *value);

	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	*/
	GGE_EXPORT int			 System_GetState(GGE_STATE_INT state);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	*/
	GGE_EXPORT bool			 System_GetState(GGE_STATE_BOOL state);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	*/
	GGE_EXPORT const char*	 System_GetState(GGE_STATE_CHAR state);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	*/
	GGE_EXPORT GGE_BOOLFUN	 System_GetState(GGE_STATE_BOOL_FUN state);
	/**
	@brief ����ϵͳ״̬
	@param state ״̬
	*/
	GGE_EXPORT void*		System_GetState(GGE_STATE_SYS_VAL state);

	/**
	@brief д�����Log
	@param format log��¼
	*/
	GGE_EXPORT void			 System_Log(const char *format, ...);
	/**
	@brief �����ⲿ��ִ���ļ����URL
	@param url ��ִ���ļ���URL
	*/
	GGE_EXPORT bool			 System_Launch(const char *url);

	/**
	@brief ��ȡ��Դ�ļ�
	@param filename ��Դ�ļ���
	@param size ��ȡ�ļ��ɹ����ļ���Сд��ò���
	@return ��ȡ�ɹ�������Դ�ڴ�ָ�룬���򷵻�0
	@note �ú������ȶ�ȡ�󶨵��ļ����ڵ��ļ�
	*/
	GGE_EXPORT char*		 Resource_Load(const char *filename, guint32 *size = 0);
	/**
	@brief ��ȡ��Դ�ļ���ָ�����ڴ���
	@param filename ��Դ�ļ���
	@param buf ���ڱ�����Դ�ļ����ڴ�
	@param size �ڴ��С�����С���ļ���С��ȡ����ʧ��
	@return ��ȡ�ɹ�����ʵ�ʶ�ȡ���ֽ�������ȡʧ�ܷ���0
	@note �ú������ȶ�ȡ�󶨵��ļ����ڵ��ļ�
	*/
	GGE_EXPORT guint32		 Resource_LoadTo(const char *filename, char *buf, guint32 size);
	/**
	@brief ��ȡ��Դ�ļ���С
	@param filename ��Դ�ļ���
	@return ��Դ�ļ���С
	@note �ú������ȶ�ȡ�󶨵��ļ����ڵ��ļ�
	*/
	GGE_EXPORT guint32		 Resource_GetSize(const char *filename);
	/**
	@brief �����Դ�ļ��Ƿ����
	@param filename ��Դ�ļ���
	@return ��Դ�ļ����ڷ���true�����򷵻�false
	*/
	GGE_EXPORT bool			 Resource_IsExist(const char *filename);
	/**
	@brief �ͷ���Դ
	@param buf Resource_Load()�����������Դ
	*/
	GGE_EXPORT void			 Resource_Free(const char *buf);
	/**
	@brief ���ļ������ļ������������渽�����ļ�����������ɣ�Ҳ������һ��zipѹ���ļ�
	@param filename �ļ���
	@param password ����
	@return �󶨳ɹ�����true�����򷵻�false
	@note ���ж���ļ��������ΰ󶨼��ɡ������ļ�ʱ�ӵ�һ�����ļ�����ʼ�����ļ�������ҵ��������أ����Ժ����ļ����е�ͬ���ļ���
	*/
	GGE_EXPORT bool			 Resource_AttachPack(const char *filename, const char *password = 0);
	/**
	@brief �Ƴ��ļ���
	@param filename �ļ���
	*/
	GGE_EXPORT void			 Resource_RemovePack(const char *filename = 0);
	/**
	@brief �����Դ�ļ�����·��
	��Resource_Load()�����ڵ�ǰĿ¼�޷��ҵ���Դ�ļ����᳢�Դ�����·���в����ļ�������·������Ӷ��������ɾ��
	@param pathname ��Դ����·��
	*/
	GGE_EXPORT void			 Resource_AddPath(const char *pathname);

	/**
	@brief �������ڲ�����ini�ļ�����������ļ��ڵ�ǰĿ¼��Ҫ���ļ���ǰ��"./"�����磺Ini_SetFile("./cfg.ini")
	@param filename �ļ���
	@note �����ļ���ʽ:\n
	;ע��\n
	[�ֶ���]\n
	����=��ֵ\n
	*/
	GGE_EXPORT void			 Ini_SetFile(const char *filename);
	/**
	@brief ��int����ֵд�������ļ�
	@param section �ֶ���
	@param name ����
	@param value ��ֵ
	*/
	GGE_EXPORT void			 Ini_SetInt(const char *section, const char *name, int value);
	/**
	@brief ���int����ֵ
	@param section �ֶ���
	@param name ����
	@param def_val Ĭ��ֵ
	@return ����ҵ�ָ���ļ�ֵ���ظ�ֵ���򷵻�defval
	*/
	GGE_EXPORT int			 Ini_GetInt(const char *section, const char *name, int def_val);
	/**
	@brief ��float����ֵд�������ļ�
	@param section �ֶ���
	@param name ����
	@param value ��ֵ
	*/
	GGE_EXPORT void			 Ini_SetFloat(const char *section, const char *name, float value);
	/**
	@brief ���float����ֵ
	@param section �ֶ���
	@param name ����
	@param def_val Ĭ��ֵ
	@return ����ҵ�ָ���ļ�ֵ���ظ�ֵ���򷵻�defval
	*/
	GGE_EXPORT float		 Ini_GetFloat(const char *section, const char *name, float def_val);
	/**
	@brief ���ַ���д�������ļ�
	@param section �ֶ���
	@param name ����
	@param value ��ֵ
	*/
	GGE_EXPORT void			 Ini_SetString(const char *section, const char *name, const char *value);
	/**
	@brief ����ַ��� 
	@param section �ֶ���
	@param name ����
	@param def_val Ĭ��ֵ
	@return ����ҵ�ָ���ļ�ֵ���ظ�ֵ���򷵻�defval(ע�⣬�ַ������ܳ���255��Ӣ���ַ������򳬹��Ĳ��ֽ�������)
	*/
	GGE_EXPORT const char*	 Ini_GetString(const char *section, const char *name, const char *def_val);

	/**
	@brief ��Ϸ�����󾭹���ʱ�䣬ÿ֡ˢ��һ�Σ���ȷ��1����
	@return ������Ϸʱ��
	*/
	GGE_EXPORT guint32		 Timer_GetTime();
	/**
	@brief ����ʵʱʱ�䣬һ֡�����ε��øú���������ֵ���ܲ�ͬ����ȷ��1����
	@return ���ص�ǰʱ��
	*/
	GGE_EXPORT guint32		 Timer_GetTick();
	/**
	@brief ������һ֡����ʱ��
	@return ������һ֡����ʱ�䣬��ȷ��0.001��
	*/
	GGE_EXPORT float		 Timer_GetDelta();
	/**
	@brief ����֡��
	@return ����֡��
	*/
	GGE_EXPORT int			 Timer_GetFPS();

	/**
	@brief ����һ����������������������Է�ֹ���������ظ���
	@return �����������ID
	*/
	GGE_EXPORT guint32		 Random_Create();
	/**
	@brief �������������
	@param seed ���������
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	*/
	GGE_EXPORT void			 Random_Seed(guint32 seed, guint32 rid = 0);
	/**
	@brief ����int���������
	@param min ��Сֵ
	@param max ���ֵ
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	@return min��max��������������min��max
	*/
	GGE_EXPORT int			 Random_Int(int min, int max, guint32 rid = 0);
	/**
	@brief ����float���������
	@param min ��Сֵ
	@param max ���ֵ
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	@return min��max��������������min��max
	*/
	GGE_EXPORT float		 Random_Float(float min, float max, guint32 rid = 0);
	/**
	@brief ����һ�������������������(Mersenne Twister)���Է�ֹ���������ظ���
	@return �����������ID
	*/
	GGE_EXPORT guint32		 Random_CreateMt();
	/**
	@brief �������������(Mersenne Twister)
	@param seed ���������
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	*/
	GGE_EXPORT void			 Random_SeedMt(guint32 seed, guint32 rid = 0);
	/**
	@brief ����int���������(Mersenne Twister)
	@param min ��Сֵ
	@param max ���ֵ
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	@return min��max��������������min��max
	*/
	GGE_EXPORT int			 Random_IntMt(int min, int max, guint32 rid = 0);
	/**
	@brief ����unsigned int���������(Mersenne Twister)
	@param min ��Сֵ
	@param max ���ֵ
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	@return min��max��������������min��max
	*/
	GGE_EXPORT guint32		 Random_UIntMt(guint32 min, guint32 max, guint32 rid = 0);
	/**
	@brief ����float���������(Mersenne Twister)
	@param min ��Сֵ
	@param max ���ֵ
	@param rid �����������ID��Ϊ0ʱ��ʾĬ��������
	@return min��max��������������min��������max
	*/
	GGE_EXPORT float		 Random_FloatMt(float min, float max, guint32 rid = 0);

	/**
	@brief ��ָ����ɫ�����Ļ
	@param color �����Ļ��ɫ
	*/
	GGE_EXPORT void			 Graph_Clear(guint32 color = 0xFF000000);
	/**
	@brief ��ʼ��Ⱦ
	@param texture ��������Ϊ��ȾĿ����������Ⱦ��������������Ⱦ��Ĭ����ȾĿ��
	@return ���óɹ�����true
	*/
	GGE_EXPORT bool			 Graph_BeginScene(ggeTexture *texture = 0);
	/**
	@brief ������Ⱦ
	@param bPresent �Ƿ���Ⱦ��̨����������Ļ�������������ȾĿ�������ò�����Ч
	*/
	GGE_EXPORT void			 Graph_EndScene(bool bPresent = true);
	/**
	@brief ������Ⱦ��̨������
	@param texture ���ƺ�̨���������ݵ�������(��������ȾĿ������)
	@param srcRt ��̨������Ҫ���Ƶ�����Ϊ0ʱ��ʾ��������
	@param destRt Ŀ����������Ϊ0ʱ��ʾ��������
	*/
	GGE_EXPORT bool			 Graph_CopyBackBuffer(ggeTexture *texture, ggeRect *srcRt = 0, ggeRect *destRt = 0, bool btFilter = false);
	/**
	@brief ������ȾĿ������
	@param src Դ����
	@param dest Ŀ������
	@param srcRt Դ��������Ϊ0ʱ��ʾ��������
	@param destRt Ŀ����������Ϊ0ʱ��ʾ��������
	*/
	GGE_EXPORT bool			 Graph_CopyRanderTarget(ggeTexture *src, ggeTexture *dest, ggeRect *srcRt = 0, ggeRect *destRt = 0, bool btFilter = false);
		/**
	@brief ���õ�ǰShader
	@param shader Ҫ���õ�Shader�����Ϊ0�������ǰShader
	*/
	GGE_EXPORT void			 Graph_SetCurrentShader(ggeShader *shader = 0);
	/**
	@brief ���ص�ǰShader
	*/
	GGE_EXPORT ggeShader*	 Graph_GetCurrentShader();
	/**
	@brief �ӵ�(x1,y1)��(x2,y2)����
	@param x1 ��ʼ��x����
	@param y1 ��ʼ��y����
	@param x2 ������x����
	@param y2 ������y����
	@param color ָ���ߵ���ɫ
	*/
	GGE_EXPORT void			 Graph_RenderLine(float x1, float y1, float x2, float y2, guint32 color = 0xFFFFFFFF);
	/**
	@brief �ӵ�(x1,y1)��(x2,y2)������
	@param x1 ��ʼ��x����
	@param y1 ��ʼ��y����
	@param x2 ������x����
	@param y2 ������y����
	@param color ָ���ߵ���ɫ
	*/
	GGE_EXPORT void			 Graph_RenderRect(float x1, float y1, float x2, float y2, guint32 color = 0xFFFFFFFF);
	/**
	@brief ��������
	@param triple ���������� 
	*/
	GGE_EXPORT void			 Graph_RenderTriple(const ggeTriple &triple);
	/**
	@brief ���ı���
	@param quad �ı������� 
	*/
	GGE_EXPORT void			 Graph_RenderQuad(const ggeQuad &quad);

	/**
	@brief ��Ⱦ�Զ���ͼԪ(�ú���������DrawCall)
	@param primType ͼԪ����
	@param vt ��������
	@param primNum ͼԪ����
	@param tex ��ȾͼԪʱʹ�õ�����
	@param blend ������ģʽ������"|"���
	@see PRIM_TYPE
	@see BLEND_MODE
	*/
	GGE_EXPORT void					Graph_RenderBatch(PRIM_TYPE primType, const ggeVertex *vt, int primNum, ggeTexture *tex = 0, int blend = BLEND_DEFAULT);
	/**
	@brief ��Ⱦ�Զ�������ͼԪ(�ú���������DrawCall)
	@param primType ͼԪ���ͣ���֧�� PRIM_POINTS, PRIM_QUADS
	@param vt ��������
	@param vertexNum ��������
	@param indices ��������
	@param primNum ͼԪ����
	@param tex ��ȾͼԪʱʹ�õ�����
	@param blend ������ģʽ������"|"���
	@see PRIM_TYPE
	@see BLEND_MODE
	*/
	GGE_EXPORT void					Graph_RenderBatchIndices(PRIM_TYPE primType, const ggeVertex *vt, int vertexNum, const guint16 *indices, int primNum, ggeTexture *tex = 0, int blend = BLEND_DEFAULT);
	/**
	@brief ���ü�������ѹջ(�ú���������DrawCall)
	@param rt ��������
	*/
	GGE_EXPORT void					Graph_PushClipRect(const ggeClipRect &rt);
	/**
	@brief ���ؼ����������֮ǰû�����ù����������򷵻�0
	*/
	GGE_EXPORT const ggeClipRect*	 Graph_GetClipRect();
	/**
	@brief ������ǰ�������򣬻ָ���һ�������������ջ��û��ʣ��ļ���������رղü�����(�ú���������DrawCall)
	*/
	GGE_EXPORT void					Graph_PopClipRect();
	/**
	@brief ���������õĲü���������
	*/
	GGE_EXPORT guint32				Graph_GetClipRectCount();
	/**
	@brief ���ñ任����ѹջ(�ú���ʹ��CPU���㶥�����꣬��������DrawCall)
	@param mat �任����
	*/
	GGE_EXPORT void					Graph_PushTransformMatrix(const ggeMatrix4 &mat);
	/**
	@brief ���ر任�������֮ǰû�����ù��任�����򷵻�0
	*/
	GGE_EXPORT const ggeMatrix4*	Graph_GetTransformMatrix();
	/**
	@brief ������ǰ�任���󣬻ָ���һ���任����
	*/
	GGE_EXPORT void					Graph_PopTransformMatrix();
	/**
	@brief ���������õı任��������
	*/
	GGE_EXPORT guint32				Graph_GetTransformMatrixCount();
	/**
	@brief ������ͼ����ѹջ(�ú���������DrawCall)
	@param dx x����ƫ���� 
	@param dy y����ƫ���� 
	@param hscale ���������ű���
	@param vscale ���������ű���
	@param rot ��ת�Ƕ�(��λ:����)
	@param hx ���ĵ�x����
	@param hy ���ĵ�y����
	*/
	GGE_EXPORT void					Graph_PushViewTransform(float dx, float dy, float hscale = 1.0f, float vscale = 1.0f, float rot = 0.0f, float hx = 0.0f, float hy = 0.0f); 
	/**
	@brief ������ͼ����ѹջ(�ú���������DrawCall)
	@param mat ��ͼ����
	*/
	GGE_EXPORT void					Graph_PushViewMatrix(const ggeMatrix4 &mat);
	/**
	@brief ������ͼ����
	*/
	GGE_EXPORT const ggeMatrix4&	Graph_GetViewMatrix();
	/**
	@brief ������ǰ��ͼ���󣬻ָ���һ����ͼ����(�ú���������DrawCall)
	*/
	GGE_EXPORT void					Graph_PopViewMatrix();
	/**
	@brief ���������õ���ͼ��������
	*/
	GGE_EXPORT guint32				Graph_GetViewMatrixCount();
	/**
	@brief ����ͶӰ����ѹջ(�ú���������DrawCall)
	@param mat ͶӰ����
	*/
	GGE_EXPORT void					Graph_PushProjectionMatrix(const ggeMatrix4 &mat);
	/**
	@brief ����ͶӰ����
	*/
	GGE_EXPORT const ggeMatrix4&	Graph_GetProjectionMatrix();
	/**
	@brief ������ǰͶӰ���󣬻ָ���һ��ͶӰ����(�ú���������DrawCall)
	*/
	GGE_EXPORT void					Graph_PopProjectionMatrix();
	/**
	@brief ���������õ�ͶӰ��������
	*/
	GGE_EXPORT	guint32				Graph_GetProjectionMatrixCount();
	/**
	@brief ������Ļ��ͼ
	@param filename �����ļ���
	@param imageFormat �ļ���ʽ(�ú�����֧��ddsѹ����ʽ)
	*/
	GGE_EXPORT void					Graph_Snapshot(const char *filename, GGE_IMAGE_FORMAT imageFormat = IMAGE_PNG);
	/**
	@brief ��ȡ��ʾģʽ����������Engine_Create()��������Ч
	*/
	GGE_EXPORT int					Graph_GetDisplayModeCount();
	/**
	@brief ��ȡ��ʾģʽ������Engine_Create()��������Ч
	*/
	GGE_EXPORT void					Graph_GetDisplayMode(int index, int &width, int &height);
	/**
	@brief ��ȡ��Ⱦ������
	*/
	GGE_EXPORT int					Graph_GetDrawnBatches();

	/**
	@brief ����ȫ���������
	@param volume ȫ�������������Χ0��100
	*/
	GGE_EXPORT void					Audio_SetMaxVolume(float volume);
	/**
	@brief ����ȫ���������
	*/
	GGE_EXPORT float				Audio_GetMaxVolume();
	/**
	@brief ���ü�����λ��
	@param position ������λ��(��������ϵ)
	*/
	GGE_EXPORT void					Audio_SetListenerPosition(const ggeVector3 &position);
	/**
	@brief ���ؼ�����λ��
	*/
	GGE_EXPORT const ggeVector3&	Audio_GetListenerPosition();
	/**
	@brief ���ü������ٶ�
	@param velocity �������ٶ�
	*/
	GGE_EXPORT void					Audio_SetListenerVelocity(const ggeVector3 &velocity);
	/**
	@brief ���ؼ������ٶ�
	*/
	GGE_EXPORT const ggeVector3&	Audio_GetListenerVelocity();
	/**
	@brief ���ü���������
	@param forward ǰ����Ĭ��(0, 0, -1)
	@param up �Ϸ���Ĭ��(0, 1, 0)
	*/
	GGE_EXPORT void					Audio_SetListenerOrientation(const ggeVector3 &forward, const ggeVector3 &up);
	/**
	@brief ���ؼ�����ǰ����
	*/
	GGE_EXPORT const ggeVector3&	Audio_GetListenerOrientationForward();
	/**
	@brief ���ؼ������Ϸ���
	*/
	GGE_EXPORT const ggeVector3&	Audio_GetListenerOrientationUp();
	/**
	@brief ���ö�����ϵ��
	@param scale ������ϵ����Ĭ��1��ֵԽ��Ӱ��Խ��
	*/
	GGE_EXPORT void					Audio_SetDopplerScale(float scale);
	/**
	@brief ���ض�����ϵ��
	*/
	GGE_EXPORT float				Audio_GetDopplerScale();
	/**
	@brief ���þ���ģ��
	@param model ����ģ�ͣ�Ĭ�� AUDIO_DISTANCE_INVERSE_CLAMPED
	@see AUDIO_DISTANCE_MODEL
	*/
	GGE_EXPORT void					Audio_SetDistanceModel(AUDIO_DISTANCE_MODEL model);
	/**
	@brief ���ؾ���ģ��
	*/
	GGE_EXPORT AUDIO_DISTANCE_MODEL Audio_GetDistanceModel();

	/**
	@brief ������X����
	@return ���X����
	*/
	GGE_EXPORT float 		 Input_GetMousePosX();
	/**
	@brief ������Y����
	@return ���Y����
	*/
	GGE_EXPORT float 		 Input_GetMousePosY();
	/**
	@brief �������λ��
	@param x ���x������
	@param y ���y������
	*/
	GGE_EXPORT void			 Input_SetMousePos(float x, float y);
	/**
	@brief ���������λ��
	@return ������λ��
	*/
	GGE_EXPORT int			 Input_GetMouseWheel();
	/**
	@brief ����Ƿ��ڴ�����
	@return �������ڴ����ڷ���true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsMouseOver();
	/**
	@brief �Ƿ��а���������ס
	@param key Ҫ���ļ��̱���
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsKeyPress(int key);
	/**
	@brief �Ƿ��а���̧��
	@param key Ҫ���ļ��̱���
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsKeyUp(int key);
	/**
	@brief �Ƿ��а�������
	@param key Ҫ���ļ��̱���
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsKeyDown(int key);
	/**
	@brief �Ƿ�����갴��������ס
	@param key Ҫ������갴������
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsMousePress(int key);
	/**
	@brief �Ƿ�����갴��̧��
	@param key Ҫ������갴������
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsMouseUp(int key);
	/**
	@brief �Ƿ�����갴������
	@param key Ҫ������갴������
	@return ���򷵻�true�����򷵻�false
	*/
	GGE_EXPORT bool			 Input_IsMouseDown(int key);
	/**
	@brief ���ص�ǰ���µİ����ļ�ֵ
	@return ��ǰ���µİ����ļ�ֵ�����޼����·���-1
	@note ���������·�ʽʹ�øú�����\n
	\code switch (Input_GetKey())
	{
	case GGEK_A:
		fnt->Print(0.0f, 0.0f, "A Key Down!");
		break;
	} \endcode
	*/
	GGE_EXPORT int			 Input_GetKey();
	/**
	@brief ���ص�ǰ������ַ����ַ���
	@return ��ǰ������ַ����ַ���,֧���������뷨
	*/
	GGE_EXPORT const char*	 Input_GetChar();
	/**
	@brief ���ذ�������
	@return ��������
	*/
	GGE_EXPORT const char*	 Input_GetKeyName(int key);


	/** @} */
}

