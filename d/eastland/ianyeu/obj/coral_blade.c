#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name( "coral blade", "�š�����" );
    add( "id", ({ "blade" }) );
    set_short( "�š�����" );
	set_long(
        "����һ���������ɺ��������ɵĳ���, ͨ�����, ����������Լ͸��\n"
        "һ˿���, �ƺ�����մ��Ѫ�����¡�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weight", 90 );
    set( "weapon_class", 30 );
    set( "min_damage", 15 );
    set( "max_damage", 28 );
//    set( "bleeding", 15 );
    set( "value", ({ 1200, "silver" }) );
}
