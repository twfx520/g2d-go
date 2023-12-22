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
\brief ��ɫģ��
*/


#pragma once
#include "ggetypes.h"

namespace gge
{
	/** @name Color
	*  @{
	*/

	/// ������ɫֵ
	inline guint32 Color_ARGB(guint32 a, guint32 r, guint32 g, guint32 b)	{ return (a << 24) + (r << 16) + (g << 8) + b; }
	/// ������ɫֵ
	inline guint32 Color_XRGB(guint32 r, guint32 g, guint32 b)			{ return Color_ARGB(255, r, g, b); }
	/// ����alphaֵ
	inline guint32 Color_GetA(guint32 col)							{ return col >> 24; }
	/// ����alphaֵ
	inline guint32 Color_SetA(guint32 col, guint32 a)					{ return (col & 0x00FFFFFF) + (a << 24); }
	/// ���غ�ɫֵ
	inline guint32 Color_GetR(guint32 col)							{ return (col >> 16) & 0xFF; }
	/// ���ú�ɫֵ
	inline guint32 Color_SetR(guint32 col, guint32 r)					{ return (col & 0xFF00FFFF) + (r << 16); }
	/// ������ɫֵ
	inline guint32 Color_GetG(guint32 col)							{ return (col >> 8) & 0xFF; }
	/// ������ɫֵ
	inline guint32 Color_SetG(guint32 col, guint32 g)					{ return (col & 0xFFFF00FF) + (g << 8); }
	/// ������ɫֵ
	inline guint32 Color_GetB(guint32 col)							{ return col & 0xFF; }
	/// ������ɫֵ
	inline guint32 Color_SetB(guint32 col, guint32 b)					{ return (col & 0xFFFFFF00) + b; }

	/** 
	@} 
	*/

	/// ��ɫģ��
	class ggeColor
	{
	public:
		float	r;	///< ��ɫ����(0.0f~1.0f)
		float	g;	///< ��ɫ����(0.0f~1.0f)
		float	b;	///< ��ɫ����(0.0f~1.0f)
		float	a;	///< alpha����(0.0f~1.0f)

		/// ���캯��
		ggeColor(float _r, float _g, float _b, float _a) { r = _r; g = _g; b = _b; a = _a; }
		/// ���캯��
		ggeColor(guint32 c)	{ SetColor(c); }
		/// ���캯��
		ggeColor()			{ r = g = b = a = 0; }

		/// ���������
		ggeColor	operator-  (const ggeColor &c)	{ return ggeColor(r - c.r, g - c.g, b - c.b, a - c.a); }
		/// ���������
		ggeColor	operator+  (const ggeColor &c)	{ return ggeColor(r + c.r, g + c.g, b + c.b, a + c.a); }
		/// ���������
		ggeColor	operator*  (const ggeColor &c)  { return ggeColor(r * c.r, g * c.g, b * c.b, a * c.a); }
		/// ���������
		ggeColor&	operator-= (const ggeColor &c)	{ r -= c.r; g -= c.g; b -= c.b; a -= c.a; return *this; }
		/// ���������
		ggeColor&	operator+= (const ggeColor &c)	{ r += c.r; g +=c .g; b += c.b; a += c.a; return *this; }
		/// ���������
		bool		operator== (const ggeColor &c)	{ return (r == c.r && g == c.g && b == c.b && a == c.a); }
		/// ���������
		bool		operator!= (const ggeColor &c)	{ return (r != c.r || g != c.g || b != c.b || a != c.a); }

		/// ���������
		ggeColor	operator*  (float scalar)		{ return ggeColor(r * scalar, g * scalar, b * scalar, a * scalar); }
		/// ���������
		ggeColor	operator/  (float scalar)		{ return ggeColor(r / scalar, g / scalar, b / scalar, a / scalar); }
		/// ���������
		ggeColor&	operator*= (float scalar)		{ r *= scalar; g *= scalar; b *= scalar; a *= scalar; return *this; }

		/**
		@brief ������ɫֵ
		@param wcolor 32λ��ɫֵ
		*/
		void	SetColor(guint32 wcolor)				{ a = (wcolor >> 24) / 255.0f; r = ((wcolor >> 16) & 0xFF) / 255.0f; g = ((wcolor >> 8) & 0xFF) / 255.0f; b = (wcolor & 0xFF) / 255.0f; }
		/**
		@brief ���32λ��ɫֵ
		@return 32λ��ɫֵ
		*/
		guint32	GetColor() const					{ return (guint32(a * 255.0f) << 24) + (guint32(r * 255.0f) << 16) + (guint32(g * 255.0f) << 8) + guint32(b * 255.0f); }
		/**
		@brief ʹ��ɫֵ��0.0f~1.0f��Χ��
		*/
		GGE_EXPORT void	Clamp();
		/**
		@brief ����c1��c2�����Բ�ֵ�Ľ��
		@param c1 ��ɫ1
		@param c2 ��ɫ2
		@param s ��ֵ��ԽСԽ�ӽ�c1
		@return ������������
		*/
		GGE_EXPORT ggeColor& Lerp(const ggeColor &c1, const ggeColor &c2, float s);
	};

	/** @name Color
	*  @{
	*/

	/// ��ɫ���������
	inline ggeColor operator* (const ggeColor &c, float s)	{ return ggeColor(s * c.r, s * c.g, s * c.b, s * c.a); }
	/// ��ɫ���������
	inline ggeColor operator* (float s, const ggeColor &c)	{ return ggeColor(s * c.r, s * c.g, s * c.b, s * c.a); }

	/** 
	@} 
	*/
}