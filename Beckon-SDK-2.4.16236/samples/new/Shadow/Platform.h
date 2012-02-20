/**************************************************************************************
Copyright � 2009 Omek Interactive Ltd. All Rights Reserved.

The coded instructions, statements, computer programs, and/or related material (collectively 
"Data") in these files contain unpublished information proprietary to Omek Interactive Ltd., 
("Omek") which is protected by national and international copyright laws and by international 
treaties.

The Data may not be disclosed or distributed to third parties, in whole or in part, without the 
prior written consent of Omek.

OMEK DOES NOT GUARANTEE NOR MAKE ANY REPRESENTATION REGARDING THE USE OF, OR THE RESULTS OF THE 
USE OF THE DATA OR OMEK'S SERVICES, IN TERMS OF CORRECTNESS, ACCURACY OR OTHERWISE. THE DATA IS 
LICENSED "AS IS" AND WITHOUT WARRANTY.   OMEK SPECIFICALLY DISCLAIMS ALL WARRANTIES OR CONDITIONS 
WITH RESPECT TO THE DATA OR THE USE OR OPERATION THEREOF, WHETHER EXPRESS, IMPLIED,STATUTOR, ARISING 
BY CUSTOM OR TRADE USAGE, OR OTHERWISE, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR USE AND NONINFRINGEMENT. WITHOUT LIMITING THE 
FOREGOING, OMEK DOES NOT WARRANT THAT THE OPERATION OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE.

IN NO EVENT WILL OMEK, ITS LICENSORS OR SUPPLIERS BE LIABLE FOR ANY DIRECT OR INDIRECT DAMAGES, COSTS, 
CLAIMS OR EXPENSES (INCLUDING WITHOUT LIMITATION LOST REVENUE, PROFIT OR DATA OR OTHER SPECIAL, INDIRECT, 
CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, 
WHETHER FOR BREACH OF CONTRACT, TORT, INFRINGEMENT OR OTHERWISE), EVEN IF OMEK HAS BEEN ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGES.  
**************************************************************************************/

#ifndef __Platform_h__
#define __Platform_h__

/************************************************************************/
/*                             Cross-Platform Definitions               */
/************************************************************************/

/// Platform identifiers.
#define PLATFORM_WIN32 		1
#define PLATFORM_LINUX		2
#define PLATFORM_BIOS		3

#define OMK_CPU_X86 1
#define OMK_CPU_ARM 2
#define OMK_CPU_C64 3

#if defined (TIDSP) || defined (X86_DSP)
#	define DSP_CODE
#endif

/// Find the current platform.
#ifdef _WIN32
#	define PLATFORM PLATFORM_WIN32
#	define OMK_CPU OMK_CPU_X86
#elif linux
#	define PLATFORM PLATFORM_LINUX
#	ifdef i386
#		define OMK_CPU OMK_CPU_X86
#	elif __arm__
#		define OMK_CPU OMK_CPU_ARM
#	else
#		error The target CPU is not supported!
#	endif
#elif TIDSP
#	define OMK_CPU OMK_CPU_C64
#	define PLATFORM PLATFORM_BIOS
#else
#	error The target platform is not supported!
#endif

#ifdef _WIN32
#include "msvc10-stdint.h"
#else
#include <stdint.h>
#endif


#if (PLATFORM == PLATFORM_WIN32)
#	define OMK_PROC_HANDLE void*
#	define _ShadowExport __declspec(dllexport)
#	define STDCALL __stdcall
#	define OMEK_CDECL __cdecl
#	define LOG4CXX_ENABLED
#	define SHARED_LIB_PREF
#	define SHARED_LIB_EXT ".dll"
#	define OMK_DATA_ALIGN(declaration, alignment) __declspec(align(alignment)) declaration
#elif (PLATFORM == PLATFORM_LINUX) 
#	define OMK_PROC_HANDLE int
#	define _ShadowExport
#	define STDCALL
#	define OMEK_CDECL
#	define SHARED_LIB_PREF "lib"
#	define SHARED_LIB_EXT ".so"
#	define OMK_DATA_ALIGN(declaration, alignment) declaration __attribute__ ((aligned (alignment)))
#else //PLATFORM == PLATFORM_BIOS
#	define OMK_PROC_HANDLE int
#	define _ShadowExport
#	define STDCALL
#	define OMEK_CDECL
#	define SHARED_LIB_PREF 
#	define SHARED_LIB_EXT
#endif


#define SHARED_LIB_NAME(name) 	std::string(SHARED_LIB_PREF)	+ \
								std::string(name) 				+ \
								std::string(SHARED_LIB_EXT)

#endif //__Platform_h__
/************************************************************************/
/*                                EOF                                   */
/************************************************************************/
