

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __FCU_SW_h_h__
#define __FCU_SW_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFCU_SW_FWD_DEFINED__
#define __IFCU_SW_FWD_DEFINED__
typedef interface IFCU_SW IFCU_SW;

#endif 	/* __IFCU_SW_FWD_DEFINED__ */


#ifndef __FCU_SW_FWD_DEFINED__
#define __FCU_SW_FWD_DEFINED__

#ifdef __cplusplus
typedef class FCU_SW FCU_SW;
#else
typedef struct FCU_SW FCU_SW;
#endif /* __cplusplus */

#endif 	/* __FCU_SW_FWD_DEFINED__ */


#ifndef __IFCU_ATK_MODE_CMD_FWD_DEFINED__
#define __IFCU_ATK_MODE_CMD_FWD_DEFINED__
typedef interface IFCU_ATK_MODE_CMD IFCU_ATK_MODE_CMD;

#endif 	/* __IFCU_ATK_MODE_CMD_FWD_DEFINED__ */


#ifndef __FCU_ATK_MODE_CMD_FWD_DEFINED__
#define __FCU_ATK_MODE_CMD_FWD_DEFINED__

#ifdef __cplusplus
typedef class FCU_ATK_MODE_CMD FCU_ATK_MODE_CMD;
#else
typedef struct FCU_ATK_MODE_CMD FCU_ATK_MODE_CMD;
#endif /* __cplusplus */

#endif 	/* __FCU_ATK_MODE_CMD_FWD_DEFINED__ */


#ifndef __IRecvView_FWD_DEFINED__
#define __IRecvView_FWD_DEFINED__
typedef interface IRecvView IRecvView;

#endif 	/* __IRecvView_FWD_DEFINED__ */


#ifndef __RecvView_FWD_DEFINED__
#define __RecvView_FWD_DEFINED__

#ifdef __cplusplus
typedef class RecvView RecvView;
#else
typedef struct RecvView RecvView;
#endif /* __cplusplus */

#endif 	/* __RecvView_FWD_DEFINED__ */


#ifndef __IMSL_BIT_CHK_FWD_DEFINED__
#define __IMSL_BIT_CHK_FWD_DEFINED__
typedef interface IMSL_BIT_CHK IMSL_BIT_CHK;

#endif 	/* __IMSL_BIT_CHK_FWD_DEFINED__ */


#ifndef __MSL_BIT_CHK_FWD_DEFINED__
#define __MSL_BIT_CHK_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSL_BIT_CHK MSL_BIT_CHK;
#else
typedef struct MSL_BIT_CHK MSL_BIT_CHK;
#endif /* __cplusplus */

#endif 	/* __MSL_BIT_CHK_FWD_DEFINED__ */


#ifndef __ISKR_CAGE_CMD_FWD_DEFINED__
#define __ISKR_CAGE_CMD_FWD_DEFINED__
typedef interface ISKR_CAGE_CMD ISKR_CAGE_CMD;

#endif 	/* __ISKR_CAGE_CMD_FWD_DEFINED__ */


#ifndef __SKR_CAGE_CMD_FWD_DEFINED__
#define __SKR_CAGE_CMD_FWD_DEFINED__

#ifdef __cplusplus
typedef class SKR_CAGE_CMD SKR_CAGE_CMD;
#else
typedef struct SKR_CAGE_CMD SKR_CAGE_CMD;
#endif /* __cplusplus */

#endif 	/* __SKR_CAGE_CMD_FWD_DEFINED__ */


#ifndef __ISKR_RDY_CHK_FWD_DEFINED__
#define __ISKR_RDY_CHK_FWD_DEFINED__
typedef interface ISKR_RDY_CHK ISKR_RDY_CHK;

#endif 	/* __ISKR_RDY_CHK_FWD_DEFINED__ */


#ifndef __SKR_RDY_CHK_FWD_DEFINED__
#define __SKR_RDY_CHK_FWD_DEFINED__

#ifdef __cplusplus
typedef class SKR_RDY_CHK SKR_RDY_CHK;
#else
typedef struct SKR_RDY_CHK SKR_RDY_CHK;
#endif /* __cplusplus */

#endif 	/* __SKR_RDY_CHK_FWD_DEFINED__ */


#ifndef __ISKR_PLC_CHK_FWD_DEFINED__
#define __ISKR_PLC_CHK_FWD_DEFINED__
typedef interface ISKR_PLC_CHK ISKR_PLC_CHK;

#endif 	/* __ISKR_PLC_CHK_FWD_DEFINED__ */


#ifndef __SKR_PLC_CHK_FWD_DEFINED__
#define __SKR_PLC_CHK_FWD_DEFINED__

#ifdef __cplusplus
typedef class SKR_PLC_CHK SKR_PLC_CHK;
#else
typedef struct SKR_PLC_CHK SKR_PLC_CHK;
#endif /* __cplusplus */

#endif 	/* __SKR_PLC_CHK_FWD_DEFINED__ */


#ifndef __ILOCK_ON_CMD_FWD_DEFINED__
#define __ILOCK_ON_CMD_FWD_DEFINED__
typedef interface ILOCK_ON_CMD ILOCK_ON_CMD;

#endif 	/* __ILOCK_ON_CMD_FWD_DEFINED__ */


#ifndef __LOCK_ON_CMD_FWD_DEFINED__
#define __LOCK_ON_CMD_FWD_DEFINED__

#ifdef __cplusplus
typedef class LOCK_ON_CMD LOCK_ON_CMD;
#else
typedef struct LOCK_ON_CMD LOCK_ON_CMD;
#endif /* __cplusplus */

#endif 	/* __LOCK_ON_CMD_FWD_DEFINED__ */


#ifndef __ISKR_TRK_STATUS_FWD_DEFINED__
#define __ISKR_TRK_STATUS_FWD_DEFINED__
typedef interface ISKR_TRK_STATUS ISKR_TRK_STATUS;

#endif 	/* __ISKR_TRK_STATUS_FWD_DEFINED__ */


#ifndef __SKR_TRK_STATUS_FWD_DEFINED__
#define __SKR_TRK_STATUS_FWD_DEFINED__

#ifdef __cplusplus
typedef class SKR_TRK_STATUS SKR_TRK_STATUS;
#else
typedef struct SKR_TRK_STATUS SKR_TRK_STATUS;
#endif /* __cplusplus */

#endif 	/* __SKR_TRK_STATUS_FWD_DEFINED__ */


#ifndef __IATK_MODE_CMD_FWD_DEFINED__
#define __IATK_MODE_CMD_FWD_DEFINED__
typedef interface IATK_MODE_CMD IATK_MODE_CMD;

#endif 	/* __IATK_MODE_CMD_FWD_DEFINED__ */


#ifndef __ATK_MODE_CMD_FWD_DEFINED__
#define __ATK_MODE_CMD_FWD_DEFINED__

#ifdef __cplusplus
typedef class ATK_MODE_CMD ATK_MODE_CMD;
#else
typedef struct ATK_MODE_CMD ATK_MODE_CMD;
#endif /* __cplusplus */

#endif 	/* __ATK_MODE_CMD_FWD_DEFINED__ */


#ifndef __IMSL_STS_CHK_FWD_DEFINED__
#define __IMSL_STS_CHK_FWD_DEFINED__
typedef interface IMSL_STS_CHK IMSL_STS_CHK;

#endif 	/* __IMSL_STS_CHK_FWD_DEFINED__ */


#ifndef __MSL_STS_CHK_FWD_DEFINED__
#define __MSL_STS_CHK_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSL_STS_CHK MSL_STS_CHK;
#else
typedef struct MSL_STS_CHK MSL_STS_CHK;
#endif /* __cplusplus */

#endif 	/* __MSL_STS_CHK_FWD_DEFINED__ */


#ifndef __ILIFTOFF_RDY_CMD_FWD_DEFINED__
#define __ILIFTOFF_RDY_CMD_FWD_DEFINED__
typedef interface ILIFTOFF_RDY_CMD ILIFTOFF_RDY_CMD;

#endif 	/* __ILIFTOFF_RDY_CMD_FWD_DEFINED__ */


#ifndef __LIFTOFF_RDY_CMD_FWD_DEFINED__
#define __LIFTOFF_RDY_CMD_FWD_DEFINED__

#ifdef __cplusplus
typedef class LIFTOFF_RDY_CMD LIFTOFF_RDY_CMD;
#else
typedef struct LIFTOFF_RDY_CMD LIFTOFF_RDY_CMD;
#endif /* __cplusplus */

#endif 	/* __LIFTOFF_RDY_CMD_FWD_DEFINED__ */


#ifndef __IPINSQ_FWD_DEFINED__
#define __IPINSQ_FWD_DEFINED__
typedef interface IPINSQ IPINSQ;

#endif 	/* __IPINSQ_FWD_DEFINED__ */


#ifndef __PINSQ_FWD_DEFINED__
#define __PINSQ_FWD_DEFINED__

#ifdef __cplusplus
typedef class PINSQ PINSQ;
#else
typedef struct PINSQ PINSQ;
#endif /* __cplusplus */

#endif 	/* __PINSQ_FWD_DEFINED__ */


#ifndef __IEMSQ_FWD_DEFINED__
#define __IEMSQ_FWD_DEFINED__
typedef interface IEMSQ IEMSQ;

#endif 	/* __IEMSQ_FWD_DEFINED__ */


#ifndef __EMSQ_FWD_DEFINED__
#define __EMSQ_FWD_DEFINED__

#ifdef __cplusplus
typedef class EMSQ EMSQ;
#else
typedef struct EMSQ EMSQ;
#endif /* __cplusplus */

#endif 	/* __EMSQ_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __FCU_SW_LIBRARY_DEFINED__
#define __FCU_SW_LIBRARY_DEFINED__

/* library FCU_SW */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FCU_SW;

#ifndef __IFCU_SW_DISPINTERFACE_DEFINED__
#define __IFCU_SW_DISPINTERFACE_DEFINED__

/* dispinterface IFCU_SW */
/* [uuid] */ 


EXTERN_C const IID DIID_IFCU_SW;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D25C2D4F-EC60-4967-BEFC-5CC7B67E80F7")
    IFCU_SW : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCU_SWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCU_SW * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCU_SW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCU_SW * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCU_SW * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCU_SW * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCU_SW * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCU_SW * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IFCU_SWVtbl;

    interface IFCU_SW
    {
        CONST_VTBL struct IFCU_SWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCU_SW_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFCU_SW_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFCU_SW_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFCU_SW_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFCU_SW_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFCU_SW_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFCU_SW_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCU_SW_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FCU_SW;

#ifdef __cplusplus

class DECLSPEC_UUID("2CF26EA6-E1A0-4CFA-92C2-9B5D0219DFE5")
FCU_SW;
#endif

#ifndef __IFCU_ATK_MODE_CMD_DISPINTERFACE_DEFINED__
#define __IFCU_ATK_MODE_CMD_DISPINTERFACE_DEFINED__

/* dispinterface IFCU_ATK_MODE_CMD */
/* [uuid] */ 


EXTERN_C const IID DIID_IFCU_ATK_MODE_CMD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("48B1EF4E-DBB4-4B2B-838A-58A4D2EA8610")
    IFCU_ATK_MODE_CMD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCU_ATK_MODE_CMDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCU_ATK_MODE_CMD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCU_ATK_MODE_CMD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCU_ATK_MODE_CMD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCU_ATK_MODE_CMD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCU_ATK_MODE_CMD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCU_ATK_MODE_CMD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCU_ATK_MODE_CMD * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IFCU_ATK_MODE_CMDVtbl;

    interface IFCU_ATK_MODE_CMD
    {
        CONST_VTBL struct IFCU_ATK_MODE_CMDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCU_ATK_MODE_CMD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFCU_ATK_MODE_CMD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFCU_ATK_MODE_CMD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFCU_ATK_MODE_CMD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFCU_ATK_MODE_CMD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFCU_ATK_MODE_CMD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFCU_ATK_MODE_CMD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCU_ATK_MODE_CMD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FCU_ATK_MODE_CMD;

#ifdef __cplusplus

class DECLSPEC_UUID("4648B153-9D1C-4E9F-A924-0308518BE95F")
FCU_ATK_MODE_CMD;
#endif

#ifndef __IRecvView_DISPINTERFACE_DEFINED__
#define __IRecvView_DISPINTERFACE_DEFINED__

/* dispinterface IRecvView */
/* [uuid] */ 


EXTERN_C const IID DIID_IRecvView;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("04DA761A-E2C1-44B4-A18C-5B0DA0AD9A94")
    IRecvView : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IRecvViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRecvView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRecvView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRecvView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRecvView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRecvView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRecvView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRecvView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IRecvViewVtbl;

    interface IRecvView
    {
        CONST_VTBL struct IRecvViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRecvView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRecvView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRecvView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRecvView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRecvView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRecvView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRecvView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IRecvView_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_RecvView;

#ifdef __cplusplus

class DECLSPEC_UUID("65D05345-9362-4879-B2DD-2920D59AF37E")
RecvView;
#endif

#ifndef __IMSL_BIT_CHK_DISPINTERFACE_DEFINED__
#define __IMSL_BIT_CHK_DISPINTERFACE_DEFINED__

/* dispinterface IMSL_BIT_CHK */
/* [uuid] */ 


EXTERN_C const IID DIID_IMSL_BIT_CHK;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A9AB739A-5E47-4B16-BB72-67EC59AD0F53")
    IMSL_BIT_CHK : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMSL_BIT_CHKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSL_BIT_CHK * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSL_BIT_CHK * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSL_BIT_CHK * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSL_BIT_CHK * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSL_BIT_CHK * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSL_BIT_CHK * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSL_BIT_CHK * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IMSL_BIT_CHKVtbl;

    interface IMSL_BIT_CHK
    {
        CONST_VTBL struct IMSL_BIT_CHKVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSL_BIT_CHK_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSL_BIT_CHK_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSL_BIT_CHK_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSL_BIT_CHK_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSL_BIT_CHK_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSL_BIT_CHK_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSL_BIT_CHK_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMSL_BIT_CHK_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MSL_BIT_CHK;

#ifdef __cplusplus

class DECLSPEC_UUID("9BD34383-5329-4414-A00F-B1401A940AB5")
MSL_BIT_CHK;
#endif

#ifndef __ISKR_CAGE_CMD_DISPINTERFACE_DEFINED__
#define __ISKR_CAGE_CMD_DISPINTERFACE_DEFINED__

/* dispinterface ISKR_CAGE_CMD */
/* [uuid] */ 


EXTERN_C const IID DIID_ISKR_CAGE_CMD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1CB9166D-AE96-4B1D-A0F9-166CF5FB9CB0")
    ISKR_CAGE_CMD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISKR_CAGE_CMDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISKR_CAGE_CMD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISKR_CAGE_CMD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISKR_CAGE_CMD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISKR_CAGE_CMD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISKR_CAGE_CMD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISKR_CAGE_CMD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISKR_CAGE_CMD * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISKR_CAGE_CMDVtbl;

    interface ISKR_CAGE_CMD
    {
        CONST_VTBL struct ISKR_CAGE_CMDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISKR_CAGE_CMD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISKR_CAGE_CMD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISKR_CAGE_CMD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISKR_CAGE_CMD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISKR_CAGE_CMD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISKR_CAGE_CMD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISKR_CAGE_CMD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISKR_CAGE_CMD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SKR_CAGE_CMD;

#ifdef __cplusplus

class DECLSPEC_UUID("859CC794-E777-4388-8D6F-44C872FF1D61")
SKR_CAGE_CMD;
#endif

#ifndef __ISKR_RDY_CHK_DISPINTERFACE_DEFINED__
#define __ISKR_RDY_CHK_DISPINTERFACE_DEFINED__

/* dispinterface ISKR_RDY_CHK */
/* [uuid] */ 


EXTERN_C const IID DIID_ISKR_RDY_CHK;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F8192AB6-265B-428C-A798-6B1215CFFD06")
    ISKR_RDY_CHK : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISKR_RDY_CHKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISKR_RDY_CHK * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISKR_RDY_CHK * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISKR_RDY_CHK * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISKR_RDY_CHK * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISKR_RDY_CHK * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISKR_RDY_CHK * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISKR_RDY_CHK * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISKR_RDY_CHKVtbl;

    interface ISKR_RDY_CHK
    {
        CONST_VTBL struct ISKR_RDY_CHKVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISKR_RDY_CHK_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISKR_RDY_CHK_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISKR_RDY_CHK_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISKR_RDY_CHK_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISKR_RDY_CHK_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISKR_RDY_CHK_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISKR_RDY_CHK_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISKR_RDY_CHK_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SKR_RDY_CHK;

#ifdef __cplusplus

class DECLSPEC_UUID("7358D754-8067-4CD7-97E7-FCAE723D131D")
SKR_RDY_CHK;
#endif

#ifndef __ISKR_PLC_CHK_DISPINTERFACE_DEFINED__
#define __ISKR_PLC_CHK_DISPINTERFACE_DEFINED__

/* dispinterface ISKR_PLC_CHK */
/* [uuid] */ 


EXTERN_C const IID DIID_ISKR_PLC_CHK;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E9B16C71-49A4-4037-8B7C-26B9CD9A2748")
    ISKR_PLC_CHK : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISKR_PLC_CHKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISKR_PLC_CHK * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISKR_PLC_CHK * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISKR_PLC_CHK * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISKR_PLC_CHK * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISKR_PLC_CHK * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISKR_PLC_CHK * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISKR_PLC_CHK * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISKR_PLC_CHKVtbl;

    interface ISKR_PLC_CHK
    {
        CONST_VTBL struct ISKR_PLC_CHKVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISKR_PLC_CHK_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISKR_PLC_CHK_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISKR_PLC_CHK_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISKR_PLC_CHK_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISKR_PLC_CHK_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISKR_PLC_CHK_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISKR_PLC_CHK_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISKR_PLC_CHK_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SKR_PLC_CHK;

#ifdef __cplusplus

class DECLSPEC_UUID("82B9F27F-2691-44B3-B39F-A9ADDDB37436")
SKR_PLC_CHK;
#endif

#ifndef __ILOCK_ON_CMD_DISPINTERFACE_DEFINED__
#define __ILOCK_ON_CMD_DISPINTERFACE_DEFINED__

/* dispinterface ILOCK_ON_CMD */
/* [uuid] */ 


EXTERN_C const IID DIID_ILOCK_ON_CMD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B123823B-465C-418D-995C-859460FE817F")
    ILOCK_ON_CMD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILOCK_ON_CMDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILOCK_ON_CMD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILOCK_ON_CMD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILOCK_ON_CMD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILOCK_ON_CMD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILOCK_ON_CMD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILOCK_ON_CMD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILOCK_ON_CMD * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILOCK_ON_CMDVtbl;

    interface ILOCK_ON_CMD
    {
        CONST_VTBL struct ILOCK_ON_CMDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILOCK_ON_CMD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILOCK_ON_CMD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILOCK_ON_CMD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILOCK_ON_CMD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILOCK_ON_CMD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILOCK_ON_CMD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILOCK_ON_CMD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILOCK_ON_CMD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LOCK_ON_CMD;

#ifdef __cplusplus

class DECLSPEC_UUID("D172C5F0-4D99-43CD-A0DA-A77ECEFC705B")
LOCK_ON_CMD;
#endif

#ifndef __ISKR_TRK_STATUS_DISPINTERFACE_DEFINED__
#define __ISKR_TRK_STATUS_DISPINTERFACE_DEFINED__

/* dispinterface ISKR_TRK_STATUS */
/* [uuid] */ 


EXTERN_C const IID DIID_ISKR_TRK_STATUS;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("873BDC63-8783-4F63-AF3D-715FDEA9E30A")
    ISKR_TRK_STATUS : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISKR_TRK_STATUSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISKR_TRK_STATUS * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISKR_TRK_STATUS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISKR_TRK_STATUS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISKR_TRK_STATUS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISKR_TRK_STATUS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISKR_TRK_STATUS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISKR_TRK_STATUS * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISKR_TRK_STATUSVtbl;

    interface ISKR_TRK_STATUS
    {
        CONST_VTBL struct ISKR_TRK_STATUSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISKR_TRK_STATUS_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISKR_TRK_STATUS_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISKR_TRK_STATUS_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISKR_TRK_STATUS_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISKR_TRK_STATUS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISKR_TRK_STATUS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISKR_TRK_STATUS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISKR_TRK_STATUS_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SKR_TRK_STATUS;

#ifdef __cplusplus

class DECLSPEC_UUID("85E2A9F5-3C51-424F-9075-BF3BF22EF5ED")
SKR_TRK_STATUS;
#endif

#ifndef __IATK_MODE_CMD_DISPINTERFACE_DEFINED__
#define __IATK_MODE_CMD_DISPINTERFACE_DEFINED__

/* dispinterface IATK_MODE_CMD */
/* [uuid] */ 


EXTERN_C const IID DIID_IATK_MODE_CMD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EACA9016-528F-43E0-A4F4-74DCAC527636")
    IATK_MODE_CMD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IATK_MODE_CMDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IATK_MODE_CMD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IATK_MODE_CMD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IATK_MODE_CMD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IATK_MODE_CMD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IATK_MODE_CMD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IATK_MODE_CMD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IATK_MODE_CMD * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IATK_MODE_CMDVtbl;

    interface IATK_MODE_CMD
    {
        CONST_VTBL struct IATK_MODE_CMDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IATK_MODE_CMD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IATK_MODE_CMD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IATK_MODE_CMD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IATK_MODE_CMD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IATK_MODE_CMD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IATK_MODE_CMD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IATK_MODE_CMD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IATK_MODE_CMD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ATK_MODE_CMD;

#ifdef __cplusplus

class DECLSPEC_UUID("E61F5F4D-667B-4EE8-A66E-A5ADD3C10775")
ATK_MODE_CMD;
#endif

#ifndef __IMSL_STS_CHK_DISPINTERFACE_DEFINED__
#define __IMSL_STS_CHK_DISPINTERFACE_DEFINED__

/* dispinterface IMSL_STS_CHK */
/* [uuid] */ 


EXTERN_C const IID DIID_IMSL_STS_CHK;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("655B3638-80B2-4C05-A7FC-8A6C2FB71485")
    IMSL_STS_CHK : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMSL_STS_CHKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSL_STS_CHK * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSL_STS_CHK * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSL_STS_CHK * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSL_STS_CHK * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSL_STS_CHK * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSL_STS_CHK * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSL_STS_CHK * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IMSL_STS_CHKVtbl;

    interface IMSL_STS_CHK
    {
        CONST_VTBL struct IMSL_STS_CHKVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSL_STS_CHK_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSL_STS_CHK_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSL_STS_CHK_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSL_STS_CHK_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSL_STS_CHK_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSL_STS_CHK_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSL_STS_CHK_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMSL_STS_CHK_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MSL_STS_CHK;

#ifdef __cplusplus

class DECLSPEC_UUID("B62A06B7-1711-4387-BDE3-A68CB8B60988")
MSL_STS_CHK;
#endif

#ifndef __ILIFTOFF_RDY_CMD_DISPINTERFACE_DEFINED__
#define __ILIFTOFF_RDY_CMD_DISPINTERFACE_DEFINED__

/* dispinterface ILIFTOFF_RDY_CMD */
/* [uuid] */ 


EXTERN_C const IID DIID_ILIFTOFF_RDY_CMD;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("34890301-9330-45D1-899D-F36DA851E121")
    ILIFTOFF_RDY_CMD : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ILIFTOFF_RDY_CMDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILIFTOFF_RDY_CMD * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILIFTOFF_RDY_CMD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILIFTOFF_RDY_CMD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILIFTOFF_RDY_CMD * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILIFTOFF_RDY_CMD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILIFTOFF_RDY_CMD * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILIFTOFF_RDY_CMD * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ILIFTOFF_RDY_CMDVtbl;

    interface ILIFTOFF_RDY_CMD
    {
        CONST_VTBL struct ILIFTOFF_RDY_CMDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILIFTOFF_RDY_CMD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILIFTOFF_RDY_CMD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILIFTOFF_RDY_CMD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILIFTOFF_RDY_CMD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILIFTOFF_RDY_CMD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILIFTOFF_RDY_CMD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILIFTOFF_RDY_CMD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ILIFTOFF_RDY_CMD_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LIFTOFF_RDY_CMD;

#ifdef __cplusplus

class DECLSPEC_UUID("F8056AE6-1658-4DBF-87F8-FD0ED0780703")
LIFTOFF_RDY_CMD;
#endif

#ifndef __IPINSQ_DISPINTERFACE_DEFINED__
#define __IPINSQ_DISPINTERFACE_DEFINED__

/* dispinterface IPINSQ */
/* [uuid] */ 


EXTERN_C const IID DIID_IPINSQ;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B58E4D17-E843-4C5A-AF85-708C5FD2D66C")
    IPINSQ : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPINSQVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPINSQ * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPINSQ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPINSQ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPINSQ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPINSQ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPINSQ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPINSQ * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IPINSQVtbl;

    interface IPINSQ
    {
        CONST_VTBL struct IPINSQVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPINSQ_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPINSQ_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPINSQ_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPINSQ_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPINSQ_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPINSQ_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPINSQ_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPINSQ_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PINSQ;

#ifdef __cplusplus

class DECLSPEC_UUID("AD08936E-35FD-42C3-B4D5-CCEADCE8C73F")
PINSQ;
#endif

#ifndef __IEMSQ_DISPINTERFACE_DEFINED__
#define __IEMSQ_DISPINTERFACE_DEFINED__

/* dispinterface IEMSQ */
/* [uuid] */ 


EXTERN_C const IID DIID_IEMSQ;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2349ACB6-98A9-4263-B124-D56986E6A729")
    IEMSQ : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEMSQVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEMSQ * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEMSQ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEMSQ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEMSQ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEMSQ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEMSQ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEMSQ * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IEMSQVtbl;

    interface IEMSQ
    {
        CONST_VTBL struct IEMSQVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEMSQ_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEMSQ_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEMSQ_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEMSQ_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEMSQ_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEMSQ_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEMSQ_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEMSQ_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_EMSQ;

#ifdef __cplusplus

class DECLSPEC_UUID("948FB563-82D9-467F-B3E2-16D136D78812")
EMSQ;
#endif
#endif /* __FCU_SW_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


