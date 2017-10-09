
#include <stdafx.h>

#include "my_direct3d_imp.h"
#include "my_direct3ddevice_imp.h"



HRESULT my_Direct3D9::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
    return NULL;
};

ULONG my_Direct3D9::AddRef(THIS) 
{
    return 0;
};

ULONG my_Direct3D9::Release(THIS)
{
    return 0;

};


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
HRESULT my_Direct3D9::GetDeviceCaps(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) 
{
    return NULL;

}
//    STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;


/*
Adapter：
序数所指示的显示器适配器。D3DADAPTER_DEFAULT始终是主要的显示器适配器。

DeviceType：
在D3DDEVTYPE列举的成员,表示预设类型的驱动器类型,在HAL(Hardware Accelerator，
硬件加速)和REF(Reference Rasterizer，一调试工具)之间选择。
这里有第三个选项，软件渲染，作用是设计能支持自定义渲染的插件。
DirectX DDK(驱动程序开发工具包)就能做到，但如果你能自己写出3D渲染器的话，
是不太可能使用VB的J……请指定参数D3DDEVTYPE_HAL（硬件加速）或D3DDEVTYPE_REF(软件模拟) 。,
如果预设的设备类型是无效的，即如果不支持硬件加速，调用此函数就会失败，
你就不能创建设备。

hFocusWindow：
与设备相关的窗口句柄，你想在哪个窗口绘制就写那个窗口的句柄

BehaviorFlags：
设定为D3DCREATE_SOFTWARE_VERTEXPROCESSING(软件顶点处理) 
或者D3DCREATE_HARDWARE_VERTEXPROCESSING(硬件顶点处理) ,
使用前应该用d3dcaps来检测用户计算机是否支持硬件顶点处理功能。

PresentationParameters：
一个D3DPRESENT_PARAMETERS 类型的变量，用于指定将要创建设备的各种信息

ppReturnedDeviceInterface：
一个DIRECT3DDEVICE9类型的指针用来返回创建的设备


PS:
一如果一块显卡支持硬件顶点处理的话，也就是说它支持硬件几何变换和光照计算。

二
D3DDEVTYPE_HAL(硬件抽向层），着色，包括变形、光照由硬件、软件，或软硬件混合处理。

D3DDEVTYPE_REF，着色由最优化的软件处理。尽可能利用矢量、单指令及CPU指令并行等。

D3DDEVTYPE_SW，由一个已用RegisterSoftwareDevice注册过的嵌入式软件设备处理。
D3DDEVTYPE_SW            = 3,使用插件的软渲染，插件要用，IDirect3D9::RegisterSoftwareDevice注册

参考
http://blog.csdn.net/leonwei/article/details/8212570

*/
HRESULT my_Direct3D9::CreateDevice(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,
                                       D3DPRESENT_PARAMETERS* pPresentationParameters,
                                       IDirect3DDevice9** ppReturnedDeviceInterface) 
{
    my_Direct3DDevice9* p = NULL;

    //参数校验
    if (Adapter >= MAX_CAPS_ADAPTER_NUM) //因为是软件渲染，所以只须保存这个值，没有对应的硬件显卡
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return HRESULT_FAIL;
    }

    if (m_aDevice[Adapter] != NULL) 
    {
        LOG_PRINTF("PARA ERR \n" );
        return HRESULT_FAIL;
    }


    //创建对象
    p = my_Direct3DDevice9::Create(Adapter, DeviceType,hFocusWindow,BehaviorFlags,
                                                   pPresentationParameters,
                                                   ppReturnedDeviceInterface);
    CHK_MEM_RET_ERR(p);

    m_aDevice[Adapter] = p;
    *ppReturnedDeviceInterface = p;
    return HRESULT_SUCC;

}



//protected function


my_Direct3D9::my_Direct3D9()
{
    int i = 0;
    for (i = 0;i < MAX_CAPS_ADAPTER_NUM; i++)
    {
        m_aDevice[i] = NULL;
    }
}
my_Direct3D9::~my_Direct3D9()
{
    int i = 0;
    for (i = 0;i < MAX_CAPS_ADAPTER_NUM; i++)
    {
        if (m_aDevice[i] != NULL)
        {
            my_Direct3DDevice9::Destroy(m_aDevice[i]);
            m_aDevice[i] = NULL;
        }
    }
}

