#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "katana", "����" );
   set_short( "��������һ���֡�" );
	set_long(
		"����һ�Ѳ���ѩ������ʿ�������ĵ���ֻ��һ�棬���ǵ����Ӳ��Ҫ��\n"
		"һ�㳣���Ľ��ߵö࣬����������ʱ������ɵ��˺��ϴ�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 90 );
	set( "weapon_class", 26 );
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "bleeding", 10 );
	set( "value", ({ 700, "silver" }) );
}
