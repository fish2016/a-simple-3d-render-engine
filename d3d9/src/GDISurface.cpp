
#include <stdafx.h>
#include "GDISurface.h"
#include <assert.h>

CGDISurface::~CGDISurface()
{
	Release();
}

CGDISurface::CGDISurface()
{
	Init();
}

CGDISurface::CGDISurface(int width,int height)
{
	Init();
	Create(width,height);
}

CGDISurface::CGDISurface(LPSTR szFileName)
{
	Init();
	LoadBmp(szFileName);
}

void CGDISurface::Init()
{
    m_width            = 0;
    m_height           = 0;
    m_hdc              = NULL;

	ZeroMemory(&m_bmpInfo,sizeof(BITMAPINFO));
	m_bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_bmpInfo.bmiHeader.biPlanes = 1;
	m_bmpInfo.bmiHeader.biBitCount = 16;	//16位颜色
}

bool CGDISurface::Create( int width, int height )
{
    // 创建图形设备句柄
	if (m_hdc) DeleteDC(m_hdc);

	m_hdc	= CreateCompatibleDC(NULL);
	m_pitch = ((width<<1) + 2) & 0xfffffffc;
	if (!m_hdc) return FALSE;

	
	m_bmpInfo.bmiHeader.biWidth = width;
	m_bmpInfo.bmiHeader.biHeight = -height;
	m_bmpInfo.bmiHeader.biSizeImage = m_pitch * height;

	HBITMAP hbmp = CreateDIBSection(m_hdc,&m_bmpInfo,DIB_RGB_COLORS,(void**)&m_ptr,NULL,0);
	SelectObject(m_hdc,hbmp);
	DeleteObject(hbmp);

    m_width    = width;
    m_height   = height;

    return true;
}

// 从文件读取一个位图
bool CGDISurface::LoadBmp( LPSTR szFileName )
{
	return LoadFromHandle((HBITMAP) LoadImage(0,
									szFileName,
									IMAGE_BITMAP,
									0,
									0,
									LR_LOADFROMFILE | LR_CREATEDIBSECTION));
}

bool CGDISurface::LoadFromHandle(HBITMAP hbmp)
{
	BITMAP bmp;
	GetObject(hbmp,sizeof(BITMAP),&bmp);

	if ( !Create(bmp.bmWidth,bmp.bmHeight) ) return false;

	HDC hdcMem = CreateCompatibleDC(NULL);
	
	SelectObject(hdcMem, hbmp);
	GetDIBits(hdcMem, hbmp, 0, bmp.bmHeight, m_ptr, &m_bmpInfo, 0);
	DeleteDC(hdcMem);

	return true;
}

void CGDISurface::Release()
{
	if (m_hdc) DeleteDC(m_hdc);
}

void CGDISurface::Clear( COLORREF c )
{
	memset(m_ptr,c,m_bmpInfo.bmiHeader.biSizeImage);
}

void CGDISurface::SetPixel(int x, int y, WORD c )
{
	assert((x >= 0) && (x < m_width) && (y >= 0) && (y < m_height));
	WORD *dst = (WORD *)m_ptr + x + y * (m_pitch>>1);
	*dst = c;
 //printf("%s, %d x %d, y %d\n", __FUNCTION__, __LINE__, x, y); ;

}
WORD CGDISurface::GetPixel(int x, int y)
{
	assert((x >= 0) && (x < m_width) && (y >= 0) && (y < m_height));
	WORD *dst = (WORD *)m_ptr + x + y * (m_pitch>>1);
	return *dst;
}

void CGDISurface::DrawLine_v1(int xStart, int yStart, int xEnd, int yEnd, WORD c )
{
    if (!((xStart >= 0) && (xStart < m_width) && (yStart >= 0) && (yStart < m_height))
        || !((xEnd >= 0) && (xEnd < m_width) && (yEnd >= 0) && (yEnd < m_height)))
    {
        printf("err: DrawLine_v1 (%d, %d) (%d, %d) (%d, %d)\n", xStart, yStart, xEnd, yEnd, m_width, m_height);
    }

	assert((xStart >= 0) && (xStart < m_width) && (yStart >= 0) && (yStart < m_height));
	assert((xEnd >= 0) && (xEnd < m_width) && (yEnd >= 0) && (yEnd < m_height));

	WORD *dst = (WORD *)m_ptr + xStart + yStart * (m_pitch>>1);
    int x = xStart;
    int y = yStart;
    
    int dx = (xEnd - xStart);
    int dy = (yEnd - yStart);

    int x_inc = 1;
    int y_inc = (m_pitch>>1);

    if (dx < 0)
    {
        x_inc = -1;
        dx = -dx; /* 转换为正数,两个原因,一个是下面左移避免最左端的符号位
                                 统一dx的整张单位为正,需要为负时,在算法中置负号;*/
    }

    if (dy < 0)
    {
        y_inc = -y_inc;
        dy = -dy;
    }
    int dx2 = dx << 1;
    int dy2 = dy << 1;
    int error = -dx;
    int index = 0;
    if (dx > dy)
    {
        error = -dx;
        for (; index <= dx; index++)
        {
            //assert(dst >= (WORD*)m_ptr && dst <= ((WORD*)m_ptr + m_width*m_height - 1));

            //SetPixel(x, y, c);
            *dst = c;
            error += dy2;
            if (error > 0)
            {
                error -= dx2;
                //--y;
                dst += y_inc;
            }  
            dst += x_inc;
        }
    }
    else
    {
        error = -dy;
        for (; index <= dy; index++)
        {
            //assert(dst >= (WORD*)m_ptr && dst <= ((WORD*)m_ptr + m_width*m_height - 1));
            //SetPixel(x, y, c);
            *dst = c;
            error += dx2;
            if (error > 0)
            {
                error -= dy2;
                //--y;
                dst += x_inc;
            }  
            dst += y_inc;
        }    
    }
}

void CGDISurface::DrawLine_v1_float(float fxStart, float fyStart, float fxEnd, float fyEnd, WORD c )
{
    DrawLine_v1((int)fxStart, (int)fyStart, (int)fxEnd, (int)fyEnd, c);
    return;
}

int CGDISurface::DrawLineTriangle_v1(POLYF4DV1* pPoly)
{
    D3DXVECTOR4* pV1 = NULL;
    D3DXVECTOR4* pV2 = NULL;
    int j = 0;
    for (; j < 3; j++)
    {
        pV1 = &pPoly->tvlist[j];
        pV2 = &pPoly->tvlist[(j+1)%3];
        DrawLine_v1_float(pV1->x, pV1->y, pV2->x, pV2->y, pPoly->color);
    }

    return ERR_SUCC;
}

void CGDISurface::Blt( CGDISurface *pSurface, int x, int y, int rx, int ry, int w, int h, SurfaceBltMode iMode )
{

}
void CGDISurface::Render(HDC hdc, int x, int y)
{
	BitBlt(hdc,x,y,m_width,m_height,m_hdc,0,0,0xcc0020);
}
