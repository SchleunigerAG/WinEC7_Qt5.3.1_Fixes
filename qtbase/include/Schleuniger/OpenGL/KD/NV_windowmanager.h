/*
 * Copyright (c) 2007 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA Corporation is strictly prohibited.
 */


#ifndef __kd_NV_windowmanager_h_
#define __kd_NV_windowmanager_h_
#include <KD/kd.h>
#include <EGL/eglext.h>

#ifdef __cplusplus
extern "C" {
#endif



/* KDWMClientNV: The representation of window manager client application. */
typedef struct KDWMClientNV KDWMClientNV;

/* KDWMClientWindowNV: The representation of window manager client window. */
typedef struct KDWMClientWindowNV KDWMClientWindowNV;

/* KDWMIndexedDataElemDefNV: An indexed data element definition, used for setting supported window properties and outputs. */

#define KD_INDEXEDDATATYPE_KDINT32 1
#define KD_INDEXEDDATATYPE_KDINT64 2
#define KD_INDEXEDDATATYPE_KDFLOAT32 3
#define KD_INDEXEDDATATYPE_KDBOOLEAN 4
#define KD_INDEXEDDATATYPE_KDCHAR 5

typedef struct KDWMIndexedDataElemDefNV
{
    KDint32 index;
    KDint32 type;
    KDint32 numelements;
} KDWMIndexedDataElemDefNV;

/* KDWMIndexedDataElemNV: An indexed data element, used to carry indexed data */

typedef struct KDWMIndexedDataElemNV
{
    KDint32 index;
    union
    {
        KDint32* i;
        KDint64* l;
        KDfloat32* f;
        KDboolean* b;
        KDchar* c;
    } data;
} KDWMIndexedDataElemNV;

/* KDWMSurfaceFreeEventDataNV: wrapper for returning surface userdata in event */

typedef struct KDWMSurfaceFreeEventDataNV
{
    void* surfaceUsrptr;
} KDWMSurfaceFreeEventDataNV;

/* KD_EVENT_WMCLIENT_REGISTER_NV: Client register event. */
#define KD_EVENT_WMCLIENT_REGISTER_NV 6001

/* KD_EVENT_WMCLIENT_UNREGISTER_NV: Client unregister event. */
#define KD_EVENT_WMCLIENT_UNREGISTER_NV 6002

/* KD_EVENT_WMCLIENT_WINDOWCREATE_NV: Client window create event. */
#define KD_EVENT_WMCLIENT_WINDOWCREATE_NV 6003

/* KD_EVENT_WMCLIENT_WINDOWDESTROY_NV: Client window destroy event. */
#define KD_EVENT_WMCLIENT_WINDOWDESTROY_NV 6004

/* KD_EVENT_WMCLIENT_WINDOWREALIZE_NV: Client window realize event. */
#define KD_EVENT_WMCLIENT_WINDOWREALIZE_NV 6005

/* KD_EVENT_WMCLIENT_WINDOWSWAP_NV: Client window swap event. */
#define KD_EVENT_WMCLIENT_WINDOWSWAP_NV 6006

/* KD_EVENT_WMCLIENT_WINDOWPROPERTY_NV: Client window property change request event. */
#define KD_EVENT_WMCLIENT_WINDOWPROPERTY_NV 6007
      

/* KD_EVENT_WMCLIENT_OUTPUT_NV: Client output request event. */
#define KD_EVENT_WMCLIENT_OUTPUT_NV 6008

/* KD_EVENT_WMCLIENT_SURFACE_RELEASE_NV: Client window surface release event. */
#define KD_EVENT_WMCLIENT_SURFACE_RELEASE_NV 6009

/* kdSetWMClientUserDataNV: Set user data associated with a window manager client. */
KD_API void KD_APIENTRY kdSetWMClientUserDataNV(KDWMClientNV* client, void* data);

/* kdGetWMClientUserDataNV: Get user data associated with a window manager client. */
KD_API void* KD_APIENTRY kdGetWMClientUserDataNV(KDWMClientNV* client);

/* kdSetWMClientWindowUserDataNV: Set user data associated with a client window. */
KD_API void KD_APIENTRY kdSetWMClientWindowUserDataNV(KDWMClientWindowNV* window, void* data);

/* kdGetWMClientWindowUserDataNV: Get user data associated with a client window. */
KD_API void* KD_APIENTRY kdGetWMClientWindowUserDataNV(KDWMClientWindowNV* window);

/* kdGetWMClientNV: Get the owner of a client window. */
KD_API KDWMClientNV* KD_APIENTRY kdGetWMClientNV(KDWMClientWindowNV* window);

/* kdWMEventProcessedNV: Signal that a window manager event is processed and all actions based on the event have been performed. */
KD_API void KD_APIENTRY kdWMEventProcessedNV(const KDEvent* event, KDint error);

/* kdSetSupportedWindowPropertiesNV: Set the collection of window properties that the window manager application supports. */
KD_API KDint KD_APIENTRY kdSetSupportedWindowPropertiesNV(const KDWMIndexedDataElemDefNV* properties, KDint size);

/* kdSetSupportedOutputsNV: Set the collection of outputs that the window manager application supports. */
KD_API KDint KD_APIENTRY kdSetSupportedOutputsNV(const KDWMIndexedDataElemDefNV* outputs, KDint size);

/* kdSetSupportedStatesNV: Set the collection of states that the window manager application supports. */
KD_API KDint KD_APIENTRY kdSetSupportedStatesNV(const KDWMIndexedDataElemDefNV* states, KDint size);

/* kdSetWMClientStateNV: Set a client global state value. */
KD_API KDint KD_APIENTRY kdSetWMClientStateNV(KDWMClientNV* client, const KDWMIndexedDataElemNV* value);

/* kdSetWMClientWindowPropertyNV: Set a client window property. */
KD_API KDint KD_APIENTRY kdSetWMClientWindowPropertyNV(KDWMClientWindowNV* window, const KDWMIndexedDataElemNV* value);

/* kdDispatchWindowEventNV, kdDispatchSystemEventNV: Dispatch OpenKODE events to clients. */
KD_API KDint KD_APIENTRY kdDispatchWindowEventNV(KDWMClientWindowNV* window, KDint32 type, const KDuint8* data, KDint datalen, KDboolean merge);
KD_API KDint KD_APIENTRY kdDispatchSystemEventNV(KDWMClientNV* client, KDint32 type, const KDuint8* data, KDint datalen, KDboolean merge);

/* kdSetWMClientWindowRenderSurfacesNV: Set client window render surfaces. */
KD_API KDint KD_APIENTRY kdSetWMClientWindowRenderSurfacesNV(KDWMClientWindowNV* window, EGLImageKHR* surfaces, void** surfaceUserData, KDint numSurfaces, KDint x, KDint y, KDint width, KDint height);

/* kdGetWMClientWindowFrontBufferNV: Get the current client window front buffer and the client's perception of the window size (stored in the client window properties) at the time of the last client update. */
KD_API void* KD_APIENTRY kdGetWMClientWindowFrontBufferNV(KDWMClientWindowNV* window, KDint* x, KDint* y, KDint* width, KDint* height);

/* kdLockWMClientWindowNV: Lock the client window, preventing it from swapping its buffers. */
KD_API void KD_APIENTRY kdLockWMClientWindowNV(KDWMClientWindowNV* window);

/* kdReleaseWMClientWindowNV: Release the client window to allow the client to swap the buffers. */
KD_API void KD_APIENTRY kdReleaseWMClientWindowNV(KDWMClientWindowNV* window);

#ifdef __cplusplus
}
#endif

#endif /* __kd_NV_windowmanager_h_ */
