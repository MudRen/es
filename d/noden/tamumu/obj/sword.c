#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "�޽�" );
	add( "id", ({ "bastardsword", "sword" }) );
	set_short(  "����֮��" );
	set_long(@C_LONG
����һ�Ѻܴ󡢷ǳ��󡢴����������ֻ�ֲ��ܡ��á������ϵľ޽���
���Ľ����Ͽ���һͷ���ǵı�־������������ˣ�
C_LONG
               );
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 38 );
	set( "min_damage", 21 );
	set( "max_damage", 43 );
	set( "weight", 230 );
	set( "nosecond", 1 );
	set( "value", ({ 210, "gold" }) );
}
