#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("green hood", "浑青抓角头巾");
        add( "id", ({ "hood" }) );
        set_short("浑青抓角头巾");
        set_long(
                "这是一顶绿油油的头巾，如果你不介意的话，这倒是非凡的防具． \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "fire":4, "cold":-5, "mental":2 ]) );
        set( "weight", 50 );
		set( "equip_func","equip_hood");
        set( "value", ({ 466, "gold" }) );
        set( "extra_look", "$N戴著一顶绿油油的头巾，看来十分可爱。\n" );

}
void equip_hood()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"小心翼翼的套上一顶绿油油的头巾.......\n"
    ,({holder}));
    tell_object(holder,
    "你小心翼翼的套上这顶绿油油的头巾.........\n");
	return ;
}


