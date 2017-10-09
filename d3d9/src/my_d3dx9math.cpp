
#include <stdafx.h>

#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3d9caps.h"

#include "my_d3dx9math.h"

//D3DXVECTOR3::D3DXVECTOR3() {};
D3DXVECTOR3::D3DXVECTOR3( CONST FLOAT * )
{
    assert(0); //不实现,因为暂时不知道这个函数的语义
}

D3DXVECTOR3::D3DXVECTOR3( CONST D3DVECTOR& vector3)
{
    this->x = vector3.x;
    this->y = vector3.y;
    this->z = vector3.z;
    return;
}

D3DXVECTOR3::D3DXVECTOR3( CONST D3DXFLOAT16 * )
{
    assert(0); //不实现,因为暂时不知道这个函数的语义
}

D3DXVECTOR3::D3DXVECTOR3( FLOAT x, FLOAT y, FLOAT z )
{
    this->x = x;
    this->y = y;
    this->z = z;
    return;
}


    // casting
D3DXVECTOR3::operator FLOAT* ()
{
    assert(0); //不实现,因为暂时不知道这个函数的语义
    return 0;
}

D3DXVECTOR3::operator CONST FLOAT* () const
{
    assert(0); //不实现,因为暂时不知道这个函数的语义
    return 0;
}


// assignment operators
D3DXVECTOR3& D3DXVECTOR3::operator += ( CONST D3DXVECTOR3& rhs)
{
    //对应方向相加
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return ((*this));
}

D3DXVECTOR3& D3DXVECTOR3::operator -= ( CONST D3DXVECTOR3& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return ((*this));

}

D3DXVECTOR3& D3DXVECTOR3::operator *= ( FLOAT rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return ((*this));

}

D3DXVECTOR3& D3DXVECTOR3::operator /= ( FLOAT rhs)
{
    float oneOverRhs = 1.0f/rhs;    //不进行除零检测


    this->x *= oneOverRhs;
    this->y *= oneOverRhs;
    this->z *= oneOverRhs;
    return ((*this));

}


// unary operators
D3DXVECTOR3 D3DXVECTOR3::operator + () const
{
    return (*this);

}

D3DXVECTOR3 D3DXVECTOR3::operator - () const
{
    //return ((-1)* (*this));
    return D3DXVECTOR3(-(this->x), -(this->y), -(this->z));

}


// binary operators
D3DXVECTOR3 D3DXVECTOR3::operator + ( CONST D3DXVECTOR3& rhs) const
{
    return D3DXVECTOR3((this->x + rhs.x), (this->y + rhs.y), (this->z + rhs.z));
}

D3DXVECTOR3 D3DXVECTOR3::operator - ( CONST D3DXVECTOR3& rhs) const
{
    return D3DXVECTOR3((this->x - rhs.x), (this->y - rhs.y), (this->z - rhs.z));
}

D3DXVECTOR3 D3DXVECTOR3::operator * ( FLOAT rhs) const
//矩阵* 浮点
{
    return D3DXVECTOR3((this->x * rhs), (this->y * rhs), (this->z * rhs));
}

D3DXVECTOR3 D3DXVECTOR3::operator / ( FLOAT rhs) const
{
    float oneOverRhs = 1.0f/rhs;    //不进行除零检测

    return D3DXVECTOR3((this->x * oneOverRhs), (this->y * oneOverRhs), (this->z * oneOverRhs));

}

//浮点 * 矩阵,全局函数实现,这样就不需要修改float类(内置类)
D3DXVECTOR3 operator * ( FLOAT lhs, CONST struct D3DXVECTOR3& rhs)  
{
    return D3DXVECTOR3((lhs*rhs.x), (lhs*rhs.y), (lhs*rhs.z));

}


BOOL D3DXVECTOR3::operator == ( CONST D3DXVECTOR3& rhs) const
{
    if (this->x != rhs.x 
        || this->y != rhs.y 
        || this->z != rhs.z)
    {
        return false;
    }

    return true;

}

BOOL D3DXVECTOR3::operator != ( CONST D3DXVECTOR3& rhs) const
{
    if (this->x != rhs.x 
        || this->y != rhs.y 
        || this->z != rhs.z)
    {
        return true;
    }

    return false;
}




D3DXVECTOR4::D3DXVECTOR4( CONST FLOAT* )
{
    assert(0);
}
D3DXVECTOR4::D3DXVECTOR4( CONST D3DXFLOAT16* )
{
    assert(0);
}
D3DXVECTOR4::D3DXVECTOR4( CONST D3DVECTOR& xyz, FLOAT w )
{
    this->x = xyz.x;
    this->y = xyz.y;
    this->z = xyz.z;   
    this->w = w;     
    return;
}
D3DXVECTOR4::D3DXVECTOR4( FLOAT x, FLOAT y, FLOAT z, FLOAT w )
{
    this->x = x;
    this->y = y;
    this->z = z;   
    this->w = w;  
    return;   
}

    // casting
D3DXVECTOR4::operator FLOAT* ()
{
    assert(0);
    return 0;    
}

D3DXVECTOR4::operator CONST FLOAT* () const
{
    assert(0);
    return 0;    
}

    // assignment operators
D3DXVECTOR4& D3DXVECTOR4::operator += ( CONST D3DXVECTOR4& rhs)
{
    //对应方向相加
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    this->w += rhs.w;
    return (*this);
}

D3DXVECTOR4& D3DXVECTOR4::operator -= ( CONST D3DXVECTOR4& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    this->w -= rhs.w;

    return *this;    
}

D3DXVECTOR4& D3DXVECTOR4::operator *= ( FLOAT rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    this->w *= rhs;
    return ((*this)); 
}

D3DXVECTOR4& D3DXVECTOR4::operator /= ( FLOAT rhs)
{
    float oneOverRhs = 1.0f/rhs;    //不进行除零检测


    this->x *= oneOverRhs;
    this->y *= oneOverRhs;
    this->z *= oneOverRhs;
    this->w *= oneOverRhs;
    return ((*this));}

// unary operators
D3DXVECTOR4 D3DXVECTOR4::operator + () const
{
    return *this;    
}

D3DXVECTOR4 D3DXVECTOR4::operator - () const
{
    return D3DXVECTOR4(-(this->x), -(this->y), -(this->z), -(this->w));
}

// binary operators
D3DXVECTOR4 D3DXVECTOR4::operator + ( CONST D3DXVECTOR4& rhs) const
{
    return D3DXVECTOR4((this->x + rhs.x), (this->y + rhs.y), (this->z + rhs.z), (this->w + rhs.w));
}

D3DXVECTOR4 D3DXVECTOR4::operator - ( CONST D3DXVECTOR4& rhs) const
{
    return D3DXVECTOR4((this->x - rhs.x), (this->y - rhs.y), (this->z - rhs.z), (this->w - rhs.w));
}

D3DXVECTOR4 D3DXVECTOR4::operator * ( FLOAT rhs) const
{
    return D3DXVECTOR4((this->x * rhs), (this->y * rhs), (this->z  * rhs), (this->w  * rhs));
}

D3DXVECTOR4 D3DXVECTOR4::operator / ( FLOAT rhs) const
{
    float oneOverRhs = 1.0f/rhs;    //不进行除零检测

    return D3DXVECTOR4((this->x * oneOverRhs), (this->y * oneOverRhs), (this->z  * oneOverRhs), (this->w  * oneOverRhs));
}

D3DXVECTOR4 operator * ( FLOAT lhs, CONST D3DXVECTOR4& rhs)
{
    return D3DXVECTOR4((lhs * rhs.x), (lhs * rhs.y), (lhs * rhs.z), (lhs * rhs.w));
}

BOOL D3DXVECTOR4::operator == ( CONST D3DXVECTOR4& rhs) const
{
    if (this->x != rhs.x 
        || this->y != rhs.y 
        || this->z != rhs.z)
    {
        return false;
    }

    return true;
}

BOOL D3DXVECTOR4::operator != ( CONST D3DXVECTOR4& rhs) const
{
    if (this->x != rhs.x 
        || this->y != rhs.y 
        || this->z != rhs.z)
    {
        return true;
    }

    return false;
}


//
D3DXMATRIX::D3DXMATRIX( CONST FLOAT * )
{
    assert(0);
}
D3DXMATRIX::D3DXMATRIX( CONST D3DMATRIX& m)
{
    this->_11 = m._11;    this->_12 = m._12;    this->_13 = m._13;    this->_14 = m._14;
    this->_21 = m._21;    this->_22 = m._22;    this->_23 = m._23;    this->_24 = m._24;
    this->_31 = m._31;    this->_32 = m._32;    this->_33 = m._33;    this->_34 = m._34;
    this->_41 = m._41;    this->_42 = m._42;    this->_43 = m._43;    this->_44 = m._44;
    return;
}
D3DXMATRIX::D3DXMATRIX( CONST D3DXFLOAT16 * )
{
    assert(0);
}

D3DXMATRIX::D3DXMATRIX( FLOAT _11, FLOAT _12, FLOAT _13, FLOAT _14,
                FLOAT _21, FLOAT _22, FLOAT _23, FLOAT _24,
                FLOAT _31, FLOAT _32, FLOAT _33, FLOAT _34,
                FLOAT _41, FLOAT _42, FLOAT _43, FLOAT _44 )

{
    this->_11 = _11;    this->_12 = _12;    this->_13 = _13;    this->_14 = _14;
    this->_21 = _21;    this->_22 = _22;    this->_23 = _23;    this->_24 = _24;
    this->_31 = _31;    this->_32 = _32;    this->_33 = _33;    this->_34 = _34;
    this->_41 = _41;    this->_42 = _42;    this->_43 = _43;    this->_44 = _44;
    return;
}


// access grants
FLOAT& D3DXMATRIX::operator () ( UINT Row, UINT Col )
{
    assert(Row > 0 && Row <= 4);
    assert(Col > 0 && Col <= 4);
    return this->m[Row - 1][Col - 1];
}

FLOAT  D3DXMATRIX::operator () ( UINT Row, UINT Col ) const
{
    assert(Row > 0 && Row <= 4);
    assert(Col > 0 && Col <= 4);
    return this->m[Row - 1][Col - 1];

}

// casting operators
D3DXMATRIX::operator FLOAT* ()
{
    assert(0);
    return 0;
}

D3DXMATRIX::operator CONST FLOAT* () const
{
    assert(0);
    return 0;
}


// assignment operators
D3DXMATRIX& D3DXMATRIX::operator *= ( CONST D3DXMATRIX& rhs)
{
    int row = 0;
    int col = 0;
    int index = 0;
    float sum = 0;
    D3DXMATRIX matrixResult;
    for (; row < 4; row++)
    {
        
        for (; col < 4; col++)
        {   
            sum = 0; 
            for (; index < 4; index++)
            {                
                sum = this->m[row][index] * rhs.m[index][col];
            }
            matrixResult.m[row][col] = sum;
        }
    }
    *this = matrixResult;
    return *this;
}

D3DXMATRIX& D3DXMATRIX::operator += ( CONST D3DXMATRIX& rhs)
{
    int row = 0;
    int col = 0;
    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            this->m[row][col] += rhs.m[row][col];
        }
    }

    return *this;
}

D3DXMATRIX& D3DXMATRIX::operator -= ( CONST D3DXMATRIX& rhs)
{
    int row = 0;
    int col = 0;
    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            this->m[row][col] -= rhs.m[row][col];
        }
    }

    return *this;}

D3DXMATRIX& D3DXMATRIX::operator *= ( FLOAT rhs)
{
    int row = 0;
    int col = 0;
    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            this->m[row][col] *= rhs;
        }
    }   
    return *this;
}

D3DXMATRIX& D3DXMATRIX::operator /= ( FLOAT rhs)
{
    int row = 0;
    int col = 0;

    float oneOverRhs = 1.0f/rhs;    //不进行除零检测

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            this->m[row][col] *= oneOverRhs;
        }
    }   

    return *this;
}


// unary operators
D3DXMATRIX D3DXMATRIX::operator + () const
{
    return *this;
}

D3DXMATRIX D3DXMATRIX::operator - () const
{
    return D3DXMATRIX(-this->_11, -this->_12, -this->_13, -this->_14,
                      -this->_21, -this->_22, -this->_23, -this->_24,
                      -this->_31, -this->_32, -this->_33, -this->_34,
                      -this->_41, -this->_42, -this->_43, -this->_44);
}


// binary operators
D3DXMATRIX D3DXMATRIX::operator * ( CONST D3DXMATRIX& rhs) const
{
    int row = 0;
    int col = 0;
    int index = 0;
    float sum = 0;
    D3DXMATRIX matrixResult;
    for (; row < 4; row++)
    {
        
        for (; col < 4; col++)
        {   
            sum = 0; 
            for (; index < 4; index++)
            {                
                sum = this->m[row][index] * rhs.m[index][col];
            }
            matrixResult.m[row][col] = sum;
        }
    }

    return matrixResult;
}

D3DXMATRIX D3DXMATRIX::operator + ( CONST D3DXMATRIX& rhs) const
{
    int row = 0;
    int col = 0;
    float sum = 0;

    D3DXMATRIX matrixResult;

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            matrixResult.m[row][col] = this->m[row][col] + rhs.m[row][col];
        }
    }

    return matrixResult;
}

D3DXMATRIX D3DXMATRIX::operator - ( CONST D3DXMATRIX& rhs) const
{
    int row = 0;
    int col = 0;
    float sum = 0;

    D3DXMATRIX matrixResult;

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            matrixResult.m[row][col] = this->m[row][col] - rhs.m[row][col];
        }
    }

    return matrixResult;
}

D3DXMATRIX D3DXMATRIX::operator * ( FLOAT rhs) const
{
    int row = 0;
    int col = 0;
    float sum = 0;

    D3DXMATRIX matrixResult;

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            matrixResult.m[row][col] = this->m[row][col] * rhs;
        }
    }

    return matrixResult;
}

D3DXMATRIX D3DXMATRIX::operator / ( FLOAT rhs) const
{
    int row = 0;
    int col = 0;
    float sum = 0;
    float oneOverRhs = 1.0f/rhs;    //不进行除零检测

    D3DXMATRIX matrixResult;

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            matrixResult.m[row][col] = this->m[row][col] * oneOverRhs;
        }
    }

    return matrixResult;
}


D3DXMATRIX operator * ( FLOAT lhs, CONST D3DXMATRIX& rhs)
{
    int row = 0;
    int col = 0;
    float sum = 0;
    float oneOverlhs = 1.0f/lhs;    //不进行除零检测

    D3DXMATRIX matrixResult;

    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {   
            matrixResult.m[row][col] = rhs.m[row][col] * oneOverlhs;
        }
    }

    return matrixResult;

}


BOOL D3DXMATRIX::operator == ( CONST D3DXMATRIX& rhs) const
{
    int row = 0;
    int col = 0;
    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {
            if (this->m[row][col] != rhs.m[row][col])
            {
                return false;
            }
        }
    }
    return true;
}

BOOL D3DXMATRIX::operator != ( CONST D3DXMATRIX& rhs) const
{
    int row = 0;
    int col = 0;
    for (; row < 4; row++)
    {       
        for (; col < 4; col++)
        {
            if (this->m[row][col] != rhs.m[row][col])
            {
                return true;
            }
        }
    }
    return false;
}


//////////////////////////////////

/*
FLOAT D3DXVec3Length
    ( CONST D3DXVECTOR3 *pV );

FLOAT D3DXVec3LengthSq
    ( CONST D3DXVECTOR3 *pV );
*/
FLOAT D3DXVec3Dot
    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
    return (pV1->x * pV2->x) + (pV1->y * pV2->y) + (pV1->z * pV2->z);
}

D3DXVECTOR3* D3DXVec3Cross
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
    assert(0);
    return NULL;
}

D3DXVECTOR3* D3DXVec3Add
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
    *pOut = *pV1 + *pV2;
    return pOut;
}

D3DXVECTOR3* D3DXVec3Subtract
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
    *pOut = *pV1 + *pV2;
    return pOut;
}

/*
// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR3* D3DXVec3Minimize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR3* D3DXVec3Maximize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Scale
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR3* D3DXVec3Lerp
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
      FLOAT s );
*/

/////////////////
//vector4

/*
FLOAT D3DXVec4Length
    ( CONST D3DXVECTOR4 *pV );

FLOAT D3DXVec4LengthSq
    ( CONST D3DXVECTOR4 *pV );
*/
FLOAT D3DXVec4Dot
    ( CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2 )
{
    return (pV1->x * pV2->x) + (pV1->y * pV2->y) + (pV1->z * pV2->z) + (pV1->w * pV2->w);
}

D3DXVECTOR4* D3DXVec4Add
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
    *pOut = *pV1 + *pV2;
    return pOut;
}

D3DXVECTOR4* D3DXVec4Subtract
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
    *pOut = *pV1 - *pV2;
    return pOut;
}

/*
// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR4* D3DXVec4Minimize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR4* D3DXVec4Maximize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

D3DXVECTOR4* D3DXVec4Scale
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR4* D3DXVec4Lerp
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      FLOAT s );
*/

/*
// Cross-product in 4 dimensions.
D3DXVECTOR4* WINAPI D3DXVec4Cross
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      CONST D3DXVECTOR4 *pV3);

D3DXVECTOR4* WINAPI D3DXVec4Normalize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* WINAPI D3DXVec4Hermite
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pT1,
      CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pT2, FLOAT s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* WINAPI D3DXVec4CatmullRom
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV0, CONST D3DXVECTOR4 *pV1,
      CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pV3, FLOAT s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* WINAPI D3DXVec4BaryCentric
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      CONST D3DXVECTOR4 *pV3, FLOAT f, FLOAT g);
*/
// Transform vector by matrix.
D3DXVECTOR4* WINAPI D3DXVec4Transform
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, CONST D3DXMATRIX *pM )
{
    pOut->x = (pV->x * pM->_11) + (pV->y * pM->_21) + (pV->z * pM->_31) + (pV->w * pM->_41);
    pOut->y = (pV->x * pM->_12) + (pV->y * pM->_22) + (pV->z * pM->_32) + (pV->w * pM->_42);
    pOut->z = (pV->x * pM->_13) + (pV->y * pM->_23) + (pV->z * pM->_33) + (pV->w * pM->_43);
    pOut->w = (pV->x * pM->_14) + (pV->y * pM->_24) + (pV->z * pM->_34) + (pV->w * pM->_44);

    return pOut;
}
/*    
// Transform vector array by matrix.
D3DXVECTOR4* WINAPI D3DXVec4TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR4 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );
*/
///////////////////////
//Matrix


//--------------------------
// 4D Matrix
//--------------------------

// inline

D3DXMATRIX* D3DXMatrixIdentity
    ( D3DXMATRIX *pOut )
{
#if 0
    *pOut = D3DXMATRIX(1, 0, 0, 0
                       0, 1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);
#endif
    pOut->_11 = 1;    pOut->_12 = 0;    pOut->_13 = 0;    pOut->_14 = 0;
    pOut->_21 = 0;    pOut->_22 = 1;    pOut->_23 = 0;    pOut->_24 = 0;
    pOut->_31 = 0;    pOut->_32 = 0;    pOut->_33 = 1;    pOut->_34 = 0;
    pOut->_41 = 0;    pOut->_42 = 0;    pOut->_43 = 0;    pOut->_44 = 1;
    return pOut;
}

BOOL D3DXMatrixIsIdentity
    ( CONST D3DXMATRIX *pM )
{
    D3DXMATRIX M2 = D3DXMATRIX(1, 0, 0, 0,
                               0, 1, 0, 0,
                               0, 0, 1, 0,
                               0, 0, 0, 1);
    if (*pM == M2)
    {
        return true;
    }

    return false;
}


FLOAT WINAPI D3DXMatrixDeterminant
    ( CONST D3DXMATRIX *pM )
{
    assert(0);
    return 0;
}
/*
HRESULT WINAPI D3DXMatrixDecompose
    ( D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, 
	  D3DXVECTOR3 *pOutTranslation, CONST D3DXMATRIX *pM )
{
    return 0;
}
*/
D3DXMATRIX* WINAPI D3DXMatrixTranspose
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM )
{
    assert(0);
    return NULL;
}

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* WINAPI D3DXMatrixMultiply
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2 )
{
    *pOut = (*pM1) * (*pM2);
    return pOut;
}

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* WINAPI D3DXMatrixMultiplyTranspose
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2 )
{
    assert(0);
    return NULL;
}

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* WINAPI D3DXMatrixInverse
    ( D3DXMATRIX *pOut, FLOAT *pDeterminant, CONST D3DXMATRIX *pM )
{
    assert(0);
    return NULL;
}

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* WINAPI D3DXMatrixScaling
    ( D3DXMATRIX *pOut, FLOAT sx, FLOAT sy, FLOAT sz )
{
#if 0
    //dengjin, 这里可以优化
    D3DXMATRIX M = D3DXMATRIX(sx,  0,  0, 0,
                               0, sy,  0, 0,
                               0,  0, sz, 0,
                               0,  0,  0, 1);
    *pOut = M;
#else
    pOut->_11 = sx;    pOut->_12 = 0;    pOut->_13 = 0;    pOut->_14 = 0;
    pOut->_21 = 0;    pOut->_22 = sy;    pOut->_23 = 0;    pOut->_24 = 0;
    pOut->_31 = 0;    pOut->_32 = 0;    pOut->_33 = sz;    pOut->_34 = 0;
    pOut->_41 = 0;    pOut->_42 = 0;    pOut->_43 = 0;    pOut->_44 = 1;
#endif
    return pOut;
}

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WINAPI D3DXMatrixTranslation
    ( D3DXMATRIX *pOut, FLOAT x, FLOAT y, FLOAT z )
{
    assert(0);
    return NULL;
}

// Build a matrix which rotates around the X axis
D3DXMATRIX* WINAPI D3DXMatrixRotationX
    ( D3DXMATRIX *pOut, FLOAT Angle )
{
    assert(0);
    return NULL;
}

// Build a matrix which rotates around the Y axis
D3DXMATRIX* WINAPI D3DXMatrixRotationY
    ( D3DXMATRIX *pOut, FLOAT Angle )
{
    assert(0);
    return NULL;
}

// Build a matrix which rotates around the Z axis
D3DXMATRIX* WINAPI D3DXMatrixRotationZ
    ( D3DXMATRIX *pOut, FLOAT Angle )
{
    assert(0);
    return NULL;
}

void D3DXMATRIX_PRINTF(D3DXMATRIX* m)
{
    printf("\n**");
    printf("\t%f, \t%f, \t%f, \t%f\n", m->_11, m->_12, m->_13, m->_14);
    printf("\t%f, \t%f, \t%f, \t%f\n", m->_21, m->_22, m->_23, m->_24);
    printf("\t%f, \t%f, \t%f, \t%f\n", m->_31, m->_32, m->_33, m->_34);
    printf("\t%f, \t%f, \t%f, \t%f\n", m->_41, m->_42, m->_43, m->_44);


    printf("\n*");

}


//////////////

// Build a perspective projection matrix. (left-handed)
#include <math.h>


#include <complex>
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf )
{
/*
xScale     0          0               0
0        yScale       0               0
0          0       zf/(zf-zn)         1
0          0       -zn*zf/(zf-zn)     0
其中:
yScale = cot(fovY/2) 
xScale = aspect ratio * yScale函数信息：
*/
    ASSERT(pOut);
    float d = 1;//= ctan(fovy/2);

/*
    Mat_Init_4X4(pOut,
                d,        0, 0, 0,
                0, d*Aspect, 0, 0,
                0,        0, 1, 1,
                0,        0, 0, 1);
*/

    //float yScale = std::cos(fovy/2) / std::sin(fovy/2);
    float yScale = std::sin(fovy/2) / std::cos(fovy/2);
    float xScale = (1 / Aspect) * yScale;
    ASSERT(xScale >= -1 || xScale <= 1);
    ASSERT(yScale >= -1 || yScale <= 1);

    pOut->_11 = xScale; pOut->_12 = 0;      pOut->_13 = 0;              pOut->_14 = 0;
    pOut->_21 = 0;      pOut->_22 = yScale; pOut->_23 = 0;              pOut->_24 = 0;
    pOut->_31 = 0;      pOut->_32 = 0;      pOut->_33 = 1;     pOut->_34 = 1;
    pOut->_41 = 0;      pOut->_42 = 0;      pOut->_43 = 0; pOut->_44 = 0;

//    pOut->_31 = 0;      pOut->_32 = 0;      pOut->_33 = zf/(zf-zn);     pOut->_34 = 1;
//    pOut->_41 = 0;      pOut->_42 = 0;      pOut->_43 = -zn*zf/(zf-zn); pOut->_44 = 0;
D3DXMATRIX_PRINTF(pOut);
    return pOut;
 
}


