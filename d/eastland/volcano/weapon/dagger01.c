#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("toy dagger","���ذ��");
       add("id",({"dagger",}) );
       set_short("���ذ��");
       set_long(
           "һ�����ذ��\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 4 );
        set( "type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 40 );
	set( "value", ({ 10, "silver" }) );

}
