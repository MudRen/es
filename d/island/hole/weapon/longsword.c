#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Standard Longsword", "��ʽ����" );
	add( "id", ({ "longsword","sword","standard" }) );
	set_short( "��ʽ����" );
	set_long(
		"����һ�ѱ�׼�ĳ��������۳��Ȼ����������ʺϳ�ѧ��ʹ�á�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 25 );
	set( "min_damage", 13 );
	set( "max_damage", 24 );
	set( "value", ({ 470, "silver" }) );
}
