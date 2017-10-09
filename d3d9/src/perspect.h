
#pragma once
#include "itransform.h"


class CPerspect : public ITransform
{
public:
    DECLEAR_ITRANSFER_INTF;
public:
    CPerspect();
    ~CPerspect();

protected:
    D3DXMATRIX m_PerspectMatrix;
};




