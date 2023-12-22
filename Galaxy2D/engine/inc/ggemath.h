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
\brief ��ѧ��
*/

#pragma once
#include "ggetypes.h"

namespace gge
{
	/** @name Math
	*  @{
	*/

	#define GGE_PI		3.14159265358979323846f		///< Բ����
	#define GGE_PI_2	1.57079632679489661923f		///< Բ����
	#define GGE_PI_4	0.785398163397448309616f	///< Բ����
	#define GGE_1_PI	0.318309886183790671538f	///< Բ����
	#define GGE_2_PI	0.636619772367581343076f	///< Բ����

	/// ����ת�Ƕ�
	inline float ToDegree(float radian) { return radian * (180.0f / (float)GGE_PI); }
	/// �Ƕ�ת����
	inline float ToRadian(float degree) { return degree * ((float)GGE_PI / 180.0f); }
	/// ��sΪ������v1��v2�����Բ�ֵ
	inline float LinearErp(float v1, float v2, float s) { return v1 + s * (v2 - v1); }

	/** 
	@} 
	*/

	/// Vector
	class ggeVector
	{
	public:
		float	x;	///< x
		float	y;	///< y

		/// ���캯��
		ggeVector(float _x, float _y) : x(_x), y(_y) {}
		/// ���캯��
		ggeVector() : x(0), y(0) {}

		/// ���������
		ggeVector	operator+  (const ggeVector &v)	const	{ return ggeVector(x + v.x, y + v.y); }
		/// ���������
		ggeVector	operator-  (const ggeVector &v)	const	{ return ggeVector(x - v.x, y - v.y); }
		/// ���������
		ggeVector	operator*  (const ggeVector &v)	const	{ return ggeVector(x * v.x, y * v.y); }
		/// ���������
		ggeVector	operator/  (const ggeVector &v)	const	{ return ggeVector(x / v.x, y / v.y); }
		/// ���������
		ggeVector	operator+  (const float v)	const		{ return ggeVector(x + v, y + v); }
		/// ���������
		ggeVector	operator-  (const float v)	const		{ return ggeVector(x - v, y - v); }
		/// ���������
		ggeVector	operator*  (const float v)	const		{ return ggeVector(x * v, y * v); }
		/// ���������
		ggeVector	operator/  (const float v)	const		{ return ggeVector(x / v, y / v); }
		/// ���������
		ggeVector&	operator+= (const ggeVector &v)			{ x += v.x; y += v.y; return *this; }
		/// ���������
		ggeVector&	operator-= (const ggeVector &v)			{ x -= v.x; y -= v.y; return *this; }
		/// ���������
		ggeVector&	operator*= (const ggeVector &v)			{ x *= v.x; y *= v.y; return *this; }
		/// ���������
		ggeVector&	operator/= (const ggeVector &v)			{ x /= v.x; y /= v.y; return *this; }
		/// ���������
		ggeVector&	operator+= (const float v)				{ x += v; y += v; return *this; }
		/// ���������
		ggeVector&	operator-= (const float v)				{ x -= v; y -= v; return *this; }
		/// ���������
		ggeVector&	operator*= (const float v)				{ x *= v; y *= v; return *this; }
		/// ���������
		ggeVector&	operator/= (const float v)				{ x /= v; y /= v; return *this; }
		/// ���������
		ggeVector	operator-  ()					const	{ return ggeVector(-x, -y); }
		/// ���������
		bool		operator== (const ggeVector &v)	const	{ return (x == v.x && y == v.y); }
		/// ���������
		bool		operator!= (const ggeVector &v)	const	{ return (x != v.x || y != v.y); }

		/**
		@brief �����ʸ�����
		@param v ʸ��
		@return ��ʸ�����
		*/
		GGE_EXPORT float		Dot(const ggeVector &v) const;
		/**
		@brief ��׼��ʸ��
		*/
		GGE_EXPORT void			Normalize();	
		/**
		@brief ���ʸ������
		@return ʸ������
		*/
		GGE_EXPORT float		Length() const;
		/**
		@brief ���ʸ�����ȵ�ƽ��
		@return ʸ�����ȵ�ƽ��
		*/
		GGE_EXPORT float		LengthSquared() const;
		/**
		@brief ������X��ĽǶ�
		@return ������X��ĽǶ�
		*/
		GGE_EXPORT float		Angle() const;
		/**
		@brief �����ʸ����Ƕ�
		@param v ʸ��
		@return ��ʸ����Ƕ�
		*/
		GGE_EXPORT float		AngleTo(const ggeVector &v) const;
		/**
		@brief ���v�ڸ�ʸ����˳ʱ�뷽�򷵻�1���������ʱ�뷽�򷵻�-1�����򷵻�0
		@param v ʸ��
		@return ���v�ڸ�ʸ����˳ʱ�뷽�򷵻�1���������ʱ�뷽�򷵻�-1�����򷵻�0
		*/
		GGE_EXPORT int			Sign(const ggeVector &v) const;
		/**
		@brief �������ʸ����ֱ��ʸ��
		@return �������ʸ����ֱ��ʸ��
		*/
		GGE_EXPORT ggeVector	Perpendicular() const;
		/**
		@brief ������vΪƽ��ķ���ʸ����v�����Ǳ�׼��ʸ��
		@return ������vΪƽ��ķ���ʸ��
		*/
		GGE_EXPORT ggeVector	Reflect(const ggeVector &v) const;
		/**
		@brief ���ó���vΪƽ��ķ���ʸ����v�����Ǳ�׼��ʸ��
		@return ���ظ�ʸ��
		*/
		GGE_EXPORT ggeVector&	ToReflect(const ggeVector &v);
		/**
		@brief ��ʸ����תָ���Ƕ�
		@param radian ��ת�Ƕ�
		*/
		GGE_EXPORT void			Rotate(float radian);
		/**
		@brief ʹʸ�����Ȳ�����ָ���ĳ���
		@param max ��󳤶�
		*/
		GGE_EXPORT void			Clamp(float max);
	};
	
	/** @name Vector
	*  @{
	*/

	/// Vector���������
	inline ggeVector operator* (const float s, const ggeVector &v)	{ return ggeVector(s * v.x, s * v.y); }
	/// Vector���������
	inline ggeVector operator/ (const float s, const ggeVector &v)	{ return ggeVector(s / v.x, s / v.y); }

	/** 
	@} 
	*/

	/// Vector3
	class  ggeVector3
	{
	public:
		float	x;	///< x
		float	y;	///< y
		float	z;	///< z

		/// ���캯��
		ggeVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		/// ���캯��
		ggeVector3() : x(0), y(0), z(0) {}

		/// ���������
		ggeVector3	operator+  (const ggeVector3 &v)	const	{ return ggeVector3(x + v.x, y + v.y, z + v.z); }
		/// ���������
		ggeVector3	operator-  (const ggeVector3 &v)	const	{ return ggeVector3(x - v.x, y - v.y, z - v.z); }
		/// ���������
		ggeVector3	operator*  (const ggeVector3 &v)	const	{ return ggeVector3(x * v.x, y * v.y, z * v.z); }
		/// ���������
		ggeVector3	operator/  (const ggeVector3 &v)	const	{ return ggeVector3(x / v.x, y / v.y, z / v.z); }
		/// ���������
		ggeVector3	operator+  (const float v)	const			{ return ggeVector3(x + v, y + v, z + v); }
		/// ���������
		ggeVector3	operator-  (const float v)	const			{ return ggeVector3(x - v, y - v, z - v); }
		/// ���������
		ggeVector3	operator*  (const float v)	const			{ return ggeVector3(x * v, y * v, z * v); }
		/// ���������
		ggeVector3	operator/  (const float v)	const			{ return ggeVector3(x / v, y / v, z / v); }
		/// ���������
		ggeVector3&	operator+= (const ggeVector3 &v)			{ x += v.x; y += v.y; z += v.z; return *this; }
		/// ���������
		ggeVector3&	operator-= (const ggeVector3 &v)			{ x -= v.x; y -= v.y; z -= v.z; return *this; }
		/// ���������
		ggeVector3&	operator*= (const ggeVector3 &v)			{ x *= v.x; y *= v.y; z *= v.z; return *this; }
		/// ���������
		ggeVector3&	operator/= (const ggeVector3 &v)			{ x /= v.x; y /= v.y; z /= v.z; return *this; }
		/// ���������
		ggeVector3&	operator+= (const float v)					{ x += v; y += v; z += v; return *this; }
		/// ���������
		ggeVector3&	operator-= (const float v)					{ x -= v; y -= v; z -= v; return *this; }
		/// ���������
		ggeVector3&	operator*= (const float v)					{ x *= v; y *= v; z *= v; return *this; }
		/// ���������
		ggeVector3&	operator/= (const float v)					{ x /= v; y /= v; z /= v; return *this; }
		/// ���������
		ggeVector3	operator-  ()						const	{ return ggeVector3(-x, -y, -z); }
		/// ���������
		bool		operator== (const ggeVector3 &v)	const	{ return (x == v.x && y == v.y && z == v.z); }
		/// ���������
		bool		operator!= (const ggeVector3 &v)	const	{ return (x != v.x || y != v.y || z != v.z); }

		/**
		@brief �����ʸ�����
		@param v ʸ��
		@return ��ʸ�����
		*/
		GGE_EXPORT float		Dot(const ggeVector3 &v) const;
		/**
		@brief �����ʸ�����
		@param v ʸ��
		@return ��ʸ�����
		*/
		GGE_EXPORT ggeVector3	Cross(const ggeVector3 &v) const;
		/**
		@brief ��׼��ʸ��
		*/
		GGE_EXPORT void			Normalize();
		/**
		@brief ���ʸ������
		@return ʸ������
		*/
		GGE_EXPORT float		Length() const;
		/**
		@brief ���ʸ�����ȵ�ƽ��
		@return ʸ�����ȵ�ƽ��
		*/
		GGE_EXPORT float		LengthSquared() const;
		/**
		@brief �����ʸ����Ƕ�
		@param v ʸ��
		@return ��ʸ����Ƕ�
		*/
		GGE_EXPORT float		Angle(const ggeVector3 &v) const;
		/**
		@brief ʹʸ�����Ȳ�����ָ���ĳ���
		@param max ��󳤶�
		*/
		GGE_EXPORT void			Clamp(float max);
	};

	/** @name Vector3
	*  @{
	*/

	/// Vector3���������
	inline ggeVector3 operator* (const float s, const ggeVector3 &v)	{ return ggeVector3(s * v.x, s * v.y, s * v.z); }
	/// Vector3���������
	inline ggeVector3 operator/ (const float s, const ggeVector3 &v)	{ return ggeVector3(s / v.x, s / v.y, s / v.z); }

	/** 
	@} 
	*/

	/// Rect
	class ggeRect
	{
	public:
		float	x1;	///< ���Ͻ�x����
		float	y1; ///< ���Ͻ�y����
		float	x2; ///< ���½�x����
		float	y2; ///< ���½�y����

		/// ���캯��
		ggeRect() : m_bClean(true) {}
		/// ���캯��
		ggeRect(float _x1, float _y1, float _x2, float _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), m_bClean(false) {}

		/// ���������
		bool		operator== (const ggeRect &v)	const	{ return (x1 == v.x1 && y1 == v.y1 && x2 == v.x2 && y2 == v.y2); }
		/// ���������
		bool		operator!= (const ggeRect &v)	const	{ return (x1 != v.x1 || y1 != v.y1 || x2 != v.x2 || y2 != v.y2); }

		/// ���ÿ��
		void	SetWidth(float w)	{ x2 = x1 + w; }
		/// ���ؿ��
		float	GetWidth()			{ return x2 - x1; }
		/// ���ø߶�
		void	SetHeight(float h)	{ y2 = y1 + h; }
		/// ���ظ߶�
		float	GetHeight()			{ return y2 - y1; }

		/**
		@brief ���þ�������
		@param _x1 ���Ͻ�x����
		@param _y1 ���Ͻ�y����
		@param _x2 ���½�x����
		@param _y2 ���½�y����
		*/
		GGE_EXPORT void Set(float _x1, float _y1, float _x2, float _y2);
		/**
		@brief �������
		*/
		GGE_EXPORT void Clear();
		/**
		@brief �����Ƿ���Ч
		@return �����Ƿ���Ч
		*/
		GGE_EXPORT bool IsClean() const;
		/**
		@brief �ƶ����ε���(x, y)�����δ�С����
		@param x x����
		@param y y����
		*/
		GGE_EXPORT void Move(float x, float y);
		/**
		@brief ���þ��η�Χ
		@param x ��������x����
		@param y ��������y����
		@param r ���η�Χ
		*/
		GGE_EXPORT void SetRadius(float x, float y, float r);
		/**
		@brief �������δ�Сʹ���ܹ�������(x, y)
		@param x x����
		@param y y����
		*/
		GGE_EXPORT void Encapsulate(float x, float y);
		/**
		@brief ����һ���������ü��þ���
		@param rect ���ڲü��ľ���
		*/
		GGE_EXPORT void ClipWith(const ggeRect &rect);
		/**
		@brief ���Ե�(x, y)�Ƿ��ڸþ��ο���
		@param x x����
		@param y y����
		@return ���Ƿ��ڸþ��ο���
		*/
		GGE_EXPORT bool TestPoint(float x, float y) const;
		/**
		@brief �����������ο��Ƿ��ཻ
		@param rect Ҫ���Եľ���
		@return �������ο��Ƿ��ཻ
		*/
		GGE_EXPORT bool Intersect(const ggeRect &rect) const;

	private:
		bool	m_bClean;
	};
}