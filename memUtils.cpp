#include "memUtils.h"
#include "Logging.h"

#include <substrate.h>

uint g_libAddress = NULL;

uint getLibraryAddress(const char* libName) {
    FILE* fp = fopen("/proc/self/maps", "rt");
    if (fp == NULL) {
        perror("fopen");
        return 0;
    }

    uint addr = 0;
    char line[1024];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, libName) != NULL) {
            addr = strtoul(line, NULL, 16);
            LOGI("%s at 0x%x", libName, addr);
            break;
        }
    }

    fclose(fp);
    return addr;
}

uint getActualOffset(uint offset)
{
    if (g_libAddress == 0)
    {
        g_libAddress = getLibraryAddress("libPVZ2.so");
    }
    return g_libAddress + offset;
}

void PVZ2HookFunction(uint offset, void* replace, void** result, const char* funcName) 
{
    MSHookFunction((void*)getActualOffset(offset), replace, result);
    LOGI("Hooked %s", funcName);
}