inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir( "/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("trans_board");
	set_location("/d/wiz/translate");
	set( "short.text", "Board of Translation");
	set( "c_short.text", "��Ӣ�ķ������԰�");
}
