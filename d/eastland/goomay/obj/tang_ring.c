#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("small golden ring","С��Ȧ��");
        add("id",({"ring"}) );
         set_short( "a small golden ring","С��Ȧ��");
	set_long(
		 "This is a small ring. \n",
		 "һ��СС�Ľ��ָ���������һ��СС�ġ��ơ��֡�\n"
		 );
	set( "unit", "ֻ" );
        set("material","light_metal");
	set( "weight", 10 );
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 2 );
	set( "value", ({  12, "gold" }) );
}
