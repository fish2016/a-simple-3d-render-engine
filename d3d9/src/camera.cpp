
#include <stdafx.h>
#include "camera.h"
#include "my_math.h"
CCamera::CCamera()
{
    D3DXMatrixIdentity(&m_CameraMatrix);    
}

CCamera::~CCamera()
{
}

void CCamera::SetTransform(CONST D3DMATRIX* pMatrix)
{
    m_CameraMatrix = *pMatrix;
}

void CCamera::Transform(RENDERLIST4DV1* renderList)
{
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;
    for (; i < renderList->num_polys; i++)
    {
        p = &renderList->poly_data[i];
        for (; j < 4; j++)
        {
            //Mat_Mul_VECTOR4D_4X4(&(p->tvlist[j]), &m_CameraMatrix, &(p->tvlist[j]));
            //p->tvlist[j] = m_CameraMatrix * p->tvlist[j];
            D3DXVec4Transform(&(p->tvlist[j]),  &(p->tvlist[j]), &m_CameraMatrix);            

        }
    }

}
