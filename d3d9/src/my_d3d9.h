
#pragma once
#include <objbase.h> 
#include <stdio.h> //just for myself debug
#define MY_XX_USE_MY_HEADER 1
#ifdef MY_XX_USE_MY_HEADER
#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3d9caps.h"
#else
#include "d3d9types.h"
#include "d3d9caps.h"

#endif

#define D3D_SDK_VERSION   32

/****************************************************************************
 *
 * Parameter for IDirect3D9::CreateDevice's Adapter argument
 *
 ****************************************************************************/

#define D3DADAPTER_DEFAULT                     0


/****************************************************************************
 *
 * Flags for IDirect3D9::CreateDevice's BehaviorFlags
 *
 ****************************************************************************/
/*
#define D3DCREATE_FPU_PRESERVE                  0x00000002L
#define D3DCREATE_MULTITHREADED                 0x00000004L

#define D3DCREATE_PUREDEVICE                    0x00000010L
*/
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING     0x00000020L
#define D3DCREATE_HARDWARE_VERTEXPROCESSING     0x00000040L
/*#define D3DCREATE_MIXED_VERTEXPROCESSING        0x00000080L

#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT     0x00000100L
#define D3DCREATE_ADAPTERGROUP_DEVICE           0x00000200L
#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX  0x00000400L
*/


#ifdef __cplusplus
extern "C" {
#endif

typedef interface IDirect3D9                    IDirect3D9;
typedef interface IDirect3DDevice9              IDirect3DDevice9;
//typedef interface IDirect3DStateBlock9          IDirect3DStateBlock9;
//typedef interface IDirect3DVertexDeclaration9   IDirect3DVertexDeclaration9;
//typedef interface IDirect3DVertexShader9        IDirect3DVertexShader9;
//typedef interface IDirect3DPixelShader9         IDirect3DPixelShader9;
typedef interface IDirect3DResource9            IDirect3DResource9;
/*typedef interface IDirect3DBaseTexture9         IDirect3DBaseTexture9;
typedef interface IDirect3DTexture9             IDirect3DTexture9;
typedef interface IDirect3DVolumeTexture9       IDirect3DVolumeTexture9;
typedef interface IDirect3DCubeTexture9         IDirect3DCubeTexture9;*/
typedef interface IDirect3DVertexBuffer9        IDirect3DVertexBuffer9;
//typedef interface IDirect3DIndexBuffer9         IDirect3DIndexBuffer9;
typedef interface IDirect3DSurface9             IDirect3DSurface9;
//typedef interface IDirect3DVolume9              IDirect3DVolume9;
//typedef interface IDirect3DSwapChain9           IDirect3DSwapChain9;
//typedef interface IDirect3DQuery9               IDirect3DQuery9;

/*
 * DLL Function for creating a Direct3D9 object. This object supports
 * enumeration and allows the creation of Direct3DDevice9 objects.
 * Pass the value of the constant D3D_SDK_VERSION to this function, so
 * that the run-time can validate that your application was compiled
 * against the right headers.
 */

IDirect3D9 * WINAPI Direct3DCreate9(UINT SDKVersion);


#undef INTERFACE
#define INTERFACE IDirect3D9

DECLARE_INTERFACE_(IDirect3D9, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
//
//    /*** IDirect3D9 methods ***/
//    STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
//    STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
//    STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier) PURE;
//    STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter,D3DFORMAT Format) PURE;
//    STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode) PURE;
//    STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter,D3DDISPLAYMODE* pMode) PURE;
//    STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed) PURE;
//    STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) PURE;
//    STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels) PURE;
//    STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) PURE;
//    STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) PURE;
//    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) PURE;
    
    #ifdef D3D_DEBUG_INFO
    LPCWSTR Version;
    #endif
};



#undef INTERFACE
#define INTERFACE IDirect3DDevice9

DECLARE_INTERFACE_(IDirect3DDevice9, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
//
//    /*** IDirect3DDevice9 methods ***/
//    STDMETHOD(TestCooperativeLevel)(THIS) PURE;
//    STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) PURE;
//    STDMETHOD(EvictManagedResources)(THIS) PURE;
//    STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PURE;
    STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps) PURE;
//    STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode) PURE;
//    STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters) PURE;
//    STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) PURE;
//    STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags) PURE;
//    STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow) PURE;
//    STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) PURE;
//    STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) PURE;
//    STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS) PURE;
//    STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PURE;
    STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) PURE;
//    STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) PURE;
//    STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) PURE;
//    STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) PURE;
//    STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp) PURE;
//    STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp) PURE;
//    STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) PURE;
//    STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) PURE;
    STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle) PURE;
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
    STDMETHOD(BeginScene)(THIS) PURE;
    STDMETHOD(EndScene)(THIS) PURE;
    STDMETHOD(Clear)(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) PURE;
    STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) PURE;
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
    STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD Value) PURE;
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
    STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) PURE;
//    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
    STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
//    STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
//    STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) PURE;
//    STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) PURE;
//    STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PURE;
//    STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PURE;
    STDMETHOD(SetFVF)(THIS_ DWORD FVF) PURE;
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
    STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) PURE;
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
//    
    #ifdef D3D_DEBUG_INFO
    D3DDEVICE_CREATION_PARAMETERS CreationParameters;
    D3DPRESENT_PARAMETERS PresentParameters;
    D3DDISPLAYMODE DisplayMode;
    D3DCAPS9 Caps;
    
    UINT AvailableTextureMem;
    UINT SwapChains;
    UINT Textures;
    UINT VertexBuffers;
    UINT IndexBuffers;
    UINT VertexShaders;
    UINT PixelShaders;
    
    D3DVIEWPORT9 Viewport;
    D3DMATRIX ProjectionMatrix;
    D3DMATRIX ViewMatrix;
    D3DMATRIX WorldMatrix;
    D3DMATRIX TextureMatrices[8];
    
    DWORD FVF;
    UINT VertexSize;
    DWORD VertexShaderVersion;
    DWORD PixelShaderVersion;
    BOOL SoftwareVertexProcessing;
    
    D3DMATERIAL9 Material;
    D3DLIGHT9 Lights[16];
    BOOL LightsEnabled[16];
    
    D3DGAMMARAMP GammaRamp;
    RECT ScissorRect;
    BOOL DialogBoxMode;
    #endif
};


#undef INTERFACE
#define INTERFACE IDirect3DResource9

DECLARE_INTERFACE_(IDirect3DResource9, IUnknown)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;

    /*** IDirect3DResource9 methods ***/
/*
    STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
    STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
    STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
    STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
    STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
    STDMETHOD_(void, PreLoad)(THIS) PURE;
    STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;
*/
};

typedef struct IDirect3DResource9 *LPDIRECT3DRESOURCE9, *PDIRECT3DRESOURCE9;


#undef INTERFACE
#define INTERFACE IDirect3DVertexBuffer9

DECLARE_INTERFACE_(IDirect3DVertexBuffer9, IDirect3DResource9)
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
//
//    /*** IDirect3DResource9 methods ***/
//    STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
//    STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
//    STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
//    STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
//    STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
//    STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
//    STDMETHOD_(void, PreLoad)(THIS) PURE;
//    STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;
    STDMETHOD(Lock)(THIS_ UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) PURE;
    STDMETHOD(Unlock)(THIS) PURE;
    STDMETHOD(GetDesc)(THIS_ D3DVERTEXBUFFER_DESC *pDesc) PURE;
    
    #ifdef D3D_DEBUG_INFO
    LPCWSTR Name;
    UINT Length;
    DWORD Usage;
    DWORD FVF;
    D3DPOOL Pool;
    DWORD Priority;
    UINT LockCount;
    LPCWSTR CreationCallStack;
    #endif
};
    
typedef struct IDirect3DVertexBuffer9 *LPDIRECT3DVERTEXBUFFER9, *PDIRECT3DVERTEXBUFFER9;

typedef interface IDirect3D9                    IDirect3D9;
typedef interface IDirect3DDevice9              IDirect3DDevice9;


#ifdef __cplusplus
}; // for extern "C" {
#endif

