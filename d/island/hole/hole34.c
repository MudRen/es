#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short("ʪ��");
	set_long(@LONG
������޴�����֮�£���Ȼ��һƬʮ�ֳ�ʪ��̦�أ�����������
Ǻ�ü��������ܺ����ˡ���Ѩ���Ե���̦Ҳ��Ϊȱ����������䣬��
���ֲ԰׵���ɫ���������˻��ɣ����������ס���𣿰�ѽ�������
�и����µĶ�Ѩ�ˡ�
LONG
		);
	 set( "exits",([
			 "northwest" : HOLE"hole33",
			 "down"      : HOLE"hole35",]) );
	 reset();
#include <replace_room.h>
}