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
\brief ���������
*/

#pragma once
#include "ggemath.h"

namespace gge
{
	/**	@brief Matrix
		\code
		struct 
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};
		float m[9];
		float _m[3][3];
		\endcode
	*/
	class ggeMatrix
	{
	public:
		union
		{
			struct 
			{
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
			};
			float m[9];
			float _m[3][3];
		};

		/// ���캯��
		ggeMatrix() {}
		/// ���캯��
		ggeMatrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) :
		_11(m11), _12(m12), _13(m13), _21(m21), _22(m22), _23(m23), _31(m31), _32(m32), _33(m33) {}

		/// ���������
		float& operator()(const int row, const int col)				{ return _m[row][col]; }
		/// ���������
		const float& operator()(const int row, const int col) const { return _m[row][col]; }
		/// ���������
		float& operator[](int index)								{ return m[index]; }
		/// ���������
		const float& operator[](int index) const					{ return m[index]; }

		/// ���������
		bool operator==(const ggeMatrix &om) const
		{
			if (m[0] != om.m[0] || m[1] != om.m[1] || m[2] != om.m[2] || 
				m[3] != om.m[3] || m[4] != om.m[4] || m[5] != om.m[5] || 
				m[6] != om.m[6] || m[7] != om.m[7] || m[8] != om.m[8])
				return false;
			return true;
		}
		/// ���������
		bool operator!=(const ggeMatrix &om) const
		{
			if (m[0] != om.m[0] || m[1] != om.m[1] || m[2] != om.m[2] || 
				m[3] != om.m[3] || m[4] != om.m[4] || m[5] != om.m[5] || 
				m[6] != om.m[6] || m[7] != om.m[7] || m[8] != om.m[8])
				return true;
			return false;
		}
		/// ���������
		ggeMatrix operator+(const ggeMatrix &om) const
		{
			ggeMatrix mat;

			mat[0] = m[0] + om.m[0]; mat[1] = m[1] + om.m[1]; mat[2] = m[2] + om.m[2];  
			mat[3] = m[3] + om.m[3]; mat[4] = m[4] + om.m[4]; mat[5] = m[5] + om.m[5];  
			mat[6] = m[6] + om.m[6]; mat[7] = m[7] + om.m[7]; mat[8] = m[8] + om.m[8];

			return mat;
		}
		/// ���������
		ggeMatrix& operator+=(const ggeMatrix &om)
		{
			m[0] += om.m[0]; m[1] += om.m[1]; m[2] += om.m[2];  
			m[3] += om.m[3]; m[4] += om.m[4]; m[5] += om.m[5];  
			m[6] += om.m[6]; m[7] += om.m[7]; m[8] += om.m[8];

			return *this;
		}
		/// ���������
		ggeMatrix operator-(const ggeMatrix &om) const
		{
			ggeMatrix mat;

			mat[0] = m[0] - om.m[0]; mat[1] = m[1] - om.m[1]; mat[2] = m[2] - om.m[2];  
			mat[3] = m[3] - om.m[3]; mat[4] = m[4] - om.m[4]; mat[5] = m[5] - om.m[5];  
			mat[6] = m[6] - om.m[6]; mat[7] = m[7] - om.m[7]; mat[8] = m[8] - om.m[8];

			return mat;
		}
		/// ���������
		ggeMatrix& operator-=(const ggeMatrix &om)
		{
			m[0] -= om.m[0]; m[1] -= om.m[1]; m[2] -= om.m[2];  
			m[3] -= om.m[3]; m[4] -= om.m[4]; m[5] -= om.m[5];  
			m[6] -= om.m[6]; m[7] -= om.m[7]; m[8] -= om.m[8];

			return *this;
		}
		/// ���������
		ggeMatrix operator*(const ggeMatrix &om) const
		{
			ggeMatrix mat;

			mat[0] = m[0] * om.m[0] + m[1] * om.m[3] + m[2] * om.m[6];
			mat[1] = m[0] * om.m[1] + m[1] * om.m[4] + m[2] * om.m[7];
			mat[2] = m[0] * om.m[2] + m[1] * om.m[5] + m[2] * om.m[8];

			mat[3] = m[3] * om.m[0] + m[4] * om.m[3] + m[5] * om.m[6];
			mat[4] = m[3] * om.m[1] + m[4] * om.m[4] + m[5] * om.m[7];
			mat[5] = m[3] * om.m[2] + m[4] * om.m[5] + m[5] * om.m[8];

			mat[6] = m[6] * om.m[0] + m[7] * om.m[3] + m[8] * om.m[6];
			mat[7] = m[6] * om.m[1] + m[7] * om.m[4] + m[8] * om.m[7];
			mat[8] = m[6] * om.m[2] + m[7] * om.m[5] + m[8] * om.m[8];

			return mat;
		}
		/// ���������
		ggeMatrix& operator*=(const ggeMatrix &om)
		{
			ggeMatrix mat(*this);

			m[0]  = mat[0] * om.m[0] + mat[1] * om.m[3] + mat[2] * om.m[6];
			m[1]  = mat[0] * om.m[1] + mat[1] * om.m[4] + mat[2] * om.m[7];
			m[2]  = mat[0] * om.m[2] + mat[1] * om.m[5] + mat[2] * om.m[8];

			m[3]  = mat[3] * om.m[0] + mat[4] * om.m[3] + mat[5] * om.m[6];
			m[4]  = mat[3] * om.m[1] + mat[4] * om.m[4] + mat[5] * om.m[7];
			m[5]  = mat[3] * om.m[2] + mat[4] * om.m[5] + mat[5] * om.m[8];

			m[6]  = mat[6] * om.m[0] + mat[7] * om.m[3] + mat[8] * om.m[6];
			m[7]  = mat[6] * om.m[1] + mat[7] * om.m[4] + mat[8] * om.m[7];
			m[8]  = mat[6] * om.m[2] + mat[7] * om.m[5] + mat[8] * om.m[8];

			return *this;
		}
		/// ���������
		ggeMatrix operator*(const float scalar) const
		{
			ggeMatrix mat;

			mat[0] = m[0] * scalar; mat[1] = m[1] * scalar; mat[2] = m[2] * scalar; 
			mat[3] = m[3] * scalar; mat[4] = m[4] * scalar; mat[5] = m[5] * scalar; 
			mat[6] = m[6] * scalar; mat[7] = m[7] * scalar; mat[8] = m[8] * scalar;

			return mat;
		}
		/// ���������
		ggeMatrix& operator*=(const float scalar)
		{
			m[0] *= scalar; m[1] *= scalar; m[2] *= scalar; 
			m[3] *= scalar; m[4] *= scalar; m[5] *= scalar; 
			m[6] *= scalar; m[7] *= scalar; m[8] *= scalar;

			return *this;
		}

		/**
		@brief ���óɵ�λ����
		*/
		GGE_EXPORT void SetIdentity();
		/**
		@brief �Ƿ�Ϊ��λ����
		@return �Ƿ�Ϊ��λ����
		*/
		GGE_EXPORT bool IsIdentity() const;
		/**
		@brief ����λ��
		@param translation λ��
		*/
		GGE_EXPORT void SetTranslation(const ggeVector &translation);
		/**
		@brief ����λ��
		@return λ��
		*/
		GGE_EXPORT ggeVector GetTranslation() const;
		/**
		@brief ������ת
		@param rotation ��ת����
		*/
		GGE_EXPORT void SetRotation(const float rotation);
		/**
		@brief ������ת
		@return ��ת����
		*/
		GGE_EXPORT float GetRotation() const;
		/**
		@brief ��������
		@param scale ����
		*/
		GGE_EXPORT void SetScale(const ggeVector &scale);
		/**
		@brief ��������
		@return ����
		*/
		GGE_EXPORT ggeVector GetScale() const;
		/**
		@brief �任ʸ��
		@param vec Ҫ�任��ʸ��
		*/
		GGE_EXPORT void TransformVector(ggeVector &vec) const;
		/**
		@brief ����Ϊ�����
		@return �ɹ�����true
		*/
		GGE_EXPORT bool SetInverse();
		/**
		@brief ��ȡ�����
		@param mat ���ڱ��������
		@return �ɹ�����true
		*/
		GGE_EXPORT bool GetInverse(ggeMatrix &mat) const;
		/**
		@brief ����Ϊת�þ���
		*/
		GGE_EXPORT void SetTranspose();
		/**
		@brief ��ȡת�þ���
		@param mat ���ڱ���ת�þ���
		*/
		GGE_EXPORT void GetTranspose(ggeMatrix &mat) const;
	};

	/**	@brief Matrix4
		\code
		struct 
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[16];
		float _m[4][4];
		\endcode
	*/
	class ggeMatrix4
	{
	public:
		union
		{
			struct 
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[16];
			float _m[4][4];
		};

		/// ���캯��
		ggeMatrix4() {}
		/// ���캯��
		ggeMatrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) :
			_11(m11), _12(m12), _13(m13), _14(m14), _21(m21), _22(m22), _23(m23), _24(m24), 
			_31(m31), _32(m32), _33(m33), _34(m34), _41(m41), _42(m42), _43(m43), _44(m44) {}

		/// ���������
		float& operator()(const int row, const int col)				{ return _m[row][col]; }
		/// ���������
		const float& operator()(const int row, const int col) const { return _m[row][col]; }
		/// ���������
		float& operator[](int index)								{ return m[index]; }
		/// ���������
		const float& operator[](int index) const					{ return m[index]; }

		/// ���������
		bool operator==(const ggeMatrix4 &om) const
		{
			if (m[0]  != om.m[0]  || m[1]  != om.m[1]  || m[2]  != om.m[2]  || m[3]  != om.m[3]  ||
				m[4]  != om.m[4]  || m[5]  != om.m[5]  || m[6]  != om.m[6]  || m[7]  != om.m[7]  ||
				m[8]  != om.m[8]  || m[9]  != om.m[9]  || m[10] != om.m[10] || m[11] != om.m[11] ||
				m[12] != om.m[12] || m[13] != om.m[13] || m[14] != om.m[14] || m[15] != om.m[15])
				return false;
			return true;
		}
		/// ���������
		bool operator!=(const ggeMatrix4 &om) const
		{
			if (m[0]  != om.m[0]  || m[1]  != om.m[1]  || m[2]  != om.m[2]  || m[3]  != om.m[3]  ||
				m[4]  != om.m[4]  || m[5]  != om.m[5]  || m[6]  != om.m[6]  || m[7]  != om.m[7]  ||
				m[8]  != om.m[8]  || m[9]  != om.m[9]  || m[10] != om.m[10] || m[11] != om.m[11] ||
				m[12] != om.m[12] || m[13] != om.m[13] || m[14] != om.m[14] || m[15] != om.m[15])
				return true;
			return false;
		}
		/// ���������
		ggeMatrix4 operator+(const ggeMatrix4 &om) const
		{
			ggeMatrix4 mat;

			mat[0]  = m[0]  + om.m[0];  mat[1]  = m[1]  + om.m[1];  mat[2] =  m[2]  + om.m[2];  mat[3]  = m[3]  + om.m[3];
			mat[4]  = m[4]  + om.m[4];  mat[5]  = m[5]  + om.m[5];  mat[6] =  m[6]  + om.m[6];  mat[7]  = m[7]  + om.m[7];
			mat[8]  = m[8]  + om.m[8];  mat[9]  = m[9]  + om.m[9];  mat[10] = m[10] + om.m[10]; mat[11] = m[11] + om.m[11];
			mat[12] = m[12] + om.m[12]; mat[13] = m[13] + om.m[13]; mat[14] = m[14] + om.m[14]; mat[15] = m[15] + om.m[15];

			return mat;
		}
		/// ���������
		ggeMatrix4& operator+=(const ggeMatrix4 &om)
		{
			m[0]  += om.m[0];  m[1]  += om.m[1];  m[2]  += om.m[2];  m[3]  += om.m[3]; 
			m[4]  += om.m[4];  m[5]  += om.m[5];  m[6]  += om.m[6];  m[7]  += om.m[7]; 
			m[8]  += om.m[8];  m[9]  += om.m[9];  m[10] += om.m[10]; m[11] += om.m[11]; 
			m[12] += om.m[12]; m[13] += om.m[13]; m[14] += om.m[14]; m[15] += om.m[15];

			return *this;
		}
		/// ���������
		ggeMatrix4 operator-(const ggeMatrix4 &om) const
		{
			ggeMatrix4 mat;

			mat[0]  = m[0]  - om.m[0];  mat[1]  = m[1]  - om.m[1];  mat[2]  = m[2]  - om.m[2];  mat[3]  = m[3]  - om.m[3];
			mat[4]  = m[4]  - om.m[4];  mat[5]  = m[5]  - om.m[5];  mat[6]  = m[6]  - om.m[6];  mat[7]  = m[7]  - om.m[7];
			mat[8]  = m[8]  - om.m[8];  mat[9]  = m[9]  - om.m[9];  mat[10] = m[10] - om.m[10]; mat[11] = m[11] - om.m[11];
			mat[12] = m[12] - om.m[12]; mat[13] = m[13] - om.m[13]; mat[14] = m[14] - om.m[14]; mat[15] = m[15] - om.m[15];

			return mat;
		}
		/// ���������
		ggeMatrix4& operator-=(const ggeMatrix4 &om)
		{
			m[0]  -= om.m[0];  m[1]  -= om.m[1];  m[2]  -= om.m[2];  m[3]  -= om.m[3];
			m[4]  -= om.m[4];  m[5]  -= om.m[5];  m[6]  -= om.m[6];  m[7]  -= om.m[7];
			m[8]  -= om.m[8];  m[9]  -= om.m[9];  m[10] -= om.m[10]; m[11] -= om.m[11];
			m[12] -= om.m[12]; m[13] -= om.m[13]; m[14] -= om.m[14]; m[15] -= om.m[15];

			return *this;
		}
		/// ���������
		ggeMatrix4 operator*(const ggeMatrix4 &om) const
		{
			ggeMatrix4 mat;

			mat[0]  = m[0] * om.m[0] + m[4] * om.m[1] + m[8]  * om.m[2] + m[12] * om.m[3];
			mat[1]  = m[1] * om.m[0] + m[5] * om.m[1] + m[9]  * om.m[2] + m[13] * om.m[3];
			mat[2]  = m[2] * om.m[0] + m[6] * om.m[1] + m[10] * om.m[2] + m[14] * om.m[3];
			mat[3]  = m[3] * om.m[0] + m[7] * om.m[1] + m[11] * om.m[2] + m[15] * om.m[3];

			mat[4]  = m[0] * om.m[4] + m[4] * om.m[5] + m[8]  * om.m[6] + m[12] * om.m[7];
			mat[5]  = m[1] * om.m[4] + m[5] * om.m[5] + m[9]  * om.m[6] + m[13] * om.m[7];
			mat[6]  = m[2] * om.m[4] + m[6] * om.m[5] + m[10] * om.m[6] + m[14] * om.m[7];
			mat[7]  = m[3] * om.m[4] + m[7] * om.m[5] + m[11] * om.m[6] + m[15] * om.m[7];

			mat[8]  = m[0] * om.m[8] + m[4] * om.m[9] + m[8]  * om.m[10] + m[12] * om.m[11];
			mat[9]  = m[1] * om.m[8] + m[5] * om.m[9] + m[9]  * om.m[10] + m[13] * om.m[11];
			mat[10] = m[2] * om.m[8] + m[6] * om.m[9] + m[10] * om.m[10] + m[14] * om.m[11];
			mat[11] = m[3] * om.m[8] + m[7] * om.m[9] + m[11] * om.m[10] + m[15] * om.m[11];

			mat[12] = m[0] * om.m[12] + m[4] * om.m[13] + m[8]  * om.m[14] + m[12] * om.m[15];
			mat[13] = m[1] * om.m[12] + m[5] * om.m[13] + m[9]  * om.m[14] + m[13] * om.m[15];
			mat[14] = m[2] * om.m[12] + m[6] * om.m[13] + m[10] * om.m[14] + m[14] * om.m[15];
			mat[15] = m[3] * om.m[12] + m[7] * om.m[13] + m[11] * om.m[14] + m[15] * om.m[15];

			return mat;
		}
		/// ���������
		ggeMatrix4& operator*=(const ggeMatrix4 &om)
		{
			ggeMatrix4 mat(*this);

			m[0]  = mat[0] * om.m[0] + mat[4] * om.m[1] + mat[8]  * om.m[2] + mat[12] * om.m[3];
			m[1]  = mat[1] * om.m[0] + mat[5] * om.m[1] + mat[9]  * om.m[2] + mat[13] * om.m[3];
			m[2]  = mat[2] * om.m[0] + mat[6] * om.m[1] + mat[10] * om.m[2] + mat[14] * om.m[3];
			m[3]  = mat[3] * om.m[0] + mat[7] * om.m[1] + mat[11] * om.m[2] + mat[15] * om.m[3];

			m[4]  = mat[0] * om.m[4] + mat[4] * om.m[5] + mat[8]  * om.m[6] + mat[12] * om.m[7];
			m[5]  = mat[1] * om.m[4] + mat[5] * om.m[5] + mat[9]  * om.m[6] + mat[13] * om.m[7];
			m[6]  = mat[2] * om.m[4] + mat[6] * om.m[5] + mat[10] * om.m[6] + mat[14] * om.m[7];
			m[7]  = mat[3] * om.m[4] + mat[7] * om.m[5] + mat[11] * om.m[6] + mat[15] * om.m[7];

			m[8]  = mat[0] * om.m[8] + mat[4] * om.m[9] + mat[8]  * om.m[10] + mat[12] * om.m[11];
			m[9]  = mat[1] * om.m[8] + mat[5] * om.m[9] + mat[9]  * om.m[10] + mat[13] * om.m[11];
			m[10] = mat[2] * om.m[8] + mat[6] * om.m[9] + mat[10] * om.m[10] + mat[14] * om.m[11];
			m[11] = mat[3] * om.m[8] + mat[7] * om.m[9] + mat[11] * om.m[10] + mat[15] * om.m[11];

			m[12] = mat[0] * om.m[12] + mat[4] * om.m[13] + mat[8]  * om.m[14] + mat[12] * om.m[15];
			m[13] = mat[1] * om.m[12] + mat[5] * om.m[13] + mat[9]  * om.m[14] + mat[13] * om.m[15];
			m[14] = mat[2] * om.m[12] + mat[6] * om.m[13] + mat[10] * om.m[14] + mat[14] * om.m[15];
			m[15] = mat[3] * om.m[12] + mat[7] * om.m[13] + mat[11] * om.m[14] + mat[15] * om.m[15];

			return *this;
		}
		/// ���������
		ggeMatrix4 operator*(const float scalar) const
		{
			ggeMatrix4 mat;

			mat[0]  = m[0]  * scalar; mat[1]  = m[1]  * scalar; mat[2] =  m[2]  * scalar; mat[3]  = m[3]  * scalar;
			mat[4]  = m[4]  * scalar; mat[5]  = m[5]  * scalar; mat[6] =  m[6]  * scalar; mat[7]  = m[7]  * scalar;
			mat[8]  = m[8]  * scalar; mat[9]  = m[9]  * scalar; mat[10] = m[10] * scalar; mat[11] = m[11] * scalar;
			mat[12] = m[12] * scalar; mat[13] = m[13] * scalar; mat[14] = m[14] * scalar; mat[15] = m[15] * scalar;

			return mat;
		}
		/// ���������
		ggeMatrix4& operator*=(const float scalar)
		{
			m[0]  *= scalar; m[1]  *= scalar; m[2]  *= scalar; m[3]  *= scalar;
			m[4]  *= scalar; m[5]  *= scalar; m[6]  *= scalar; m[7]  *= scalar;
			m[8]  *= scalar; m[9]  *= scalar; m[10] *= scalar; m[11] *= scalar;
			m[12] *= scalar; m[13] *= scalar; m[14] *= scalar; m[15] *= scalar;

			return *this;
		}

		/**
		@brief ���óɵ�λ����
		*/
		GGE_EXPORT void SetIdentity();
		/**
		@brief �Ƿ�Ϊ��λ����
		@return �Ƿ�Ϊ��λ����
		*/
		GGE_EXPORT bool IsIdentity() const;
		/**
		@brief ����λ��
		@param translation X/Y/Z���ϵ�λ��
		*/
 		GGE_EXPORT void SetTranslation(const ggeVector3 &translation);
		/**
		@brief ����λ��
		@return X/Y/Z���ϵ�λ��
		*/
		GGE_EXPORT ggeVector3 GetTranslation() const;
		/**
		@brief ��ŷ����������ת
		@param rotation ŷ������ת����
		*/
 		GGE_EXPORT void SetRotation(const ggeVector3 &rotation);
		/**
		@brief ������תŷ����
		@return ŷ������ת����
		*/
		GGE_EXPORT ggeVector3 GetRotation() const;
		/**
		@brief ����Χ��X�����ת
		@param angle ��ת����
		*/
		GGE_EXPORT void SetRotationX(float angle);
		/**
		@brief ����Χ��Y�����ת
		@param angle ��ת����
		*/
		GGE_EXPORT void SetRotationY(float angle);
		/**
		@brief ����Χ��Z�����ת
		@param angle ��ת����
		*/
		GGE_EXPORT void SetRotationZ(float angle);
		/**
		@brief ����Χ��ָ�������ת
		@param axis ��ת��
		@param angle ��ת����
		*/
	   GGE_EXPORT void SetRotationAxis(const ggeVector3 &axis, float angle);
		/**
		@brief ��������
		@param scale X/Y/Z���ϵ�����
		*/
 		GGE_EXPORT void SetScale(const ggeVector3 &scale);
		/**
		@brief ��������
		@return X/Y/Z���ϵ�����
		*/
		GGE_EXPORT ggeVector3 GetScale() const;
		/**
		@brief �任ʸ��
		@param vec Ҫ�任��ʸ��
		*/
		GGE_EXPORT void TransformVector(ggeVector &vec) const;
		/**
		@brief �任ʸ��
		@param vec Ҫ�任��ʸ��
		*/
		GGE_EXPORT void TransformVector3(ggeVector3 &vec) const;
		/**
		@brief ����Ϊ�����
		@return �ɹ�����true
		*/
 		GGE_EXPORT bool SetInverse();
		/**
		@brief ��ȡ�����
		@param mat ���ڱ��������
		@return �ɹ�����true
		*/
		GGE_EXPORT bool GetInverse(ggeMatrix4 &mat) const;
		/**
		@brief ����Ϊת�þ���
		*/
		GGE_EXPORT void SetTranspose();
		/**
		@brief ��ȡת�þ���
		@param mat ���ڱ���ת�þ���
		*/
		GGE_EXPORT void GetTranspose(ggeMatrix4 &mat) const;
		/**
		@brief ����͸��ͶӰ����
		@param fov y��۲췶Χ�нǻ���
		@param aspect �ݺ��
		@param zn ���ü���
		@param zf Զ�ü���
		*/
		GGE_EXPORT void BuildProjectionMatrixPerspectiveFovLH(float fov, float aspect, float zn, float zf);
		/**
		@brief ��������ͶӰ����
		@param wov ��Ļ���
		@param hov ��Ļ�߶�
		@param zn Z������Сֵ
		@param zf Z�������ֵ
		*/
		GGE_EXPORT void BuildProjectionMatrixOrthoLH(float wov, float hov, float zn, float zf);
		/**
		@brief ������ͼ����
		@param position �۲��λ��
		@param target �۲�Ŀ��λ��
		@param up ���Ϸ���
		*/
		GGE_EXPORT void BuildCameraLookAtMatrixLH(const ggeVector3 &position, const ggeVector3 &target, const ggeVector3 &up);
	};
}