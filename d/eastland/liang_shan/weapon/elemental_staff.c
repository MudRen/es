#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("elemental staff","ˮ����׹�");
       add("id",({"staff"}) );
       set_short("ˮ����׹�");
	   set_long(
           "һ�Ѱ߰��ĹŴ�ľ���������������ã��㻳�������ܵ�����ʹ�ã�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
        set("special_damage",30);
}

