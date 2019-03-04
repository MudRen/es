#include <takeda.h>
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int fish_present = 1;

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
"�����ơ�����ϸ�۲���Щ������������һ���������м䣬�������ʲ�ᶫ��?\n"
            ]));        
        set( "exits", ([
                "south" : TROOM"beach8",
                "north" : TROOM"village2",
                "west"  : TROOM"room2"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 object fish1,fish2,fish3;
 if ( !arg || arg != "net")
    return notify_fail(
    "Ҫ��ʲ��?\n");
	if( !fish_present )
		write(
		    "�����������������ȥ��ʲ�ᶼû���֣���������ܿ����ˡ�\n"
		);
	else {
		write(@ALONG
�㷢�������м������ֻС�㣬������������Ͻ����������ڱ���ǰ����һ�£�
�ۣ���ζ��������ʱʧȥ˼������������������Ҳ������.....
ALONG
		);
		fish_present = 0;
		fish1 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		fish2 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		fish3 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		if( (int)fish1->move(this_player()) != MOVE_OK )
			fish1->move( this_object() );
	        if( (int)fish2->move(this_player()) != MOVE_OK )
	                fish2->move( this_object() );
	        if( (int)fish3->move(this_player()) != MOVE_OK )        
	                fish3->move( this_object() );
	        (CONDITION_PREFIX + "weak")->apply_effect(this_player(),4,4);
	        return 1;
	}
}
