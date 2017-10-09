
#pragma once

#include <objbase.h> 
#define MY_XX_USE_MY_HEADER 1

#ifdef MY_XX_USE_MY_HEADER

#include "my_d3d9types.h"
#include "my_d3d9caps.h"
#else
#include "d3d9types.h"
#include "d3d9caps.h"

#endif
#include "my_d3d9.h"

struct Vertex
{
	float _x, _y, _z;

};

struct Color
{
	D3DCOLOR _color;
};


struct ColorVertex
{
	ColorVertex(){}

	ColorVertex(float x, float y, float z, D3DCOLOR c)
	{
		_x = x;	 _y = y;  _z = z;  _color = c;
	}

	float _x, _y, _z;
	D3DCOLOR _color;

	static const DWORD FVF;
};
//const DWORD ColorVertex::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;


#if 1
//DECLARE_INTERFACE_(IDirect3DVertexBuffer9, IDirect3DResource9)
class my_Direct3DVertexBuffer9 : public IDirect3DVertexBuffer9

{
    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) ;
    STDMETHOD_(ULONG,AddRef)(THIS) ;
    STDMETHOD_(ULONG,Release)(THIS) ;
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
    STDMETHOD(Lock)(THIS_ UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) ;
    STDMETHOD(Unlock)(THIS) ;
    STDMETHOD(GetDesc)(THIS_ D3DVERTEXBUFFER_DESC *pDesc);
#if 0    
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
#endif

public:
    static IDirect3DVertexBuffer9* Create(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,HANDLE* pSharedHandle);
    static int Destry(my_Direct3DVertexBuffer9* p);
    int  Init(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,HANDLE* pSharedHandle);

protected:
    //LPCWSTR Name;
    UINT m_Length;
    DWORD m_Usage;
    DWORD m_FVF;
    D3DPOOL m_Pool;
    DWORD m_Priority;
    UINT m_LockCount;
    //LPCWSTR CreationCallStack;

    BYTE* m_pBuffer;
    bool m_bIsLock;
    D3DVERTEXBUFFER_DESC m_Desc;

protected:

public:
    my_Direct3DVertexBuffer9(); //为了先编译通过，先放在public
    ~my_Direct3DVertexBuffer9();
    BYTE* GetBuffer();

};



#endif

