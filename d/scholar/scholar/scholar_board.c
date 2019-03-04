inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/scholar/data/attic") ;
	set_save_dir("/d/scholar/data") ;
	set_save_file("scholar_board");
	set_location("/d/scholar/scholar/scholar_guild");
	set ("short.text", "Scholar's bulletin board");
	set ("c_short.text", "�������԰�");
	replace_program("/std/board/bboard");
}
