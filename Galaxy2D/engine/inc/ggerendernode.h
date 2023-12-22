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
\brief ��Ⱦ�ڵ�
*/

#pragma once
#include "ggerefcounter.h"
#include "ggemath.h"
#include "ggematrix.h"

namespace gge
{
	class ggeRenderNode : public ggeRefCounter
	{
	public:
		ggeRenderNode() : m_nodeID(-1), m_zOrder(0), m_localOrder(0), m_childOrder(1), m_bValid(true), m_bVisible(true), m_bNeedSort(false), 
			m_parent(0), m_userData(0), m_bUpdateLocalTransform(true), m_bUpdateWorldTransform(true), m_scale(1.0f, 1.0f, 1.0f)
		{
			_CreateNodeData();
		}

		~ggeRenderNode()
		{
			RemoveAllChild();
			if (GetParent()) 
				GetParent()->_RemoveFromChildList(this);

			_DeleteNodeData();
		}

		/// ���ظ��ڵ�
		ggeRenderNode* GetParent() const { return m_parent; }

		/// ���ظ��ڵ�
		GGE_EXPORT ggeRenderNode* GetRoot() const;

		/// ����ӽڵ�
		GGE_EXPORT void AddChild(ggeRenderNode *node);

		/// �Ƴ��ӽڵ�
		GGE_EXPORT void RemoveChild(ggeRenderNode *node);

		/// �Ƴ������ӽڵ�
		GGE_EXPORT void RemoveAllChild();

		/// �Ӹ��ڵ����Ƴ�
		GGE_EXPORT void RemoveFromParent();

		/// �����ӽڵ�����
		GGE_EXPORT guint32 GetChildCount() const;

		/// �����ӽڵ�
		GGE_EXPORT ggeRenderNode* GetChild(guint32 pos) const;

		/// �����ӽڵ�
		GGE_EXPORT ggeRenderNode* FindChild(int id) const;
		
	public:
		/// ˢ�£�bUpdateTransform��ʾ�Ƿ�Ҫˢ�µ�ǰ�ڵ���ӽڵ�ı任����
		virtual	void Update(float dt, bool bUpdateTransform = false)				
		{ 
			_Update(dt, bUpdateTransform);
		}

		/// ��Ⱦ
		virtual	void Render()						
		{ 
			if (IsVisible())
			{
				if (GetChildCount() > 0)
				{
					_Render();
				}
				else
				{
					OnRender(m_parentTransform);
				}
			}
		}

		/// ˢ��ʱ���ã�parentTransform�Ǹ��ڵ�ı任����bTransformChanged��ʾ��ǰ�ڵ�ı任�����Ѹı�
		virtual void OnUpdate(float dt, const ggeMatrix4 &parentTransform, bool bTransformChanged) 
		{
		}

		/// ��Ⱦʱ���ã�transform�ǵ�ǰ�ڵ�ı任����
		virtual void OnRender(const ggeMatrix4 &transform)
		{
			//Graph_PushTransformMatrix(transform);
			//Render something...
			//Graph_PopTransformMatrix();
		}

	public:
		/// ����ID
		void			SetID(int id)		{ m_nodeID = id; }
		/// ����ID
		int				GetID()	const		{ return m_nodeID; }

		/// �����Ƿ�ɼ�
		virtual void	SetVisible(bool b)	{ m_bVisible = b; }
		/// �����Ƿ�ɼ�
		virtual bool	IsVisible() const	{ return m_bVisible; }

		/// ����ZOrder��Ĭ��Ϊ0����ֵԽ��Խ����Ⱦ�����<0���ʾ�ڸ��ڵ�֮ǰ��Ⱦ
		virtual void	SetZOrder(int z)	{ _SetZOrder(z); }
		/// ����ZOrder
		virtual int		GetZOrder() const	{ return m_zOrder; }

		/// �Ƿ���Ч���´�ˢ��ʱ���ڵ���Ƴ���������Ч�Ľڵ�
		virtual bool	IsValid() const		{ return m_bValid; }
		/// ����Ϊ��Ч״̬
		virtual void	Kill()				{ m_bValid = false; }

		/// �����û�����
		void			SetUserData(void *v){ m_userData = v; }
		/// �����û�����
		void*			GetUserData() const { return m_userData; }

	public:
		/** @name ��������
		*  @{
		*/
		void	SetPosition(float x, float y)				{ m_position.x = x; m_position.y = y; TransformDirty(); }
		void	SetPosition(const ggeVector &v)				{ m_position.x = v.x; m_position.y = v.y; TransformDirty(); }
		void	SetPosition3D(float x, float y, float z)	{ m_position.x = x; m_position.y = y; m_position.z = z; TransformDirty(); }
		void	SetPosition3D(const ggeVector3 &v)			{ m_position = v; TransformDirty(); }

		void	SetPositionX(float x)						{ m_position.x = x; TransformDirty(); }
		void	SetPositionY(float y)						{ m_position.y = y; TransformDirty(); }
		void	SetPositionZ(float z)						{ m_position.z = z; TransformDirty(); }
		/** 
		@} 
		*/

		/** @name ��������
		*  @{
		*/
		float	GetPositionX() const						{ return m_position.x; }
		float	GetPositionY() const						{ return m_position.y; }
		float	GetPositionZ() const						{ return m_position.z; }
		const	ggeVector3& GetPosition3D() const			{ return m_position; }
		/** 
		@} 
		*/

		/** @name ��������
		*  @{
		*/
		void	SetScale(float x, float y)					{ m_scale.x = x;m_scale.y = y; TransformDirty(); }
		void	SetScale(const ggeVector &v)				{ m_scale.x = v.x;m_scale.y = v.y; TransformDirty(); }
		void	SetScale3D(float x, float y, float z)		{ m_scale.x = x;m_scale.y = y;m_scale.z = z; TransformDirty(); }
		void	SetScale3D(const ggeVector3 &v)				{ m_scale = v; TransformDirty(); }

		void	SetScaleX(float x)							{ m_scale.x = x; TransformDirty(); }
		void	SetScaleY(float y)							{ m_scale.y = y; TransformDirty(); }
		void	SetScaleZ(float z)							{ m_scale.z = z; TransformDirty(); }
		/** 
		@} 
		*/

		/** @name ��������
		*  @{
		*/
		const	ggeVector3& GetScale3D() const				{ return m_scale; }
		float	GetScaleX()	const							{ return m_scale.x; }
		float	GetScaleY()	const							{ return m_scale.y; }
		float	GetScaleZ()	const							{ return m_scale.z; }
		/** 
		@} 
		*/

		/** @name ������ת
		*  @{
		*/
		void	SetRotation(float v)						{ m_rotation.z = v; TransformDirty(); }
		void	SetRotation3D(float x, float y, float z)	{ m_rotation.x = x; m_rotation.y = y; m_rotation.z = z; TransformDirty(); }
		void	SetRotation3D(const ggeVector3 &v)			{ m_rotation = v; TransformDirty(); }

		void	SetRotationX(float x)						{ m_rotation.x = x; TransformDirty(); }
		void	SetRotationY(float y)						{ m_rotation.y = y; TransformDirty(); }
		void	SetRotationZ(float z)						{ m_rotation.z = z; TransformDirty(); }
		/** 
		@} 
		*/

		/** @name ������ת
		*  @{
		*/
		float	GetRotation() const							{ return m_rotation.z; }
		float	GetRotationX() const						{ return m_rotation.x; }
		float	GetRotationY() const						{ return m_rotation.y; }
		float	GetRotationZ() const						{ return m_rotation.z; }
		const	ggeVector3& GetRotation3D() const			{ return m_rotation; }
		/** 
		@} 
		*/
		
		/// ���ñ��ر任����
		GGE_EXPORT void		SetLocalTransform(const ggeMatrix4 &mat);
		/// ���ر��ر任����
		GGE_EXPORT const	ggeMatrix4& GetLocalTransform() const;
		/// ��������任����
		GGE_EXPORT const	ggeMatrix4&	GetWorldTransform() const;
		/// �������絽���صı任����
		GGE_EXPORT const	ggeMatrix4& GetWorldToLocalTransform(ggeMatrix4 &mat) const;

		/// ������������
		ggeVector3	GetWorldPosition() const						{ return GetWorldTransform().GetTranslation(); }
		/// ת��ʸ������������
		void		ConvertToWorldPosition(ggeVector &v) const		{ GetWorldTransform().TransformVector(v); }
		/// ת��ʸ������������
		void		ConvertToWorldPosition3D(ggeVector3 &v) const	{ GetWorldTransform().TransformVector3(v); }
		/// ת��ʸ������������
		void		ConvertToNodePosition(ggeVector &v) const		{ ggeMatrix4 mat; GetWorldToLocalTransform(mat).TransformVector(v); }
		/// ת��ʸ������������
		void		ConvertToNodePosition3D(ggeVector3 &v) const	{ ggeMatrix4 mat; GetWorldToLocalTransform(mat).TransformVector3(v); }

	protected:
		GGE_EXPORT	void	Sort();
		void				TransformDirty()	{ m_bUpdateLocalTransform = true; m_bUpdateWorldTransform = true; }
		void				ZOrderDirty()		{ m_bNeedSort = true; }

	protected:
		int		m_nodeID;
		int		m_zOrder;
		int		m_childOrder;
		int		m_localOrder;
		bool	m_bValid;
		bool	m_bVisible;
		bool	m_bNeedSort;
		mutable bool m_bUpdateLocalTransform;
		mutable bool m_bUpdateWorldTransform;
		
		ggeVector3	m_position;
		ggeVector3	m_scale;
		ggeVector3	m_rotation;

		mutable ggeMatrix4 m_localTransform;
		mutable ggeMatrix4 m_worldTransform;
		ggeMatrix4	m_parentTransform;

		ggeRenderNode	*m_parent;
		void			*m_userData;
		void			*m_nodeData;

	protected:
		GGE_EXPORT	void	_Update(float dt, bool bUpdateTransform);
		GGE_EXPORT	void	_Render();

	private:
		friend		bool	_RenderNodeComparison(const ggeRenderNode *node1, const ggeRenderNode *node2);
		GGE_EXPORT	void	_CreateNodeData();
		GGE_EXPORT	void	_DeleteNodeData();

		GGE_EXPORT	void	_SetZOrder(int z);
		GGE_EXPORT	int		_GetLocalOrder();
		GGE_EXPORT	bool	_RemoveFromChildList(const ggeRenderNode *node);
	};
};