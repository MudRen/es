#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "worn hat", "��ñ��" );
	add( "id", ({ "hat" }) );
   set_short( "��ñ��" );
	set_long(
		"�ⶥñ���Ѿ����ƾ��ˣ������кü����ƶ���\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 15, "silver" }) );
}
