#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("steel battleaxe", "ս��");
	add( "id", ({ "axe", "battleaxe" }) );
	set_short( "����ս��" );
	set_long(
		"���ս�����������ء��������Ǽ�սʿ���ĸ߼�������\n"
	);
	set( "unit", "��" );
	set( "weight", 190 );
	setup_weapon( "axe", 31, 22, 35 );
	set( "bleeding", 10 );
	set( "value", ({ 980, "silver" }) );
}
