
#include "../god.h"
inherit "/std/board/bboard";

void create()
{
        bboard::create();
        set_attic_dir (DATA"attic") ;
        set_save_dir(DATA) ;
        set_save_file("god_board");
        set_location(GOD"god_guild");
        set ("short.text", "GOD's bulletin board");
        set ("c_short.text", "ƒß…Ò¡Ù—‘∞Â");
}
