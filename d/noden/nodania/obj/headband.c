#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name("headband", "��ʤͷ��");
	set_short("��ʤͷ��");
	set_long(
		"����һ����ɫͷ������д������ʤ����\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "armor_class", 3 );
	set( "defense_bonus", 5 );
	set( "value", ({ 3100, "gold" }) );
	set( "weight", 40 );
	set( "no_sale", 1);
}
