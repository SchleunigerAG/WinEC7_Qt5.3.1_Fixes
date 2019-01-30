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
 * <b>NVIDIA Tegra: OpenMAX Container Extension Interface</b>
 *
 */

#ifndef NVOMX_ParserExtensions_h_
#define NVOMX_ParserExtensions_h_

/**
 * @defgroup nv_omx_il_parser_reader Container Demux
 *   
 * This is the NVIDIA OpenMAX container demux class extension interface.
 *
 * These extensions include demuxer control and query of meta-data, stream type,
 * cache size, duration, file name and more.
 * 
 * See also \link nv_omx_il_tracklist Container Tracklist Extensions\endlink
 *
 * @ingroup nvomx_container_extension
 * @{
 */

/* MUST ADD NEW TYPES TO END OF ENUM */
typedef enum
{
    NvxStreamType_NONE = 0,
    NvxStreamType_MPEG4,
    NvxStreamType_H264,
    NvxStreamType_H263,
    NvxStreamType_WMV,
    NvxStreamType_JPG,
    NvxStreamType_MP3,
    NvxStreamType_WAV,
    NvxStreamType_AAC,
    NvxStreamType_AACSBR,
    NvxStreamType_BSAC,
    NvxStreamType_WMA,
    NvxStreamType_WMAPro,
    NvxStreamType_WMALossless,
    NvxStreamType_AMRWB,
    NvxStreamType_AMRNB,
    NvxStreamType_VORBIS,
    NvxStreamType_MPEG2V,
    NvxStreamType_AC3,
    NvxStreamType_WMV7,
    NvxStreamType_WMV8,
    NvxStreamType_WMAVoice,
    NvxStreamType_MP2,
    NvxStreamType_ADPCM,
    NvxStreamType_MS_MPG4,
    NvxStreamType_QCELP,
    NvxStreamType_EVRC,
    NvxStreamType_H264Ext,
    NvxStreamType_VP6,
    NvxStreamType_MPEG4Ext,
    NvxStreamType_MJPEG,
    NvxStreamType_Theora,
    NvxStreamType_MAX = 0x7FFFFFFF
} ENvxStreamType;

typedef enum
{
    NvxMetadata_Artist,
    NvxMetadata_Album,
    NvxMetadata_Genre,
    NvxMetadata_Title,
    NvxMetadata_Year,
    NvxMetadata_TrackNum,
    NvMMetadata_Encoded,
    NvxMetadata_Comment,
    NvxMetadata_Composer,
    NvxMetadata_Publisher,
    NvxMetadata_OriginalArtist,
    NvxMetadata_AlbumArtist,
    NvxMetadata_Copyright,
    NvxMetadata_Url,
    NvxMetadata_BPM,
    NvxMetadata_CoverArt,
    NvxMetadata_CoverArtURL,
    NvxMetadata_MAX = 0x7FFFFFFF
} ENvxMetadataType;

/** Temporary File path parameter for writer components that write files. 
 *  See ::NVX_PARAM_FILENAME for details.
 */
#define NVX_INDEX_PARAM_TEMPFILEPATH "OMX.Nvidia.index.param.tempfilename"
/** Holds filename for components that read/write files. */
typedef struct NVX_PARAM_TEMPFILEPATH {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_STRING pTempPath;       /**< Temporary file path as supported by stdio implementation */
} NVX_PARAM_TEMPFILEPATH;


/** Filename parameter for source, demux, and sink components that read/write files.
 *  See ::NVX_PARAM_FILENAME for details.
 */
#define NVX_INDEX_PARAM_FILENAME "OMX.Nvidia.index.param.filename"
/** Holds filename for components that read/write files. */
typedef struct NVX_PARAM_FILENAME {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_STRING pFilename;       /**< Name of file as supported by stdio implementation */
} NVX_PARAM_FILENAME;

/** Duration parameter for source, demux and sink components that read/write files.
 *  See ::NVX_PARAM_DURATION for details.
 */
#define NVX_INDEX_PARAM_DURATION "OMX.Nvidia.index.param.duration"  
/** Holds duration for components that read/write files. */
typedef struct NVX_PARAM_DURATION {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_TICKS nDuration;        /**< Duration in microsecs */
} NVX_PARAM_DURATION;

/** Stream type parameter for source, demux and sink components that read/write files.
 *  See ::NVX_PARAM_STREAMTYPE for details.
 */
#define NVX_INDEX_PARAM_STREAMTYPE "OMX.Nvidia.index.param.streamtype"
/** Holds stream type for components that read/write files. */
typedef struct NVX_PARAM_STREAMTYPE {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 nPort;              /**< Port that this struct applies to */
    ENvxStreamType eStreamType; /**< Stream type */
} NVX_PARAM_STREAMTYPE;

/** Audio stream parameters for source, demux and sink components that read/write files.
 *  See ::NVX_PARAM_AUDIOPARAMS for details.
 */
#define NVX_INDEX_PARAM_AUDIOPARAMS "OMX.Nvidia.index.param.audioparams"
/** Holds audio stream info for components that read/write files. */
typedef struct NVX_PARAM_AUDIOPARAMS {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 nPort;              /**< Port that this struct applies to */
    OMX_U32 nSampleRate;        /**< Sample rate in HZ */
    OMX_U32 nBitRate;           /**< Bits rate in bits per second */
    OMX_U32 nChannels;          /**< Number of channels (mono = 1, stereo = 2, etc) */
    OMX_U32 nBitsPerSample;     /**< Bits per sample */
} NVX_PARAM_AUDIOPARAMS;

/** Meta data config for demux components that read files with meta data.
 * If specified metadata not found, returns empty string or 
 * OMX_ErrorInsufficientResources if sValueStr is too small.
 *
 * See ::NVX_CONFIG_QUERYMETADATA
 */
#define NVX_INDEX_CONFIG_QUERYMETADATA "OMX.Nvidia.index.config.querymetadata"
/** Holds meta data info for demux components. */
typedef struct NVX_CONFIG_QUERYMETADATA {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    ENvxMetadataType eType;     /**< Meta data type */
    OMX_STRING sValueStr;       /**< String to hold results */
    OMX_U32 nValueLen;          /**< Length of results string */
    OMX_METADATACHARSETTYPE eCharSet;   /**< Character set to use */
} NVX_CONFIG_QUERYMETADATA;

/** File cache size config for demux components that read files.
 * See ::NVX_CONFIG_FILECACHESIZE
 */
#define NVX_INDEX_CONFIG_FILECACHESIZE "OMX.Nvidia.index.config.filecachesize"
/** Holds cache size configuration. */
typedef struct NVX_CONFIG_FILECACHESIZE {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 nFileCacheSize;     /**< in MB, 0 = none, 1 = max */
} NVX_CONFIG_FILECACHESIZE;

/** File cache info config for demux components that read files.
 * See ::NVX_CONFIG_FILECACHEINFO
 */
#define NVX_INDEX_CONFIG_FILECACHEINFO "OMX.Nvidia.index.config.filecacheinfo"
/** Holds file cache information. */
typedef struct NVX_CONFIG_FILECACHEINFO {
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U64 nDataBegin;         /**< Data Begin */
    OMX_U64 nDataFirst;         /**< Data First */
    OMX_U64 nDataCur;           /**< Data Current */
    OMX_U64 nDataLast;          /**< Data Last */
    OMX_U64 nDataEnd;           /**< Data End */
} NVX_CONFIG_FILECACHEINFO;

/* Charset define to extend OMX_METADATACHARSETTYPE for a U32 type */
#define NVOMX_MetadataCharsetU32    0x10000000
#define NVOMX_MetadataFormatJPEG    0x10000001
#define NVOMX_MetadataFormatPNG     0x10000002
#define NVOMX_MetadataFormatBMP     0x10000003
#define NVOMX_MetadataFormatUnknown 0x10000004
#define NVOMX_MetadataFormatGIF     0x10000005

/** @} */

/**
 * @defgroup nv_omx_il_parser_dtv DTV Source
 *   
 * This is the NVIDIA OpenMAX DTV source class extension interface. 
 *
 * These extensions include recording and pause mode, source selection, channel
 * info and control and more.
 *
 * @ingroup nvomx_container_extension
 * @{
 */

typedef enum
{
    NvxRecordingMode_Enable = 1,
    NvxRecordingMode_EnableExclusive,
    NvxRecordingMode_Disable,
    NvxRecordingMode_Force32 = 0x7FFFFFFF
} ENvxRecordingMode;

typedef enum
{
    NvxSource_AutoDetect = 1,
    NvxSource_File,
    NvxSource_Force32 = 0x7FFFFFFF
} ENvxSource;

/** Recording mode parameter for DTV components.
 * See ::NVX_PARAM_RECORDINGMODE
 */
#define NVX_INDEX_PARAM_RECORDINGMODE "OMX.Nvidia.index.param.recordingmode"
/** Holds DTV recording mode. */
typedef struct NVX_PARAM_RECORDINGMODE
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    ENvxRecordingMode RecordingMode;    /**< Recording mode */
} NVX_PARAM_RECORDINGMODE;

/** Source parameter for DTV components.
 * See ::NVX_PARAM_SOURCE
 */
#define NVX_INDEX_PARAM_SOURCE "OMX.Nvidia.index.param.source"
/** Holds DTV source type. */
typedef struct NVX_PARAM_SOURCE
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    ENvxSource Source;          /**< Source type */
} NVX_PARAM_SOURCE;

/** Channel ID parameter for DTV components.
 * See ::NVX_PARAM_CHANNELID
 */
#define NVX_INDEX_PARAM_CHANNELID "OMX.Nvidia.index.param.channelid"
/** Holds DTV channel ID. */
typedef struct NVX_PARAM_CHANNELID
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 ChannelID;          /**< Channel ID */
} NVX_PARAM_CHANNELID;


/** Pause config for DTV components.
 * See ::NVX_CONFIG_PAUSEPLAYBACK
 */
#define NVX_INDEX_CONFIG_PAUSEPLAYBACK "OMX.Nvidia.index.config.pauseplayback"
/** Holds data to enable DTV pause. */
typedef struct NVX_CONFIG_PAUSEPLAYBACK
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_BOOL bPausePlayback;    /**< Pause if TRUE */
} NVX_CONFIG_PAUSEPLAYBACK;

/** Holds DTV program ID. */
typedef struct ENvxDTVProgRec
{
    OMX_U32 ProgID;
} ENvxDTVProg;

/** Holds a DTV program list. */
typedef struct ENvxDTVProgProgsListRec
{
    OMX_U32 NumProgs;
    ENvxDTVProg *pProgs;
} ENvxDTVProgProgsList;

/** Program list config for DTV components.
 * See ::NVX_CONFIG_PROGRAMS_LIST
 */
#define NVX_INDEX_CONFIG_PROGRAMS_LIST "OMX.Nvidia.index.config.programslist"
/** Holds a DTV program list. */
typedef struct NVX_CONFIG_PROGRAMS_LIST
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    ENvxDTVProgProgsList ProgsList; /**< Program list */
} NVX_CONFIG_PROGRAMS_LIST;

/** Current program config for DTV components.
 * See ::NVX_CONFIG_CURRENT_PROGRAM
 */
#define NVX_INDEX_CONFIG_CURRENT_PROGRAM "OMX.Nvidia.index.config.currentprogram"
/** Holds a DTV current program ID. */
typedef struct NVX_CONFIG_CURRENT_PROGRAM
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 ProgID;             /**< Current program */
} NVX_CONFIG_CURRENT_PROGRAM;

/** @} */

/**
 * @defgroup nv_omx_il_parser_writer Container Mux
 *   
 * This is the NVIDIA OpenMAX container mux class extension interface. 
 *
 * These extensions include muxer control and query of stream type, cache size, 
 * duration, file name and more.
 *
 * @ingroup nvomx_container_extension
 * @{
 */

/** Maximum number of frames to write to file parameter.
 * See ::OMX_PARAM_U32TYPE
 */
#define NVX_INDEX_PARAM_MAXFRAMES "OMX.Nvidia.index.param.maxframes"

/** Muxer buffer config parameter.
 * @deprecated This parameter is deprecated.
 */
#define NVX_INDEX_PARAM_OTHER_3GPMUX_BUFFERCONFIG  "OMX.Nvidia.index.param.other.3gpmux.bufferconfig"
/** @deprecated This structure is deprecated. */
typedef struct NVX_PARAM_OTHER_3GPMUX_BUFFERCONFIG
{
    OMX_U32 nSize;              /**< Size of the structure in bytes. */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information. */
    OMX_U32 nPortIndex;         /**< Port to which this struct applies. */
    OMX_BOOL bUseCache;         /**< @deprecated This field is deprecated. */
    OMX_U32 nBufferSize;        /**< @deprecated This field is deprecated. */
    OMX_U32 nPageSize;          /**< @deprecated This field is deprecated. */
} NVX_PARAM_OTHER_3GPMUX_BUFFERCONFIG;

/** Current number of audio and video frames config.
 * See ::NVX_CONFIG_3GPMUXGETAVRECFRAMES
 */
#define NVX_INDEX_CONFIG_3GPMUXGETAVRECFRAMES "OMX.Nvidia.index.config.3gpmuxgetavrecframes"
/** Holds a number of audio and video frames. */
typedef struct NVX_CONFIG_3GPMUXGETAVRECFRAMES
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_U32 nPortIndex;         /**< Port that this struct applies to */
    OMX_U32 nAudioFrames;       /**< Number of audio frames muxed */
    OMX_U32 nVideoFrames;       /**< Number of video frames muxed */
}NVX_CONFIG_3GPMUXGETAVRECFRAMES;

/** Split filename config.
 * See ::NVX_CONFIG_SPLITFILENAME
 */
#define NVX_INDEX_CONFIG_SPLITFILENAME "OMX.Nvidia.index.config.splitfilename"
/** Holds split filenames. */
typedef struct NVX_CONFIG_SPLITFILENAME
{
    OMX_U32 nSize;              /**< Size of the structure in bytes */
    OMX_VERSIONTYPE nVersion;   /**< NVX extensions specification version information */
    OMX_STRING pFilename;       /**< Name of file as supported by stdio implementation */
}NVX_CONFIG_SPLITFILENAME;

/** @} */


#endif
/* File EOF */