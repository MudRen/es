#include "../takeda.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(17);
    set_name("Gong Sun Shen","����ʤ");
    add("id",({"gong","sun","shen"}) );
    set_short("����ʤ");
    set_long(@C_LONG
�㿴��һ���ɷ���ǣ���ò�����������ˣ���������ɽһͬ���޾���ͷ��
����ʤ�������������Ϊ��ɽ���з�����ǿ���ˣ����˸߳��Ľ����⣬��˵������
�в��ݻ�������������
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "vampire");
    set( "unit", "��" );
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
    "����ʤ��ʼ�����\n"
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

