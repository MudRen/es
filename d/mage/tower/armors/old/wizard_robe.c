#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wizard's robe", "巫师魔袍" );
	add( "id", ({ "robe", }) );
	set_short( "a wizard's robe", "巫师魔袍");
	set_long( @LONG
	This robe is used by wizard Rashudi. It is made by magical cloth,
so spreads a strong power of magic.
LONG
    , @C_LONG
	这是魔导士拉修帝惯於穿著的服装，不要看它只是用普通的布织成，它可是拥有
出乎你意料之外的防御力，据说还能抵抗各种魔法。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 45 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 35 );
	set( "defense_bonus", 10 );
	set( "special_defense" ,
	      ([ "evil": 10, "none":2 ]) );
	set( "extra_skills", ([ "magic-shield" :10 ]) );
	set( "no_sale", 1);
	set( "value", ({ 2000, "silver" }) );
}
