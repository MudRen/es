#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("long spear of Black","�ڳ�ì");
       add("id",({"spear"}) );
       set_short("�ڳ�ì");
       set_long(
           "һ��ͨ���ںڵĸֳ�ì������������Ϣ�Ĵ�����˵����ࡣ\n"
     	);
	
	set( "unit", "��" );
 	set( "weapon_class", 40 );
        set( "type","thrusting");
	set( "min_damage", 20 );
	set( "max_damage", 40 );
	set( "weight", 120 );
	set( "value", ({ 200, "gold" }) );
}
