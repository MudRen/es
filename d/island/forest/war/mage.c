#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";
inherit HOME+"magic";


void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(16);
        set_name("Daemon Magician","圣灵魔导士");
        add( "id", ({"magician","daemon","mage"}) );
        set_short("圣灵魔导士");
        set_long(@LONG
这是位圣灵魔导士，在历次战争中，他总是以纯熟的混合系魔法毁灭
敌人，获取胜利。
LONG
                );
        set("unit","位");
        set("race","daemon");
        set("gender","male");
        set("alignment",-500);
        set("hit_points",350);
        set("max_hp",350);
        set("spell_points",1000);
        set("max_sp",1000);
        set("justice",8);
        set_perm_stat("int",28);
        set_perm_stat("str",15);
        set_perm_stat("dex",25);
        set_perm_stat("kar",25);
        set_perm_stat("pie",20);
        
        set_natural_armor(30,30);
        set_natural_weapon(10,5,20);
        
        set( "special_defense", ([ "all":25,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":0,"weakest":60,"ganglion":0 ]) );
        set("killer",1);      
        set( "wealth/gold",100 );
        set( "tactic_func", "cast_spell" );
        set("weight",350);
        
        set_skill("shortblade",80 );
        set_skill("dodge",80);
        set_skill("parry",80);
        set("aiming_loc","ganglion"); 
        
        wield_weapon(TWEP"shortblade1");
        equip_armor(TOBJ"hat1");
        equip_armor(TOBJ"robe1");
}

int cast_spell()
{
        object *victim;
        
        if( !(victim=query_attacker()) ) return 0;
            if( random(20)<3 ) {        
         tell_room( environment(this_object()),
"\n魔导士闭目含首吟唱著咒文：周游四方的精灵啊，以圣灵之名，清净这世上的邪恶\n"      
"吧！！只见他右手的火球穿过左手的寒气团，形成一颗光球冲入 "
+victim->query("c_name")+" 的胸口......\n");
         victim->receive_special_damage("evil",50);
         report( this_object(),victim );      
               return 1;
       }
        else return 0;
}   

