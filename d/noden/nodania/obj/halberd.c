#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("halberd", "���");
	set_short("���Ƴ��");
	set_long(
		"���ֳ��ͨ����ŵ�ٻʼ���ʿ�ŵ���ʿ��ϲ����������\n"
	);
	set( "unit", "��" );
	set( "weight", 160 );
	set( "type", "polearm" );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "value", ({ 1900, "silver" }) );
}
