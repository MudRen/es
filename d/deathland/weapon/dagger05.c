#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("scalpel","������");
       add("id",({"dagger",}) );
       set_short("������");
       set_long(
     	 "һ��ר��������ʱʹ�õ�С��.\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 24 );
    set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 24 );
	set( "weight", 32 );
	set( "extra_skills", (["operation":10]) );
	set( "value", ({ 1900 , "silver" }) );

}
