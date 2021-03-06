#include <mudlib.h>

inherit WEAPON;

string C_NAME="神龙枪";

void create()
{
        seteuid(getuid());
        set_name( "lance of dragon", C_NAME );
        add( "id", ({ "lance", "dragonlance" }) );
        set_short( "长枪 神龙枪" );
        set_long(
                "这是杨家的传家之宝,杨六郎视之比性命更为重要\n"
                "据说是这枪中有着可怕的魔法为量,如果你是一个赤胆精忠的人杨家枪就会\n"
                "引发其可怕的魔力,传说枪中神龙会助你作战!\n"
        );
        set( "unit", "把" );
        set( "type", "jousting" );
        set( "weapon_class", 49 );
        set( "min_damage", 35 );
        set( "max_damage", 60 );
        set( "weight", 220 );
        set( "hit_func", "weapon_hit" );
        set( "value", ({ 5600, "silver" }) );
        set( "no_sale", 1 );
}


int weapon_hit(object victim,int dam)
{
        object holder;
        int align,max;
        string him,me,bonus;

        if ( !victim ) return 0;
        if( !holder = environment(this_object()) || !living(holder) ) return 0;
        else {
                /* 决定特殊攻击的伤害度 */
                align=holder->query( "alignment" );
                if( align >= 150000 ) { dam=40; }
                else if( align < 150000 ) { dam=35; }
                else if( align < 100000 ) { dam=30; }
                else if( align < 45000 ) { dam=25; }
                else if( align < 15000 ) { dam=20; }
                else if( align < 4500 ) { dam=15; }
                else if( align < 1500 ) { dam=10; }
                
                if ( random(50) < 10 ) {
                        if ( (int)holder->query( "spell_points" )< 5 ) {
                                tell_object( holder,set_color( "你的精神不足以召唤地狱恶魔....\n","HIR" ) );
                                return 1;
                        }
                        
                        him=victim->query( "c_name" );
                        me=holder->query( "c_name" );
                        tell_object( holder,set_color(
                                "你手上的","HIW")+C_NAME+set_color("突然飞出空中化成一条银龙冲向"+him+"。\n","HIW") );
                        tell_object( victim,set_color(
                                me+"手上的","HIW")+C_NAME+set_color("飞到空中化成一第银龙向你袭来。\n","HIW") );
                        tell_room( environment(holder),set_color(
                                me+"手上的","HIW")+C_NAME+set_color("飞到空中化成一第银龙冲向"+him+"。\n","HIW"),({ holder,victim }) );
                        victim->receive_special_damage( "cold",dam );
//                      report( victim );
                        holder->add( "spell_points",-5 );
                        victim->set( "last_attacker",holder );
                        return dam;
                }
        return 0;
        }
}
