#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's shoes", "巫师神靴" );
	add( "id", ({ "shoes", "shoe", }) );
	set_short( "a wizard's shoes", "巫师神靴" );
	set_long( @TOPIC
	The pair of shoes used by wizard Rashudi. It is made by normal cloth,
but spreads a special power of magic.
TOPIC
    , @C_TOPIC
	拉修帝惯於穿著的靴子，虽然只是用普通的布做的，但散发出一股魔力。
C_TOPIC
	);
	set( "unit", "双" );
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
