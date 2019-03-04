inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/thief/data/attic");
	set_save_dir("/d/thief/data");
	set_save_file("thief_board");
	set_location("/d/thief/hall/thief_guild");
	set ("short.text", "Thief's bulletin board");
	set ("c_short.text", "С͵���԰�");
	set ("c_long.text", 
		"����һ�����԰壬ר�������Լ��¡���ϸ�÷���ο� help board��\n");
}
