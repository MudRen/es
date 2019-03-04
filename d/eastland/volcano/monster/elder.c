#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "wraith elder", "�����峤��" );
        add ("id", ({ "elder" }) );
        set_short( "�����峤��");
        set("unit","λ");
        set_long(
           "�����峤���Ѳ������������Ѿã����ǰ����������ʴȵģ������޳�ÿ\n"
           "�����ͷ����������ɱ��ͷ����һֱҪ��һ����������Ч�����ɽ����\n"
           "�����⣬������̬���ӵģ��������൱���µĶ��֣����峤��������\n"
           "���֡�\n"
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
        "�ǳ���л���һ��˺����ı��У�������е��ô���������\��\��һ�ߣ�\n"+
        "��������пգ���˳������λ�һر��е�Ӣ��ͬ�������Һú�лл����!!\n"
             );
      tell_room(environment(player),
        "���ϰѱ�������������\n");
      ob->remove();
      return 1;
    }

    tell_object(player,
      "\n�ǳ���л���һ��ⱦ�У��ⱦ��ӵ��ǿ�������������ʹ�ò����ܿ��ܻ�\n"
      "���������ǳ�������ѣ����ڻ��ɣ������ɽ�����������������������ɡ�\n\n"
       );
    if( (int)(player->query_quest_level("Dragon_box"))==1 ) {
       player->finish_quest("Dragon_box",2);
       player->delete_temp("dragon_box");
       tell_object(player,
          set_color("���Ѿ���ɺ������е�������õ�10000�㾭��ֵ\n","HIY"));
          player->gain_experience(10000);
     }
     ob->remove();
     tell_room(environment(player),
           "���ϰѱ�������������\n");
    return 1;
}
