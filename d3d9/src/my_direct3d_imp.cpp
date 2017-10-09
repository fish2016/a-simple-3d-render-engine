
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
Adapter��
������ָʾ����ʾ����������D3DADAPTER_DEFAULTʼ������Ҫ����ʾ����������

DeviceType��
��D3DDEVTYPE�оٵĳ�Ա,��ʾԤ�����͵�����������,��HAL(Hardware Accelerator��
Ӳ������)��REF(Reference Rasterizer��һ���Թ���)֮��ѡ��
�����е�����ѡ������Ⱦ�������������֧���Զ�����Ⱦ�Ĳ����
DirectX DDK(�������򿪷����߰�)��������������������Լ�д��3D��Ⱦ���Ļ���
�ǲ�̫����ʹ��VB��J������ָ������D3DDEVTYPE_HAL��Ӳ�����٣���D3DDEVTYPE_REF(���ģ��) ��,
���Ԥ����豸��������Ч�ģ��������֧��Ӳ�����٣����ô˺����ͻ�ʧ�ܣ�
��Ͳ��ܴ����豸��

hFocusWindow��
���豸��صĴ��ھ�����������ĸ����ڻ��ƾ�д�Ǹ����ڵľ��

BehaviorFlags��
�趨ΪD3DCREATE_SOFTWARE_VERTEXPROCESSING(������㴦��) 
����D3DCREATE_HARDWARE_VERTEXPROCESSING(Ӳ�����㴦��) ,
ʹ��ǰӦ����d3dcaps������û�������Ƿ�֧��Ӳ�����㴦���ܡ�

PresentationParameters��
һ��D3DPRESENT_PARAMETERS ���͵ı���������ָ����Ҫ�����豸�ĸ�����Ϣ

ppReturnedDeviceInterface��
һ��DIRECT3DDEVICE9���͵�ָ���������ش������豸


PS:
һ���һ���Կ�֧��Ӳ�����㴦��Ļ���Ҳ����˵��֧��Ӳ�����α任�͹��ռ��㡣

��
D3DDEVTYPE_HAL(Ӳ������㣩����ɫ���������Ρ�������Ӳ�������������Ӳ����ϴ���

D3DDEVTYPE_REF����ɫ�����Ż��������������������ʸ������ָ�CPUָ��еȡ�

D3DDEVTYPE_SW����һ������RegisterSoftwareDeviceע�����Ƕ��ʽ����豸����
D3DDEVTYPE_SW            = 3,ʹ�ò��������Ⱦ�����Ҫ�ã�IDirect3D9::RegisterSoftwareDeviceע��

�ο�
http://blog.csdn.net/leonwei/article/details/8212570

*/
HRESULT my_Direct3D9::CreateDevice(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,
                                       D3DPRESENT_PARAMETERS* pPresentationParameters,
                                       IDirect3DDevice9** ppReturnedDeviceInterface) 
{
    my_Direct3DDevice9* p = NULL;

    //����У��
    if (Adapter >= MAX_CAPS_ADAPTER_NUM) //��Ϊ�������Ⱦ������ֻ�뱣�����ֵ��û�ж�Ӧ��Ӳ���Կ�
    {
        LOG_PRINTF("PARA ERR DeviceType \n");
        return HRESULT_FAIL;
    }

    if (m_aDevice[Adapter] != NULL) 
    {
        LOG_PRINTF("PARA ERR \n" );
        return HRESULT_FAIL;
    }


    //��������
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

