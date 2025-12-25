#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "overlays/actors/ovl_Elf_Msg/z_elf_msg.h"
#include "overlays/actors/ovl_Elf_Msg3/z_elf_msg3.h"
#include "overlays/actors/ovl_Elf_Msg4/z_elf_msg4.h"
#include "overlays/actors/ovl_Elf_Msg5/z_elf_msg5.h"
#include "overlays/actors/ovl_Elf_Msg6/z_elf_msg6.h"

RECOMP_HOOK("ElfMsg_Init") void ElfMsg_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg* this = (ElfMsg*)thisx;

    // Sets a flag to tell the game that the Tatl hint dialog have been triggered already.
    // These normally trigger automatically after approaching an object close enough.
    // Examples:
    //     The pushable block in the bridges room in Woodfall Temple;
    //     The pushable block at the Snowhead Temple entrance.
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
    //     Getting closer to the fountain in Clock Town Fairy Fountain;
    //     Moving along the path in Snowhead.
    Flags_SetSwitch(play, ELFMSG3_GET_SWITCH_FLAG(&this->actor));
}

RECOMP_HOOK("ElfMsg4_Init") void ElfMsg4_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg4* this = (ElfMsg4*)thisx;

    // Sets a flag to tell the game that the Tatl interruption cutscenes have been triggered already.
    // Not to be confused with ElfMsg3, ElfMsg4 is specifically for moving the camera to another actor, usually invisible ones.
    // These normally trigger automatically after walking over a certain area.
    // Places it occurs:
    //     Entering the central room in Woodfall Temple;
    //     Entering the central room in Snowhead Temple;
    //     Entering the room after the entrance in Great Bay Temple;
    //     Maybe blender room in Great Bay Temple?
    Flags_SetSwitch(play, ELFMSG4_GET_SWITCH_FLAG(&this->actor));
}

RECOMP_HOOK("ElfMsg5_Init") void ElfMsg5_Init_init(Actor* thisx, PlayState* play) {
    ElfMsg5* this = (ElfMsg5*)thisx;

    // Unknown as to what this one does, but seems to happen sometimes alongside ElfMsg4.
    // Places it occurs:
    //     Entering the central room in Woodfall Temple;
    //     Entering the central room in Snowhead Temple;
    //     Entering the room after the entrance in Great Bay Temple;
    //     Maybe blender room in Great Bay Temple?
    Flags_SetSwitch(play, ELFMSG5_GET_SWITCH_FLAG(&this->actor));
}

RECOMP_HOOK("ElfMsg6_Init") void ElfMsg6_Init_init(ElfMsg6* this, PlayState* play) {

    // Function called from ElfMsg6_Init to check the conditions for which cutscene with Tatl to play after a cycle reset.
    // The flags below are set to make the game believe the cutscenes have been watched, so no cutscene is played.
    SET_WEEKEVENTREG(WEEKEVENTREG_31_04);   // Flag for coming out of Clock Tower after returning to human form.
    SET_WEEKEVENTREG(WEEKEVENTREG_87_10);   // Flag for coming out of Clock Tower after obtaining Odolwa's Remains.
    SET_WEEKEVENTREG(WEEKEVENTREG_87_20);   // Flag for coming out of Clock Tower after obtaining Goht's Remains.
    SET_WEEKEVENTREG(WEEKEVENTREG_87_40);   // Flag for coming out of Clock Tower after obtaining Gyorg's Remains.
    SET_WEEKEVENTREG(WEEKEVENTREG_87_80);   // Flag for coming out of Clock Tower after obtaining Twinmold's Remains.
    SET_WEEKEVENTREG(WEEKEVENTREG_79_10);   // Flag for Tatl hint on South Clock Town platform before 12 AM on night 3.
    SET_WEEKEVENTREG(WEEKEVENTREG_88_20);   // Flag for Tatl popup before going up in Clock Tower after 12 AM on night 3.
}