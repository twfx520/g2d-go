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
	/// λ��ê��
	enum MESH_REF_POINT
	{
		MESH_NODE,		///< ԭʼ����
		MESH_TOPLEFT,	///< �������Ͻ�
		MESH_CENTER,	///< ��������
		MESH_FORCE32BIT = 0x7FFFFFFF,
	};

	/// ����ģ��
	class ggeMesh : public ggeRefCounter
	{
	public:
		/**
		@brief ��������
		@param mesh Դ����
		*/
		virtual void		Copy(ggeMesh *mesh) = 0;
		/**
		@brief ���ص�ǰ�����һ������
		@return ��ǰ�����һ������
		*/
		virtual ggeMesh*	Clone() = 0;

		/**
		@brief ��Ⱦ����
		@param x x����
		@param y y����
		*/
		virtual void		Render(float x, float y) = 0;
		/**
		@brief ��������
		@param color ��ɫ
		@param z Z��
		*/
		virtual void		Clear(guint32 color = 0xFFFFFFFF, float z = 0.5f) = 0;

		/**
		@brief ������Ⱦ�������������Զ���Ϊ��������
		@param texture ������Ⱦ������
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
		@brief ����Z��
		@param col ��
		@param row ��
		@param z 0.0f��1.0f��0��ʾ���ϲ㣬1��ʾ���²�
		*/
		virtual void		SetZ(int col, int row, float z) = 0;
		/**
		@brief ���Z��
		@param col ��
		@param row ��
		@return Z��
		*/
		virtual float		GetZ(int col, int row) = 0;
		/**
		@brief ������Ⱦ��ɫ
		@param col ��
		@param row ��
		@param color ��Ⱦ��ɫ
		*/
		virtual void		SetColor(int col, int row, guint32 color) = 0;
		/**
		@brief �����ɫ
		@param col ��
		@param row ��
		@return ������ɫ
		*/
		virtual guint32		GetColor(int col, int row) = 0;
		/**
		@brief ���ýڵ�λ��
		@param col Ҫ�ƶ�����
		@param row Ҫ�ƶ�����
		@param dx xλ��
		@param dy yλ��
		@param ref λ��ê�� @see MESH_REF_POINT
		*/
		virtual void		SetDisplacement(int col, int row, float dx, float dy, int ref = MESH_NODE) = 0;
		/**
		@brief ��ö���λ��
		@param col ��
		@param row ��
		@param dx xλ��
		@param dy yλ��
		@param ref λ��ê�� @see MESH_REF_POINT
		*/
		virtual void		GetDisplacement(int col, int row, float *dx, float *dy, int ref = MESH_NODE) = 0;

		/**
		@brief �������
		@return ����
		*/
		virtual int			GetRows() = 0;
		/**
		@brief �������
		@return ����
		*/
		virtual int			GetCols() = 0;
		/**
		@brief ��ýڵ����
		@return �ڵ����
		*/
		virtual ggeVertex*	GetNodeList() = 0;
	};

	/**
	@brief ��������
	@param cols ����
	@param rows ����
	@return �ɹ�����ggeMeshָ�룬���򷵻�0
	*/
	GGE_EXPORT ggeMesh*  Mesh_Create(int cols, int rows);
}