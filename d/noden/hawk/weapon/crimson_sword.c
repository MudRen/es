#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimsom longsword", "长剑" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "鲜红色长剑" );
	set_long(
		"这是一把有著奇异的鲜红色剑刃的长剑。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 18 );
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "value", ({ 450, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>12 && sp > 5 ) {
		tell_object( owner, 
			"\n你的鲜红色长剑突然爆出一股熊熊烈火，剑身被烧得通红！\n\n"
		        ); 
		tell_room( environment(owner), 
			owner->query("c_name") + "的鲜红色长剑突然爆出一股熊熊烈火，剑身被烧得通红！\n",
			owner );
		victim->receive_special_damage( "fire", intelligence );
		owner->add( "spell_points", -5 );
		return intelligence;
	}
}
