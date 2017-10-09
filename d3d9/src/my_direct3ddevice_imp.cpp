
#include <stdafx.h>
#include "my_xx_types.h"
#include "my_direct3d_imp.h"
#include "my_direct3ddevice_imp.h"
#include "my_direct3dvertexbuffer_imp.h"



HRESULT my_Direct3DDevice9::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
    return NULL;
};

ULONG my_Direct3DDevice9::AddRef(THIS) 
{
    return 0;
};

ULONG my_Direct3DDevice9::Release(THIS)
{
    return 0;

};


//    /*** IDirect3DDevice9 methods ***/
//    STDMETHOD(TestCooperativeLevel)(THIS) PURE;
//    STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) PURE;
//    STDMETHOD(EvictManagedResources)(THIS) PURE;
//    STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PURE;
HRESULT my_Direct3DDevice9::GetDeviceCaps(THIS_ D3DCAPS9* pCaps)
{
    return NULL;
}
//    STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode) PURE;
//    STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters) PURE;
//    STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) PURE;
//    STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags) PURE;
//    STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow) PURE;
//    STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) PURE;
//    STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) PURE;
//    STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS) PURE;
//    STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PURE;
HRESULT my_Direct3DDevice9::Present(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
    m_pRenderSystem->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);

    return NULL;

}
//    STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) PURE;
//    STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) PURE;
//    STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) PURE;
//    STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp) PURE;
//    STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp) PURE;
//    STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) PURE;
my_Direct3DVertexBuffer9 g_my_IDirect3DVertexBuffer9_tmp;
HRESULT my_Direct3DDevice9::CreateVertexBuffer(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
{
    *ppVertexBuffer = static_cast<IDirect3DVertexBuffer9*>(my_Direct3DVertexBuffer9::Create(Length, Usage, FVF, Pool, pSharedHandle));
    if (ppVertexBuffer == NULL)
    {
        return HRESULT_FAIL;

    }
    return HRESULT_SUCC;

}
//    STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateRenderTarget)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint) PURE;
//    STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) PURE;
//    STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface) PURE;
//    STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain,IDirect3DSurface9* pDestSurface) PURE;
//    STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter) PURE;
//    STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color) PURE;
//    STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget) PURE;
//    STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget) PURE;
//    STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil) PURE;
//    STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) PURE;
HRESULT my_Direct3DDevice9::BeginScene(THIS)
{
    return NULL;

}
HRESULT my_Direct3DDevice9::EndScene(THIS)
{
    return NULL;

}
HRESULT my_Direct3DDevice9::Clear(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) 
{
    ASSERT(m_pRenderSystem);
    m_pRenderSystem->Clear(Count, pRects, Flags, Color, Z, Stencil);
    return NULL;

}
HRESULT my_Direct3DDevice9::SetTransform(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) 
{
TRACE_FUNC;
    m_pRenderSystem->SetTransform(State, pMatrix);
    return NULL;

}
//    STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) PURE;
//    STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) PURE;
//    STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport) PURE;
//    STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport) PURE;
//    STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial) PURE;
//    STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial) PURE;
//    STDMETHOD(SetLight)(THIS_ DWORD Index,CONST D3DLIGHT9*) PURE;
//    STDMETHOD(GetLight)(THIS_ DWORD Index,D3DLIGHT9*) PURE;
//    STDMETHOD(LightEnable)(THIS_ DWORD Index,BOOL Enable) PURE;
//    STDMETHOD(GetLightEnable)(THIS_ DWORD Index,BOOL* pEnable) PURE;
//    STDMETHOD(SetClipPlane)(THIS_ DWORD Index,CONST float* pPlane) PURE;
//    STDMETHOD(GetClipPlane)(THIS_ DWORD Index,float* pPlane) PURE;
HRESULT my_Direct3DDevice9::SetRenderState(THIS_ D3DRENDERSTATETYPE State,DWORD Value) 
{
    return NULL;

}
//    STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue) PURE;
//    STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB) PURE;
//    STDMETHOD(BeginStateBlock)(THIS) PURE;
//    STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB) PURE;
//    STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus) PURE;
//    STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus) PURE;
//    STDMETHOD(GetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9** ppTexture) PURE;
//    STDMETHOD(SetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9* pTexture) PURE;
//    STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) PURE;
//    STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) PURE;
//    STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue) PURE;
//    STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value) PURE;
//    STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses) PURE;
//    STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries) PURE;
//    STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries) PURE;
//    STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber) PURE;
//    STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT *PaletteNumber) PURE;
//    STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect) PURE;
//    STDMETHOD(GetScissorRect)(THIS_ RECT* pRect) PURE;
//    STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware) PURE;
//    STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS) PURE;
//    STDMETHOD(SetNPatchMode)(THIS_ float nSegments) PURE;
//    STDMETHOD_(float, GetNPatchMode)(THIS) PURE;
HRESULT my_Direct3DDevice9::DrawPrimitive(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{
#if 0
int ii = 0;
int jj = 0;
static WORD c = RGB(0, 0, 0);
static WORD c1 = RGB(255, 0, 0);
static WORD c2 = RGB(0, 250, 0);
static WORD c3 = RGB(0, 0, 250);
static WORD c4 = RGB(100, 100, 100);
static WORD count = 0;
if (count++ > 300)
{
    count = 0;
}
#if 0
switch (count % 5)
    {
        case 0:
            c = c1;
            break;
        case 1:
            c = c2;
            break;
        case 2:
            c = c3;
            break;
        case 3:
            c = c3;
            break;
        case 4:
            c = c4;
            break;
    }
#endif
#if 1
switch (count)
    {
        case 60:
            c = c1;
            break;
        case 120:
            c = c2;
            break;
        case 180:
            c = c3;
            break;
        case 220:
            c = c3;
            break;
        case 290:
            c = c4;
            break;
    }
#endif
for (ii = 0; ii < 640; ii++)
{
    for (jj = 0; jj < 480; jj++)
    {
        m_pCGDISurface->SetPixel(ii, jj, c);
    }

}
#endif

#ifdef test_for_draw
//static WORD c3 = RGB(255, 0, 0);
static WORD c = RGB(0, 0, 0);
static WORD c1 = RGB(255, 0, 0);
static WORD c2 = RGB(0, 250, 0);
static WORD c3 = RGB(0, 0, 250);
static WORD c4 = RGB(100, 100, 100);
//m_pCGDISurface->DrawLine_v1(100, 400, 400, 300, c3);
//m_pCGDISurface->DrawLine_v1(400, 300, 100, 400, c3);
//m_pCGDISurface->DrawLine_v1(400, 300, 100, 300, c3);
int h = m_ClientRect.bottom - 1;
m_pCGDISurface->DrawLine_v1(0, 0, h, h, c1 );


m_pCGDISurface->DrawLine_v1(h, 0, 0, h, c1 );


m_pCGDISurface->DrawLine_v1(0, 0, 0, h, c1 );

m_pCGDISurface->DrawLine_v1(h, h, h, 0, c1 );

m_pCGDISurface->DrawLine_v1(h, h, h, 0, c1 );
//
m_pCGDISurface->DrawLine_v1(0, 239, h, 239, c1 );

m_pCGDISurface->DrawLine_v1(239, 0, 239, h, c1 );

m_pCGDISurface->DrawLine_v1(0, h, h, 239, c1 );

m_pCGDISurface->DrawLine_v1(239, 0, 0, h, c1 );

m_pCGDISurface->DrawLine_v1(239, 0, 0, h, c1 );

m_pCGDISurface->DrawLine_v1(0, 239, h, h, c1 );

#endif

    //目前先只支持这3 种
    ASSERT((D3DPT_POINTLIST == PrimitiveType) 
        || (D3DPT_LINELIST == PrimitiveType)
        || (D3DPT_TRIANGLELIST == PrimitiveType));

    int i = 0;
    int j = 0;
    UINT stepVertexNum = 0;
    UINT processVertexNum = 0;
    CSTREAM* pstream = NULL;
    BYTE* pCurrentData = NULL;

    switch (PrimitiveType)
    {
        case D3DPT_POINTLIST:
            stepVertexNum = 1;   
            processVertexNum = 1;    
            break;

        case D3DPT_LINELIST:
            stepVertexNum = 2;       
            processVertexNum = 2; 
            break;

        case D3DPT_TRIANGLELIST:
            stepVertexNum = 3;  
            processVertexNum = 3;      
            break;

        default:
            break;
    }
#if 1
    for (i = 0; i < MAX_STREAM_NUM; i++)
    {
        pstream = &m_stream[i];
        if (false == m_stream[i].IsValid())
        {
            continue;
        }

        pstream->SetVertexNumOfBlock(processVertexNum);
        //pstream->SetTraverseParam(stepVertexNum);
        
        for (pCurrentData = pstream->Begin(), j = 0;
             !pstream->IsEnd(); 
             pstream->NextBlock(), j++)
        {
            pCurrentData = pstream->Current();
            m_pRenderSystem->InsertRenderList(pCurrentData, pstream->ElementSize(), m_FVF, pstream->GetVertexNumOfBlock());
        }
        
    }
#endif

m_FVF;
//m_pRenderSystem->PrintRenderList();
    m_pRenderSystem->Render();
    //m_pRenderSystem->ClearRenderList();
    return NULL;

}
//    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
HRESULT my_Direct3DDevice9::DrawPrimitiveUP(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
    return NULL;

}
//    STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
//    STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) PURE;
//    STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) PURE;
//    STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PURE;
//    STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PURE;
HRESULT my_Direct3DDevice9::SetFVF(THIS_ DWORD FVF)
{
    //only support D3DFVF_XYZ \ D3DFVF_DIFFUSE
    ASSERT((FVF & (~(D3DFVF_XYZ | D3DFVF_DIFFUSE))) == 0);
    m_FVF = FVF;
    return NULL;

}
//    STDMETHOD(GetFVF)(THIS_ DWORD* pFVF) PURE;
//    STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader) PURE;
//    STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader) PURE;
//    STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader) PURE;
//    STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
//    STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
//    STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
//    STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
//    STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) PURE;
//    STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
HRESULT my_Direct3DDevice9::SetStreamSource(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
TRACE_FUNC;
    //printf("%s, %d\n", __FUNCTION__, __LINE__);

    m_stream[StreamNumber].SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
    return NULL;
}
//    STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride) PURE;
//    STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT Setting) PURE;
//    STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT* pSetting) PURE;
//    STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData) PURE;
//    STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData) PURE;
//    STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader) PURE;
//    STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader) PURE;
//    STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader) PURE;
//    STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
//    STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
//    STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
//    STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
//    STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount) PURE;
//    STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
//    STDMETHOD(DrawRectPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo) PURE;
//    STDMETHOD(DrawTriPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo) PURE;
//    STDMETHOD(DeletePatch)(THIS_ UINT Handle) PURE;
//    STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) PURE;



//add below
my_Direct3DDevice9* my_Direct3DDevice9::Create(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,
                                DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,
                                IDirect3DDevice9** ppReturnedDeviceInterface)
{
TRACE_FUNC;
    int iRet = ERR_SUCC;
    my_Direct3DDevice9* p_my_Direct3DDevice9 = NULL;


    p_my_Direct3DDevice9 = new my_Direct3DDevice9();
    CHK_MEM_RET_NULL(p_my_Direct3DDevice9);
    
    iRet = p_my_Direct3DDevice9->Init(Adapter,DeviceType,hFocusWindow,
                                BehaviorFlags,pPresentationParameters,
                                ppReturnedDeviceInterface);
    CHK_RET_NULL_RELEASE_MEM(iRet, p_my_Direct3DDevice9);

    return p_my_Direct3DDevice9;
}

int my_Direct3DDevice9::Destroy(my_Direct3DDevice9* p_my_Direct3DDevice9)
{
TRACE_FUNC;
    delete p_my_Direct3DDevice9;
    return ERR_SUCC;
}

int my_Direct3DDevice9::Init(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,
                                DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,
                                IDirect3DDevice9** ppReturnedDeviceInterface)
{
    TRACE_FUNC;
    //参数校验
    if (Adapter >= MAX_CAPS_ADAPTER_NUM) //因为是软件渲染，所以只须保存这个值，没有对应的硬件显卡
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return ERR_FAIL;
    }

    if (DeviceType != D3DDEVTYPE_HAL
        && DeviceType != D3DDEVTYPE_REF
        && DeviceType != D3DDEVTYPE_SW
        && DeviceType != D3DDEVTYPE_NULLREF)
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return ERR_FAIL;
    }

    if (NULL == hFocusWindow)
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return ERR_FAIL;
    }

    BehaviorFlags; //不检测，参数多，与本实现无关
    if (ERR_SUCC != check_PresentationParameters(pPresentationParameters))
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return ERR_FAIL;
    }
    int width = 640;
    int height = 480;
    bool bRtn = false;

    bRtn = GetClientRect(hFocusWindow, &m_ClientRect);
    if (false == bRtn)
    {
        LOG_PRINTF("GetClientRect fail \n");
        return ERR_FAIL;
    }
/*
    m_pCGDISurface = new CGDISurface(m_ClientRect.right, m_ClientRect.bottom);
    if (NULL == m_pCGDISurface)
    {
        LOG_PRINTF("new CGDISurface fail \n");
        return ERR_FAIL;    
    }

    printf("%s, %d: create surface success, width = %d, bottom = %d\n", __FUNCTION__, __LINE__,
                                                            m_ClientRect.right, m_ClientRect.bottom);*/

    //save for CreateDevice begin
    m_Adapter = Adapter;
    m_DeviceType = DeviceType;
    m_hFocusWindow = hFocusWindow;
    m_BehaviorFlags = BehaviorFlags;
    m_PresentationParameters = *pPresentationParameters; 
    //save for CreateDevice end
    int iRtn = ERR_SUCC;
    m_pRenderSystem = CRendersystem::Create();
    CHK_MEM_RET_ERR(m_pRenderSystem);
    iRtn = m_pRenderSystem->Init(width, height, hFocusWindow);
    CHK_COND_RET_ERR(ERR_SUCC == iRtn);
    TRACE_FUNC;
    //m_pRenderSystem->CreateBackSurfce(int width,int height);
    return ERR_SUCC;
}

/*
让我们来看看DirectX的API文档
BackBufferFormat

The back buffer format. For more information about formats, see D3DFORMAT.
 This value must be one of the render-target formats as validated by IDirect3D9::CheckDeviceType. 
You can use IDirect3DDevice9::GetDisplayMode to obtain the current format.
关于背景缓冲格式。更多的信息请参阅D3DFORMAT。
这个值必须属于可用的IDirect3D9::CheckDeviceType渲染-目标格式。
你可以通过使用IDirect3DDevice9::GetDisplayMode 来获取当前格式。
 
In fact, D3DFMT_UNKNOWN can be specified for the BackBufferFormat while in windowed mode. 
This tells the runtime to use the current display-mode format and eliminates the need to call IDirect3DDevice9::GetDisplayMode.

         事实上，D3DFMT_UNKNOWN可以用来使用当在窗口模式下时，
这会告诉计算机去使用当前的显示模式格式从而避免去调用IDirect3DDevice9::GetDisplayMode

For windowed applications, the back buffer format no longer needs to match the display-mode format 
because color conversion can now be done by the hardware (if the hardware supports color conversion). 
The set of possible back buffer formats is constrained, but the runtime will allow any valid back buffer format 
to be presented to any desktop format. (There is the additional requirement that the device be operable in the desktop mode; 
devices typically do not operate in 8 bits per pixel modes.)

Full-screen applications cannot do color conversion.

对于窗口应用程序，背景缓冲格式不再需要去符合显示模式格式
因为颜色变化现在会被硬件完成(如果硬件支持颜色转换)。
这样可能使背景缓冲格式受到限制，
但是计算机将会允许任何有效的背景缓冲格式出现在任何的桌面格式
(这里有一个附加要求device必须是可操作的在桌面模式中，device通常不会操作在8位像素模式)。

对于全屏程序是不需要颜色转换的
*/
int my_Direct3DDevice9::check_PresentationParameters(const D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    /*
        back buffer的长宽注意如果是全屏模式必须等于显卡的其中一种分辨率
        如果是窗口不填就用这个窗口的大小*/


    /*--backbuffer的格式（主要是颜色格式），必须与当前的render target相同。
        在窗口模式D3DFMT_UNKNOWN可以直接使用去匹配当前的显示格式，全屏不行*/

    /*
          HWND                hDeviceWindow; --窗口；窗口模式，就是显示的窗口，如果null，则使用当前的激活窗口。
        全屏模式，主显示器使用当前的激活窗口，其他显示器必须使用一个确定的窗口。
        当窗口重置时back buffer不会被重置。
        */

    pPresentationParameters->Windowed;

    /* UINT                FullScreen_RefreshRateInHz;--全屏时硬件刷新屏幕的频率，
    EnumAdapterModes返回的模式中选其一，窗口模式要填0，*/
    pPresentationParameters->FullScreen_RefreshRateInHz;

    return ERR_SUCC;
}




