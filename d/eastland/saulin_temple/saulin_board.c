#include <mudlib.h>  
#include "saulin_temple.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/eastland/data/attic");
	set_save_dir("/d/eastland/data");
	set_save_file("saulin_board");
        set_location(SAULIN"monk_guild");
	set ("short.text", "openion board");
	set ("c_short.text", "���ֹ������԰�");
	set ("c_long.text", 
@DESC
����һ�����԰壬���˱��� BUGS ���ṩ���ӣ���ϸ�÷���ο� help board��
��������¼��乫����������ϣ����Ҷ�෢�ԣ����������ø��� !!
DESC
);
}
