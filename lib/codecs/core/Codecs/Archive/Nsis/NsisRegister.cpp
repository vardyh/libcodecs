// NsisRegister.cpp

#include "StdAfx.h"

#include "../../Common/RegisterArc.h"

#include "NsisHandler.h"
static IInArchive *CreateArc() { return new NArchive::NNsis::CHandler; }

static CArcInfo g_ArcInfo =
{ ".nsis", NSIS_SIGNATURE, NArchive::NNsis::kSignatureSize, CreateArc, 0 };

REGISTER_ARC(nsis)
