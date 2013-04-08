// RegisterArc.h

#ifndef __REGISTER_ARC_H
#define __REGISTER_ARC_H

#include "../Archive/IArchive.h"

typedef IInArchive * (*CreateInArchiveP)();
typedef IOutArchive * (*CreateOutArchiveP)();

struct CArcInfo
{
	const char *Name;
	Byte Signature[28];  // FIXME Byte Signature[16]; adding 22 bytes to insure kSignature[0x1A]!= 0 and  kSignature[0x1B] != 0
	int SignatureSize;
	CreateInArchiveP CreateInArchive;
	CreateOutArchiveP CreateOutArchive;
};

void RegisterArc(const CArcInfo *arcInfo);

#define REGISTER_ARC_NAME(x) CRegister ## x

#define REGISTER_ARC(x) struct REGISTER_ARC_NAME(x) { \
    REGISTER_ARC_NAME(x)() { RegisterArc(&g_ArcInfo); }}; \
    static REGISTER_ARC_NAME(x) g_RegisterArc;

#endif
