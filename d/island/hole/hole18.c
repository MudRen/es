#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "ʪ��" );
	set_long(@LONG
������޴�����֮�£���Ȼ��һƬʮ�ֳ�ʪ��̦�أ�����������
Ǻ�ü��������ܺ����ˡ���Ѩ���Ե���̦Ҳ��Ϊȱ����������䣬��
���ֲ԰׵���ɫ���������˻��ɣ�����������˾�ס��
LONG
);
	set( "exits",([
			"northeast" : HOLE"hole17",
			"south" : HOLE"hole19"
			]) );
	reset();
#include <replace_room.h>
}
