#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "light rapier", "���ͽ�" );
	add( "id", ({ "rapier" }) );
	set_short( "���ͽ�" );
	set_long(@CLONG
����һ����ͨ��ʿʮ��ϲ���Ľ�������ϸ��������춻Ӷ�������
���ݻ��н����Ļ��ְ��ۡ�
CLONG
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 12 );
	set( "weight", 60 );
	set( "value", ({ 240, "silver" }) );
}
