inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir("/d/mage/data/attic") ;
	set_save_dir("/d/mage/data") ;
	set_save_file("mage_board");
	set_location("/d/mage/tower/mage_guild");
	set ("short.text", "mage's bulletin board");
	set ("c_short.text", "ħ��ʦ���԰�");
}
