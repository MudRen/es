#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's shoes", "��ʦ��ѥ" );
	add( "id", ({ "shoes", "shoe", }) );
	set_short( "a wizard's shoes", "��ʦ��ѥ" );
	set_long( @TOPIC
	The pair of shoes used by wizard Rashudi. It is made by normal cloth,
but spreads a special power of magic.
TOPIC
    , @C_TOPIC
	���޵۹�춴�����ѥ�ӣ���Ȼֻ������ͨ�Ĳ����ģ���ɢ����һ��ħ����
C_TOPIC
	);
	set( "unit", "˫" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set( "special_defense", 
	     ([ "divine":10, "none":2 ]) );
	set( "extra_skills", ([ "recharge" :10 ]) );
	set( "extra_stats", ([ "dex":2 ]) );     
	set( "weight", 20 );
	set( "no_sale", 1);
	set( "value", ({ 2700, "silver" }) );
}
