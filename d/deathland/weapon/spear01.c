#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("long spear of Wind", "��֮��ì");
	add ("id",({ "spear" }) );
	set_short("��֮��ì");
	set_long(
            "һ������ս���з��Ӽ���\�ܵĳ�ì,���ܹ��������������˵�����\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 25 );
	set( "type", "thrusting" );
	set( "min_damage", 10 );
	set( "max_damage", 23 );
	set( "weight", 190 );
	set( "value", ({ 2220, "silver" }) );
}

