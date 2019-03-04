inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/knight/data/attic");
	set_save_dir("/d/knight/data");
	set_save_file("knight_board");
	set_location("/d/knight/fortress/knight_guild");
	set ("short.text", "Knight's bulletin board");
	set ("c_short.text", "��ʿ���԰�");
}
