#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("sharp dagger","����ذ��");
       add("id",({"dagger",}) );
       set_short("����ذ��");
       set_long(
           "һ�ѷ�����ذ��,���Ա����Լ�\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 14 );
    set("type","dagger");
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "weight", 35 );
	set( "value", ({ 30, "gold" }) );

}
