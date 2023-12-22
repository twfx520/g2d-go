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
\brief ������������
*/

#pragma once

/// Galaxy2D Game Engine ���ֿռ�
namespace gge
{
	#ifdef GALAXY2D_DLL
	#define GGE_EXPORT __declspec(dllexport)
	#else
	#define GGE_EXPORT __declspec(dllimport)
	#endif

	/// ��ȫɾ��ָ��
	#define GGE_DELETE(p)		{ if(p) { delete (p);     (p)=0; } }

	/// ��ȫɾ������
	#define GGE_DELETE_ARRAY(p)	{ if(p) { delete[] (p);   (p)=0; } }

	/// ��ȫ�ͷ�ָ��
	#define GGE_RELEASE(p)		{ if(p) { (p)->Release(); (p)=0; } }

	typedef char				gint8;		///< gint8
	typedef short				gint16;		///< gint16
	typedef int					gint32;		///< gint32
	typedef long long			gint64;		///< gint64
	typedef unsigned char		guint8;		///< guint8
	typedef unsigned short		guint16;	///< guint16
	typedef unsigned int		guint32;	///< guint32
	typedef unsigned long long	guint64;	///< guint64
}
