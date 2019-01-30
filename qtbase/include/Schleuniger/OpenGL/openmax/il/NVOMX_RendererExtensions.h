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
 * <b>NVIDIA Tegra: OpenMAX Renderer Extension Interface</b>
 *
 */

#ifndef NVOMX_RendererExtensions_h_
#define NVOMX_RendererExtensions_h_

/**
 * @defgroup nv_omx_il_video_renderer Video Renderer
 * 
 * This is the NVIDIA OpenMAX video renderer class extensions interface.
 *
 * These extensions include aspect ratio control, single frame stepping,
 * window and overlay control, frame capture, delivery statistics and more.
 *
 * @ingroup nvomx_renderer_extension
 * @{
 */

/** Config extension index to force video aspect ratio correction (letter-boxed).
 *  See ::NVX_CONFIG_KEEPASPECT
 */
#define NVX_INDEX_CONFIG_KEEPASPECT "OMX.Nvidia.index.config.keepaspect"
/** Holds data to force video aspect ratio correction. */
typedef struct NVX_CONFIG_KEEPASPECT {
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_BOOL bKeepAspect;           /**< Boolean to enable aspect ratio correction */
} NVX_CONFIG_KEEPASPECT;

// Allow manual override on WinA to permit power optimizations from client side
typedef enum
{
    NvxWindow_A = 0,
    NvxWindow_MAX = 0x7FFFFFFF
} ENvxWindowType;

typedef enum
{
    NvxWindowAction_TurnOn = 0,
    NvxWindowAction_TurnOff,
    NvxWindowAction_MAX = 0x7FFFFFFF
} ENvxWindowDispActionType;

/** Config extension index to disable/enable the primary display window and only show the video overlay.
 *  See ::NVX_CONFIG_WINDOWOVERRIDE
 */
#define NVX_INDEX_CONFIG_WINDOW_DISP_OVERRIDE "OMX.Nvidia.index.config.windisp"
/** Holds data to disable/enable the primary display window. */
typedef struct NVX_CONFIG_WINDOWOVERRIDE
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    ENvxWindowType eWindow;             /**< Primary display window type */
    ENvxWindowDispActionType eAction;   /**< Action */
} NVX_CONFIG_WINDOWOVERRIDE;

/** Config extension index to capture the uncompressed video frame data.
 *  See ::NVX_CONFIG_WINDOWOVERRIDE
 */
#define NVX_INDEX_CONFIG_CAPTURERAWFRAME "OMX.Nvidia.index.config.capturerawframe"
/** Holds data to capture the uncompressed video frame data. */
typedef struct NVX_CONFIG_CAPTURERAWFRAME
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_U8 *pBuffer;                    /**< Pointer to buffer to capture into */
    OMX_U32 nBufferSize;                /**< Size of buffer */
} NVX_CONFIG_CAPTURERAWFRAME;

/** Config extension index to select tiled vs linear video data format.
 *  Tiled is a more efficent format, but less compatible with third-party components.
 *
 *  See ::NVX_CONFIG_CUSTOMCOLORFORMAT
 */
#define NVX_INDEX_CONFIG_CUSTOMCOLORFORMAT "OMX.Nvidia.index.config.customcolorformat"
/** Holds data to select tiled versus linear video data format. */
typedef struct NVX_CONFIG_CUSTOMCOLORFORMAT
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_BOOL bTiled;                    /**< Boolean to enable tiled video format */
} NVX_CONFIG_CUSTOMCOLORFORMAT;

/** Config extension index to allow single frame stepping.
 *  See ::NVX_CONFIG_SINGLE_FRAME
 */
#define NVX_INDEX_CONFIG_SINGLE_FRAME "OMX.Nvidia.index.config.singleframe"
/** Holds data to allow single frame stepping. */
typedef struct NVX_CONFIG_SINGLE_FRAME
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_BOOL bEnableMode;               /**< Boolean to enable single frame stepping mode */
} NVX_CONFIG_SINGLE_FRAME;

/** Config extension index to query the number of frames rendered.
 *  See ::NVX_CONFIG_NUMRENDEREDFRAMES
 */
#define NVX_INDEX_CONFIG_NUMRENDEREDFRAMES "OMX.Nvidia.index.config.numrenderedframes"
/** Holds data to query the number of frames rendered. */
typedef struct NVX_CONFIG_NUMRENDEREDFRAMES
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_U32 nFrames;                    /**< Number of rendered frames */
} NVX_CONFIG_NUMRENDEREDFRAMES;

/** Config extension index to allow the video renderer to handle differing size and format video
 * frames on the fly.
 * This will cause a power/performance penalty.
 *
 *  See ::NVX_CONFIG_RENDERHINTMIXEDFRAMES
 */
#define NVX_INDEX_CONFIG_RENDERHINTMIXEDFRAMES "OMX.Nvidia.index.config.renderhintmixedframes"
/** Holds data to allow mixed format frame types. */
typedef struct NVX_CONFIG_RENDERHINTMIXEDFRAMES
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_BOOL bMixedFrames;              /**< Boolean to enable mixed frames support */
} NVX_CONFIG_RENDERHINTMIXEDFRAMES;

/** Config extension index to allow client to provide it's own overlay surface.
 *  See ::NVX_CONFIG_EXTERNALOVERLAY
 */
#define NVX_INDEX_CONFIG_EXTERNALOVERLAY "OMX.Nvidia.index.config.externaloverlay"
/** Holds data to allow the client to provide its own overlay surface. */
typedef struct NVX_CONFIG_EXTERNALOVERLAY
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_U64 oOverlayPtr;                /**< Pointer to application overlay surface */
} NVX_CONFIG_EXTERNALOVERLAY;

/** Config extension index to request il to allocate rm surface instead of os memory.
 *  See ::NVX_CONFIG_ALLOCATERMSURF
 */
#define NVX_INDEX_CONFIG_ALLOCATERMSURF "OMX.Nvidia.index.config.rmsurf"
/** Holds data to allow il to allocate rm surface for ilclient. */
typedef struct NVX_CONFIG_ALLOCATERMSURF
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_BOOL bRmSurf;
} NVX_CONFIG_ALLOCATERMSURF;

/** @} */

/**
 * @defgroup nv_omx_il_audio_renderer Audio Renderer
 *   
 * This is the NVIDIA OpenMAX audio renderer class extensions interface.
 *
 * These extensions include HDMI and IS2 output control, graphic equalizer,
 * dynamic range compression and automatic gain control, IIR filter setup and more.
 *
 * @ingroup nvomx_renderer_extension
 * @{
 */

/** Number of bands for graphic equalizer */
#define EQBANDS 5
/** Number of channels for graphic equalizer */
#define EQ_NO_CHANNEL 2

/** Number of parametric equalizer filter types */
#define MIXER_NUM_PARA_EQ_FILTERS         4
/** Band-pass parametric equalizer filter */
#define MIXER_BANDPASS_IIR_FILTER         1
/** High-pass parametric equalizer filter */
#define MIXER_HIGHPASS_IIR_FILTER         2
/** Low-pass parametric equalizer filter */
#define MIXER_LOWPASS_IIR_FILTER          3

typedef enum NVX_AUDIO_OUTPUTTYPE {
    NVX_AUDIO_OutputI2S = 0,
    NVX_AUDIO_OutputHdmi,
    NVX_AUDIO_Force32 = 0x7FFFFFFF
} NVX_AUDIO_OUTPUTTYPE;

/** Config extension index to select audio output device.
 *  See ::NVX_CONFIG_AUDIOOUTPUT
 */
#define NVX_INDEX_CONFIG_AUDIO_OUTPUT "OMX.Nvidia.index.config.audio.output"
/** Holds data to select audio output device. */
typedef struct NVX_CONFIG_AUDIOOUTPUT {
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    NVX_AUDIO_OUTPUTTYPE eOutputType;   /**< Audio output type */
} NVX_CONFIG_AUDIOOUTPUT;

/** Config extension index to disable timestamp event notifications.
 *  Disabling the events help lower power consumption.
 *
 *  See ::NVX_CONFIG_DISABLETSUPDATES
 */
#define NVX_INDEX_CONFIG_DISABLETIMESTAMPUPDATES "OMX.Nvidia.index.config.disabletimestampupdates"
/** Holds data to disable timestamp event notifications. */
typedef struct NVX_CONFIG_DISABLETSUPDATES {
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_BOOL bDisableTSUpdates;         /**< Boolean to disable timestamp event notification */
} NVX_CONFIG_DISABLETSUPDATES;

/** Config extension index to setup the graphic equalizer.
 *  See ::NVX_CONFIG_AUDIO_GRAPHICEQ
 */
#define NVX_INDEX_CONFIG_AUDIO_GRAPHICEQ "OMX.Nvidia.index.config.audio.graphiceq"
/** Holds data to setup the graphic equalizer. */
typedef struct NVX_CONFIG_AUDIO_GRAPHICEQ
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_U32 bEnable;                    /**< Boolean to enable the EQ */
    OMX_S32 dBGain[EQ_NO_CHANNEL][EQBANDS];     /**< Gain in dB per channel and frequency band */
}NVX_CONFIG_AUDIO_GRAPHICEQ;

/** Config extension index to setup dynamic range compression (DRC) and automatic gain control (AGC).
 *  See ::NVX_CONFIG_AUDIO_DRCPROPERTY
 */
#define NVX_INDEX_CONFIG_AUDIO_DRCPROPERTY "OMX.Nvidia.index.config.audio.drcproperty"
/** Holds data to setup dynamic range compression. */
typedef struct NVX_CONFIG_AUDIO_DRCPROPERTY
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_S32   EnableDrc;                /**< Boolean to enable DRC */
    OMX_S32   ClippingTh;               /**< Clipping threshold in dB (UpperCompTh <= ClipTh <= 0dB) */
    OMX_S32   LowerCompTh;              /**< Lower compression threshold in dB (NoiseGateTh <= LowerCompTh <= UpperCompTh) */
    OMX_S32   UpperCompTh;              /**< Upper compression threshold in dB (LowerCompTh <= UpperCompTh <= ClipTh) */
    OMX_S32   NoiseGateTh;              /**< Noise gate threshold in dB (-90dB <= NoiseGateTh <= LowerCompTh) */
}NVX_CONFIG_AUDIO_DRCPROPERTY;

/** Config extension index to setup the parametric equalizer filter.
 *  See ::NVX_CONFIG_AUDIO_PARAEQFILTER
 */
#define NVX_INDEX_CONFIG_AUDIO_PARAEQFILTER "OMX.Nvidia.index.config.audio.paraeqfilter"
/** Holds data to setup the parametric equalizer filter. */
typedef struct NVX_CONFIG_AUDIO_PARAEQFILTER
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;           /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                 /**< Port that this struct applies to */
    OMX_U32   bEnable;                  /**< Boolean to enable parametric equalizer */
    OMX_U32   bUpdate;                                  /**< Boolean indicates new filter parameters when already enabled */
    OMX_U32   FilterType[MIXER_NUM_PARA_EQ_FILTERS];    /**< MIXER_LOWPASS_IIR_FILTER, MIXER_BANDPASS_IIR_FILTER or MIXER_HIGHPASS_IIR_FILTER */
    OMX_S32   F0[MIXER_NUM_PARA_EQ_FILTERS];            /**< Frequency array in Hz (Range 0 - Fs/2) */
    OMX_S32   BndWdth[MIXER_NUM_PARA_EQ_FILTERS];       /**< Bandwidth array in Hz (Range 0 - Fs/2) */
    OMX_S32   dBGain[MIXER_NUM_PARA_EQ_FILTERS];        /**< Decibel gain array in dB (Limit +/- 12.0 dB) */
}NVX_CONFIG_AUDIO_PARAEQFILTER;

/** @} */
#endif

/* File EOF */
