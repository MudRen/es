#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid( getuid() );
	set_name( "Sword of Markara", "�꿨��֮��" );
	add( "id", ({ "markara","sword" }) );
	set_short( "�꿨��֮��" );
	set_long(
        "����꿨��֮���ǹ����͸�������ʿ�������������������������\n"
		"�����Ļ��ƣ���������Ľ��Ǵ����������ӵ�������\n"
	);
	set( "unit", "��" );
	set( "weapon_class", 35 );
	set( "type", "longblade" );
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 120 );
	set( "value", ({ 230, "gold" }) );
}
