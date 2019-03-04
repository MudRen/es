
#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("Spear of red steel", "���ì");
        add ("id",({ "spear" }) );
        set_short("Spear of red steel", "���ì");
        set_long(
            "A special spear which made by red magic steel.\n",
            "����һ���ɺ�ɫħ�������������ɵĳ�ì�������������\n"+
	    "��â��ì�⣬�ƺ������ڲ�ͬ��������\n"
        );
        set( "unit", "��" );
        set( "weapon_class", 25 );
        set( "type", "thrusting" );
        set( "min_damage", 10 );
	set( "max_damage", 36 );
	set( "weight", 190 );
        set( "value", ({ 1650, "silver" }) );
}
