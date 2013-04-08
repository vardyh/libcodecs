#ifndef __MSWIN__
# if defined (_WIN32) || defined (_WIN64)
#  define __MSWIN__ 1
# endif
#endif

#ifndef __LINUX__
# if defined (__linux__)
#  define __LINUX__ 1
# endif
#endif

#ifndef __DARWIN__
# if defined (__APPLE__) || defined (__apple__)
#  define __DARWIN__ 1
# endif
#endif

#ifdef __x86_64__
# define __CDECL
#else
# ifdef __GNUC__
#  define __CDECL __attribute__((cdecl))
# else
#  define __CDECL __cdecl
# endif
#endif
#define EXPORT_DECL __CDECL

#define INITGUID
#include <windows.h>
#include <Common/MyCom.h>
#include <Common/StringConvert.h>
#include <Codecs/ICoder.h>
#include <Codecs/IPassword.h>
#include <Codecs/Archive/IArchive.h>
#include <Codecs/Common/RegisterArc.h>
#include <Windows/StdAfx.h>
#include <Windows/Defs.h>
#include <Windows/PropVariant.h>

static void (EXPORT_DECL *__libxsse_register_codec)(void *) = 0;

#if defined(__MSWIN__)

# include <windows.h>

static void register_codec(const CArcInfo *arcInfo)
{
	if (!__libxsse_register_codec) {
		HMODULE xsse = LoadLibraryA("libxsse.dll");
		if (!xsse)
			return;
		__libxsse_register_codec = (void (EXPORT_DECL *)(void *))
			GetProcAddress(xsse, "libxsse_register_codec");
		if (!__libxsse_register_codec)
			return;
	}
	__libxsse_register_codec((void *) arcInfo);
}

#elif defined(__DARWIN__) || defined(__LINUX__)

# include <stdio.h>
# include <dlfcn.h>

static void register_codec(const CArcInfo *arcInfo)
{
#ifdef __LINUX__
# define DYLD_EXT ".so"
#else
# define DYLD_EXT ".dylib"
#endif
	if (!__libxsse_register_codec) {
		void *xsse = dlopen("libxsse" DYLD_EXT, RTLD_LAZY);
		if (!xsse)
			return;
		__libxsse_register_codec = (void (EXPORT_DECL *)(void *))
			dlsym(xsse, "libxsse_register_codec");
		if (!__libxsse_register_codec)
			return;
	}
	__libxsse_register_codec((void *) arcInfo);
}

#else
# error OS not supported!
#endif

void RegisterArc(const CArcInfo *arcInfo)
{
	register_codec(arcInfo);
}
