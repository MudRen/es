#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("Healer's inner room", "��ҽ���鷿");
	set_long( @LONG_DESCRIPTION
This is the inner section of healer's guild. Many valuable data is
stored here for fellow healers to study. In front of you is a book
shelf, you can find the books by searching the catalog. Also you
can see a human model with outlines on different nurves.. etc.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
��������ҽ���ǽ���ҽ���ĵõĵط���������ҽ�߶����ܹ����Լ�����������
������Ϊ�٣�������������ж�(study)������ҽ������������ҽѧ�����������
ǰ����һ���޴����̴ľ��ܣ�������ȴ�����ϵ�Ŀ¼(catalog)�������⣬
�㻹���Կ���һ��ľ�Ƶ�����ģ��(model)�������ʾ��һ��Ѿ��������
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
//	set( "c_item_desc", ([ 
//		"model" : @LONG_TEXT
//�������ģ������ҽ��������ϰ����õģ������ֶ��ԣ�������ģ����ϰ���
//��˵�Ǳ��޵Ŀγ̡�
//LONG_TEXT
//	]) );

        set( "objects", ([
                       "model" : "/d/healer/objs/model" ,
                       ]) ) ;	
        set( "item_func", ([
 		"catalog": "view_catalog" ]) );
	set( "exits", ([ 
		"west" : "/d/healer/building/healer_guild",
		"up" : "/d/healer/building/healer_upper",
		"south" : "/d/healer/building/healer_troom",
		"north" : "/d/healer/building/healer_reagent" 
		
		]) );

	set_spells( ([
		"heal"        : ({ "white-magic", 20, 4, 20, 100 }),
		"power-boost" : ({ "white-magic", 35, 3, 10, 150 }),
		"protect"     : ({ "white-magic", 60, 4, 10, 200 }),
		"paralyze"    : ({ "white-magic", 15, 4, 10, 100 }),
		"antidote"    : ({ "white-magic", 15, 6,  5, 100 })
	]) );
	
	reset();
}
