/* Copyright (c) 2007 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an
 * express license agreement from NVIDIA Corporation is strictly prohibited.
 */

/** 
 * @file
 * <b>NVIDIA Tegra: OpenMAX Index Extension Interface</b>
 *
 */

/**
 * @defgroup nv_omx_il_index General Index
 *   
 * This is the NVIDIA OpenMAX index extensions interface. 
 *
 * These extensions custom events and error codes.
 *
 * @ingroup nvomx_general_extension
 * @{
 */

#ifndef _NVOMX_IndexExtensions_h_
#define _NVOMX_IndexExtensions_h_

#include <OMX_Core.h>
#include <OMX_Component.h>

#include "OMX_Core.h"

#include "NVOMX_RendererExtensions.h"
#include "NVOMX_ParserExtensions.h"
#include "NVOMX_CameraExtensions.h"
#include "NVOMX_DecoderExtensions.h"

/** Representation of timeout values, in milliseconds */
typedef OMX_U32 NvxTimeMs;

/** Maximum timeout value (Never timeout) */
#define NVX_TIMEOUT_NEVER   0xffffffff
/** Minimum timeout value */
#define NVX_TIMEOUT_MIN     0

/** Custom event extensions */
typedef enum NVX_EVENTTYPE_ENUM {
    /** Start of extended OpenMAX camera event types */
    NVX_EventVendorStartUnused = 0x70000000,

    /** Image capture started */
    NVX_EventImageStart = (NVX_EventVendorStartUnused | 0xB00000),
    /** Image EXIF information ready */
    NVX_EventImage_EXIFInfo                    = NVX_EventImageStart + 1,
    /** Camera component started */
    NVX_EventCameraStart = (NVX_EventVendorStartUnused | 0xD00000),
    /** Camera AE, AF, AWB locked */
    NVX_EventCamera_AlgorithmsLocked           = NVX_EventCameraStart,
    /** Camera auto focus achieved */
    NVX_EventCamera_AutoFocusAchieved,
    /** Camera auto exposure achieved */
    NVX_EventCamera_AutoExposureAchieved,
    /** Camera auto white balance achieved */
    NVX_EventCamera_AutoWhiteBalanceAchieved,
    /** Camera auto focus timed out */
    NVX_EventCamera_AutoFocusTimedOut,
    /** Camera auto exposure timed out */
    NVX_EventCamera_AutoExposureTimedOut,
    /** Camera auto white balance timed out */
    NVX_EventCamera_AutoWhiteBalanceTimedOut,
    /** Camera capture aborted */
    NVX_EventCamera_CaptureAborted,
    /** Camera capture started */
    NVX_EventCamera_CaptureStarted,
    /** Camera still capture completed */
    NVX_EventCamera_StillCaptureReady,

    /** Start of extended OpenMAX renderer event types */
    NVX_EventRendererStart = (NVX_EventVendorStartUnused | 0xE00000),
    /** First video frame displayed */
    NVX_EventFirstFrameDisplayed,
    /** First audio sample played */
    NVX_EventFirstAudioFramePlayed,

    /** Start of extended OpenMAX other event types */
    NVX_EventOtherStart = (NVX_EventVendorStartUnused | 0xF00000),
    /** NVIDIA multimedia block warning */
    NVX_EventBlockWarning,
    NVX_EventForBuffering,

    NVX_EventDRM_DirectLicenseAcquisition,

    /** Limit of extended OpenMAX event types */
    NVX_EventMax = OMX_EventMax,
} NVX_EVENTTYPE;

/** Custom error extensions */
typedef enum
{
    /** Start of extended OpenMAX error types */
    NvxError_ExtendedCodesStart = 0x80004000,

    /** Parser returns DRM license not found for particular track */
    NvxError_ParserDRMLicenseNotFound = 0x80004001,

    /** Parser returns DRM license error */
    NvxError_ParserDRMFailure = 0x80004002,

    /** Parser returns DRM license error */
    NvxError_ParserCorruptedStream = 0x80004003,

    /** Parser returns Seek Unsupported */
    NvxError_ParserSeekUnSupported = 0x80004004, 
    
    /** Parser returns Trickmode Unsupported */
    NvxError_ParserTrickModeUnSupported = 0x80004005, 

    /** Writer returns insufficient memory */
    NvxError_WriterInsufficientMemory = 0x80004006,

    /** Writer returns file write failed */
    NvxError_FileWriteFailed = 0x80004007,

    /** Writer returns write failure */
    NvxError_WriterFailure = 0x80004008,

    /** Writer returns unsupported stream */
    NvxError_WriterUnsupportedStream = 0x80004009,

    /** Writer returns unsupported user data */
    NvxError_WriterUnsupportedUserData = 0x8000400A,

    /** Writer returns 2GB limit exceeded */
    NvxError_WriterFileSizeLimitExceeded = 0x8000400B,

    /** Limit of extended OpenMAX error types */
    NvxError_Max = 0x7FFFFFFF
} NvxError;

/** @} */

/* Indicates the config changed on a port (buffer flag version) */
#define NVX_BUFFERFLAG_CONFIGCHANGED  0x00040000

/** Profiling config for internal use only */
#define NVX_INDEX_CONFIG_PROFILE "OMX.Nvidia.index.config.profile"
/** Holds a profiling information. */
typedef struct NVX_CONFIG_PROFILE
{
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;

    OMX_BOOL bProfile;
#define PROFILE_FILE_NAME_LENGTH 256
    char     ProfileFileName[PROFILE_FILE_NAME_LENGTH];
    OMX_BOOL bVerbose;
    OMX_BOOL bStubOutput;
    OMX_U32  nForceLocale; // 0 - no, 1 -cpu, 2 - avp
    OMX_U32  nNvMMProfile;
    OMX_BOOL bNoAVSync;
    OMX_BOOL enableUlpMode;
    OMX_U32 ulpkpiMode;
    OMX_S32  nAVSyncOffset;
    OMX_BOOL bFlip;
    OMX_U32  nFrameDrop;

    OMX_BOOL bSanity;
    OMX_U32  nAvgFPS;
    OMX_U32  nTotFrameDrops;

    // for camera
    OMX_U64 nTSPreviewStart;
    OMX_U64 nTSCaptureStart;
    OMX_U64 nTSCaptureEnd;
    OMX_U64 nTSPreviewEnd;
    OMX_U32 nPreviewStartFrameCount;
    OMX_U32 nPreviewEndFrameCount;
    OMX_U32 nCaptureStartFrameCount;
    OMX_U32 nCaptureEndFrameCount;
    OMX_S32 xExposureTime;
    OMX_S32 nExposureISO;
    OMX_U32 nBadFrameCount;
} NVX_CONFIG_PROFILE;

/** Config extension index NV specific (i.e. OEM specific) buffers within OMX_Buffer header
 *  See ::NVX_PARAM_USENVBUFFER
 */

/** OMX extension index to EMBED  */
#define NVX_INDEX_CONFIG_USENVBUFFER \
    "OMX.Nvidia.index.config.usenvbuffer"       /**< reference: OMX_PARAM_BOOLEANTYPE */

/** NVIDIA specific buffer Flag:
  *
  * A component sets OMX_BUFFERFLAG_NV_BUFFER to indicate a NVIDIA (i.e. OEM ) specific Buffer
  * is embedded within the OMX Buffer Payload Data.  This Buffer Flag is intended to be used across
  * two NVIDIA openmax components in non-Tunneled mode. (e.g. Video Capture on Android Camcorder app)
  * @ingroup buf
  */

#define OMX_BUFFERFLAG_NV_BUFFER 0x10000000 

/** Holds data to enable proprietary buffer transfers. */
typedef struct NVX_PARAM_USENVBUFFER
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< OMX specification version info */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_BOOL bUseNvBuffer;
} NVX_PARAM_USENVBUFFER;

#endif

/* File EOF */
