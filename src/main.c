#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"
#include "repy_api.h"
#include "recompconfig.h"
REPY_PREINIT_ADD_NRM_TO_ALL_INTERPRETERS;

extern Actor *gCurrentActorPointer;





RECOMP_HOOK("func_gloabl_asm_80680908") void split_on_barrel_break() {
    if (gCurrentActorPointer) {
        if (gCurrentActorPointer->control_state==0xC) {
            recomp_printf("Test");
        }
    }
}