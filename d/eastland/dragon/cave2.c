
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
�������˶�Ѩʱ�㷢�ִ˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ������
��ʱ��һЩ��ֵ���ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�е�
��칹��һ�������ľ�ɫ�����㼸���������ںδ���
C_LONG_DESCRIPTION
	);
	set("objects",([
	    "woman_fighter":"/d/eastland/dragon/monster/woman_fighter"]));
	    
	set( "light", 0 );
	set( "exits", ([
	    "west" : Lcave"cave3",
		"leave" : "/d/eastland/7,18.east"
	]) );
	reset();
#include <replace_room.h>
}
