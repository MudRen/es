#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "three moon gloves", "��������" );
	add( "id", ({ "gloves" }) );
	set_short( "��������" );
	set_long(@C_LONG
һ˫����о��õ�����������ס�
C_LONG
	);
	set( "unit", "˫" );
        set("material","cloth");
	set( "type", "hands" );
	set( "weight", 70 );
        set( "defense_bonus", 1 );
        set("special_defense",(["magic":15,"divine":-15]) );
	set( "value", ({ 240, "silver" }) );
}
