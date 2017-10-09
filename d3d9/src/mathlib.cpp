
#include <stdafx.h>
#include "my_math.h"


///////////////////////////////////////////////////////////////




void Mat_Init_4X4(MATRIX4X4_PTR ma, 
                 float m00, float m01, float m02, float m03,
                 float m10, float m11, float m12, float m13,
                 float m20, float m21, float m22, float m23,
                 float m30, float m31, float m32, float m33)

{
// this function fills a 4x4 matrix with the sent data in 
// row major form
ma->_11 = m00; ma->_12 = m01; ma->_13 = m02; ma->_14 = m03;
ma->_21 = m00; ma->_22 = m01; ma->_23 = m02; ma->_24 = m03;
ma->_31 = m00; ma->_32 = m01; ma->_33 = m02; ma->_34 = m03;
ma->_41 = m00; ma->_42 = m01; ma->_43 = m02; ma->_44 = m03;

} // end Mat_Init_4X4

void Mat_Mul_VECTOR4D_4X4(VECTOR4D_PTR  va, 
                          MATRIX4X4_PTR mb,
                          VECTOR4D_PTR  vprod)
{
// this function multiplies a VECTOR4D against a 
// 4x4 matrix - ma*mb and stores the result in mprod
// the function makes no assumptions

    for (int col=0; col < 4; col++)
        {
        // compute dot product from row of ma 
        // and column of mb
        float sum = 0; // used to hold result

        for (int row=0; row<4; row++)
             {
             // add in next product pair
             sum+=(va->m[row]*mb->m[row][col]);
             } // end for index

        // insert resulting col element
        vprod->m[col] = sum;

        } // end for col

} // end Mat_Mul_VECTOR4D_4X4



#if 0
//dx interface

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WINAPI D3DXMatrixTranslation
    ( D3DXMATRIX *pOut, FLOAT x, FLOAT y, FLOAT z )
{
    Mat_Init_4X4(pOut,
                x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, y, 0,
                0, 0, 0, 1);
    return pOut;
}



// Build a lookat matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixLookAtLH
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pEye, CONST D3DXVECTOR3 *pAt,
      CONST D3DXVECTOR3 *pUp )
{
#if 0
    D3DXVECTOR3 n = *pAt - *pEye;
    D3DXVECTOR3 v = *pUp;
    D3DXVECTOR3 u = n * v;
    v = u * n;
/*
    Normalize(&u);
    Normalize(&v);
    Normalize(&n);
*/
    D3DXVECTOR3 factorX = -((*pEye)*u); //Æ½ÒÆÒò×Ó
    D3DXVECTOR3 factorY = -((*pEye)*v);
    D3DXVECTOR3 factorZ = -((*pEye)*n);
    Mat_Init_4X4(pOut,
                u.x,         v.x,      n.x,  0,
                u.y,         v.y,      n.y,  0,
                u.z,         v.z,      n.z,  0,
            factorX,     factorY,  factorZ,  1);

#endif    
    return pOut;

}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf )
{
    float d = 1;//= ctan(fovy/2);


    Mat_Init_4X4(pOut,
                d,        0, 0, 0,
                0, d*Aspect, 0, 0,
                0,        0, 1, 1,
                0,        0, 0, 1);

    return pOut;
}
#endif

D3DXMATRIX* WINAPI my_MatrixViewPort
    ( D3DXMATRIX *pOut, FLOAT width, FLOAT height/*, FLOAT fovy*/)
{
    //float d = ctan(fovy/2);

    Mat_Init_4X4(pOut,
                    1,       0, 0, 0,
                    0,      -1, 0, 0,
                width,  height, 1, 1,
                0,           0, 0, 0);

    return pOut;
}


