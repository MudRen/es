#include "farwind.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/noden/data/attic") ;
	set_save_dir("/d/noden/data") ;
	set_save_file("bugs_board");
	set_location(FARWIND"square") ;
	set ("short.text", "ES bugs board");
	set ("c_short.text", "ES BUGS ���԰�");
	set ("c_long.text", "����һ�����԰壬ר���˱��� BUGS ����ϸ�÷���ο� help board��\n"
		"��� ES ����춴�ҵģ����ϣ���κ��˶��ڴ˱��������ֵ� BUGS ��\n");
}
