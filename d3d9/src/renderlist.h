
#pragma once

#include "my_xx_types.h"
#include "my_d3d9types.h"
#include "my_d3dx9math.h"


// defines for polygons and faces version 1
#if 0
// attributes of polygons and polygon faces
#define POLY4DV1_ATTR_2SIDED              0x0001
#define POLY4DV1_ATTR_TRANSPARENT         0x0002
#define POLY4DV1_ATTR_8BITCOLOR           0x0004
#define POLY4DV1_ATTR_RGB16               0x0008
#define POLY4DV1_ATTR_RGB24               0x0010

#define POLY4DV1_ATTR_SHADE_MODE_PURE       0x0020
#define POLY4DV1_ATTR_SHADE_MODE_CONSTANT   0x0020 // (alias)
#define POLY4DV1_ATTR_SHADE_MODE_FLAT       0x0040
#define POLY4DV1_ATTR_SHADE_MODE_GOURAUD    0x0080
#define POLY4DV1_ATTR_SHADE_MODE_PHONG      0x0100
#define POLY4DV1_ATTR_SHADE_MODE_FASTPHONG  0x0100 // (alias)
#define POLY4DV1_ATTR_SHADE_MODE_TEXTURE    0x0200 


// states of polygons and faces
#define POLY4DV1_STATE_ACTIVE             0x0001
#define POLY4DV1_STATE_CLIPPED            0x0002
#define POLY4DV1_STATE_BACKFACE           0x0004

// defines for objects version 1
#define OBJECT4DV1_MAX_VERTICES           1024  // 64
#define OBJECT4DV1_MAX_POLYS              1024 // 128

// states for objects
#define OBJECT4DV1_STATE_ACTIVE           0x0001
#define OBJECT4DV1_STATE_VISIBLE          0x0002 
#define OBJECT4DV1_STATE_CULLED           0x0004

// attributes for objects
#endif
// render list defines
#define RENDERLIST4DV1_MAX_POLYS          32768// 16384
#if 0
// 4D homogenous vector, point with w ////////////////////
typedef struct VECTOR4D_TYP
{
union
    {
    float M[4]; // array indexed storage

    // explicit names
    struct
         {
         float x,y,z,w;
         }; // end struct
    }; // end union

} VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;
#endif

// a self contained polygon used for the render list
typedef struct POLYF4DV1_TYP
{
int state;    // state information
int attr;     // physical attributes of polygon
int color;    // color of polygon

D3DXVECTOR4 vlist[3];  // the vertices of this triangle
D3DXVECTOR4 tvlist[3]; // the vertices after transformation if needed

POLYF4DV1_TYP *next; // pointer to next polygon in list??
POLYF4DV1_TYP *prev; // pointer to previous polygon in list??

} POLYF4DV1, *POLYF4DV1_PTR;

// object to hold the render list, this way we can have more
// than one render list at a time
typedef struct RENDERLIST4DV1_TYP
{
int state; // state of renderlist ???
int attr;  // attributes of renderlist ???

// the render list is an array of pointers each pointing to 
// a self contained "renderable" polygon face POLYF4DV1
POLYF4DV1_PTR poly_ptrs[RENDERLIST4DV1_MAX_POLYS];

// additionally to cut down on allocatation, de-allocation
// of polygons each frame, here's where the actual polygon
// faces will be stored
POLYF4DV1 poly_data[RENDERLIST4DV1_MAX_POLYS];

int num_polys; // number of polys in render list

} RENDERLIST4DV1, *RENDERLIST4DV1_PTR;

inline int RENDERLIST_TRANSFORM(RENDERLIST4DV1* pRendList, CONST D3DMATRIX* pMatrix)
{
    int i = 0;
    int j = 0;
    POLYF4DV1* p = NULL;

    for (i = 0; i < pRendList->num_polys; i++)
    {
        for (j = 0; j < 4; j++)
        {
            p = &(pRendList->poly_data[i]);
        }
    }
}


inline void VECTOR4D_CROSS_MATRIX(D3DXVECTOR4* pVector4d, CONST D3DMATRIX* pMatrix, D3DXVECTOR4* pOut)
{
    ASSERT(pVector4d);
    ASSERT(pMatrix);
    ASSERT(pOut);

    int row = 0;
    int col = 0;
    float* pm = NULL;

    for (;col < 4; col++)
    {        
        for (;row < 4; row++)
        {
            pOut->m[col] += pMatrix->m[row][col]*pVector4d->m[row];
        }
    }

/*
    for (;row < 4; row++)
    {
        for (;col < 4; col++)
        {
            pMatrix->m[row][col];
        }

    }
*/
}

