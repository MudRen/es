#include <mudlib.h>

inherit WEAPON;

string C_NAME="魔神之剑";

void create()
{
        seteuid(getuid());
        set_name( "sword of demogorgod", C_NAME );
        add( "id", ({ "sword", "demogorgod" }) );
        set_short( "星月之(天龙)宝剑" );
        set_long(
       "这是星月杀了邪恶的天龙,用天龙的牙做成的一把剑。\n"
       "对龙有特别的攻击力。\n"
        );
        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weapon_class", 10 );
        set( "min_damage", 35 );
        set( "max_damage", 65 );
        set( "extra_skills", ([ "parry":20 ]) );
        set( "weight", 180 );
        set( "hit_func", "weapon_hit" );
        set( "value", ({ 7200, "silver" }) );
}

int weapon_hit(object victim, int damage)
{
        if( (string)victim->query("race")!="dragon" ) return 0;
        victim->receive_special_damage( "magic", damage );

        return damage;
}
