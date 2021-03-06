#include <takeda.h>
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int fish_present = 1;

void create()
{
	::create();
	set_short( "石碣村" );
	set_long(
	"这里是梁山泊外的小渔村－石碣村，村中居民并不多，大约只有\n"
	"五六家，家家门口都晒著许\多鱼网(net)或渔具，也许\这儿的居民通通\n"
	"都靠打渔维生。\n"
	  );
	set_outside("eastland");
        set("c_item_desc",(["net":
"这些是再普通不过的鱼网，这儿的居民们利用它来捕捉湖中的水产以维\n"
"持生计。你仔细观察这些鱼网，在其中一张鱼网的中间，好像缠著什麽东西?\n"
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
    "要找什麽?\n");
	if( !fish_present )
		write(
		    "你把鱼网翻过来翻过去，什麽都没发现，你想你可能看错了。\n"
		);
	else {
		write(@ALONG
你发现鱼网中间缠著几只小鱼，你把它从鱼网上解下来，放在鼻子前闻了一下，
哇，这味道让你暂时失去思考的能力，体力好像也变弱了.....
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
