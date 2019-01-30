/* Copyright (c) 2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an
 * express license agreement from NVIDIA Corporation is strictly prohibited.
 */

/** 
 * @file
 * <b>NVIDIA Tegra: OpenMAX Camera Extension Interface</b>
 *
 */

/**
 * @defgroup nv_omx_il_camera Camera
 *   
 * This is the NVIDIA OpenMAX camera class extension interface. 
 *
 * These extensions include auto-focus, auto-exposure, auto-whitebalance, half-press, 
 * focus regions, sharpness, hue, framerate, encoder control, edge enhancement and more.
 *
 * @ingroup nvomx_camera_extension
 * @{
 */

#ifndef NVOMX_CameraExtensions_h_
#define NVOMX_CameraExtensions_h_

typedef float NVX_F32;

/** Holds a floating point rectangle. */
typedef struct NVX_RectF32
{
    OMX_S32 left;
    OMX_S32 top;
    OMX_S32 right;
    OMX_S32 bottom;
} NVX_RectF32;

#define NVX_MAX_FOCUS_REGIONS  8
#define NVX_MAX_DIRECT_FOCUSER_CONTROL_LENGTH  16
#define NVX_VIDEOENC_DCI_SIZE 80
#define MAX_NUM_SENSOR_MODES  8

typedef enum NVX_VIDEO_ERROR_RESILIENCY_LEVEL_TYPE {
    NVX_VIDEO_ErrorResiliency_None = 0,
    NVX_VIDEO_ErrorResiliency_Low,
    NVX_VIDEO_ErrorResiliency_High,
    NVX_VIDEO_ErrorResiliency_Invalid = 0x7FFFFFFF
} NVX_VIDEO_ERROR_RESILIENCY_LEVEL_TYPE;

typedef enum NVX_VIDEO_APPLICATION_TYPE {
    NVX_VIDEO_Application_Camcorder = 0,    /**< Timestamps set for camcorder */
    NVX_VIDEO_Application_VideoTelephony,   /**< Timestamps set for telephony */
    NVX_VIDEO_Application_Invalid = 0x7FFFFFFF
} NVX_VIDEO_APPLICATION_TYPE;

/** Param extension index to fine tune video encoder configuration.
 *  See ::NVX_PARAM_VIDENCPROPERTY
 */
#define NVX_INDEX_PARAM_VIDEO_ENCODE_PROPERTY "OMX.Nvidia.index.param.video.encode.prop"
/** Holds data to fine tune video encoder configuration. */
typedef struct NVX_PARAM_VIDENCPROPERTY
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */

    NVX_VIDEO_APPLICATION_TYPE eApplicationType;                    /**< Application Type */
    NVX_VIDEO_ERROR_RESILIENCY_LEVEL_TYPE eErrorResiliencyLevel;    /**< Error Resiliency Level */
    OMX_BOOL bSvcEncodeEnable;                                      /**< Boolean to enable H.264 Scalable Video Codec mode */
} NVX_PARAM_VIDENCPROPERTY;

/** Param extension index to enable/disable stringent bitrate for encoder.
 *  See ::OMX_CONFIG_BOOLEANTYPE
 */
#define NVX_INDEX_PARAM_VIDEO_ENCODE_STRINGENTBITRATE "OMX.Nvidia.index.param.video.encode.stringentbitrate"

/** Config extension index to enable camera test pattern.
 *  See ::NVX_CONFIG_CAMERATESTPATTERN
 */
#define NVX_INDEX_CONFIG_CAMERATESTPATTERN "OMX.Nvidia.index.config.cameratestpattern"
/** Holds data to enable camera test pattern. */
typedef struct NVX_CONFIG_CAMERATESTPATTERN
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32 TestPatternIndex;       /**< Boolean to enable test pattern */
}NVX_CONFIG_CAMERATESTPATTERN;

/** Config extension index to set duration in milliseconds for smooth zooming.
 *  See ::OMX_PARAM_U32TYPE
 */
#define NVX_INDEX_CONFIG_SMOOTHZOOMTIME "OMX.Nvidia.index.config.smoothzoomtime"

/** Config extension index to abort zooming.
 *  See ::OMX_CONFIG_BOOLEANTYPE
 */
#define NVX_INDEX_CONFIG_ZOOMABORT "OMX.Nvidia.index.config.zoomabort"

/** Config extension index to set scale factor multiplier in digital zoom.
 *  See ::NVX_CONFIG_DZSCALEFACTORMULTIPLIER
 */
#define NVX_INDEX_CONFIG_DZSCALEFACTORMULTIPLIER "OMX.Nvidia.index.config.dzscalefactormultiplier"
/** Holds data to set scale factor multiplier in digital zoom. */
typedef struct NVX_CONFIG_DZSCALEFACTORMULTIPLIER
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_S32 ZoomFactorMultiplier;   /**< Scale factor from 100 to 800 (1.0-8.0) up to 8x digital */
}NVX_CONFIG_DZSCALEFACTORMULTIPLIER;

/** Config extension index to enable/disable camera preview.
 *  See ::OMX_CONFIG_BOOLEANTYPE
 */
#define NVX_INDEX_CONFIG_PREVIEWENABLE "OMX.Nvidia.index.config.previewenable"

/** Config extension index to enable/disable capture pause.
 *  See ::OMX_CONFIG_BOOLEANTYPE
 */
#define NVX_INDEX_CONFIG_CAPTUREPAUSE "OMX.Nvidia.index.config.capturepause"

/** Config extension index to setup converge and lock (half-press).
 * When this extension is called, the camera component will start
 * converging (achieving) auto focus, auto exposure, and/or auto
 * white balance. If the camera component achieves one or
 * more of these properties then it will lock settings of those
 * properties. If the camera component was unable to achieve one or
 * more of those properties in a certain time then it times out
 * for that property.
 * 
 * The camera component notifies the application about
 * those properties that were achieved and those that timed out
 * using events. The following lists shows the different
 * events that are sent.
 * - Auto focus achieved (See ::NVX_EventCamera_AutoFocusAchieved)
 * - Auto focus timed out (See ::NVX_EventCamera_AutoFocusTimedOut)
 * - Auto exposure achieved (See ::NVX_EventCamera_AutoExposureAchieved)
 * - Auto exposure timed out (See ::NVX_EventCamera_AutoExposureTimedOut)
 * - Auto white balance achieved (See
 *      ::NVX_EventCamera_AutoWhiteBalanceAchieved)
 * - Auto white balance timed out (See 
 *      ::NVX_EventCamera_AutoWhiteBalanceTimedOut)
 * 
  * Although converge and lock is used with auto focus, auto exposure, and
 * auto white balance properties, an application can choose to
 * enable any one or any combination of these properties. When
 * any of these properties is disabled then half press will not
 * attempt to achieve that property.
 *
 *  See ::NVX_CONFIG_CONVERGEANDLOCK
 */
#define NVX_INDEX_CONFIG_CONVERGEANDLOCK "OMX.Nvidia.index.config.convergeandlock"
/** Holds data to setup converge and lock. */
typedef struct NVX_CONFIG_CONVERGEANDLOCK
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_BOOL bUnlock;               /**< Boolean to unlock AF, AE, AWB settings */
    OMX_BOOL bAutoFocus;            /**< Boolean to enable auto focus */
    OMX_BOOL bAutoExposure;         /**< Boolean to enable auto exposure */
    OMX_BOOL bAutoWhiteBalance;     /**< Boolean to enable auto white balance */
    OMX_U32  nTimeOutMS;            /**< Timeout in milliseconds */
} NVX_CONFIG_CONVERGEANDLOCK;

/** Config extension index to setup pre-capture converge.
 *  @deprecated This index is deprecated.
 */
#define NVX_INDEX_CONFIG_PRECAPTURECONVERGE "OMX.Nvidia.index.config.precaptureconverge"
/** Holds data to setup pre-capture converge. */
typedef struct NVX_CONFIG_PRECAPTURECONVERGE
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_BOOL bPrecaptureConverge;       /**< Boolean to enable pre-capture converge */
    OMX_BOOL bContinueDuringCapture;    /**< Boolean to enable continous converge during capture */
    OMX_U32  nTimeOutMS;                /**< Timeout in milliseconds */
} NVX_CONFIG_PRECAPTURECONVERGE;

/** Config extension index to setup min and max frame rate for camera.
 *  See ::NVX_CONFIG_AUTOFRAMERATE
 */
#define NVX_INDEX_CONFIG_AUTOFRAMERATE "OMX.Nvidia.index.config.autoframerate"
/** Holds data to setup auto frame rate for camera. */
typedef struct NVX_CONFIG_AUTOFRAMERATE
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_BOOL bEnabled;              /**< Boolean to enable auto frame rate */
    OMX_S32  low;                   /**< Lowest frame rate allowed */
    OMX_S32  high;                  /**< Highest frame rate allowed */
} NVX_CONFIG_AUTOFRAMERATE;

/** Config extension index to setup raw capture.
 *  See ::NVX_CONFIG_CAMERARAWCAPTURE
 */
#define NVX_INDEX_CONFIG_CAMERARAWCAPTURE "OMX.Nvidia.index.config.camera.rawcapture"
/** Holds data to setup raw capture. */
typedef struct NVX_CONFIG_CAMERARAWCAPTURE
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32 nCaptureCount;          /**< Number of frames to capture */
    OMX_STRING Filename;            /**< File name to store into */
} NVX_CONFIG_CAMERARAWCAPTURE;

typedef enum
{
    NvxFlicker_Off,
    NvxFlicker_Auto,
    NvxFlicker_50HZ,
    NvxFlicker_60HZ
} ENvxFlickerType;

/** Config extension index to setup flicker.
 *  See ::NVX_CONFIG_FLICKER
 */
#define NVX_INDEX_CONFIG_FLICKER "OMX.Nvidia.index.config.flicker"
/** Holds data to setup flicker. */
typedef struct NVX_CONFIG_FLICKER
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    ENvxFlickerType eFlicker;       /**< Flicker type */
} NVX_CONFIG_FLICKER;

typedef enum NVX_IMAGEFILTERTYPE {
    NVX_ImageFilterPosterize = 0x30000000,
    NVX_ImageFilterSepia,
    NVX_ImageFilterBW,
    NVX_ImageFilterMax = 0x7FFFFFFF
} NVX_IMAGEFILTERTYPE;

/** Config extension index to setup hue. 
 *  See ::NVX_CONFIG_HUETYPE
 */
#define NVX_INDEX_CONFIG_HUE "OMX.Nvidia.index.config.hue"
/** Holds data to setup hue. */
typedef struct NVX_CONFIG_HUETYPE
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_S32 nHue;                   /**< Hue in degrees, 0 to 359 */
} NVX_CONFIG_HUETYPE;


/** Config extension index to control focus regions.
 * The rectangle coordinates are normalized to -1.0 to 1.0 on the
 * X and Y axis. 
 * Auto focus region will work only when auto focus is enabled. 
 *
 *  See ::NVX_CONFIG_FocusRegionsRect
 */
#define NVX_INDEX_CONFIG_FOCUSREGIONSRECT "OMX.Nvidia.index.config.focusregionsrect"
/** Holds data to control focus regions. */
typedef struct NVX_CONFIG_FocusRegionsRect
{
    OMX_U32      nRegions;                          /**< Number of regions */
    NVX_RectF32  regions[NVX_MAX_FOCUS_REGIONS];    /**< Array of NVX_RectF32 to specify each focus region */
} NVX_CONFIG_FocusRegionsRect;

/** Config extension index to control camera focusing regions sharpness values.
 *  See ::NVX_CONFIG_FOCUSREGIONS_SHARPNESS
 */
#define NVX_INDEX_CONFIG_FOCUSREGIONSSHARPNESS "OMX.Nvidia.index.config.focusregionssharpness"
/** Holds data to control camera focusing regions sharpness values. */
typedef struct NVX_CONFIG_FOCUSREGIONS_SHARPNESS
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32           nRegions;                             /**< Number of currently active focusing regions */
    NVX_F32           nSharpness[NVX_MAX_FOCUS_REGIONS];    /**< Sharpness values for active focusing regions */
} NVX_CONFIG_FOCUSREGIONS_SHARPNESS;    

/** Config extension index for direct focuser control.
 *  See ::NVX_CONFIG_DIRECT_FOCUSERCONTROL
 */
#define NVX_INDEX_CONFIG_DIRECTFOCUSERCONTROL "OMX.Nvidia.index.config.directfocusercontrol"
/** Holds a direct focuser control. */
typedef struct NVX_CONFIG_DIRECT_FOCUSERCONTROL
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32           nLength;                                              /**< Length of focuser control sequence */
    OMX_U32           nControl[NVX_MAX_DIRECT_FOCUSER_CONTROL_LENGTH];      /**< Focuser control sequence */
} NVX_CONFIG_DIRECT_FOCUSERCONTROL;

/** Config extension for querying camera low-level focuser device capabilities.
 *  See ::NVX_CONFIG_FOCUSER_CAPABILITIES
 */
#define NVX_INDEX_CONFIG_FOCUSERCAPABILITIES "OMX.Nvidia.index.config.focusercapabilities"
/** Holds a querying focuser capabilities. */
typedef struct NVX_CONFIG_FOCUSER_CAPABILITIES
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32           nRange;               /**< Range of focuser movement in device-dependent steps */
    NVX_F32           directionFactor;      /**< Scaling factor for focuser device movement in "infinity" and "macro" directions */
    OMX_U32           nSettleTime;          /**< Guaranteed settling time in millisecs */
} NVX_CONFIG_FOCUSER_CAPABILITIES;

/** Holds a sensor mode configuration. */
typedef struct NVX_SENSORMODE
{
    OMX_S32 width;
    OMX_S32 height;
    NVX_F32 FrameRate;
} NVX_SENSORMODE;

/** Config extension index to control sensor mode list of supported resolution and frame rate.
 *  See ::NVX_CONFIG_SENSORMODELIST
 */
#define NVX_INDEX_CONFIG_SENSORMODELIST "OMX.Nvidia.index.config.sensormodelist"
/** Holds sensor modes. */
typedef struct NVX_CONFIG_SENSORMODELIST
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */

    OMX_U32 nSensorModes;                                   /**< Number of sensor modes */
    NVX_SENSORMODE SensorModeList[MAX_NUM_SENSOR_MODES];    /**< Array of sensor modes */
} NVX_CONFIG_SENSORMODELIST;

/** Config extension index to get sensor ID.
 *  See ::OMX_PARAM_U32TYPE
 */
#define NVX_INDEX_PARAM_SENSORID "OMX.Nvidia.index.config.sensorid"

/** Config extension index to setup edge enhancement.
 * Edge enhancement increases the apparent sharpness of full
 * resolution images. It has no effect on downscaled images.
 *
 *  See ::NVX_CONFIG_EDGEENHANCEMENT
 */
#define NVX_INDEX_CONFIG_EDGEENHANCEMENT "OMX.Nvidia.index.config.edgeenhancement"
/** Holds data to setup edge enhancement. */
typedef struct NVX_CONFIG_EDGEENHANCEMENT
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */

    OMX_BOOL bEnable;               /**< Boolean to enable/disable edge enhancement */
    NVX_F32 strength;               /**< Strength of edge enhancement (0 to 100) */
} NVX_CONFIG_EDGEENHANCEMENT;

/** Config extension index for ISP data dump.
 *  @deprecated This index is deprecated.
 */
#define NVX_INDEX_CONFIG_ISPDATA "OMX.Nvidia.index.config.ispdata"
/** @deprecated This structure is deprecated. */
typedef struct NVX_CONFIG_ISPDATA
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    NVX_F32 ilData;                 /**< ilData */
    NVX_F32 ilData2;                /**< ilData2 */
} NVX_CONFIG_ISPDATA;

/** Config extension index to set temporal tradeoff level for video encoder.
 *  - 0 = Encoder delivers frames as fast as possible
 *  - 1 = Encoder drops 1 in 5 frames
 *  - 2 = Encoder drops 1 in 3 frames
 *  - 3 = Encoder drops 1 in 2 frames
 *  - 4 = Encoder drops 2 in 3 frames
 *
 *  See ::NVX_CONFIG_TEMPORALTRADEOFF
 */
#define NVX_INDEX_CONFIG_VIDEO_ENCODE_TEMPORALTRADEOFF "OMX.Nvidia.index.config.video.encode.temporaltradeoff"
/** Holds data to set temporal tradeoff. */
typedef struct NVX_CONFIG_TEMPORALTRADEOFF
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32 TemporalTradeOffLevel;  /**< Temporal Tradeoff Level */
} NVX_CONFIG_TEMPORALTRADEOFF;

/** Config extension index to get decoder configartion information from video encoder.
 *  See ::NVX_CONFIG_DecoderConfigInfo
 */
#define NVX_INDEX_CONFIG_VIDEO_ENCODE_DCI "OMX.Nvidia.index.config.video.encode.dci"
/** Holds data to get decoder configuration. */
typedef struct NVX_CONFIG_DecoderConfigInfo
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U8 DecoderConfigInfo[NVX_VIDEOENC_DCI_SIZE];    /**< Decoder configuration info*/
    OMX_U8 SizeOfDecoderConfigInfo;                     /**< Size of decoder configuration info*/
}NVX_CONFIG_DecoderConfigInfo;              

#endif

/** @} */
/* File EOF */
