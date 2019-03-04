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
	set ("short.text", "��ʦ���԰�");
	set ("long.text", "����һ�����԰壬ר�������Լ��¡���ϸ�÷���ο� help board��\n"
						"������԰���Ȼ�������ʦ����ģ����κ��˶���ӭ���������ԡ�\n");
	replace_program("/std/board/bboard");
}
