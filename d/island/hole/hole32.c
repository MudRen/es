#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "ʪ��" );
	set_long(@LONG
������޴�����֮�£���Ȼ��һƬʮ�ֳ�ʪ��̦�أ�����������
Ǻ�ü��������ܺ����ˡ���Ѩ���Ե���̦Ҳ��Ϊȱ����������䣬��
���ֲ԰׵���ɫ���������˻��ɣ����������ס����
LONG
	);
	set( "exits",([
			"east" : HOLE"hole33",
			"northwest" : HOLE"hole31"
			]) );
	reset();
#include <replace_room.h>
}
