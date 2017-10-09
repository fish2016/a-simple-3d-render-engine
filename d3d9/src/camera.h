
#pragma once
#include "itransform.h"


class CCamera : public ITransform
{
public:
    DECLEAR_ITRANSFER_INTF;
    CCamera();
    ~CCamera();
protected:
    D3DXMATRIX m_CameraMatrix;
};

