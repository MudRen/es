#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "wraith elder", "矮灵族长老" );
        add ("id", ({ "elder" }) );
        set_short( "矮灵族长老");
        set("unit","位");
        set_long(
           "矮灵族长老已不管族内琐事已久，他是矮灵族中最仁慈的，他不赞成每\n"
           "年的人头祭，反对猎杀人头，他一直要找一个方法来有效解决火山爆发\n"
           "的问题，别看他老态龙钟的，他可是相当可怕的对手，连族长都得让他\n"
           "三分。\n"
        );
        set("alignment",500);
        set("wealth/gold",350);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 5, 5, 15 );
        set_natural_armor( 60, 25 );
        set ("gender", "male");
        set ("race", "dwarf");
        set("max_sp",700);
        set("spell_points",700);
        set_skill("concentrate",100);
        set_skill("wand",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set("guild_levels/black-magic",70) ;
        set("guild_levels/guild",70);
        set("spells/lightning",3);
        set("magic_delay",2);
        set( "tactic_func", "cast_help" ); 
        set("aim_difficulty",(["critical":100,"weakest":40,
                               "vascular":60,"ganglion":50 ])) ;
        set("special_defense",(["all":60,"none":60]));
        wield_weapon(OWEAPON"wand2");
        equip_armor(OARMOR"cloth4");
        equip_armor(OARMOR"amulet3");
        equip_armor(OARMOR"legging3");
        equip_armor(OARMOR"helmet3");
        equip_armor(OARMOR"glove1");
}

int cast_help()
{ 
    object victim;
    string name;
    int i,j,ran,vickar,vicint,ref;
    victim = query_attacker();
    vicint = victim->query_perm_stat("int") ;
    vickar = victim->query_perm_stat("kar") ;
    
    i =30-vicint ;
    j =30-vickar ;
    
    if( i+j < 1 )  ref = 1 ;
    else ref = random(i+j) ; 

    ran = random(50) ;
                            
    if ( (int)this_object()->query("spell_points")< 300 )   
         this_object()->set("spell_points",600);

    if ( ran < ref  )
       {
          name=victim->query("name");
          command("cast lightning on "+name); 
          return 1;
        }
    else 
       {
          return 0;
        }
}

int accept_item(object player, object ob)
{
    if( (string)ob->query("killer") != (string)player->query("name") ) {
      tell_object(player,
        "非常感谢你找回了黑龙的宝盒，这个宝盒的用处，我们先\摆\到一边，\n"+
        "如果他日有空，请顺便与那位找回宝盒的英雄同来，让我好好谢谢你们!!\n"
             );
      tell_room(environment(player),
        "长老把宝盒收了起来。\n");
      ob->remove();
      return 1;
    }

    tell_object(player,
      "\n非常感谢你找回这宝盒，这宝盒拥有强大的力量，假如使用不当很可能会\n"
      "导至产生非常大的灾难，我在怀疑，当年火山爆发就是有人乱用这盒子造成。\n\n"
       );
    if( (int)(player->query_quest_level("Dragon_box"))==1 ) {
       player->finish_quest("Dragon_box",2);
       player->delete_temp("dragon_box");
       tell_object(player,
          set_color("你已经完成黑龙宝盒的任务，你得到10000点经验值\n","HIY"));
          player->gain_experience(10000);
     }
     ob->remove();
     tell_room(environment(player),
           "长老把宝盒收了起来。\n");
    return 1;
}
