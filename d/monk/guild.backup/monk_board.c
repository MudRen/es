inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/monk/data/attic");
	set_save_dir("/d/monk/data");
	set_save_file("monk_board");
    set_location("/d/monk/guild/monk_guild");
	set ("short.text", "Monk's bulletin board");
	set ("c_short.text", "��ɮ�������԰�");
}
