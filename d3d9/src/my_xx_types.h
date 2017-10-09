
#pragma once

#include <assert.h>
#include "my_d3d9.h"

//#include <windef.h>
// TYPES //////////////////////////////////////////////////

// basic unsigned types
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned char  UCHAR;
typedef unsigned char  BYTE;
typedef unsigned int   QUAD;
typedef unsigned int   UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned long ULONG;

typedef float FLOAT;


//my define dengjin add

#define CONST const

//typedef bool BOOL;


//#define HWND        void*

//#define interface
//#define WINAPI


//for debug
#ifdef ASSERT
    #undef ASSERT
#endif
#define ASSERT(x) assert(x)
#define LOG_PRINTF(x) printf(x)

#define HRESULT_SUCC 0
#define HRESULT_FAIL 1

#define ERR_SUCC 0
#define ERR_FAIL 1
//#define TRACE_FUNC  do { printf("%s, %d\n", __FUNCTION__, __LINE__); } while(0)
#define TRACE_FUNC  

/*
#define CHK_MEM_RET_ERR(ptr) do {\
                                    ASSERT(ptr); \
                                    if (NULL == ptr) \
                                    { \
                                        LOG_PRINTF("alloc mem fail\n"); \
                                        return ERR_FAIL; \ 
                                    } \
                                } while(0)
*/
#define CHK_MEM_RET_ERR(ptr) do {\
                                   ASSERT(ptr); \
                                    if (NULL == ptr) \
                                    {\
                                        LOG_PRINTF("alloc mem fail\n"); \
                                        return ERR_FAIL; \
                                    }\
                                } while(0)


#define CHK_MEM_RET_NULL(ptr) do {\
                                ASSERT(ptr); \
                                if (NULL == ptr) \
                                    { \
                                        LOG_PRINTF("alloc mem fail\n"); \
                                        TRACE_FUNC; \
                                        return NULL; \
                                    } \
                                } while(0)


#define CHK_RET_NULL(err_code) do {\
                                    if (err_code != ERR_SUCC) \
                                        { \
                                            LOG_PRINTF("chk reture null fail\n"); \
                                            TRACE_FUNC; \
                                            return NULL; \
                                        } \
                                    } while(0)


#define CHK_RET_NULL_RELEASE_MEM(err_code, ptr) do {\
                                            if (err_code != ERR_SUCC) \
                                            {\
                                                ASSERT(0); \
                                                { \
                                                    if (ptr != NULL)\
                                                    { \
                                                        delete ptr; \
                                                    } \
                                                    LOG_PRINTF("chk reture null release fail\n"); \
                                                    printf("%d, ptr %p\n", err_code, ptr); \
                                                    TRACE_FUNC; \
                                                    return NULL; \
                                                } \
                                            } \
                                    } while(0)



#define CHK_COND_RET_ERR(cond) do {\
                           ASSERT(cond); \
                            if (!(cond)) \
                            {\
                                LOG_PRINTF("chk condition fail\n"); \
                                return ERR_FAIL; \
                            }\
                        } while(0)


