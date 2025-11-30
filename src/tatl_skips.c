#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "overlays/actors/ovl_Elf_Msg/z_elf_msg.h"
#include "overlays/actors/ovl_Elf_Msg3/z_elf_msg3.h"
#include "overlays/actors/ovl_Elf_Msg4/z_elf_msg4.h"
#include "overlays/actors/ovl_Elf_Msg5/z_elf_msg5.h"

RECOMP_HOOK("ElfMsg_Init") void ElfMsg_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg* this = (ElfMsg*)thisx;

    // Sets a flag to tell the game that the Tatl hint dialog have been triggered already.
    // These normally trigger automatically after approaching an object close enough.
    // Examples:
    //      The pushable block in the bridges room in Woodfall Temple;
    //      The pushable block at the Snowhead Temple entrance.
    Flags_SetSwitch(play, ELFMSG_GET_SWITCH_FLAG(&this->actor));
}

// Not skipping ElfMsg2 because this kind is the one that the player has to go out of their way to trigger.
// ElfMsg2 is triggered by Z-targeting something and pressing C-up (probably not for literally everything).

RECOMP_HOOK("ElfMsg3_Init") void ElfMsg3_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg3* this = (ElfMsg3*)thisx;

    // Sets a flag to tell the game that the Tatl interruption dialogs have been triggered already.
    // Not to be confused with ElfMsg4, ElfMsg3 is specifically for when the camera closes in on Link.
    // These normally trigger automatically after walking over a certain area.
    // Examples:
    //      Getting closer to the fountain in Clock Town Fairy Fountain;
    //      Moving along the path in Snowhead.
    Flags_SetSwitch(play, ELFMSG3_GET_SWITCH_FLAG(&this->actor));
}

RECOMP_HOOK("ElfMsg4_Init") void ElfMsg4_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg4* this = (ElfMsg4*)thisx;

    // Sets a flag to tell the game that the Tatl interruption cutscenes have been triggered already.
    // Not to be confused with ElfMsg3, ElfMsg4 is specifically for moving the camera to another actor, usually invisible ones.
    // These normally trigger automatically after walking over a certain area.
    // Example: Entering the central room in Woodfall Temple.
    Flags_SetSwitch(play, ELFMSG4_GET_SWITCH_FLAG(&this->actor));
}

RECOMP_HOOK("ElfMsg5_Init") void ElfMsg5_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg5* this = (ElfMsg5*)thisx;

    // Unknown as to what this one does, but seems to happen sometimes alongside ElfMsg5.
    // Places it occurs:
    //      Entering the central room in Woodfall Temple;
    //      Entering the central room in Snowhead Temple;
    //      Entering the room after the entrance in Great Bay Temple;
    //      Maybe blender room in Great Bay Temple?
    Flags_SetSwitch(play, ELFMSG5_GET_SWITCH_FLAG(&this->actor));
}