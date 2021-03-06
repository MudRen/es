#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("海威港码头");
        set_long( @C_LONG_DESCRIPTION
你现在正站在海威镇的码头上，数十艘或大或小的渔船散布在港口内。你看到
许\多渔民将鱼网(net)挂在码头旁边的空地，往南不远处是一个鱼市场(market)，
这里偶尔会有来自西方的诺顿渡轮停靠，海威镇的居民对这些打扰他们平静生活的
陌生人早已司空见惯，你的出现并没有引起太多人的注意。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "c_item_desc", ([ 
                "net" : @LONG_TEXT
这些鱼网因为经年使用，所以上面都因为海水的浸蚀而布满了许\多小孔，由此
也可以看出这里的居民生活非常节俭。
LONG_TEXT
, 
                "market" : @LONG_TEXT
鱼市场就在南边不远处，渔民们出海打鱼回来就会把一篓一篓新鲜的渔获运到
市场去卖。
LONG_TEXT
 ]) );
    set("objects",([
        "mew1":"/d/eastland/haiwei/monster/mew",
        "mew2":"/d/eastland/haiwei/monster/mew"]));  
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/road_jetty" ]) );
        reset();
#include <replace_room.h>
}

void init()
{
        if( !find_object("/d/std/ocean/ship_iriah") )
                "/d/std/ocean/ship_iriah"->frog();
        if( !find_object("/d/std/ocean/ship_ta_tong") )
                "/d/std/ocean/ship_ta_tong"->frog();
}
