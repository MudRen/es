//#pragma save_binary

#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
    object *obs, ob;
	::create();
	set_short("圆形广场");
	set_long( @LONG_DESCRIPTION
你现在站在摩亚达城最著名的圆形广场，这是摩亚达城最著名的地方。
你可以看到很多对魔法有兴趣的人聚集在这里，他们谈论著一些有关於魔法
的话题——咒文、卷轴等等。「银色之塔」(silver tower)就在广场的正中
央，它是一栋银色的圆形建筑物，你看到有一个很大的铁门可供出入。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"south" : MOYADA"mainrd7.c", 
		"west"  : MOYADA"mainrd6.c", 
		"north" : MOYADA"mainrd5.c", 
		"east"  : MOYADA"mainrd8.c",
	]) );
	set( "item_desc", ([
      "tower" : "一栋银色的圆形建筑物，也许你可以进去(enter)看看。\n",
	]) );
	reset();
}

void reset()
{
    object ob;
    if( !present("vendor", this_object()) ) {
      ob = new( "/obj/vendor" );
      ob->set("no_attack", 0);
      ob->set_natural_weapon(20, 10, 20);
      ob->set_natural_armor(40, 10);
      ob->set("max_hp", 200);
      ob->set("hit_points", 200);
      ob->set("exp_reward", 300);
      ob->set("wealth", ([ "silver" : 20 ]) );
      ob->move( this_object() );
    }
    ::reset();
}

void init()
{
    add_action("to_enter","enter");
}

int to_enter( string arg )
{
    object player;
    player = this_player();
    
    if( !arg || arg != "tower" )
      return notify_fail("Enter what?\n");
    tell_room( this_object(), 
      sprintf("%s走进塔内。\n", player->query("c_name") ), player );
    player->move_player("/d/mage/tower/mage_guild","SNEAK");
    tell_room( environment(player), 
      sprintf("%s(%s)走了进来。\n", player->query("c_name"),player->query("name") ), player );
    return 1;
}
