#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "�ɸ���" );
	set_long(@LONG
�������һЩ�ɵľ���װ���͵ﱤ��Ŀǰ�Ѿ����������ˡ�ԭ����
��ǰפ���ڴ˵ص�ʿ�������������������������״��ң�����ȫ���
��Һ������Ǭ�Ƶģ���춿���޷����ԭ�����Ա�������������᳷
�����������ٶȷ�����
LONG
	);
	set( "exits",([
			"southwest" : HOLE"hole29"
			]) );
	reset();
#include <replace_room.h>
}
