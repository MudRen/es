
inherit "/std/board/bboard";

void create()
{
        bboard::create();
        set_attic_dir("/u/boss/demogorgon/data/attic") ;
        set_save_dir("/u/boss/demogorgon/data") ;
        set_save_file("dem_board");
        set_location("/u/boss/demogorgon/dema");
        set ("short.text", "dem's bulletin board");
        set ("c_short.text", "ħ�����԰�");
}
