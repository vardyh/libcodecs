// Common/CRC.cpp

#include "StdAfx.h"

#include <rtl/7zCrc.h>

struct CCRCTableInit { CCRCTableInit() { CrcGenerateTable(); } } g_CRCTableInit;
