
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("��Ѩ");
	set_long( @C_LONG_DESCRIPTION
�������˶�Ѩʱ�㷢�ִ˴���һ����ɽ�۶������ܶ�����ֵĻ��ɫ��ʯ������
��ʱ��һЩ��ֵ���ʯ�ᾧ�����䱻���ӳ��֮ʱ���ᷴ���Ѥ���Ĺ��ߣ�����ԭ�е�
��칹��һ�������ľ�ɫ�����㼸���������ںδ���ɽ�����˴˴���Ȼ�зֲ棬������
��֪��ȥ�δӡ�
C_LONG_DESCRIPTION
	);
	set( "light", 0 );
	set( "exits", ([
	    "east" : Lcave"cave2",
		"northwest" : Lcave"cave4",
		"southwest" : Lcave"cave5"
	]) );
	reset();
#include <replace_room.h>
}
