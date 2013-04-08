// CabRegister.cpp

#include "StdAfx.h"

#include "../../Common/RegisterArc.h"

#include "CabHandler.h"
static IInArchive *CreateArc() { return new NArchive::NCab::CHandler; }

static CArcInfo g_ArcInfo =
{ ".cab", { 0x4D, 0x53, 0x43, 0x46 }, 4, CreateArc, 0 };

REGISTER_ARC(cab)
