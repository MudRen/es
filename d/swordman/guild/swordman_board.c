inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/swordman/data/attic");
	set_save_dir("/d/swordman/data");
	set_save_file("swordman_board");
	set_location("/d/swordman/guild/guild");
	set ("short.text", "Swordman's bulletin board");
	set ("c_short.text", "�����������԰�");
}
