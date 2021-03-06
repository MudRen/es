#include "../takeda.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(17);
    set_name("Gong Sun Shen","公孙胜");
    add("id",({"gong","sun","shen"}) );
    set_short("公孙胜");
    set_long(@C_LONG
你看到一个仙风道骨，相貌清奇的中年道人，他就是梁山一同参赞军务头领
公孙胜，外号入云龙，为梁山泊中法力最强的人，除了高超的剑术外，据说他还具
有操纵火龙王的能力。
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "vampire");
    set( "unit", "个" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",15);
    set_perm_stat( "int",30);
    set_perm_stat( "con",25);
    set_perm_stat( "piety",20);
    set_perm_stat( "karma",22);
	
    set ("max_hp",440);
    set ("max_sp",3000);
    set ("hit_points",440);
    set("spell_points",3000);
    set ("wealth", ([ "gold":60]) );
    set_natural_weapon(24,16,19);
	set_natural_armor(25,18);
    set ("weight", 160);
    set ("chat_chance",10);
    set ( "att_chat_output",({
    "公孙胜开始喃喃自语。\n"
    }));
    set_skill("target",100);
    set_skill("black-magic",100);
    set_skill("concentrate",100);
    set_skill("dodge",80);
    set_skill("parry",80);
    set_skill("longblade",100);
    set("magic_delay",2);
    set("spells/flare",3);
    set("special_defense", (["magic":95,"evil":15]) ); 
    set ("aim_difficulty",(["vascular":40]) );
    set( "tactic_func", "cast_spell");
    wield_weapon(TWEAPON"pinesword");
    equip_armor(TARMOR"thunder_cape");
    equip_armor(TARMOR"wire_jade");
    equip_armor(TARMOR"gold_hat");
    equip_armor(TARMOR"dark_cape");
}

int cast_spell()
{
    object victim;
    string name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    
      if (random(5)< 1) {
      command("cast flare on "+name);
      this_object()->receive_healing(30);
      return 1;
      }
    else return 0;   
}

