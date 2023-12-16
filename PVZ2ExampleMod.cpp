#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unistd.h>
#include <substrate.h>
#include "memUtils.h"
#include "PVZ2ExampleMod.h"
#include "SexyTypes.h"

class ZombieAlmanac
{
public:
    void* vftable;
    std::map<SexyString, uint> m_aliasToId;
};

class PlantNameMapper
{
public:
    void* vftable;
    std::map<SexyString, uint> m_aliasToId;
};

typedef ZombieAlmanac* (*ZombieAlmanacCtor)(ZombieAlmanac*);
ZombieAlmanacCtor oZombieAlmanacCtor = NULL;

void* hkCreateZombieTypenameMap(ZombieAlmanac* a1)
{
    // Let the game create the original alias->id map
    ZombieAlmanac* obj = oZombieAlmanacCtor(a1);
    // Now add our own zombie aliases to it
    obj->m_aliasToId["steam"] = 441; // 441 is the first free id in 9.4.1
    obj->m_aliasToId["steam_armor1"] = 442;
    obj->m_aliasToId["steam_armor2"] = 443;
    obj->m_aliasToId["steam_flag"] = 444;

    return obj;
}

typedef PlantNameMapper* (*PlantNameMapperCtor)(PlantNameMapper*);
PlantNameMapperCtor oPlantNameMapperCtor = NULL;

void* hkCreatePlantNameMapper(PlantNameMapper* self)
{
    // Same deal with the ZombieAlamanc::ctor hook
    PlantNameMapper* obj = oPlantNameMapperCtor(self);
    // Register our own plant aliases
    obj->m_aliasToId["another_peashooter_clone"] = 185;
    return obj;
}

// The original function is broken for some reason. We don't need it
uint oCamelZombieFunc = NULL;

typedef void(*camelMinigameModuleFunc)(int, int, int);
camelMinigameModuleFunc cmmFunc = (camelMinigameModuleFunc)getActualOffset(0x797494);

void hkCamelZombieFunc(int a1, int a2, int a3)
{
    // Redirect call to some function in CamelMinigameModule
    // This fixes the crash when camels are rising from the ground
    cmmFunc(a1, a2, a3);
}

__attribute__((constructor))
// This is automatically executed when the lib is loaded
// Run your initialization code here
void libPVZ2ExampleMod_main()
{
	LOGI("Initializing %s", LIB_TAG);
    PVZ2HookFunction(0x105123C, (void*)hkCreateZombieTypenameMap, (void**)&oZombieAlmanacCtor, "ZombieAlmanac::ZombieAlamanc");
    PVZ2HookFunction(0xD994B8, (void*)hkCreatePlantNameMapper, (void**)&oPlantNameMapperCtor, "PlantNameMapper::PlantNameMapper");
    PVZ2HookFunction(0x7942BC, (void*)hkCamelZombieFunc, (void**)&oCamelZombieFunc, "CamelZombie::vftable_func_0xEC");
    LOGI("Finished initializing");
}