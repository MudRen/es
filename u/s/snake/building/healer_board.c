inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/healer/data/attic") ;
	set_save_dir("/d/healer/data") ;
	set_save_file("healer_board");
	set_location("/d/healer/building/healer_guild");
	set ("short.text", "Healer's bulletin board");
	set ("c_short.text", "��ҽ�����԰�");
}
