
#pragma once
#include "my_d3d9.h"

#define MAX_STREAM_NUM 3

class CSTREAM
{
public:
    CSTREAM();
    ~CSTREAM();
    int SetStreamSource(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pVertexBuffer,UINT OffsetInBytes,UINT Stride);
    bool IsValid() 
    { 
        
        //printf("%s, %d, %d %d\n", __FUNCTION__, __LINE__, (bool)m_pStreamData, (m_pStreamData != NULL));

        //return ((m_pStreamData != NULL) ? true : false);
        return (m_pStreamData ? true : false);
    };
    //UINT ElementSize();
    DWORD FVF() {return m_VertexBufferDesc.FVF;};
/*
    UINT ElementNum()
    {
        UINT uElementNum = 0;
        if ()
        return uElementNum;
    };
*/
    BYTE* Begin();
    BYTE* End();
    BYTE* Current();

    void NextBlock();
    bool IsEnd();
    int SetVertexNumOfBlock(UINT num);

    UINT GetVertexNumOfBlock();
    UINT ElementSize();









protected:
    UINT m_StreamNumber;
    IDirect3DVertexBuffer9* m_pStreamData;
    UINT m_OffsetInBytes;
    UINT m_Stride;
    D3DVERTEXBUFFER_DESC m_VertexBufferDesc;
    UINT m_VertexNumOfBlock;
    BYTE* m_pCurrent;
    BYTE* m_pBuffer;

    

};

