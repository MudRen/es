#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("wraith shortsword","����̽�");
       add("id",({"shortsword"}) );
       set_short("����̽�");
       set_long(
           "һ���ɻ�ɽ�����Ƶİ���̽�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set( "type","shortblade");
        set( "second",1);
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 200 );
	set( "value", ({ 500, "gold" }) );
}
