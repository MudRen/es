#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("�ص�");
	set_long( 
@LONG_DESCRIPTION
������һ����������ص��У���о���һ˿���⣬�㿴��һֻС�����ڽ������ڷ�
��������ĵ����п��Ըо�������ǰ��ȥ�����ܻ���Σ�ա�
LONG_DESCRIPTION
	);
set( "exits", ([
     "up" : OGROUP"warea9",
     "west" : OGROUP"tunnel2"
     ]) );
reset();
}
void init()
{
     if(this_player()) this_player()->set_explore("eastland#38");
}
