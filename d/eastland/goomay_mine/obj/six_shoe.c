#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("shoes","����ѥ");
	add( "id", ({ "shoes", "shoe", }) );
	set_short( "a shoes", "����ѥ" );
	set_long(@C_TOPIC
����ͨ��Ƥ�����ģ��������ʽ����Ĳã�������ڲ�ͬ�����Բ�������֮���ơ�
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "leather" );
	set( "armor_class", 5 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "all":5, "none":2 ]) );     
	set( "weight", 40 );
	set( "no_sale", 1);
	set( "value", ({ 1500, "silver" }) );
}
