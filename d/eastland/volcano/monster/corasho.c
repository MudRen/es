#include <mudlib.h>

inherit MONSTER;

int times,jump;

void create ()
{
        ::create();
    set_level(19);
    set_name("wraith flamen corasho","��������˾������");
    add("id",({"flamen","corasho"}) );
    set_short("��������˾������");
    set_long(@C_LONG
������ʦ�����˵ĵܵܣ��ǰ��������ר˾�������ʦ��
C_LONG
        );
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "λ" );
    times=0;
    jump=0;
    set_perm_stat( "dex",27);
    set_perm_stat( "int",30);
    set_perm_stat( "karma",27);
    set("max_hp",1800);
    set("max_sp",3800);
    set("hit_points",1800);
    set("spell_points",3800);
    set_natural_weapon(25,10,22);
    set_natural_armor(75,25);
    set("aim_difficulty",(["critical":100, "vascular":30]) );
    set("special_defense", (["all":50,"none":30]) );
    set_skill("shortblade",100);
    set_skill("dodge",100);
    set_skill("parry",100);
    set("spells/lightning",2);
    set("spells/ether-bolt",4);
    set("spells/flare",0);
    set("spells/sleet",2);
    set("spells/fireball",4);
~    set("att_chat_output",({
          "���ߣ���֪����Ķ���������֪����ʵ�Ҳ��ǰ�������������ħ��ʦ����\n",
          }) );
    set("chat_chance",15);
    set("time_to_heal",10);
    set("cast_busy",2 ) ;
    set_temp("detect_hide",1) ;
    set_temp("detect_invis",1) ;
    set_skill("concentrate",100);
    set_skill("target",100);
    set_skill("black-magic",100);
    set_skill("elemental",100);
    set("guild_levels/black-magic",80) ;
    set("guild_levels/elemental",80);
    set("guild_levels/guild",80);
    set( "inquiry", ([
         "��������" : "@@ask_treasure",
         "����":"@@ask_treasure",
        ]) );
    set( "tactic_func", "cast_spell");
    wield_weapon("/d/eastland/volcano/weapon/ghostsword.c");
    equip_armor("/d/eastland/volcano/armor/ring4.c");
}

void ask_treasure(object who)
{
     tell_object( who ,
"������˵�������ߣ����������Ҳ�����찫����ı��ֻҪ������������롣��\n"
       );    
}

int cast_spell()
{
    int i;
    object victim;
    string name;

    if ( !(victim = query_attacker()) ) return 0;
    if (!jump) 
      if (random(10)<4) return 0;
  
    if ((int)this_object()->query("spell_points")<1000)
      this_object()->set("spell_points",5000);
    jump=1;
    times++;
    name=(string)victim->query("name");
    i=random(5);
    switch (i) {
     case 0:command("cast ether-bolt on "+name);
            break;
     case 1:command("cast lightning on "+name);
            break;
     case 2:command("cast flare on "+name);       
            break;
     case 3:command("cast sleet on "+name);
            break;
     case 4:command("cast fireball on "+name);
            break;               
     default :
            command("say �г��:~~\n");
            break;  
    }
    if (times>1) {
      times=0;
      jump=0;
      this_object()->set("cast_busy",2);
      return 1;
    }
                             
    this_object()->set("cast_busy",0);
    this_object()->set("stop_attack",0);
    this_player()->continue_attack();
    
    return 1;
}

void die()
{
  object obj;
  obj=new("/d/eastland/volcano/obj/bookkey");
  obj->move(this_object());
  ::die();
}



