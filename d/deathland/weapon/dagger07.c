#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("holy dagger","��ʥذ��");
       add("id",({"dagger",}) );
       set_short("a holy dagger","��ʥذ��");
       set_long(
           "A dagger enchanted holy power.\n",
           "һ�Ѹ�����ʥ����ذ��.\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
    set("type","dagger");
	set( "min_damage", 22 );
	set( "max_damage", 30 );
	set( "weight", 80 );
	set( "value", ({ 3000 , "silver" }) );

}
