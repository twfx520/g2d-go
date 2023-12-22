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
\brief XMLģ��
*/

#pragma once
#include "ggetypes.h"
#include "ggerefcounter.h"

namespace gge
{
	/// XML�ڵ�
	class ggeXmlNode
	{
	public:
		/// ���캯��
		ggeXmlNode() : m_XmlNode(0) {}

		/// ���ýڵ�����
		GGE_EXPORT void			SetName(const char *name);
		/// ���ؽڵ�����
		GGE_EXPORT const char*	GetName() const;
		/// �Ƿ�����Ч�ڵ�
		GGE_EXPORT bool			IsValid() const;

		/**
		@brief ������һ���ڵ�
		@param name ���ָ���˸ò������򷵻���һ��������ò�����ͬ�Ľڵ�
		@return ����ggeXmlNode
		*/
		GGE_EXPORT ggeXmlNode	GetNextNode(const char *name = 0) const;
		/**
		@brief ����ǰһ���ڵ�
		@param name ���ָ���˸ò������򷵻�ǰһ��������ò�����ͬ�Ľڵ�
		@return ����ggeXmlNode
		*/
		GGE_EXPORT ggeXmlNode	GetPreviousNode(const char *name = 0) const;
		/**
		@brief ���ص�һ���ӽڵ�
		@param name ���ָ���˸ò������򷵻ص�һ��������ò�����ͬ���ӽڵ�
		@return ����ggeXmlNode
		*/
		GGE_EXPORT ggeXmlNode	GetFirstChild(const char *name = 0) const;
		/**
		@brief �������һ���ӽڵ�
		@param name ���ָ���˸ò������򷵻����һ��������ò�����ͬ���ӽڵ�
		@return ����ggeXmlNode
		*/
		GGE_EXPORT ggeXmlNode	GetLastChild(const char *name = 0) const;
		
		/**
		@brief ���ײ�����ڵ�
		@param name �ڵ�����
		@param bText �Ƿ���Text���ͽڵ㣬�����Text���ͽڵ㣬�����������Ժ��ӽڵ�
		@return ���ز���Ľڵ�
		*/
		GGE_EXPORT ggeXmlNode	InsertFirstChild(const char *name, bool bText = false);
		/**
		@brief ��ָ���ӽڵ�����ڵ�
		@param after ����λ��
		@param name �ڵ�����
		@param bText �Ƿ���Text���ͽڵ㣬�����Text���ͽڵ㣬�����������Ժ��ӽڵ�
		@return ���ز���Ľڵ�
		*/
		GGE_EXPORT ggeXmlNode	InsertAfterChild(ggeXmlNode after, const char *name, bool bText = false);
		/**
		@brief ��β������ڵ�
		@param name �ڵ�����
		@param bText �Ƿ���Text���ͽڵ㣬�����Text���ͽڵ㣬�����������Ժ��ӽڵ�
		@return ���ز���Ľڵ�
		*/
		GGE_EXPORT ggeXmlNode	InsertEndChild(const char *name, bool bText = false);
		/**
		@brief ɾ��һ���ӽڵ�
		@param remove Ҫɾ���Ľڵ�
		*/
		GGE_EXPORT void			DeleteChild(ggeXmlNode remove);
		/**
		@brief ��������ӽڵ�
		*/
		GGE_EXPORT void			Clear();


		/** @name ��������ֵ
		*  @{
		*/
		GGE_EXPORT void			SetInt(const char *name, int val);
		GGE_EXPORT void			SetLongLong(const char *name, gint64 val);
		GGE_EXPORT void			SetUInt(const char *name, guint32 val);
		GGE_EXPORT void			SetULongLong(const char *name, guint64 val);
		GGE_EXPORT void			SetFloat(const char *name, float val);
		GGE_EXPORT void			SetDouble(const char *name, double val);
		GGE_EXPORT void			SetBool(const char *name, bool val);
		GGE_EXPORT void			SetString(const char *name, const char *val);
		/** 
		@} 
		*/

		/** @name ��������ֵ�������ȡ����ʧ�ܷ���def
		*  @{
		*/
		GGE_EXPORT int			GetInt(const char *name, int def = 0) const;
		GGE_EXPORT gint64		GetLongLong(const char *name, gint64 def = 0) const;
		GGE_EXPORT guint32		GetUInt(const char *name, guint32 def = 0) const;
		GGE_EXPORT guint64		GetULongLong(const char *name, guint64 def = 0) const;
		GGE_EXPORT float		GetFloat(const char *name, float def = 0) const;
		GGE_EXPORT double		GetDouble(const char *name, double def = 0) const;
		GGE_EXPORT bool			GetBool(const char *name, bool def = false) const;
		GGE_EXPORT const char*	GetString(const char *name, const char* def = 0) const;
		/** 
		@} 
		*/
		
		/**
		@brief ɾ������
		@param name ������
		*/
		GGE_EXPORT void			DeleteAttribute(const char *name);
		/**
		@brief ���õ�ǰ�ڵ��Ƿ���CData����ǰ�ڵ���Text���ͽڵ�ʱ��Ч
		@param b Ϊtrue��ʾ��ǰ�ڵ���CData��������
		*/
		GGE_EXPORT void			SetCData(bool b);
		/**
		@brief ���ص�ǰ�ڵ��Ƿ���CData
		*/
		GGE_EXPORT bool			IsCData();

	private:
		friend class	ggeXmlElementHelper;
		void			*m_XmlNode;
	};

	/// XML�ĵ�
	class ggeXmlDocument : public ggeRefCounter
	{
	public:
		/**
		@brief ����XML�ļ������øú�����֮ǰ���ص�ggeXmlNode��ʧЧ
		@param filename �ļ���
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool			LoadFile(const char *filename) = 0;
		/**
		@brief ����XML�ļ�
		@param filename �ļ���
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool			SaveFile(const char *filename) = 0;
		/**
		@brief ����XML�ַ��������øú�����֮ǰ���ص�ggeXmlNode��ʧЧ
		@param str Ҫ�������ַ������磺\<node string="string">test_node\</node>
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool			Parse(const char* str) = 0;
		/**
		@brief ���ظ��ڵ�
		*/
		virtual ggeXmlNode		GetRootNode() = 0;
	};

	/**
	@brief ����XML�ĵ�
	@return �ɹ�����ggeXmlDocumentָ�룬���򷵻�0
	@note
		\code
		XML�ļ����ݣ�
		<?xml version="1.0" encoding="gb2312" ?>
		<XmlRoot>
			<Val1 Str="Test" />
			<Val2 Num="1" />
			<Val3>
				<ChildNode ID="0" />
				<ChildNode ID="1" />
				<ChildNode ID="2" />
				<ChildNode ID="3" />
			</Val3>
			<Val4>This is a text!</Val4>
		</XmlRoot>
		\endcode
		\code
		ʾ������

		//����XML�ĵ�
		ggeXmlDocument *doc = Xml_Create();
		//��ȡ���ڵ�
		ggeXmlNode root = doc->GetRootNode();
		root.SetName("XmlRoot");

		//��������ΪVal1�Ľڵ�
		ggeXmlNode valNode = root.InsertEndChild("Val1");
		//��������"Str"��ֵΪ"Test"
		valNode.SetString("Str", "Test");

		//��������ΪVal2�Ľڵ�
		valNode = root.InsertEndChild("Val2");
		//��������"Num"��ֵΪ1
		valNode.SetInt("Num", 1);

		//��������ΪVal3�Ľڵ㣬
		valNode = root.InsertEndChild("Val3");
		for (int i = 0; i < 4; i++)
		{
		//��Val3�ڵ��´����ӽڵ�
		ggeXmlNode childNode = valNode.InsertEndChild("ChildNode");
		//��������"ID"ֵ
		childNode.SetInt("ID", i);
		}

		//��������ΪVal4�Ľڵ�
		valNode = root.InsertEndChild("Val4");
		//����һ���ַ����ӽڵ�
		valNode = valNode.InsertEndChild("This is a test!", true);

		//����xml�ļ�
		doc->SaveFile("myxml.xml");

		//��xml�ļ�
		doc->LoadFile("myxml.xml");

		//��ȡ���ڵ�
		root = doc->GetRootNode();

		//���Root��
		cout<<root.GetName()<<endl;
		//���Val1
		cout<<"Val1:"<<root.GetFirstChild("Val1").GetString("Str")<<endl;
		//���Val2
		cout<<"Val2:"<<root.GetFirstChild("Val2").GetInt("Num")<<endl;
		//���Val3
		valNode = root.GetFirstChild("Val3").GetFirstChild("ChildNode");
		while (valNode.IsValid())
		{
		cout<<"Val3:"<<valNode.GetString("ID")<<endl;
		valNode = valNode.GetNextNode();
		}
		//���Val4
		cout<<"Val4:"<<root.GetFirstChild("Val4").GetFirstChild().GetName()<<endl;

		//�ͷ�Doc
		GGE_RELEASE(doc);
	\endcode
	*/
	GGE_EXPORT ggeXmlDocument*  Xml_Create();
}