/*
遗留问题
1. 目前没有接口向IDirect3DVertexBuffer9查询buffer地址,
先通过m_Desc.Type = D3DRTYPE_VERTEXBUFFER;判断类型强转到具体类,用具体类的指针返回查询结果
*/
#include <stdafx.h>
#include "stream.h"

#include "my_xx_types.h"
#include "my_direct3dvertexbuffer_imp.h"
CSTREAM::CSTREAM()
{
    m_pBuffer = NULL;
    m_pStreamData = NULL;
}
CSTREAM::~CSTREAM()
{
}
int CSTREAM::SetStreamSource(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pVertexBuffer,UINT OffsetInBytes,UINT Stride)
{
    m_StreamNumber = StreamNumber;
    m_pStreamData = pVertexBuffer;
    m_OffsetInBytes = OffsetInBytes;
    m_Stride = Stride;
    pVertexBuffer->GetDesc(&m_VertexBufferDesc);
    ASSERT((D3DRTYPE_VERTEXBUFFER == m_VertexBufferDesc.Type) 
            || (D3DRTYPE_INDEXBUFFER == m_VertexBufferDesc.Type));
    if (D3DRTYPE_VERTEXBUFFER == m_VertexBufferDesc.Type)
    {

        m_pBuffer = (static_cast<my_Direct3DVertexBuffer9*>(pVertexBuffer))->GetBuffer();
        ASSERT(m_pBuffer);
    }
    //printf("%s, %d %p\n", __FUNCTION__, __LINE__, m_pBuffer);

    return 0;
}

BYTE* CSTREAM::Begin()
{
    ASSERT(m_pBuffer);
    m_pCurrent = m_pBuffer;
    return m_pCurrent;
}

BYTE* CSTREAM::End()
{
    return m_pBuffer + m_VertexBufferDesc.Size;
}

BYTE* CSTREAM::Current()
{
    return m_pCurrent;
}
void CSTREAM::NextBlock()
{
static int c = 0;

    m_pCurrent += m_Stride*m_VertexNumOfBlock;
    ASSERT(m_pCurrent >= m_pBuffer);
    //printf("%s, %d c = %d ,%d, m_pBuffer = %p, %p %p\n", __FUNCTION__, __LINE__, c++, m_VertexBufferDesc.Size, m_pCurrent, m_pBuffer, m_pBuffer + m_VertexBufferDesc.Size);

    //ASSERT(m_pCurrent < m_pBuffer + m_VertexBufferDesc.Size);
    ASSERT(m_pCurrent <= m_pBuffer + m_VertexBufferDesc.Size ); //最后一次会等于

}

bool CSTREAM::IsEnd()
{
    bool bRtn = m_pCurrent >= End();
    //printf("%s, %d  bRtn = %d, pCurrentData = %p, End %p \n", __FUNCTION__, __LINE__, bRtn, m_pCurrent,  End());

    return bRtn;
}
int CSTREAM::SetVertexNumOfBlock(UINT num)
{
    m_VertexNumOfBlock = num;
    return ERR_SUCC;
}

UINT CSTREAM::GetVertexNumOfBlock()
{
    return m_VertexNumOfBlock;
}
UINT CSTREAM::ElementSize()
{
    return m_Stride;
}
