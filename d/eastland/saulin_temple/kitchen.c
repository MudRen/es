#include "saulin_temple.h"

inherit SELLER;
inherit ROOM;

int book_found = 0;

void create()
{
	object ob,ob2;
	::create();
	set_short("香积厨");
	set_long( @C_LONG_DESCRIPTION
这是一间四周有著大窗户的房间，房子的中央是两个大火炉其上各
有一饭锅，北边放有许\多的餐\具，西边则是一个洗洁槽，此处供应少林
寺数千僧侣的伙食，此刻正有许\多人在里面忙著切菜煮饭，而煮饭产生的
蒸气正袅袅的上升，使整个房间弥漫著蒙浓白雾。你看到门口贴了张纸
(paper) 好像是价目表。  
C_LONG_DESCRIPTION
	);
	set("light", 1);
	set("exits", ([
        "east"  : SAULIN"grass5",
	]) );
    set( "item_func",([ "paper" : "show_menu" ]));
    set_inventory( ({
//       ({ SAULIN_OBJ"vege_food", 10, 10 }),
       ({ SAULIN_OBJ"apple" , 5, 5 }),
       ({ SAULIN_OBJ"banana", 5, 5 }),
    }) );

        ob = new( SAULIN_MONSTER"cooking_monk" );
        ob->move( this_object() );
        ob2 = new( SAULIN_MONSTER"gin_ping" );
        ob2->move( this_object() );

	reset();	
}

void init()
{
   seller::init();
   add_action("do_search","search");
}

int do_search()
{
   object obj,obj2;
   obj = this_player();
   if ( obj->query_temp("monk_movement") && book_found == 0 &&
        obj->query_temp("book_quest/step") == 3)
   {
       tell_object(obj,@MSG1

你听了火工头陀的话後, 在这儿仔细寻找, 果然在角落发现了一本经书。
你赶紧拿起来看看, 书名正是－－楞枷经。

你心想皇天不负苦心人, 你终於找到它, 赶快去回报给方丈知道吧!!
MSG1
);
       obj2 = new("/d/eastland/saulin_temple/obj/sutra.c");
       obj->set_temp("book_quest/step",4);
       obj2->move(obj);
       book_found = 1;
       return 1;
   }
   return 0;
}
void reset()
{
    ::reset();
    book_found = 0;
}
