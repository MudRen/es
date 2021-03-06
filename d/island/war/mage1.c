#include "../island.h"

inherit IWAR"i_warvalue";
inherit ISLAND+"magic";


void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(14);
        set_name("Daemon Magician","银魔导士");
        add( "id", ({"magician","daemon","mage"}) );
        set_short("银魔导士");
        set_long(@LONG
这是位银魔导士，在历次战争中，他总是以纯熟的雷系魔法毁灭敌人，
获取胜利。
LONG
                );
        set("unit","位");
        set("race","daemon");
        set("gender","male");
        set("alignment",-300);
        set("hit_points",350);
        set("max_hp",350);
        set("spell_points",1000);
        set("max_sp",1000);
        set("justice",5);        
        set_perm_stat("int",28);
        set_perm_stat("str",12);
        set_perm_stat("dex",20);
        set_perm_stat("kar",20);
        set_perm_stat("pie",15);
        
        set_natural_armor(20,25);
        set_natural_weapon(8,5,30);
        
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":0,"weakest":60,"ganglion":20 ]) );
        set("killer",1);      
        set( "wealth/gold",70 );
        set( "tactic_func", "cast_spell" );
        set("weight",450);
        
        set_skill("dagger",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        
        wield_weapon(IWARO"dagger2");
        equip_armor(IWARO"t_hat2");
        equip_armor(IWARO"t_robe2");
}

int cast_spell()
{
	object victim;
	
	if( !(victim=query_attacker()) ) return 0;
	if( random(20)<3 ) {        
	tell_room( environment(this_object()),
"\n银魔导士闭目含首吟唱著咒文：悲怜苍生的雷神啊，以汝之圣名，召唤\n"      
"四方的雷之精灵－－「  印度拉之箭  」－－只见他的手心射出无数的光\n"
"箭毫不留情的肆虐 "+victim->query("c_name")+" 的身躯......\n");
         victim->receive_special_damage("electric",40);
         report( victim );      
               return 1;
       }
        else return 0;
}   

