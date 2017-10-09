
#include <stdafx.h>
#include "screen.h"
#include "my_math.h"

CScreen::CScreen()
{
    D3DXMatrixIdentity(&m_ScreenMatrix);    
}

CScreen::~CScreen()
{
}

void CScreen::SetTransform(CONST D3DMATRIX* pMatrix)
{
    m_ScreenMatrix = *pMatrix;

}
int CScreen::SetViewport(int w, int h)
{
    m_Width = w;
    m_Height = h;
    return ERR_SUCC;
}
void CScreen::Transform(RENDERLIST4DV1* renderList)
{
D3DXMATRIX Out;
BuildScreenMatrix(&Out);
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;
    for (; i < renderList->num_polys; i++)
    {
        p = &renderList->poly_data[i];
        for (; j < 4; j++)
        {
            //Mat_Mul_VECTOR4D_4X4(&(p->tvlist[j]), &m_ScreenMatrix, &(p->tvlist[j]));
            //p->tvlist[j] = m_ScreenMatrix * p->tvlist[j];
            D3DXVec4Transform(&(p->tvlist[j]),  &(p->tvlist[j]), &m_ScreenMatrix);

        }
    }
printf("BuildScreenMatrix\n");
printf("m_Width = %d   // %f\n", m_Width, (float)m_Width);
D3DXMATRIX_PRINTF(&m_ScreenMatrix);
    return;
}

int CScreen::BuildScreenMatrix(D3DXMATRIX* pOut)
{
    float alpha = (float)((m_Width - 1)*0.5);
    float theta = (float)((m_Height - 1)*0.5);
    pOut->_11 = alpha; pOut->_12 = 0;      pOut->_13 = 0; pOut->_14 = 0;
    pOut->_21 = 0;     pOut->_22 = -theta; pOut->_23 = 0; pOut->_24 = 0;
    pOut->_31 = 0;     pOut->_32 =0;       pOut->_33 = 1; pOut->_34 = 0;
    pOut->_41 = alpha; pOut->_42 = theta;  pOut->_43 = 0; pOut->_44 = 1;

    m_ScreenMatrix = *pOut;
printf("BuildScreenMatrix\n");
D3DXMATRIX_PRINTF(pOut);
    return ERR_SUCC;

}

