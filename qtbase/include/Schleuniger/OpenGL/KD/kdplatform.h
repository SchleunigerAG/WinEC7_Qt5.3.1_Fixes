/*
 * Copyright (c) 2007 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA Corporation is strictly prohibited.
 */

/* Sample KD/kdplatform.h for OpenKODE Core 1.0.3  */
#ifndef __kdplatform_h_
#define __kdplatform_h_

#define KD_API
#define KD_APIENTRY

typedef int KDint32;
typedef unsigned int KDuint32;
typedef long long KDint64;
typedef unsigned long long KDuint64;
typedef short KDint16;
typedef unsigned short KDuint16;
typedef unsigned long KDuintptr;
typedef unsigned long KDsize;
typedef long KDssize;
#define KDINT_MIN (-0x7fffffff-1)
#define KDINT_MAX 0x7fffffff
#define KDUINT_MAX 0xffffffffU
#define KDINT64_MIN (-0x7fffffffffffffffLL-1)
#define KDINT64_MAX 0x7fffffffffffffffLL
#define KDUINT64_MAX 0xffffffffffffffffULL
#define KDSSIZE_MIN (-0x7fffffff-1)
#define KDSSIZE_MAX 0x7fffffff
#define KDSIZE_MAX 0xffffffffU
#define KDUINTPTR_MAX 0xffffffffU
#define KD_NORETURN
#define KD_WINDOW_SUPPORTED
#ifdef KD_NDEBUG
#define kdAssert(c)
#else
#define kdAssert(c) ((void)( (c) ? 0 : (kdHandleAssertion(#c, __FILE__, __LINE__), 0)))
#endif

#define KD_INFINITY_BITS 0x7f800000u
#define KD_INFINITY (kdBitsToFloatNV(KD_INFINITY_BITS))

KD_API float KD_APIENTRY kdBitsToFloatNV(KDuint32 x);


/** KHR_formatted extension */
#include <stdarg.h>
typedef va_list KDVaListKHR;

// If there are problems with including stdarg.h here under any of the Windows
// operating systems, we might want to change it back to using char* instead of
// va_list
//typedef char *KDVaListKHR;


#define KD_VA_START_KHR(ap, parmN)  \
        do {ap = (KDVaListKHR)&parmN + sizeof(parmN);} while(0)

#define KD_VA_ARG_CHAR_KHR(ap)      (KDchar)va_arg(ap, KDint)
#define KD_VA_ARG_CHARPTR_KHR(ap)   (KDchar*)(KD_VA_ARG_PTR_KHR(ap))
#define KD_VA_ARG_INT16_KHR(ap)     (KDint16)va_arg(ap, KDint)
#define KD_VA_ARG_INT32_KHR(ap)     va_arg(ap, KDint32)
#define KD_VA_ARG_INT_KHR(ap)       va_arg(ap, KDint)
#define KD_VA_ARG_INT64_KHR(ap)     va_arg(ap, KDint64)
#define KD_VA_ARG_INTPTR_KHR(ap)    (KDint*)(KD_VA_ARG_PTR_KHR(ap))
#define KD_VA_ARG_INT16PTR_KHR(ap)  (KDint16*)(KD_VA_ARG_PTR_KHR(ap))
#define KD_VA_ARG_FLOAT32_KHR(ap)   (KDfloat32)(va_arg(ap, double))
#define KD_VA_ARG_PTR_KHR(ap)       (void *)va_arg(ap, char *)

#define KD_VA_END_KHR(ap)           \
        do {ap = (KDVaListKHR)0;} while(0)

#endif /* __kdplatform_h_ */

