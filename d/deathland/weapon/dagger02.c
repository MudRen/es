#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name(" short dagger","��ذ��");
       add("id",({"dagger",}) );
       set_short("��ذ��");
       set_long(
           "һ�������һ����ذ��\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 9 );
    set("type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 8 );
	set( "weight", 25 );
	set( "value", ({ 50 , "silver" }) );

}
