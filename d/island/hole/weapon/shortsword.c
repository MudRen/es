#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "standard shortsword", "��ʽ�̽�" );
	add( "id", ({ "shortsword","sword","standard" }) );
	set_short( "��ʽ�̽�" );
	set_long(
            "����һ�ѱ�׼�Ķ̽��������������ǳ��ȶ����ʺϳ�ѧ��ʹ�á�\n"
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "value", ({ 290, "silver" }) );
}
