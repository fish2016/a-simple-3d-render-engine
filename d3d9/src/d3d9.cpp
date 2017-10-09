
#include <stdafx.h>
#include "my_xx_types.h"
//#ifdef MY_XX_USE_MY_HEADER

#include "my_d3d9.h"
#include "my_d3dx9math.h"
#include "my_direct3d_imp.h"
IDirect3D9 * WINAPI Direct3DCreate9(UINT SDKVersion)
{
    AllocConsole();
    freopen("CONOUT$","w+t",stdout);
    freopen("CONIN$","r+t",stdin);
TRACE_FUNC;
    IDirect3D9* pIDirect3D9 = NULL;
    if (D3D_SDK_VERSION != SDKVersion)
    {
        return NULL;
    }
    pIDirect3D9 = new my_Direct3D9;
    return pIDirect3D9;
}

#if 0
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf )
{
    return NULL;
}
#endif

