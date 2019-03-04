#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("six sun boots","六阳元靴");
     add( "id", ({ "boots" }) );
     set_short( "六阳元靴" );
     set_long(@C_TOPIC
一双绣著六日的靴子。靴子上面的手工很精致,非一时可以完成。
C_TOPIC
              );
     set( "unit", "双" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 2 );
     set( "defense_bonus", 1 );
     set( "weight", 60 );
     set("special_defense",(["magic":15,"evil":-20]) );
     set( "value", ({ 200, "silver" }) );
}