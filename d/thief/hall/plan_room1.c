#include <mudlib.h>

inherit "/d/thief/hall/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("����о�����");
	set_long( @LONG_DESCRIPTION
������С͵�ǻ��ཻ����ƺ�ƭ���ĵط�������С͵�����ܹ����Լ��ĵ���
��������Ϊ�٣������������ѧϰ(study)����С͵���������Ĵ������ӣ�����
��ǰ��������һ���޴���飬������ȴ����ϵ�Ŀ¼(catalog)����
PS. Ŀǰ��δ����ѧϰ��
LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"catalog": "view_catalog" ]) );
	set( "exits", ([ 
		"north" : "/d/thief/hall/thief_guild" ]) );
	set_tricks( ([
		"set-fire"   	 : ({ "trick", 20, 4, 20, 100 }),
		"shut-up"		 : ({ "trick", 35, 3, 10, 150 }),
		"bag-bag"    	 : ({ "trick", 60, 4, 10, 200 }),
		"not-me" 	     : ({ "trick", 15, 4, 10, 100 }),
		"throw-dagger"   : ({ "trick", 15, 6,  5, 100 })
	]) );
	
	reset();
}

