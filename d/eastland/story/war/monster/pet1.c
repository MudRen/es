#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(13);
	set_name( "Troll beast", "巨神兽" );
	add( "id", ({ "beast" }) );
	set_short( "巨神兽" );
	set_long(@LONG
一只口张獠牙的巨人族野兽，经过了长久的训练，富有很强的攻击力。
LONG
	);
	set( "unit", "只" );
	set( "race","巨人");
	set( "alignment", -100 );
	set_natural_armor(60,15);
	set_natural_weapon(40,8,20);
	set( "killer", 1 );
        set( "pursing", 1 );
        set( "war_points", 50 );
	set_skill( "unarmed-parry", 60 );
        set_skill( "unarm", 100 );
        set_c_verbs( ({
             "%s张开阔口向%s咬去",
             "%s挥动利爪抓向%s"}) );
        set_c_limbs( ({ "头部", "身体", "牙" }) );
        set("tactic_func","my_tactic");
}
int my_tactic()
{
     object victim;
     string name;
     if ( !victim=query_attacker() ) return 0;
     if ( random(10) > 1 ) return 0;
     name=victim->query("c_name");
     tell_room(environment(),sprintf("巨神兽张开阔口往%s身上一咬！\n",name),victim);
     tell_object(victim,"巨神兽张开阔口往你身上一咬！\n\n");
     (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,5,5);
     return 1;
}
