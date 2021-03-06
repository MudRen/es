#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dragon idol", "龙形傀儡" );
        add( "id", ({ "idol", "dragon" }) );
        set_short( "龙形傀儡" );
        set_long(
                "你看到一个巨大的龙形傀儡，它的四肢似乎被一些看不见的线牵动著。\n"
        );
        set( "unit", "只" );
        set( "race", "dragon" );
        set( "alignment", -1100 );
        set_natural_armor( 50, 30 );
        set_natural_weapon( 40, 30, 50 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "dex", 26 );
        set( "hit_points", 700 );
        set( "max_hp", 700 );
        set( "aim_difficulty",
                ([ "critical":30,"vascular":20,"weakest":20,"ganglion":35]) );
        set( "special_defense",([ "all":30,"none":30 ]) );
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set( "tactic_func", "my_tactic" );
        set( "wealth/gold", 100 );
        set( "killer", 1);
        set( "pursuing", 1);
        set_c_limbs( ({ "头部", "身体", "腿部", "尾巴" }) );
        set_c_verbs( ({ "%s张嘴往%s猛咬", "%s用巨爪抓向%s" }) );
}

int my_tactic()
{
        object *victim;

        if( random(20)<3 ) {
                tell_room( environment(this_object()),
                        "\n龙形傀儡发出一声可怕的吼叫声，从口中喷出许多黑色的气体....。\n\n",
                        this_object() );
                victim = query_attackers();
                victim->receive_special_damage( "magic", 30 );
                return 1;
        }
        return 0;
}
