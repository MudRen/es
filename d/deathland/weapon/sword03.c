#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Longsword of Nightmare","���γ���");
        add("id",({"sword","longsword","nightmare"}) );
        set_short("���γ���");
      	set_long(
           "һ�ѻ�����ĵ��˲������εķ�������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 33 );
	set( "weight", 100 );
	set( "value", ({ 320, "gold" }) );

}

