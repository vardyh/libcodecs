// RarRegister.cpp

#include "StdAfx.h"

#include "../../Common/RegisterArc.h"

#include "RarHandler.h"
static IInArchive *CreateArc() { return new NArchive::NRar::CHandler; }

static CArcInfo g_ArcInfo =
{ ".rar", {0x52 , 0x61, 0x72, 0x21, 0x1a, 0x07, 0x00}, 7, CreateArc, 0,  };

REGISTER_ARC(rar)
