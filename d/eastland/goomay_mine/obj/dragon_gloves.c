#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dragon gloves", "��������" );
	add( "id", ({ "dragon", "gloves", }) );
	set_short( "dragon gloves", "��������" );
	set_long(@C_TOPIC
һ˫���������ף���������һֻ������ֵķ�����ʹ�����������ɫ���١�
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "cloth");
        set( "armor_class", 4 );
	set( "defense_bonus", 5 );
	set( "special_defense",
	    ([ "acid":10, "poison":5 ]) );    
	set( "weight", 10 );
	set( "value", ({ 2500, "silver" }) );
}
