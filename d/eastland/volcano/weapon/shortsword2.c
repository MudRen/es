#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("blue_water shortsword","��ˮ�̽�");
       add("id",({"shortsword"}) );
       set_short("��ˮ�̽�");
       set_long(
           "һ�Ѱ�͸���Ķ̽��������ƺ���ˮ����\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 40 );
        set( "type","shortblade");
        set( "second", 1);
	set( "min_damage", 23 );
	set( "max_damage", 36 );
	set( "weight", 200 );
	set( "value", ({ 500, "gold" }) );
}
