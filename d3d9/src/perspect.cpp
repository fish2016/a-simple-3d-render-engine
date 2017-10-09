
#include <stdafx.h>
#include "perspect.h"
#include "my_math.h"

CPerspect::CPerspect()
{
    D3DXMatrixIdentity(&m_PerspectMatrix);    
}

CPerspect::~CPerspect()
{
}

void CPerspect::SetTransform(CONST D3DMATRIX* pMatrix)
{
    m_PerspectMatrix = *pMatrix;
}

void CPerspect::Transform(RENDERLIST4DV1* renderList)
{
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;
    for (; i < renderList->num_polys; i++)
    {
        p = &renderList->poly_data[i];
        for (; j < 4; j++)
        {
            //Mat_Mul_VECTOR4D_4X4(&p->tvlist[j], &m_PerspectMatrix, &p->tvlist[j]);
            //p->tvlist[j] = m_PerspectMatrix * p->tvlist[j];
            D3DXVec4Transform(&(p->tvlist[j]),  &(p->tvlist[j]), &m_PerspectMatrix);
            p->tvlist[j].x /= p->tvlist[j].w;
            p->tvlist[j].y /= p->tvlist[j].w;
            p->tvlist[j].z /= p->tvlist[j].w;
            p->tvlist[j].w /= p->tvlist[j].w;

        }
    }
    D3DXMATRIX_PRINTF(&m_PerspectMatrix);
    return;
}

