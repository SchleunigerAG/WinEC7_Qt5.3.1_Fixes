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
 * <b>NVIDIA Tegra: OpenMAX Decoder Extension Interface</b>
 *
 */

/**
 * @defgroup nv_omx_il_decoder Decoder
 *   
 * This is the NVIDIA OpenMAX decoder class extensions interface.
 *
 * These extensions include ultra low power (ULP) mode, video de-interlacing, JPEG EXIF info,
 * thumbnail generation and more.
 *
 * @ingroup nvomx_decoder_extension
 * @{
 */

#ifndef NVOMX_DecoderExtensions_h_
#define NVOMX_DecoderExtensions_h_

#define NVX_EXIF_MAKE_LENGTH   16
#define NVX_EXIF_MODEL_LENGTH  32
#if 0
#define NVX_EXIF_APP1_DATE_TIME_ORIGINAL_LENGTH            32
#define NVX_EXIF_APP1_DATE_TIME_DIGITIZED_LENGTH           32
#define NVX_EXIF_APP1_SOFTWARE_LENGTH                      64
#define NVX_EXIF_APP1_DATE_TIME_LENGTH                     21
#define NVX_EXIF_APP1_YCBCR_POSITIONING_LENGTH             32
#define NVX_EXIF_APP1_METERING_MODE_LENGTH                 22
#define NVX_EXIF_APP1_COMPONENTS_CONFIGURATION_LENGTH      10
#define NVX_EXIF_APP1_FLASH_PIX_VERSION_LENGTH             28   
#define NVX_EXIF_APP1_COLOR_SPACE_LENGTH                   13
#define NVX_EXIF_APP1_ORIENTATION_LENGTH                   17
#define NVX_EXIF_APP1_FLASH_FIRING_LENGTH                  13
#define NVX_EXIF_APP1_FLASH_RETURN_LENGTH                  36
#define NVX_EXIF_APP1_SCENE_CAPTURE_TYPE_LENGTH            30
#define NVX_EXIF_APP1_LIGHT_SOURCE_LENGTH                  16
#define NVX_EXIF_APP1_LIGHT_WHITE_BALANCE_LENGTH           7
#define NVX_EXIF_APP1_CUSTOM_RENDERED_LENGTH               7
#define NVX_EXIF_APP1_EXPOSURE_MODE_LENGTH                 16
#define NVX_EXIF_APP1_DIGITAL_ZOOM_RATIO_LENGTH            8
#define NVX_EXIF_APP1_EXPOSURE_TIME_LENGTH                 8
#define NVX_EXIF_APP1_SUBJECT_DISTANCE_RANGE_LENGTH        8
#define NVX_EXIF_APP1_EXPOSURE_BIAS_VALUE_LENGTH           8
#define NVX_EXIF_APP1_INTEROPERABILITY_IFD_POINTER_LENGTH  2
#define NVX_EXIF_APP1_EXIF_VERSION_LENGTH                  4
#define NVX_EXIF_APP1_ISO_SPEED_RATINGS_LENGTH             2
#define NVX_EXIF_APP1_EXIF_OFFSET_LENGTH                   4
#define NVX_EXIF_APP1_FNUMBER_LENGTH                       8
#endif

/* General decoder extensions */

/** Param extension index to enable low memory mode by disabling meta-data buffers.
 *  See ::NVX_PARAM_LOWMEMMODE
 */
#define NVX_INDEX_PARAM_LOWMEMMODE "OMX.Nvidia.index.param.lowmemmode"
/** Holds information to enable low memory mode. */
typedef struct NVX_PARAM_LOWMEMMODE {
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_BOOL bLowMemMode;           /**< Boolean to enable low memory mode */
} NVX_PARAM_LOWMEMMODE;

/** Param extension index to enable synchronized decode mode.
 *  This is a higher performance decoding mode that processes buffers on the same thread 
 *  as the decoder core.   However, this can potentially cause compability problems with
 *  other OpenMAX components.
 *  See ::NVX_PARAM_SYNCDECODE
 */
#define NVX_INDEX_PARAM_SYNCDECODE "OMX.Nvidia.index.param.syncdecode"
/** Holds information to enable synchronized decode mode. */
typedef struct NVX_PARAM_SYNCDECODE {
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_BOOL bSyncDecodeMode;       /**< Boolean to enable synchronized decode mode */
} NVX_PARAM_SYNCDECODE;

/** Config extension index to enable ultra low power mode.
 *  See ::NVX_CONFIG_ULPMODE
 */
#define NVX_INDEX_CONFIG_ULPMODE "OMX.Nvidia.index.config.ulpmode"
/** Holds information to enable ultra low power mode. */
typedef struct NVX_CONFIG_ULPMODE {
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_BOOL enableUlpMode;         /**< Boolean to enable ultra low power mode */
    OMX_U32 kpiMode;                /**< Reserved for internal use */
} NVX_CONFIG_ULPMODE;

/* Audio decoder extensions */

/** Config extension index to enable audio only hints (audio decoder classes only).
 *  See ::NVX_CONFIG_AUDIOONLYHINT
 */
#define NVX_INDEX_CONFIG_AUDIOONLYHINT "OMX.Nvidia.index.config.audioonlyhint"
/** Holds information to enable audio-only hints. */
typedef struct NVX_CONFIG_AUDIOONLYHINT {
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_BOOL bAudioOnlyHint;        /**< Boolean to enable ultra low power mode for audio decoder only */
} NVX_CONFIG_AUDIOONLYHINT;

/* Video decoder extensions */

typedef enum
{
    OMX_DeintMethod_NoDeinterlacing,        /**< NO deinterlacing */
    OMX_DeintMethod_BobAtFrameRate,         /**< Bob on full frame. Two fields output one frame. */
    OMX_DeintMethod_BobAtFieldRate,         /**< Bob on full frame. Two fields output two frames. */
    OMX_DeintMethod_WeaveAtFrameRate,       /**< Weave on full frame. Two fields output one frame. (This is same as NO deinterlacing) */
    OMX_DeintMethod_AdaptiveAtFrameRate,    /**< Adaptive. Method decided at MB level. Two field output one frame. */
    OMX_DeintMethod_AdaptiveAtFieldRate,    /**< Adaptive. Method decided at MB level. Two field output two frames. */
    OMX_DeintMethod_Force32 = 0x7FFFFFFF
} OMX_DeinterlaceMethod;

/** Param extension index to configure the deinterlacing mode (video decoder classes only).
 *  See ::NVX_PARAM_DEINTERLACE
 */
#define NVX_INDEX_PARAM_DEINTERLACING "OMX.Nvidia.index.param.deinterlacing"
/** Holds information to configure the deinterlacing mode. */
typedef struct
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_U32 DeinterlaceMethod;      /**< Deinterlace method, see ::OMX_DeinterlaceMethod */
}NVX_PARAM_DEINTERLACE;

/* JPG decoder extensions */

/** Config extension index to setup thumbnail generation (image decoder classes only).
 *  See ::NVX_CONFIG_THUMBNAIL
 */
#define NVX_INDEX_CONFIG_THUMBNAIL "OMX.Nvidia.index.config.thumbnail"
/** Holds information to setup thumbnail generation. */
typedef struct NVX_CONFIG_THUMBNAIL
{
    OMX_U32 nSize;                  /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;       /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;             /**< Port that this struct applies to */
    OMX_BOOL bEnabled;              /**< Boolean to enable thumbnail output */
    OMX_U32 nWidth;                 /**< Width of thumbnail */
    OMX_U32 nHeight;                /**< Height of thumbnail */
} NVX_CONFIG_THUMBNAIL;

/** Config extension index to query decoded EXIF information (image decoder classes only).
 *  See ::NVX_CONFIG_EXIFINFO
 */
#define NVX_INDEX_CONFIG_EXIFINFO "OMX.Nvidia.index.config.exifinfo"
/** Holds information to query decoded EXIF information. */
typedef struct NVX_CONFIG_EXIFINFO
{
    OMX_U32 nSize;                          /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;               /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;                     /**< Port that this struct applies to */
    OMX_U8  isEXIFPresent;                  /**< Flag to indicate presence of EXIF data in image */
    OMX_U8  Make[NVX_EXIF_MAKE_LENGTH];     /**< Name of camera manufracturer */
    OMX_U8  Model[NVX_EXIF_MODEL_LENGTH];   /**< Name of camera model */
    OMX_U32 ThumbnailCompression;           /**< Thumbnail compression type */
    OMX_U32 ThumbnailOffset;                /**< Offset in bytes to thumbnail data */
    OMX_U32 ThumbnailLength;                /**< Length in bytes of thumbnail data */
    OMX_U32 ThumbnailImageWidth;            /**< Thumbnail image width */
    OMX_U32 ThumbnailImageHeight;           /**< Thumbnail image height */
    OMX_U32 PrimaryImageWidth;              /**< Primary image width */
    OMX_U32 PrimaryImageHeight;             /**< Primary image height */
    OMX_U8  ResolutionUnit;                 /**< Resolution units */
    OMX_U64 XResolution;                    /**< X resolution */
    OMX_U64 YResolution;                    /**< Y resolution */
    OMX_U8  bpp;                            /**< Bits per pixel */
    OMX_U8  ImageDescription[32];           /**< Description text */
#if 0
    OMX_U16 ISOSpeedRatings;
    OMX_U8  Software[NVX_EXIF_APP1_SOFTWARE_LENGTH];
    OMX_U8  DateTime[NVX_EXIF_APP1_DATE_TIME_LENGTH];
    OMX_U8  YCbCrPositioning[NVX_EXIF_APP1_YCBCR_POSITIONING_LENGTH];
    OMX_U8  ExifVersion[NVX_EXIF_APP1_EXIF_VERSION_LENGTH];
    OMX_U8  DateTimeOriginal[NVX_EXIF_APP1_DATE_TIME_ORIGINAL_LENGTH];
    OMX_U8  DateTimeDigitized[NVX_EXIF_APP1_DATE_TIME_DIGITIZED_LENGTH];
    OMX_U8  ComponentsConfiguration[NVX_EXIF_APP1_COMPONENTS_CONFIGURATION_LENGTH];
    OMX_U8  MeteringMode[NVX_EXIF_APP1_METERING_MODE_LENGTH];
    OMX_U8  FlashPixVersion[NVX_EXIF_APP1_FLASH_PIX_VERSION_LENGTH];
    OMX_U8  ColorSpace[NVX_EXIF_APP1_COLOR_SPACE_LENGTH];
    OMX_U8  Orientation[NVX_EXIF_APP1_ORIENTATION_LENGTH];
    OMX_S64 ExposureBiasValue;              //[NVX_EXIF_APP1_EXPOSURE_BIAS_VALUE_LENGTH];
    OMX_U8  FNumber[NVX_EXIF_APP1_FNUMBER_LENGTH];
    OMX_U8  FlashFiring[NVX_EXIF_APP1_FLASH_FIRING_LENGTH];
    OMX_U8  FlashReturn[NVX_EXIF_APP1_FLASH_RETURN_LENGTH];
    OMX_U8  SceneCaptureType[NVX_EXIF_APP1_SCENE_CAPTURE_TYPE_LENGTH];
    OMX_U8  LightSource[NVX_EXIF_APP1_LIGHT_SOURCE_LENGTH];
    OMX_U64 SubjectDistanceRange;
    OMX_U8  WhiteBalance[NVX_EXIF_APP1_LIGHT_WHITE_BALANCE_LENGTH];
    OMX_U8  CustomRendered[NVX_EXIF_APP1_CUSTOM_RENDERED_LENGTH];
    OMX_U64 ExposureTime;
    OMX_U8  ExposureMode[NVX_EXIF_APP1_EXPOSURE_MODE_LENGTH];
    OMX_U64 DigitalZoomRatio;
    OMX_U16 InteroperabilityIFDPointer;
#endif
} NVX_CONFIG_EXIFINFO;

/** Holds stream information to find the appropriate component. */
typedef struct {
    OMX_BOOL bUseSPSAndPPS;             /**< Use SPS and PPS as input */
    OMX_BOOL bHasCABAC;                 /**< Does stream use CABAC encoding */
    OMX_U32  nWidth;                    /**< Width of stream */
    OMX_U32  nHeight;                   /**< Height of stream */
    OMX_U32  nSPSCount;                 /**< Number of SPS NALU's */
    OMX_U8   **SPSNAUL;                 /**< Pointer to SPS NALU's array */
    OMX_U32  *SPSNAULLen;               /**< Pointer to length of SPS NALU array */
    OMX_U32  nPPSCount;                 /**< Number of PPS NALU's */
    OMX_U8   **PPSNAUL;                 /**< Pointer to PPS NALU's array */
    OMX_U32  *PPSNAULLen;               /**< Pointer to length of PPS NALU array */
} NVX_H264_DECODE_INFO;

/** Holds platform and stream information. */
typedef struct
{
    OMX_U32 nSize;                      /**< Size of the structure in bytes */
    OMX_U32 nPlatform;                  /**< Platform related info */
    ENvxStreamType eStreamType;         /**< Stream type */
    union {
        NVX_H264_DECODE_INFO    h264;   /**< Additional data for H.264 streams */
    } streamInfo;

} NVX_STREAM_PLATFORM_INFO;

/** 
   Finds an component name based on stream and platform information.

   @param [in] pStreamInfo
       A pointer to the structure containing stream and platform information.
   @param [out] compName
       A pointer to the found component name
   @retval OMX_ERRORTYPE
       Returns an appropriate error.
 */
OMX_API OMX_ERRORTYPE NVOMX_FindComponentName(
    OMX_IN  NVX_STREAM_PLATFORM_INFO *pStreamInfo,
    OMX_OUT OMX_STRING  *compName);

#endif
/** @} */
/* File EOF */
