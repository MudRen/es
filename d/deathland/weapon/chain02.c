#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("white morningstar","�����ǡ�");
       add("id",({"morningstar",}) );
       set_short("a white morningstar","�����ǡ�");
       set_long(
           "һ�Ѱ�ɫ���ǡ�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 22 );
    set("type","chain");
	set( "min_damage", 11 );
	set( "max_damage", 23 );
	set( "weight", 210 );
	set( "value", ({ 100, "gold" }) );
}
