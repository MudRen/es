inherit "/std/board/bboard";
int query_max_msg() { return 50 ; }
int query_min_msg() { return 20 ; }
void create()
{
	bboard::create();
	set_attic_dir ("/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("wiz_board");
	set_location("/d/wiz/wiz_office");
	set ("short.text", "巫师留言板");
	set ("long.text", "这是一个留言板，专供人留言纪事。详细用法请参看 help board。\n"
						"这个留言板虽然是属於巫师公会的，但任何人都欢迎在这里留言。\n");
	replace_program("/std/board/bboard");
}
