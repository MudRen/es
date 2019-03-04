inherit "/std/board/bboard";
int query_max_msg() { return 100; }
int query_min_msg() { return 30 ; }

void create()
{
	bboard::create();
	set_attic_dir( "/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("idea_board");
	set_location("/d/wiz/ideas");
	set( "short.text", "Board of Ideas");
	set( "c_short.text", "�������԰�");
}
