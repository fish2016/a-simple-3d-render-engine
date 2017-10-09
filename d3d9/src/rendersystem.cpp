
#include <stdafx.h>
#include "my_d3d9.h"
#include "rendersystem.h"


#include "my_direct3dvertexbuffer_imp.h"
CRendersystem* CRendersystem::Create()
{
    CRendersystem* p = new CRendersystem();
    assert(p);
    return p;
}
int CRendersystem::Destroy()
{
    return ERR_SUCC;
}
int CRendersystem::Init(int width,int height, HWND hFocusWindow)
{
    void* p = NULL;
    p = CreateBackSurface(width, height);
    CHK_MEM_RET_ERR(p);

	m_dstHDC = GetDC(hFocusWindow);

    m_Screen.SetViewport(width, height);
    ClearRenderList();
    return ERR_SUCC;
}

CRendersystem::CRendersystem()
{
    memset(&rend_list, 0, sizeof(rend_list));


}

CRendersystem::~CRendersystem()
{
}
int CRendersystem::InsertRenderList(BYTE* pData, UINT VertexSize, DWORD FVF, UINT VertexNum)
{
    ASSERT(pData);
    ASSERT((FVF & D3DFVF_XYZ) != 0); //一定不能等于0
    ASSERT(VertexNum <= 3);  

    Vertex* pVertex = NULL;
    Color*  pColor = NULL;
    BYTE* p;

    POLYF4DV1* pCurrentPoly = NULL; 

    UINT i = 0; 
    //D3DFVF_XYZ
    //D3DFVF_DIFFUSE

    CHK_COND_RET_ERR(rend_list.num_polys < RENDERLIST4DV1_MAX_POLYS);
    CHK_COND_RET_ERR(VertexNum <= 3);

    p = pData;
    pVertex = (Vertex*)pData;
    //printf("rend_list.nuqqqm_polys = %d\n", rend_list.num_polys);

    pCurrentPoly = &rend_list.poly_data[rend_list.num_polys];
    rend_list.num_polys++;
    rend_list.poly_ptrs[rend_list.num_polys] = pCurrentPoly;

    pCurrentPoly->state = 0;
    pCurrentPoly->attr = 0;
    pCurrentPoly->color = 0;

    for (i = 0; i < VertexNum; i++)
    {
        pCurrentPoly->vlist[i].x = ((Vertex*)p)->_x;
        pCurrentPoly->vlist[i].y = ((Vertex*)p)->_y;
        pCurrentPoly->vlist[i].z = ((Vertex*)p)->_z;
        pCurrentPoly->vlist[i].w = 1;
        //if ((FVF & D3DFVF_DIFFUSE) != 0)
        {
            pCurrentPoly->color = 0x00;//暂时这样//*(Color*)(p + sizeof(Vertex));
        }
#ifdef debug_for_rs
static int c = 0;
c++;

        if (c <= 6)
        {
            printf("buf: %p %p: x, y, z %f %f %f, VertexSize %d\n", p, &pCurrentPoly->vlist[i], 
                                (((Vertex*)p)->_x), (((Vertex*)p)->_y), (((Vertex*)p)->_z), VertexSize);
        }
#endif
        p += VertexSize;

    }

    if (rend_list.num_polys == 0)
       {
       // set pointers to null, could loop them around though to self
       rend_list.poly_data[0].next = NULL;
       rend_list.poly_data[0].prev = NULL;
       } // end if
    else
       {
       // first set this node to point to previous node and next node (null)
       rend_list.poly_data[rend_list.num_polys].next = NULL;
       rend_list.poly_data[rend_list.num_polys].prev = 
             &rend_list.poly_data[rend_list.num_polys-1];

       // now set previous node to point to this node
       rend_list.poly_data[rend_list.num_polys-1].next = 
              &rend_list.poly_data[rend_list.num_polys];
       } // end else

    return ERR_SUCC;

}

int CRendersystem::ClearRenderList()
{
    rend_list.num_polys = 0;
    return ERR_SUCC;
}

int CRendersystem::PrintRenderList()
{
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;

static int c = 0;
c++;
if (c >= 5)
{
    //return ERR_SUCC;
}
    printf("*** PrintRenderList");
    printf("rend_list.num_polys = %d\n", rend_list.num_polys);

    for (i = 0; i < rend_list.num_polys; i++)
    {
        printf("** poly[%d]:\n", i);

        for (j = 0; j < 4; j++)
        {
            p = &(rend_list.poly_data[i]);
            //printf("buf_start_addr: %p\n", p);
            printf("*vertex[%d] (%f, %f, %f, %f) color = 0x%x\n", j, 
                                p->vlist[j].x, p->vlist[j].y, p->vlist[j].z, p->vlist[j].w, 
                                rend_list.poly_data[i].color);

            printf("*tv        (%f, %f, %f, %f) \n",                                 
                                p->tvlist[j].x, p->tvlist[j].y, p->tvlist[j].z, p->tvlist[j].w);

            /*printf("*vertex[%d] (x, y, z, w) = dd(%d, %d, %d, %d) color = 0x%x\n\n\n", j, p->vlist[j].x, p->vlist[j].y, 
                                                             p->vlist[j].z, p->vlist[j].w, rend_list.poly_data[i].color);*/
        }
    }

    printf("*\n\n");

    return ERR_SUCC;
}


int CRendersystem::Render()
{
    ASSERT(m_pCGDISurface);
    int i = 0;
    int j = 0;
    //D3DXVECTOR4* pV1;
    //D3DXVECTOR4* pV2;
    POLYF4DV1* pPoly = NULL;

    //PrintRenderList(); // for debug
    if (0 == rend_list.num_polys)
    {
        return ERR_SUCC;
    }
static int c = 0;
c++;
if (c >= 2)
{
    //ClearRenderList(); //本轮渲染完毕,清除渲染列表数据

    //return ERR_SUCC;
}
    m_World.Transform(&rend_list);
printf("m_World.Transform(&rend_list);\n");
PrintRenderList();
    m_Camera.Transform(&rend_list);
printf("m_Camera.Transform(&rend_list);\n");
PrintRenderList();

    m_Perspect.Transform(&rend_list);
printf("m_Perspect.Transform(&rend_list);\n");
PrintRenderList();

    m_Screen.Transform(&rend_list);
printf("m_Screen.Transform(&rend_list);\n");
PrintRenderList();

    for (i = 0; i < rend_list.num_polys; i++)
    {
        pPoly = &(rend_list.poly_data[i]);
        m_pCGDISurface->DrawLineTriangle_v1(pPoly);
#if 0
        for (j = 0; j < 2; j++)
        {
            pV1 = &pPoly->tvlist[j];
            pV2 = &pPoly->tvlist[j+1];
            m_pCGDISurface->DrawLine_v1_float(pV1->x, pV1->y, pV2->x, pV2->y, pPoly->color);
        }
#endif
    }
    ClearRenderList(); //本轮渲染完毕,清除渲染列表数据
    return ERR_SUCC;

}

void CRendersystem::BeginScene()
{
}

void CRendersystem::EndScene()
{
}

void CRendersystem::Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
{
    m_pCGDISurface->Clear(Color);
}

int CRendersystem::SetTransform(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    ASSERT(pMatrix);
    if (D3DTS_VIEW == State)
    {
        m_World.SetTransform(pMatrix);
    }    
    else if (D3DTS_VIEW == State)
    {
        m_Camera.SetTransform(pMatrix);
    }
    else if (D3DTS_PROJECTION == State)
    {
        m_Perspect.SetTransform(pMatrix);    
    }
    else
    {
        return ERR_FAIL;
    }

    return ERR_SUCC;

}
CGDISurface* CRendersystem::CreateBackSurface(int width,int height)
{
    m_pCGDISurface = new CGDISurface(width, height);
    if (NULL == m_pCGDISurface)
    {
        LOG_PRINTF("new CGDISurface fail \n");
        return NULL;    
    }


    //printf("%s, %d: create surface success, width = %d, bottom = %d\n", __FUNCTION__, __LINE__,
    //                                                        m_ClientRect.right, m_ClientRect.bottom);
    printf("%s, %d: create surface success, width = %d, bottom = %d\n", __FUNCTION__, __LINE__,
                                                            width, height);
    return m_pCGDISurface;
}

int CRendersystem::Present(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRec,
              HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
    ASSERT(m_dstHDC);
    m_pCGDISurface->Render(m_dstHDC, 0, 0);
    return ERR_SUCC;

}
