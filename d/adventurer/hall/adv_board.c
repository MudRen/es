inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/adventurer/data/attic");
	set_save_dir("/d/adventurer/data");
	set_save_file("adventurer_board");
	set_location("/d/adventurer/hall/adv_guild");
	set ("short.text", "Adventurer's bulletin board");
	set ("c_short.text", "ð�������԰�");
	set ("c_long.text", "����һ�����԰壬ר�������Լ��¡���ϸ�÷���ο� help board��\n"
						"���ð���߹�������춴�ҵģ�����κ��˶���ӭ���������ԡ�\n");
}
