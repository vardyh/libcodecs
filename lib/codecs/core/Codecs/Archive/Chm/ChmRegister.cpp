// ChmRegister.cpp

#include "StdAfx.h"

#include "../../Common/RegisterArc.h"

#include "ChmHandler.h"
static IInArchive *CreateArc() { return new NArchive::NChm::CHandler; }

static CArcInfo g_ArcInfo =
{ ".chm", { 'I', 'T', 'S', 'F' }, 4, CreateArc, 0 };

REGISTER_ARC(chm)
