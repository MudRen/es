#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("Ϫ��ɳ��");
	set_long( @LONG
������֮����һϪ�����ɳ����ǰ��Ϫˮ�Ӷ��ϻ�������������������ע��һ
����ɫ�Ĵ󶴡���Ϫ����������ǧ��ߵ�ɽ�壬����в������������ߣ������
����Խ������
LONG
	);
        set("light",1);
	set( "exits", ([ 
         "southeast" : SAREA"bottom2",
        ]) );
	reset();
}
