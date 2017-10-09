
#pragma once
//#include "my_d3d9types.h"

#include "itransform.h"




class CWorld : public ITransform
{
public:
    DECLEAR_ITRANSFER_INTF;

public:

    CWorld();
    ~CWorld();

protected:
    D3DXMATRIX m_WorldMatrix;
};

