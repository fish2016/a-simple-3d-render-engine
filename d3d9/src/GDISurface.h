#ifndef __GDISurface_H__
#define __GDISurface_H__

#include <windows.h>
#include <stdio.h>
#include <wingdi.h>
#include "renderlist.h"

class CGDIGraphicsDevice;

// 表面类 用来存放一个图片，并用来显示图片
class CGDISurface
{
public:
    
    // 位块传送方式
    enum SurfaceBltMode
    {
        BLT_BLOCK,          // 复制方式， 完全显示在目标上
        BLT_ALPHATEST,      // 透明色检测方式， 如果遇到 RGB( 0, 0, 255 ) 图片里的纯蓝色就跳过
        BLT_ALPHABLEND,     // 未支持
    };

    CGDISurface();
	CGDISurface(int width,int height);
	CGDISurface(LPSTR szFileName);

    virtual ~CGDISurface();
    
    bool	Create(int iWidth, int iHeight );
    bool	LoadBmp(LPSTR szFileName);

    void	Release();

	int		GetWidth() {return m_width;}
	int		GetHeight() {return m_height;}
	int		GetPitch() {return m_pitch;}
	BYTE*   GetlpData() {return m_ptr;}
	HDC		GetDC() {return m_hdc;}

    void	Clear(COLORREF c = RGB(0,0,0));
    void	SetPixel(int x, int y, WORD c);
	WORD	GetPixel(int x, int y);
	void	Blt(CGDISurface *pSurface, int x, int y, int rx, int ry, int w, int h, SurfaceBltMode sbmMode);
	void	Render(HDC hdc, int x=0,int y =0);

private:
    int		m_width;
    int		m_height;
	int		m_pitch;
	BYTE*	m_ptr;

	BITMAPINFO	m_bmpInfo;
    HDC m_hdc;

	bool	LoadFromHandle(HBITMAP hbmp);
	void	Init();

public:
    void DrawLine_v1(int xStart, int yStart, int xEnd, int yEnd, WORD c );
    void DrawLine_v1_float(float fxStart, float fyStart, float fxEnd, float fyEnd, WORD c );

    int DrawLineTriangle_v1(POLYF4DV1* pPoly4D);

};

#endif // __GDISurface_H__
