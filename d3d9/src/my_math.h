
#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3d9caps.h"
#include "my_d3dx9math.h"
//--------------------------
// 4D Matrix
//--------------------------

// inline

D3DXMATRIX* D3DXMatrixIdentity
    ( D3DXMATRIX *pOut );

BOOL D3DXMatrixIsIdentity
    ( CONST D3DXMATRIX *pM );


//将dx的矩阵数据结构与mat的数据结构进行关联
typedef D3DXMATRIX MATRIX4X4;
typedef D3DXMATRIX* MATRIX4X4_PTR;
typedef D3DXVECTOR4* VECTOR4D_PTR;

// 4x4 identity matrix
const MATRIX4X4 IMAT_4X4 = MATRIX4X4(1,0,0,0, 
                                     0,1,0,0, 
                                     0,0,1,0, 
                                     0,0,0,1);

#define MAT_IDENTITY_4X4(m) {memcpy((void *)(m), (void *)&IMAT_4X4, sizeof(MATRIX4X4));}

///////////////////////////////////////////////////////////////

void Mat_Init_4X4(MATRIX4X4_PTR ma, 
                 float m00, float m01, float m02, float m03,
                 float m10, float m11, float m12, float m13,
                 float m20, float m21, float m22, float m23,
                 float m30, float m31, float m32, float m33);


 
void Mat_Mul_VECTOR4D_4X4(VECTOR4D_PTR  va, 
                           MATRIX4X4_PTR mb,
                           VECTOR4D_PTR  vprod);

