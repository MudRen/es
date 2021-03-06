#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimson scepter", "权杖" );
	add( "id", ({ "mace","scepter" }) );
	set_short( "鲜红色权杖" );
	set_long(
		"这是一把鲜红色的权杖，它的末端铸著一个有著三只犄角恶魔的头。\n" );
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 150 );
	set( "weapon_class", 28 );
	set( "min_damage", 16 );
	set( "max_damage", 27 );
	set( "value", ({ 950, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>19 && sp > 5 ) {
		tell_object( owner, 
			"\n你的鲜红色权杖上的恶魔头突然睁开眼睛，从"+victim->query("c_name")+
			"身上咬下一块血淋淋的肉！\n你觉得一股力量从权杖上注入你的体内....\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "的鲜红色权杖上的恶魔头突然睁开眼睛，并且一口从你身上咬下一块血淋\n"
			"淋的肉！\n"
                        );
       		tell_room( environment(owner),
			owner->query("c_name") + "的鲜红色权杖上的恶魔头突然睁开眼睛，并且从"
			+ victim->query("c_name") + "身上咬下一块血淋淋的肉！\n"
			,({ victim, owner }) );
		victim->receive_special_damage( "evil", intelligence );
		owner->receive_healing( intelligence );
		owner->add( "spell_points", -5 );
		owner->add( "alignment", -100 );
		return intelligence * 2;
	}
}
