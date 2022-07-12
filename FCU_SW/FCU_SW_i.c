

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for FCU_SW.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_FCU_SW,0xBE91D12C,0xA13B,0x42B2,0x8A,0x2D,0xA4,0x26,0x11,0x33,0xA5,0x4E);


MIDL_DEFINE_GUID(IID, DIID_IFCU_SW,0xD25C2D4F,0xEC60,0x4967,0xBE,0xFC,0x5C,0xC7,0xB6,0x7E,0x80,0xF7);


MIDL_DEFINE_GUID(CLSID, CLSID_FCU_SW,0x2CF26EA6,0xE1A0,0x4CFA,0x92,0xC2,0x9B,0x5D,0x02,0x19,0xDF,0xE5);


MIDL_DEFINE_GUID(IID, DIID_IFCU_ATK_MODE_CMD,0x48B1EF4E,0xDBB4,0x4B2B,0x83,0x8A,0x58,0xA4,0xD2,0xEA,0x86,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_FCU_ATK_MODE_CMD,0x4648B153,0x9D1C,0x4E9F,0xA9,0x24,0x03,0x08,0x51,0x8B,0xE9,0x5F);


MIDL_DEFINE_GUID(IID, DIID_IRecvView,0x04DA761A,0xE2C1,0x44B4,0xA1,0x8C,0x5B,0x0D,0xA0,0xAD,0x9A,0x94);


MIDL_DEFINE_GUID(CLSID, CLSID_RecvView,0x65D05345,0x9362,0x4879,0xB2,0xDD,0x29,0x20,0xD5,0x9A,0xF3,0x7E);


MIDL_DEFINE_GUID(IID, DIID_IMSL_BIT_CHK,0xA9AB739A,0x5E47,0x4B16,0xBB,0x72,0x67,0xEC,0x59,0xAD,0x0F,0x53);


MIDL_DEFINE_GUID(CLSID, CLSID_MSL_BIT_CHK,0x9BD34383,0x5329,0x4414,0xA0,0x0F,0xB1,0x40,0x1A,0x94,0x0A,0xB5);


MIDL_DEFINE_GUID(IID, DIID_ISKR_CAGE_CMD,0x1CB9166D,0xAE96,0x4B1D,0xA0,0xF9,0x16,0x6C,0xF5,0xFB,0x9C,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_SKR_CAGE_CMD,0x859CC794,0xE777,0x4388,0x8D,0x6F,0x44,0xC8,0x72,0xFF,0x1D,0x61);


MIDL_DEFINE_GUID(IID, DIID_ISKR_RDY_CHK,0xF8192AB6,0x265B,0x428C,0xA7,0x98,0x6B,0x12,0x15,0xCF,0xFD,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_SKR_RDY_CHK,0x7358D754,0x8067,0x4CD7,0x97,0xE7,0xFC,0xAE,0x72,0x3D,0x13,0x1D);


MIDL_DEFINE_GUID(IID, DIID_ISKR_PLC_CHK,0xE9B16C71,0x49A4,0x4037,0x8B,0x7C,0x26,0xB9,0xCD,0x9A,0x27,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_SKR_PLC_CHK,0x82B9F27F,0x2691,0x44B3,0xB3,0x9F,0xA9,0xAD,0xDD,0xB3,0x74,0x36);


MIDL_DEFINE_GUID(IID, DIID_ILOCK_ON_CMD,0xB123823B,0x465C,0x418D,0x99,0x5C,0x85,0x94,0x60,0xFE,0x81,0x7F);


MIDL_DEFINE_GUID(CLSID, CLSID_LOCK_ON_CMD,0xD172C5F0,0x4D99,0x43CD,0xA0,0xDA,0xA7,0x7E,0xCE,0xFC,0x70,0x5B);


MIDL_DEFINE_GUID(IID, DIID_ISKR_TRK_STATUS,0x873BDC63,0x8783,0x4F63,0xAF,0x3D,0x71,0x5F,0xDE,0xA9,0xE3,0x0A);


MIDL_DEFINE_GUID(CLSID, CLSID_SKR_TRK_STATUS,0x85E2A9F5,0x3C51,0x424F,0x90,0x75,0xBF,0x3B,0xF2,0x2E,0xF5,0xED);


MIDL_DEFINE_GUID(IID, DIID_IATK_MODE_CMD,0xEACA9016,0x528F,0x43E0,0xA4,0xF4,0x74,0xDC,0xAC,0x52,0x76,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_ATK_MODE_CMD,0xE61F5F4D,0x667B,0x4EE8,0xA6,0x6E,0xA5,0xAD,0xD3,0xC1,0x07,0x75);


MIDL_DEFINE_GUID(IID, DIID_IMSL_STS_CHK,0x655B3638,0x80B2,0x4C05,0xA7,0xFC,0x8A,0x6C,0x2F,0xB7,0x14,0x85);


MIDL_DEFINE_GUID(CLSID, CLSID_MSL_STS_CHK,0xB62A06B7,0x1711,0x4387,0xBD,0xE3,0xA6,0x8C,0xB8,0xB6,0x09,0x88);


MIDL_DEFINE_GUID(IID, DIID_ILIFTOFF_RDY_CMD,0x34890301,0x9330,0x45D1,0x89,0x9D,0xF3,0x6D,0xA8,0x51,0xE1,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_LIFTOFF_RDY_CMD,0xF8056AE6,0x1658,0x4DBF,0x87,0xF8,0xFD,0x0E,0xD0,0x78,0x07,0x03);


MIDL_DEFINE_GUID(IID, DIID_IPINSQ,0xB58E4D17,0xE843,0x4C5A,0xAF,0x85,0x70,0x8C,0x5F,0xD2,0xD6,0x6C);


MIDL_DEFINE_GUID(CLSID, CLSID_PINSQ,0xAD08936E,0x35FD,0x42C3,0xB4,0xD5,0xCC,0xEA,0xDC,0xE8,0xC7,0x3F);


MIDL_DEFINE_GUID(IID, DIID_IEMSQ,0x2349ACB6,0x98A9,0x4263,0xB1,0x24,0xD5,0x69,0x86,0xE6,0xA7,0x29);


MIDL_DEFINE_GUID(CLSID, CLSID_EMSQ,0x948FB563,0x82D9,0x467F,0xB3,0xE2,0x16,0xD1,0x36,0xD7,0x88,0x12);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif


