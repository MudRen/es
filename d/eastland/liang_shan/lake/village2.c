#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ʯ�ٴ�" );
	set_long(
	"��������ɽ�����С��壭ʯ�ٴ壬���о��񲢲��࣬��Լֻ��\n"
	"�����ң��Ҽ��ſڶ�ɹ����\������(net)����ߣ�Ҳ��\����ľ���ͨͨ\n"
	"��������ά����\n"
	  );
	set_outside("eastland");
        set("c_item_desc",(["net":
"��Щ������ͨ����������������ľ���������������׽���е�ˮ����ά\n"
"�����ơ�\n"
            ]));        
        set( "exits", ([
                "north" : TROOM"fish_plate",
                "east"  : TROOM"room1",
                "west"  : TROOM"room3",
                "south" : TROOM"village1"
        ]) );
        set( "objects",([
                "merchant" : "/d/eastland/haiwei/monster/merchant"
        ]));
        reset();
}
