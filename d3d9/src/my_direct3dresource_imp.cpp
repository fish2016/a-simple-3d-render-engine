
#include <stdafx.h>

#include "my_direct3ddevice_imp.h"



HRESULT my_Direct3Drrr::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
    return NULL;
};

ULONG my_Direct3Drrr::AddRef(THIS) 
{
    return 0;
};

ULONG my_Direct3Drrr::Release(THIS)
{
    return 0;

};


//    /*** IDirect3DDevice9 methods ***/
//    STDMETHOD(TestCooperativeLevel)(THIS) PURE;
//    STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) PURE;
//    STDMETHOD(EvictManagedResources)(THIS) PURE;
//    STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PURE;
HRESULT my_Direct3Drrr::GetDeviceCaps(THIS_ D3DCAPS9* pCaps)
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
HRESULT my_Direct3Drrr::Present(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
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
HRESULT my_Direct3Drrr::CreateVertexBuffer(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
{
    return NULL;

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
HRESULT my_Direct3Drrr::BeginScene(THIS)
{
    return NULL;

}
HRESULT my_Direct3Drrr::EndScene(THIS)
{
    return NULL;

}
HRESULT my_Direct3Drrr::Clear(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) 
{
    return NULL;

}
HRESULT my_Direct3Drrr::SetTransform(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) 
{
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
HRESULT my_Direct3Drrr::SetRenderState(THIS_ D3DRENDERSTATETYPE State,DWORD Value) 
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
HRESULT my_Direct3Drrr::DrawPrimitive(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{
    return NULL;

}
//    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
HRESULT my_Direct3Drrr::DrawPrimitiveUP(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
    return NULL;

}
//    STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
//    STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) PURE;
//    STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) PURE;
//    STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PURE;
//    STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PURE;
HRESULT my_Direct3Drrr::SetFVF(THIS_ DWORD FVF)
{
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
HRESULT my_Direct3Drrr::SetStreamSource(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
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

