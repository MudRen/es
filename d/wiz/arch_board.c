inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir( "/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("arch_board");
	set_location("/d/wiz/arch_office");
	set( "short.text", "Archwizards' bulletin board");
	set( "c_short.text", "����ʦ���԰�");
}
