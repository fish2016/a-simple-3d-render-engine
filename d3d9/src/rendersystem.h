
#pragma once

#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3dx9math.h"
#include "GDISurface.h"

#include "itransform.h"
#include "world.h"
#include "camera.h"
#include "perspect.h"
#include "screen.h"

#include "renderlist.h"



class CRendersystem
{
public:
    static CRendersystem* Create();
    static int Destroy();
    int Init(int width,int height, HWND hFocusWindow);

//    STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) PURE;
    void BeginScene() ;
    void EndScene() ;
    void Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) ;
    int SetTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) ;

    void SetRenderState(D3DRENDERSTATETYPE State,DWORD Value);
    void SetFVF(DWORD FVF) ;
    void SetStreamSource(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) ;
    int InsertRenderList(BYTE* pData, UINT VertexSize, DWORD FVF, UINT VertexNum);    
    int CRendersystem::ClearRenderList();
    int Render();
    int Present(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,
                            HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion);
protected:
    CGDISurface* CreateBackSurface(int width,int height);

public:
    CRendersystem();
    ~CRendersystem();

public: //for debug
    int PrintRenderList();

protected:
    RENDERLIST4DV1 rend_list;
    CWorld m_World;
    CCamera m_Camera;
    CPerspect m_Perspect;
    CScreen m_Screen;
    CGDISurface* m_pCGDISurface;
    HDC m_dstHDC;
};









