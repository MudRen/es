#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("two-faced blade","�������е�");
       add("id",({"blade"}) );
       set_short("�������е�");
	   set_long(
           "����һ���������صı��������ⲿ�������ֲ棬�ƺ���������������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
    set("type","longblade");
	set( "min_damage", 13 );
	set( "max_damage", 26 );
	set("bleeding",5);
	set( "value", ({ 62, "gold" }) );
	set( "extra_skills",(["parry":10]));
	
}	
