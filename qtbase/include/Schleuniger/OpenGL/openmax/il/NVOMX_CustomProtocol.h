/* Copyright (c) 2008 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property 
 * and proprietary rights in and to this software, related documentation 
 * and any modifications thereto.  Any use, reproduction, disclosure or 
 * distribution of this software and related documentation without an 
 * express license agreement from NVIDIA Corporation is strictly prohibited.
 */

/** 
 * @file
 * <b>NVIDIA Tegra: OpenMAX Custom Protocol Registration Interface</b>
 *
 */

/**
 * @defgroup nv_omx_il_protocol Custom Protocol Plug-in Interface
 *   
 * This interface is meant to allow registering of a custom set of file i/o 
 * operations that are then associated with a URI protocol.  This can be used 
 * to implement various network streaming protocols or simple forms of 
 * full-file DRM decryption.  See the definition of 
 * NVOMX_RegisterNVCustomProtoReader() for how to register a protocol.
 *
 * This is essentially a simplified version of an OpenMAX ContentPipe.
 *
 * @ingroup nvomx_plugins
 * @{
 */

#ifndef NVOMX_CUSTOMPROTOCOL_H_
#define NVOMX_CUSTOMPROTOCOL_H_

#include "OMX_Types.h"
#include "OMX_ContentPipe.h"
#include "nvcustomprotocol.h"

/** Register a NV_CUSTOM_PROTOCOL interface to handle protocol szProto. 
 *
 * Associates a protocol (eg, "drm://") with a NVMM_CUSTOM_PROTOCOL 
 * structure.  Any files then opened with the protocol prefix will use the
 * functions in pProtocol for all file access.
 *
 * @param szProto   The protocol name to register, must include '://'
 * @param pProtocol Pointer to an NVMM_CUSTOM_PROTOCOL implementation
 */
CPresult NVOMX_RegisterNVCustomProtocol(OMX_STRING szProto, 
                                        NV_CUSTOM_PROTOCOL *pProtocol);

#endif

/** @} */
/* File EOF */
