#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Police Mace","警棍");
    add("id",({"mace"}) );
    set_short("警棍");
    set_long(@LONG
这是根用米苏里矿和金刚石合成的警用振暴棍.
LONG
             ); 
    set("unit","把");
    set("weapon_class",25);
    set("type","blunt");
    set("min_damage",15);
    set("max_damage",30);
    set("weight",150);
//    set("hit_func","special_atk");
    set("special_damage",2);
    set("value",({400,"silver"}) );
 }
 
 int special_atk(object victim,int dam)
 {
     object holder;
     dam=(int)query("special_damage");

     if( !victim ) return 0;
     if( !(holder=environment(this_object())) || !living(holder) )
     return 0;
     
     if( random(20) > 5 ) return 0;
     tell_object(victim,
     "\n突然警棍发出一阵电击，你觉得全身上下无法使劲\n\n" );
     tell_room(environment(victim),
     "\n突然警棍发出一阵电击，只见"+victim->query("c_name")+"立刻瘫了下去！\n\n"
     ,victim );
     victim->block_attack(6);
     victim->set("last_attacker",holder);
     victim->receive_damage( dam );
     victim->set_temp("msg_stop_attack",
     "(你全身上下感到疼痛无力，无法出手攻击！)\n" );
     return dam;
}
