#include <mudlib.h>  
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/monk/data/attic");
	set_save_dir("/d/monk/data");
	set_save_file("water_board");
	set_location("/d/monk/guild/monk_pass");
	set("short.text", "talking board");
	set("c_short.text", "��ɮ�����ˮ��");
	set("c_long.text", 
@DESC
��һ����Ϊ�� ���λ���Ӱ ��������� Ӧ�����ǹ� ��
                                                   ��ղ����ܾ� 
 
����һ�����԰壬��ʮ����·�������ˮ֮�á�ָ���÷���ο� help board��
DESC
	);
}
