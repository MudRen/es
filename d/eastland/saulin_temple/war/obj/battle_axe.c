
#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("bonze battle axe","ͭս��");
       add("id",({"axe",}) );
       set_short("ͭս��");
       set_long(
           "����һ���������������Ķ̸���\n"
        );

        set( "unit", "��" );
        set( "weapon_class", 14 );
	set("type","axe");
        set( "min_damage", 7 );
        set( "max_damage", 14 );
	set( "min_damage", 9 );
        set( "max_damage", 16 );
	set( "weight", 65 );
        set( "value", ({ 30, "gold" }) );
}
