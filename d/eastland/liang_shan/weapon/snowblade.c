#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("snow iron-blade","ѩ��������");
       add("id",({"iron-blade","blade",}) );
       set_short("ѩ��������");
	   set_long(
           "һ�����Ϻ���������ɵĵ������з���ɭɭ�ĺ��⣬�����൱������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 37 );
        set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 37 );
	set( "weight", 140 );
	set( "nosecond", 1 );
        set( "bleeding", 10 );
	set( "value", ({ 740, "gold" }) );
	
}	
