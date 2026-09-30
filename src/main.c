#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"
#include "repy_api.h"
#include "recompconfig.h"
REPY_PREINIT_ADD_NRM_TO_ALL_INTERPRETERS;

extern Actor *gCurrentActorPointer;




void star_timer() {
    REPY_FN_SETUP;
    REPY_FN_SET_STR("command","start");
    REPY_FN_IMPORT("connector");
    REPY_FN_EXEC_CACHE(start_timer,"connector.send_command(command)\n");
    REPY_FN_CLEANUP;
}

void split_timer() {
    REPY_FN_SETUP;
    REPY_FN_SET_STR("command","split");
    REPY_FN_IMPORT("connector");
    REPY_FN_EXEC_CACHE(start_timer,"connector.send_command(command)\n");
    REPY_FN_CLEANUP;
}

RECOMP_CALLBACK("*", recomp_on_new_file_start) void NewFileStartTimer(void) {
    star_timer();
}

RECOMP_HOOK("func_global_asm_80680908") void split_on_barrel_break() {
    if (gCurrentActorPointer) {
        if (gCurrentActorPointer->control_state==0xC) {
            recomp_printf("Test");
        }
    }
}