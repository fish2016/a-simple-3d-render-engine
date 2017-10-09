
#include <stdafx.h>
#include "world.h"
#include "my_math.h"

CWorld::CWorld()
{
    D3DXMatrixIdentity(&m_WorldMatrix);    
};

CWorld::~CWorld()
{
};

void CWorld::SetTransform(CONST D3DMATRIX* pMatrix)
{
    m_WorldMatrix = *pMatrix;
}

void CWorld::Transform(RENDERLIST4DV1* rend_list)
{
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;
    for (; i < rend_list->num_polys; i++)
    {
        p = &(rend_list->poly_data[i]);
        for (; j < 4; j++)
        {
            //Mat_Mul_VECTOR4D_4X4(&(p->vlist[j]), &m_WorldMatrix, &(p->tvlist[j]));
            //p->vlist[j] = m_WorldMatrix * p->tvlist[j];
            D3DXVec4Transform(&(p->tvlist[j]),  &(p->vlist[j]), &m_WorldMatrix);
        }
    }
    return;
}
