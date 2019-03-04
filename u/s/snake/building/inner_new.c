#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("Healer's inner room", "��ҽ���鷿");
	set_long( @C_LONG_DESCRIPTION
��������ҽ���ǽ���ҽ���ĵõĵط���������ҽ�߶����ܹ����Լ�����������
������Ϊ�٣�������������ж�(study)������ҽ������������ҽѧ�����������
ǰ����һ���޴����̴ľ��ܣ�������ȴ�����ϵ�Ŀ¼(catalog)�������⣬
�㻹���Կ���һ��ľ�Ƶ�����ģ��(model)�������ʾ��һ��Ѿ��������
C_LONG_DESCRIPTION
	);

	    set( "light", 1 );
        set( "objects", ([
                       "model" : "/d/healer/objs/model" ,
                       ]) ) ;	
	set( "exits", ([ 
		"west" : "/d/healer/building/healer_guild",
		"up" : "/d/healer/building/healer_upper",
		"south" : "/d/healer/building/healer_troom",
		"north" : "/d/healer/building/healer_reagent" 
		
		]) );
	reset();
}

