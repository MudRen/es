#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "amber ring", "�����ָ" );
	add( "id", ({ "ring" }) );
   set_short( "�����ָ" );
	set_long(
		"һ���൱�����������ָ����о�����ɢ����һ��ħ����\n"
	);
	set( "unit", "��" );
	set( "type", "finger" );
	set( "material", "element");
	set( "armor_class", 0 );
	set( "defense_bonus", 5 );
    set( "special_defense",
               ([ "mental":3, "electric":-3, "acid":3 ]) );
	set( "weight", 8 );
	set( "value", ({ 640, "silver" }) );
}
