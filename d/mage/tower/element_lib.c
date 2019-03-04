//#pragma save_binary
#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "Ԫ��ħ��ͼ����");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
������������ɫ֮���в�����ḻ��һ��ͼ���ң��������ղ��й�Ԫ��ħ����
������鼮���κεط�Ҳ�Ȳ��ϵģ�����Ŀǰħ��ʦ�ǹ�Ϊʹ�õļ���ħ��֮�⣬
��Щ�鼮�������صķ��������ڻ�û�����ܿ���������Է��ĵ�һ������ϵ�����
(index)������Ŀǰ����Щ�������Բο���������ͨ��ͼ��ݴ�����ͨ����
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"west" : MAGE"library" ]) );
	set( "item_func", ([
	    "index" : "view_catalog" ]) );
	set_spells( ([
		"light"       : ({ "elemental", 10, 7, 10, 100 }),
		"fireball"    : ({ "elemental", 15, 6, 10, 150 }),
		"sleet"       : ({ "elemental", 40, 4, 10, 150 }),
    "flamming-shield" : ({ "elemental", 40, 3, 15, 115 }),
      "ice-shield"    : ({ "elemental", 40, 3, 15, 135 }),
	]) );
	reset();
}

