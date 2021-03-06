#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith staff", "矮灵权杖" );
	add( "id", ({ "staff" }) );
	set_short("矮灵权杖" );
	set_long(
		"这是一把矮灵族历代相传的权杖，它的末端铸著一个猫眼石，\n"
                "猫眼石的瞳孔中似乎还闪著绿光。\n" );
	set( "unit", "把" );
	set( "type", "blunt" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>15 && sp > 5 ) {
		tell_object( owner, 
               "\n你的权杖上猫眼石的瞳眼突然张开，从瞳眼中射出一道七彩光芒，"+victim->query("c_name")+
		"的灵魂似乎被吸了去\n你觉得一股力量从权杖上注入你的体内....\n\n");
		tell_object( victim, 
                owner->query("c_name") + "的权杖上猫眼石的瞳眼突然开，一道七彩光芒射向你，你的灵魂似乎被吸了去\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "的权杖上的瞳眼突然张开，一道七彩光芒射向"
                        + victim->query("c_name") + "并且把他的灵魂吸了去！\n",
			({ victim, owner }) );
	victim->receive_special_damage( "evil", intelligence );
	owner->receive_healing( intelligence );
	owner->add( "spell_points", -5 );
	owner->add( "alignment", -100 );
	return intelligence * 2;
	}
}
