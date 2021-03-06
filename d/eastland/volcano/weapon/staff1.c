#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "broken_ice staff", "破冰杖" );
	add( "id", ({ "staff" }) );
	set_short( "破冰杖" );
	set_long(
		"这是一把无坚不摧，攻无不破的神杖，杖头长满尖刺。\n"
                "杖身呈现乳白色，据说这把杖还有灵性。\n" );
	set( "unit", "把" );
	set( "type", "blunt" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 28 );
	set( "min_damage", 15 );
	set( "max_damage", 28 );
	set( "value", ({ 1000, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int pietyy, sp;

	owner = environment();
	pietyy = owner->query_stat("pie");
	sp = owner->query("spell_points");
	if( random(pietyy)>17 && sp > 5 ) {
		tell_object( owner, 
                "\n你的破冰杖上的尖刺突然射出，直接命中，"+victim->query("c_name")+
		"的要害。\n\n");
		tell_object( victim, 
                owner->query("c_name") + "的破冰杖上的尖刺突然射出，直接命中你的要害。\n\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "的破冰杖上的尖刺突然射出，直接命中"
                        + victim->query("c_name") + "的要害！\n\n",
			({ victim, owner }) );
	victim->receive_damage( 15+random(10) );
	owner->add( "spell_points", -5 );
	return 1;
	}
}
