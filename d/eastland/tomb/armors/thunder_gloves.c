#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder gloves", "�׵�����" );
	add( "id", ({ "glove", "gloves", }) );
	set_short( "�׵�����" );
	set_long( 
@C_TOPIC
��֮�������������ף���Լ����������¡¡������������
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "defense_bonus", 2 );
	set( "special_defense",
	    ([ "electric":10, "poison":-5 ]) );
	set( "extra_skills", ([ "parry":10 ]) );    
	set( "extra_stats", ([ "int": -1,"str": -1 ]) );
	set( "weight", 50 );
	set( "value", ({ 1700, "silver" }) );
}
