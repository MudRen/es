#include <mudlib.h> 
inherit "/std/board/bboard";

void create()
{
	::create();
	set_attic_dir ("/u/s/supertramp/cwa") ;
	set_save_dir("/u/s/supertramp/cwa") ;
	set_save_file("cwa_board");
	set_location("/u/s/supertramp/cwa/cwa_club") ;
	set ("short.text", "CWA's bulletin board");
	set ("c_short.text", "ɫ��Э�����԰�");
	set ("c_long.text", "����һ�����԰壬ר��ɫ�������Լ��¡���ϸ�÷���ο� help board��\n"
        );
}
