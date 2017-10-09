
#pragma once
#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3d9caps.h"

//#include "rendersystem.h"
#include "renderlist.h"

class ITransform
{
public:
    void SetTransform(CONST D3DMATRIX* pMatrix);
    void Transform(RENDERLIST4DV1* renderList);
};

#define DECLEAR_ITRANSFER_INTF void SetTransform(CONST D3DMATRIX* pMatrix); \
                               void Transform(RENDERLIST4DV1* renderList)



