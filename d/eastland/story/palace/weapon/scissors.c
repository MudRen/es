#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "large scissors", "�󻨼�" );
	add( "id", ({ "scissors", "scissor" }) );
	set_short( "�󻨼�" );
	set_long(@LONG
����һ�������޼�ֲ��Ĵ����������մ��Щ��ҳ���
LONG
	);
	set( "type", "shortblade" );
	set( "weapon_class", 20 );
	set( "min_damage", 15 );
	set( "max_damage", 22 );
	set( "weight", 80 );
	set( "value", ({ 1000, "silver" }) );
	set_c_verbs( ({ "��%s��%sһ��" }) );
}
