inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir( "/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("qc_board");
	set_location("/d/wiz/qc-request");
	set( "short.text", "Board of QC-Request");
	set( "c_short.text", "Ʒ�ʹ������԰�");
}
