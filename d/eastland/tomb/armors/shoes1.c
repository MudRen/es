#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "holy shoes", "��ħЬ" );
	add( "id", ({ "shoes", }) );
	set_short( "��ħЬ" );
	set_long( @C_TOPIC
һ˫�����۵�Ь�ӣ�ȴ����������ʲ��������
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 6 );
	set( "defense_bonus", 3 );
	set( "special_defense", 
	     ([ "evil": 5 ]) );
	set( "weight", 30 );
	set( "value", ({ 1000, "silver" }) );
}
