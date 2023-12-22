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
\brief Jsonģ��
*/

#pragma once
#include "ggetypes.h"
#include "ggerefcounter.h"

namespace gge
{
	/// Jsonֵ
	class ggeJsonValue
	{
	public:
		/// ֵ����
		enum ValType
		{
			VAL_NULL,		///< Null
			VAL_BOOL,		///< Bool
			VAL_INT,		///< Int
			VAL_FLOAT,		///< Float
			VAL_STRING,		///< String
			VAL_OBJECT,		///< Object
			VAL_ARRAY,		///< Array
		};

		/// ���������
		class Iterator
		{
		public:
			Iterator() : m_Index(0), m_JsonValue(0), m_JsonDocument(0) {}

			/// ��������
			GGE_EXPORT const char*	GetName();
			/// ����ֵ
			GGE_EXPORT ggeJsonValue	GetValue();
			/// �������Ƿ���Ч
			GGE_EXPORT bool			IsValid();
			/// ��ȡ��һ��ֵ
			GGE_EXPORT void			NextValue();

		private:
			friend class ggeJsonValue;
			guint32	m_Index;
			void	*m_JsonValue;
			void	*m_JsonDocument;
		};

		/// ���캯��
		ggeJsonValue() : m_JsonValue(0), m_JsonDocument(0) {}

		/// ����ֵ����
		GGE_EXPORT ValType		GetType() const;
		/// �Ƿ���Ч
		GGE_EXPORT bool			IsValid() const;

		/** @name ����ֵ
		*  @{
		*/
		GGE_EXPORT void			SetInt(int val);
		GGE_EXPORT void			SetUInt(guint32 val);
		GGE_EXPORT void			SetLongLong(gint64 val);
		GGE_EXPORT void			SetULongLong(guint64 val);
		GGE_EXPORT void			SetBool(bool val);
		GGE_EXPORT void			SetFloat(float val);
		GGE_EXPORT void			SetDouble(double val);
		GGE_EXPORT void			SetString(const char *val);
		/** 
		@} 
		*/

		/// ����Ϊ����
		GGE_EXPORT ggeJsonValue& SetArray();
		/// ����Ϊ����
		GGE_EXPORT ggeJsonValue& SetObject();
		
		/** @name ����ָ�����͵�ֵ
		*  @{
		*/
		GGE_EXPORT int			GetInt() const;
		GGE_EXPORT guint32		GetUInt() const;
		GGE_EXPORT gint64		GetLongLong() const;
		GGE_EXPORT guint64		GetULongLong() const;
		GGE_EXPORT bool			GetBool() const;
		GGE_EXPORT float		GetFloat() const;
		GGE_EXPORT double		GetDouble() const;
		GGE_EXPORT const char*	GetString() const;
		/** 
		@} 
		*/

		/**
		@brief ���ֵ
		@param name �����ǰֵ�Ƕ��󣬸ò���������������
		@return ����ӵ�ֵ
		*/
		GGE_EXPORT ggeJsonValue	AddValue(const char *name = 0);

		/**
		@brief ��ȡ����ֵ
		@param index ��������
		@return ����ָ��������ֵ
		*/
		GGE_EXPORT ggeJsonValue	GetValue(guint32 index);
		/**
		@brief ��ȡ����ֵ
		@param name ������
		@return ����ָ�����ֵ�ֵ
		*/
		GGE_EXPORT ggeJsonValue	GetValue(const char *name);

		/**
		@brief ɾ������ֵ
		@param index ��������
		*/
		GGE_EXPORT void			DelValue(guint32 index);
		/**
		@brief ɾ������ֵ
		@param name ������
		@param bKeepOrder �Ƿ񱣳�˳�򣬲����ֿ������ɾ��Ч��
		*/
		GGE_EXPORT void			DelValue(const char *name, bool bKeepOrder = false);

		/// ��������������ֵ������
		GGE_EXPORT guint32		GetValueCount();
		/// ���ض��������
		GGE_EXPORT Iterator		GetObjectIterator();

	private:
		friend class ggeJsonValueHelper;
		void *m_JsonValue;
		void *m_JsonDocument;
	};

	/// Json�ĵ�
	class ggeJsonDocument : public ggeRefCounter
	{
	public:
		/**
		@brief ����Json�ļ������øú�����֮ǰ���ص�ggeJsonValue��ʧЧ
		@param filename �ļ���
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool			LoadFile(const char *filename) = 0;
		/**
		@brief ����Json�ļ�
		@param filename �ļ���
		@param bFomart �Ƿ��ʽ������ļ�����ʽ������ļ����ݸ��׶�������ʹ�ļ�����
		@return �ɹ�����true�����򷵻�false
		@note ע�⣬���ڵ��������������
		*/
		virtual bool			SaveFile(const char *filename, bool bFomart = false) = 0;
		/**
		@brief ����Json�ַ��������øú�����֮ǰ���ص�ggeJsonValue��ʧЧ
		@param str Ҫ�������ַ������磺{ aaa: "test", bbb: 123 }
		@return �ɹ�����true�����򷵻�false
		*/
		virtual bool			Parse(const char* str) = 0;
		/**
		@brief ���ظ��ڵ�
		*/
		virtual ggeJsonValue	GetRootValue() = 0;
	};

	/**
	@brief ����Json�ĵ�
	@return �ɹ�����ggeJsonDocumentָ�룬���򷵻�0
	@note
	\code
		ʾ������

		//����Json�ĵ�
		ggeJsonDocument *doc = Json_Create();
		//��ȡ���ڵ㣬������Ϊ����
		ggeJsonValue root = doc->GetRootValue().SetObject();

		//�����ֵ
		root.AddValue("val1").SetDouble(3.14);

		//����ַ���
		root.AddValue("val2").SetString("This is a test!");

		//�������ΪVal1��ֵ��������Ϊ����
		ggeJsonValue val = root.AddValue("val3").SetArray();

		//�����ֵ
		for (int i = 0; i < 4; i++)
		{
			val.AddValue().SetInt(i * 10);
		}

		//����xml�ļ�
		doc->SaveFile("myjson.json");

		//��xml�ļ�
		doc->LoadFile("myjson.json");

		//��ȡ���ڵ�
		root = doc->GetRootValue();

		//��������ֵ
		for (ggeJsonValue::Iterator it = root.GetObjectIterator(); it.IsValid(); it.NextValue())
		{
			val = it.GetValue();
			switch (val.GetType())
			{
			case ggeJsonValue::VAL_FLOAT:
				cout<<it.GetName()<<"  "<<val.GetDouble()<<endl;
				break;

			case ggeJsonValue::VAL_INT:
				cout<<it.GetName()<<"  "<<val.GetInt()<<endl;
				break;

			case ggeJsonValue::VAL_STRING:
				cout << it.GetName() << "  " << val.GetString() << endl;
				break;

			case ggeJsonValue::VAL_ARRAY:
				cout<<it.GetName()<<endl;
				//��������ֵ
				for (guint32 i = 0; i < val.GetValueCount(); i++)
				{
					ggeJsonValue arrval = val.GetValue(i);
					cout<<"    "<<arrval.GetInt()<<endl;
				}
				break;
			}
		}

		//�ͷ�Doc
		GGE_RELEASE(doc);
	\endcode
	*/
	GGE_EXPORT ggeJsonDocument* Json_Create();
}