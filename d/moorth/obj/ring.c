#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crystal ring", "ˮ����ָ" );
	add( "id", ({ "ring" }) );
	set_short( "a crystal ring", "ˮ����ָ" );
	set_long(
		"You see a crystal ring. It is glowing in a soft aura.\n",
		"���ˮ����ָ��������һ���ʺ�ɫ��ˮ����ˮ����Χ�ƺ�Χ����һ\n"
		"Ȧˮ������ˮ���ڲ�������΢���յ��������ʡ�\n"
	);
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "energy":5, "electric":-8 ]) );
	set( "weight", 3 );
	set( "value", ({ 1840, "silver" }) );
}
