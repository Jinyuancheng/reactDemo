

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for activexone.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
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


#ifndef __activex2Doneidl_h__
#define __activex2Doneidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___Dactivexone_FWD_DEFINED__
#define ___Dactivexone_FWD_DEFINED__
typedef interface _Dactivexone _Dactivexone;

#endif 	/* ___Dactivexone_FWD_DEFINED__ */


#ifndef ___DactivexoneEvents_FWD_DEFINED__
#define ___DactivexoneEvents_FWD_DEFINED__
typedef interface _DactivexoneEvents _DactivexoneEvents;

#endif 	/* ___DactivexoneEvents_FWD_DEFINED__ */


#ifndef __activexone_FWD_DEFINED__
#define __activexone_FWD_DEFINED__

#ifdef __cplusplus
typedef class activexone activexone;
#else
typedef struct activexone activexone;
#endif /* __cplusplus */

#endif 	/* __activexone_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_activexone_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_activexone_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_activexone_0000_0000_v0_0_s_ifspec;


#ifndef __activexoneLib_LIBRARY_DEFINED__
#define __activexoneLib_LIBRARY_DEFINED__

/* library activexoneLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_activexoneLib;

#ifndef ___Dactivexone_DISPINTERFACE_DEFINED__
#define ___Dactivexone_DISPINTERFACE_DEFINED__

/* dispinterface _Dactivexone */
/* [uuid] */ 


EXTERN_C const IID DIID__Dactivexone;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("f7de0f19-c0f0-4e94-92c0-7bdd4437b79e")
    _Dactivexone : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DactivexoneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Dactivexone * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Dactivexone * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Dactivexone * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Dactivexone * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Dactivexone * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Dactivexone * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Dactivexone * This,
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
    } _DactivexoneVtbl;

    interface _Dactivexone
    {
        CONST_VTBL struct _DactivexoneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Dactivexone_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Dactivexone_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Dactivexone_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Dactivexone_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Dactivexone_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Dactivexone_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Dactivexone_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Dactivexone_DISPINTERFACE_DEFINED__ */


#ifndef ___DactivexoneEvents_DISPINTERFACE_DEFINED__
#define ___DactivexoneEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DactivexoneEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DactivexoneEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ca633a28-4a3d-45dd-9798-04dbcf4e8809")
    _DactivexoneEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DactivexoneEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DactivexoneEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DactivexoneEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DactivexoneEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DactivexoneEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DactivexoneEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DactivexoneEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DactivexoneEvents * This,
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
    } _DactivexoneEventsVtbl;

    interface _DactivexoneEvents
    {
        CONST_VTBL struct _DactivexoneEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DactivexoneEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DactivexoneEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DactivexoneEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DactivexoneEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DactivexoneEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DactivexoneEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DactivexoneEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DactivexoneEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_activexone;

#ifdef __cplusplus

class DECLSPEC_UUID("fd510174-7005-4a4e-babe-04f892a1c372")
activexone;
#endif
#endif /* __activexoneLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


