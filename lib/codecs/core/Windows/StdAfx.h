// StdAfx.h

#ifndef __STDAFX_H
#define __STDAFX_H

#ifdef _WIN32
# include "../Common/MyWindows.h"
# include "../Common/NewHandler.h"
# ifndef ENV_HAVE_WCTYPE_H
#  define ENV_HAVE_WCTYPE_H
# endif
# ifndef ENV_HAVE_WCHAR__H
#  define ENV_HAVE_WCHAR__H
# endif
# ifndef ENV_HAVE_MBRTOWC
#  define ENV_HAVE_MBRTOWC
# endif
# ifndef ENV_HAVE_WCSTOMBS
#  define ENV_HAVE_WCSTOMBS
# endif
#else
# include "../myWindows/StdAfx.h"
#endif

#endif
