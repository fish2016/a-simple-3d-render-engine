#pragma once

#include "itransform.h"

class CScreen : public ITransform
{
public:
    DECLEAR_ITRANSFER_INTF;
    CScreen::CScreen();
    CScreen::~CScreen();
    int BuildScreenMatrix(D3DXMATRIX* matrix);
    int SetViewport(int w, int h);
protected:
    D3DXMATRIX m_ScreenMatrix;
    int m_Width;
    int m_Height;
};


