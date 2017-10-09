
#pragma once

#include <objbase.h> 
#define MY_XX_USE_MY_HEADER 1
#include "my_xx_types.h"

#ifdef MY_XX_USE_MY_HEADER

#include "my_d3d9types.h"
#include "my_d3d9caps.h"
#else
#include "d3d9types.h"
#include "d3d9caps.h"

#endif
#include "my_d3d9.h"
#include "my_direct3ddevice_imp.h"


#if 1
//DECLARE_INTERFACE_(IDirect3D9, IUnknown)

#define MAX_CAPS_ADAPTER_NUM 3

class my_Direct3D9 : public IDirect3D9
{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
    STDMETHOD_(ULONG,AddRef)(THIS) ;
    STDMETHOD_(ULONG,Release)(THIS) ;

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
    STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) ;
//    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
    STDMETHOD(CreateDevice)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,
                                DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,
                                IDirect3DDevice9** ppReturnedDeviceInterface) ;
    
    #ifdef D3D_DEBUG_INFO
    LPCWSTR Version;
    #endif

//add 
public:
    my_Direct3D9();

protected:


    my_Direct3DDevice9* m_aDevice[MAX_CAPS_ADAPTER_NUM];
protected:




protected:

public:
    ~my_Direct3D9();



};

#endif

