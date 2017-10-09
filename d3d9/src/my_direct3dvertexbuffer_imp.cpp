
#include <stdafx.h>
#include "my_xx_types.h"
#include "my_direct3dvertexbuffer_imp.h"



HRESULT my_Direct3DVertexBuffer9::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
    return NULL;
};

ULONG my_Direct3DVertexBuffer9::AddRef(THIS) 
{
    return 0;
};

ULONG my_Direct3DVertexBuffer9::Release(THIS)
{
    delete this;
    return 0;

};



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
UINT g_lock_tmp_buff[256];
HRESULT my_Direct3DVertexBuffer9::Lock(THIS_ UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) 
{
#if 0
    AllocConsole();
    freopen("CONOUT$","w+t",stdout);
    freopen("CONIN$","r+t",stdin);

#endif
    //*ppbData = (void*)(&g_lock_tmp_buff[0]);
    *ppbData = (void*)GetBuffer();
    printf("%s, %d %p %p\n", __FUNCTION__, __LINE__, *ppbData, (&g_lock_tmp_buff[0]));

    return 0; //dengjin add for debug

    ASSERT(m_pBuffer);
    ASSERT(ppbData);
    ASSERT(OffsetToLock < m_Length);

    ASSERT((OffsetToLock + SizeToLock) <= m_Length);

    if (m_bIsLock != false)
    {
        return HRESULT_FAIL;
    }

    *ppbData = (m_pBuffer + OffsetToLock);
        
    m_bIsLock = true;
    return NULL;

}
HRESULT my_Direct3DVertexBuffer9::Unlock(THIS) 
{
    m_bIsLock = false;
    return NULL;

}
HRESULT my_Direct3DVertexBuffer9::GetDesc(THIS_ D3DVERTEXBUFFER_DESC *pDesc)
{
    ASSERT(pDesc);
    *pDesc = m_Desc;
    return HRESULT_SUCC;
}
IDirect3DVertexBuffer9*  my_Direct3DVertexBuffer9::Create(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,HANDLE* pSharedHandle)
{
    int iRet = ERR_SUCC;
    my_Direct3DVertexBuffer9* p = NULL;


    p = new my_Direct3DVertexBuffer9();
    CHK_MEM_RET_NULL(p);
    
    iRet = p->Init(Length,Usage, FVF, Pool, pSharedHandle);
    
    CHK_RET_NULL_RELEASE_MEM(iRet, p);

    return p;
}

int my_Direct3DVertexBuffer9::Destry(my_Direct3DVertexBuffer9* p)
{
    delete p;
    return ERR_SUCC;
}

int  my_Direct3DVertexBuffer9::Init(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,HANDLE* pSharedHandle)
{
    ASSERT(!m_pBuffer);
    if (m_pBuffer)
    {
        delete m_pBuffer;
        m_pBuffer = NULL;
    }
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    m_pBuffer = new BYTE[Length];
    //Name;
    m_Length = Length;
    m_Usage = Usage;
    m_FVF = FVF;
    m_Pool = Pool;
    m_Priority;
    m_LockCount;
    //CreationCallStack;

    #ifdef D3D_DEBUG_INFO
    Name;
    Length = Length;
    Usage = Usage;
    FVF = FVF;
    Pool = Pool;
    Priority;
    LockCount;
    CreationCallStack;
    #endif

    m_Desc.Format;
    m_Desc.Type = D3DRTYPE_VERTEXBUFFER;
    m_Desc.Usage = 0; //ÔÝÊ±Ð´0
    m_Desc.Pool = Pool;
    m_Desc.Size = Length;
    m_Desc.FVF = FVF;
    return ERR_SUCC;

}

my_Direct3DVertexBuffer9::my_Direct3DVertexBuffer9()
{
    m_pBuffer = NULL;
    m_bIsLock = false;
}

my_Direct3DVertexBuffer9::~my_Direct3DVertexBuffer9()
{
    if (m_pBuffer)
    {
        delete[] m_pBuffer;
        m_pBuffer = NULL;
    }

}

BYTE* my_Direct3DVertexBuffer9::GetBuffer()
{
    return m_pBuffer;
}
