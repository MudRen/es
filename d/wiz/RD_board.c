inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir( "/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("RD_board");
	set_location("/d/wiz/RandD");
	set( "short.text", "Board of R & D");
	set( "c_short.text", "�з������԰�");
}
