#include "../killer.h"
inherit "/std/board/bboard";

void create()
{
        bboard::create();
        set_attic_dir (DATA"attic") ;
        set_save_dir(DATA) ;
        set_save_file("killer_board");
        set_location(KILLER"killer_guild");
        set ("short.text", "Killer's bulletin board");
        set ("c_short.text", "ɱ�����԰�");
}
