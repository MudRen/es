#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's ring", "巫师神戒" );
	add( "id", ({ "ring" }) );
	set_short( "a wizard's ring", "巫师神戒" );
	set_long( @LONG
	This ring is used by wizard Rashudi. It is made by magical ruby and 
spreads a wanderful power of magic.
LONG
    , @C_LONG
	魔导士拉修帝最喜欢的戒指，由於用被附与魔法的红宝石制成，散发出一股不可抵
抗的魔力，据说拥有抵抗各种魔法的能力。
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 10 );
	set( "special_defense", 
	     ([ "poison":5, "magic":10 ]) );
	set( "extra_skills", ([ "black-magic":10 ]) );      
	set( "weight", 5 );
	set( "no_sale", 1);
	set( "value", ({ 6000, "silver" }) );
}
