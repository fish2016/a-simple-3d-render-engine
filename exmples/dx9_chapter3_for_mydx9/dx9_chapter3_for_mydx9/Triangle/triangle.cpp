//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: triangle.cpp
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, Geforce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Renders a triangle in wireframe mode.  Demonstrates vertex buffers, 
//       render states, and drawing commands.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "d3dUtility.h"

#define VERTEX_NUM_OF_SQUARE 36
#define TRIANGLE_NUM_OF_SQUARE 12

//
// Globals
//

IDirect3DDevice9* Device = 0; 

const int Width  = 640;
const int Height = 480;

IDirect3DVertexBuffer9* Triangle = 0; // vertex buffer to store
                                      // our triangle data.

//
// Classes and Structures
//

struct Vertex
{
	Vertex(){}

	Vertex(float x, float y, float z, D3DCOLOR c)
	{
		_x = x;	 _y = y;  _z = z; _color = c;
	}

	float _x, _y, _z;
	D3DCOLOR _color;

	static const DWORD FVF;
};
const DWORD Vertex::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

void build_graphic()
{
	// Create the vertex buffer.
	//
	Device->CreateVertexBuffer(
		VERTEX_NUM_OF_SQUARE * sizeof(Vertex), // size in bytes
		D3DUSAGE_WRITEONLY, // flags
		Vertex::FVF,        // vertex format
		D3DPOOL_MANAGED,    // managed memory pool
		&Triangle,          // return create vertex buffer
		0);                 // not used - set to 0

	//
	// Fill the buffers with the triangle data.
	//

	Vertex* vertices;
	Triangle->Lock(0, 0, (void**)&vertices, 0);
// 1 front
	vertices[0] = Vertex(-1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));
	vertices[1] = Vertex( 1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[2] = Vertex( -1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff));

	vertices[3] = Vertex( 1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff));
	vertices[4] = Vertex( 1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[5] = Vertex( -1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0x55));

// 2 back
	vertices[6] = Vertex(-1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0, 0, 0xff));   
	vertices[7] = Vertex( 1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));   
	vertices[8] = Vertex(-1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0xff, 0, 0)); 
                                             
	vertices[9] = Vertex( -1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0xff, 0, 0));   
	vertices[10] = Vertex( 1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0)); 
	vertices[11] = Vertex(1.0f, 1.0f,  4.0f, D3DCOLOR_XRGB(0, 0, 0xff));

// 3 left
	vertices[12] = Vertex(-1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff));
	vertices[13] = Vertex(-1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[14] = Vertex(-1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));

	vertices[15] = Vertex(-1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));
	vertices[16] = Vertex( -1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[17] = Vertex(-1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0, 0xff));

// 4 right
	vertices[18] = Vertex(1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));  
	vertices[19] = Vertex(1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));  
	vertices[20] = Vertex(1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff)); 
                                            
	vertices[21] = Vertex(1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0xff, 0, 0)); 
	vertices[22] = Vertex(1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0)); 
	vertices[23] = Vertex(1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff));  
// 5 top
	vertices[24] = Vertex(-1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));
	vertices[25] = Vertex( -1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[26] = Vertex( 1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0, 0xff));

	vertices[27] = Vertex(1.0f, 1.0f, 4.0f, D3DCOLOR_XRGB(0, 0, 0xff));
	vertices[28] = Vertex( 1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[29] = Vertex( -1.0f, 1.0f, 2.0f, D3DCOLOR_XRGB(0xff, 0, 0));

// 6 bottom
	vertices[30] = Vertex(1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0xff, 0, 0)); 
	vertices[31] = Vertex( -1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0, 0xff, 0));
	vertices[32] = Vertex(-1.0f, -1.0f, 2.0f , D3DCOLOR_XRGB(0, 0, 0xff)); 
                                             
	vertices[33] = Vertex(-1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0, 0xff));  
	vertices[34] = Vertex( 1.0f, -1.0f, 2.0f, D3DCOLOR_XRGB(0, 0xff, 0)); 
	vertices[35] = Vertex( 1.0f, -1.0f, 4.0f, D3DCOLOR_XRGB(0xff, 0, 0));

	Triangle->Unlock();
}
//
// Framework Functions
//
bool Setup()
{

	//
	// Create the vertex buffer.
	//
#if 0
	Device->CreateVertexBuffer(
		3 * sizeof(Vertex), // size in bytes
		D3DUSAGE_WRITEONLY, // flags
		Vertex::FVF,        // vertex format
		D3DPOOL_MANAGED,    // managed memory pool
		&Triangle,          // return create vertex buffer
		0);                 // not used - set to 0

	//
	// Fill the buffers with the triangle data.
	//

	Vertex* vertices;
	Triangle->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = Vertex(-1.0f, 0.0f, 2.0f);
	vertices[1] = Vertex( 0.0f, 1.0f, 2.0f);
	vertices[2] = Vertex( 1.0f, 0.0f, 2.0f);

	Triangle->Unlock();
#endif
    build_graphic();
	//
	// Set the projection matrix.
	//

	// Set camera.
	//
/*
	D3DXVECTOR3 pos(0.0f, 3.0f, -3.0f);
	D3DXVECTOR3 target(0.0f, 1.0f, 1.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

	D3DXVECTOR3 pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

*/
	D3DXVECTOR3 pos(-2.0f, 3.0f, -1.0f);
	D3DXVECTOR3 target(0.0f, 1.0f, 1.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &pos, &target, &up);
printf("D3DXMatrixLookAtLH\n");
D3DXMATRIX_PRINTF(&V);

	Device->SetTransform(D3DTS_VIEW, &V);


	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
			&proj,                        // result
			D3DX_PI * 0.5f,               // 90 - degrees
			(float)Width / (float)Height, // aspect ratio
			1.0f,                         // near plane
			1000.0f);                     // far plane

D3DXMATRIX_PRINTF(&proj);
printf("w h = %d, %d ar %f  1/ar %f\n", Width, Height, (float)Width / (float)Height, 1 / ((float)Width / (float)Height));

	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//
	// Set wireframe mode render state.
	//

	//Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
    Device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_FLAT);
    Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	return true;
}
void Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(Triangle);
}

bool Display(float timeDelta)
{
D3DXMATRIX WorldMatrix;
static int c = 0;
c++;
if (c >= 2)
{
    //ClearRenderList(); //本轮渲染完毕,清除渲染列表数据

    //return true;
}
//return true;
	if( Device )
	{

//

		//
		// spin the cube:
		//
		D3DXMATRIX Rx, Ry;

		// rotate 45 degrees on x-axis
		D3DXMatrixRotationX(&Rx, 3.14f / 4.0f);
        //D3DXMatrixRotationX(&Rx, 0);
printf("D3DTS_WORLD rx\n");

D3DXMATRIX_PRINTF(&Rx);
		// incremement y-rotation angle each frame
		static float y = 0.0f;
		D3DXMatrixRotationY(&Ry, y);
printf("D3DTS_WORLD ry\n");

D3DXMATRIX_PRINTF(&Ry);
		y += timeDelta*0.5;

		// reset angle to zero when angle reaches 2*PI
		if( y >= 6.28f )
			y = 0.0f;

		// combine x- and y-axis rotation transformations.
		D3DXMATRIX p = Rx * Ry;
	    Device->SetTransform(D3DTS_WORLD, &p);
        printf("D3DTS_WORLD matrix\n");
        D3DXMATRIX_PRINTF(&p);
	
//
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		Device->BeginScene();

		Device->SetStreamSource(0, Triangle, 0, sizeof(Vertex));
		Device->SetFVF(Vertex::FVF);
    	Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
    	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

		// Draw one triangle.
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, TRIANGLE_NUM_OF_SQUARE);

		D3DXMatrixTranslation(&WorldMatrix, 0, 4.0f, 0.0f);
        p = p * WorldMatrix;
	    Device->SetTransform(D3DTS_WORLD, &p);
        Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
    	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, TRIANGLE_NUM_OF_SQUARE);

		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}
	return true;
}


//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	if(!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop( Display );

	Cleanup();

	Device->Release();

	return 0;
}
