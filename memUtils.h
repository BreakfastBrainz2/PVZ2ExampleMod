#pragma once
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include "Logging.h"

extern uint g_libAddress;
// Get base address of a library (.so) loaded in memory.
uint getLibraryAddress(const char* libName);
// Get actual offset of address inside libPVZ2.so
uint getActualOffset(uint offset);
// Hook a function in libPVZ2
void PVZ2HookFunction(uint offset, void* replace, void** result, const char* funcName);