inherit "/std/board/bboard";

void create()
{
        bboard::create();
        set_attic_dir ("/u/s/sage/guild/boarddata/attic") ;
        set_save_dir("/u/s/sage/guild/boarddata") ;
        set_save_file("killer_board");
     set_location("/u/s/sage/guild/killer_guild");
        set ("short.text", "Killer's bulletin board");
        set ("c_short.text", "ɱ�����԰�");
}
