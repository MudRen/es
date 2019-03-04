// Modified by Yueh to let lich teach magic, in 1995/3/8
#include "/d/noden/forest/ruin/ruin.h"
inherit MONSTER;
#define STATS_D                 "/adm/daemons/statsd"
#define life_damage 30
#define auto_heal 20
void create ()
{
	::create();
	seteuid( getuid() );
	set_level(18);
	set_name( "Lich", "��ħ" );
	add ("id", ({ "lich", "mage", }) );
	set_short( "ڤ��ħ��ʿ ��ħ" );
	set_long( @C_LONG
а���ڤ��ħ��ʿΪ��ʹ�Լ��������������Լ�ʩ��ڰ�ħ����������Ѹ��ã�
ȫ���������£�ӵ����������������ʹ�ÿ��º�ħ���ĺ��ǡ�
C_LONG
	);
	set( "alignment", -8000 );
    set( "gender", "male" );
    set( "race", "undead" );
    set( "unit", "��" );
	set_perm_stat( "dex", 27 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 1000);
	set ("max_sp", 2500);
	set ("hit_points", 1000);
	set ("spell_points", 2500);
	set ("wealth", ([ "gold": 10 ]) );
	set_natural_weapon( 33, 21, 32 );
	set_natural_armor( 87, 50 );
	set ("time_to_heal", 2);
	set ("unbleeding", 1);
	set ("aim_difficulty", ([ "critical":80, "weakest":100, "ganglion":100, ]) );
	set ("special_defense", ([ "all":90, "fire":45, "none":70 ]) );
    set ("weight", 400);
    set ("exp_reward",32590 );
    set_experience(950000);
    set ("tactic_func", "cast_spell");
    set_skill("wand",100);
    set_skill("dodge",70);
    set_skill("black-magic",100);
    set_skill("elemental",100);
    set_skill("target",100);
    set_skill("concentrate",100);
    set("magic_delay", 1);
    set("spells/sleet",3);
    set("spells/lightning",5);
    set("spells/ether-bolt",8);
    set("c_death_msg","%s�����忪ʼ����... ������ʧ��\n");
    
    wield_weapon(OBJ"thunder_wand");
    equip_armor(OBJ"black_cloak");
    set( "inquiry", ([
                "magic" : "@@ask_magic"
        ]) );
}

int cast_spell()
{// 40% call demon -> 60% little 40% great and continue attack.
 // if( hp < 100 ) -> 100% ���� hp add 20-40 and continue attack.
 // if( hp < 300 ) -> 25% steal life force, damage 30-40 stop.
 // else 40% cast spell -> 70% sleet 3,  21% ether-bolt 8, 9% lightning 5.
 //      60% normal attack.
    object victim, monster;
    int damage;
    victim = query_attacker();
    if( !victim ) return 0;
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2500);
    if( (random(10)<4) && !present("daemon", environment(this_object())) ) {
      if( random(10) < 6 ) {
        tell_room( environment(this_object()),
          "��ħ������С��ħ������������\n" );
        monster = new(MOB"little_demon");
      } else {
        tell_room( environment(this_object()),
          "��ħ���������ħ������������\n");
        monster = new(MOB"great_demon");
      }
      monster->move(environment(this_object()));
      monster->kill_ob(victim);
    }
    
    if( (this_object()->query("hit_points")<100) ) {
      tell_room( environment(victim),
        "��ħ�����������ָ�ԭ�ˡ�\n");
      this_object()->receive_heal( auto_heal+random(auto_heal) );
    }
    
    if( (this_object()->query("hit_points")<300) && (random(20)<5) ) {
      tell_object( victim, "��ħ��ȡ�������������о��е����ѡ�\n");
      tell_room( environment(victim), 
        "�㿴��һ�����ε������"+victim->query("c_name")+
        "Ʈ����ħ���ϣ�\n��ħ�������ָ�ԭ�ˡ�\n" ,
        victim);
      damage = life_damage + random(10);
      victim->receive_special_damage("life", damage, 1);
      this_object()->receive_heal( damage );
      return 1;
    }
    
    if( random(10) < 4 ) return 0;
    
    if( random(10) < 7 )
      command("cast sleet on "+victim->query("name"));
    else if( random(10) < 7 )
      command("cast ether-bolt on "+victim->query("name"));
    else 
      command("cast lightning on "+victim->query("name"));
    return 1;
}

void die()
{
	object killer;

	if( killer = query("last_attacker") ) killer->set_explore("noden#23");
	::die();
}

void kick_out( object obj )
{
     tell_object( obj, "��ħһ�Ű������˳�ȥ��\n"  );
     tell_room( environment(obj), "��ħһ�Ű�" + obj->query("c_name") + "���˳�ȥ��\n" ,obj);
     obj->move_player(RUIN"tunnel_4", "�㿴��"+obj->query("c_cap_name")+"���˳�����ˤ���Ľų��졣", "" );
}

void ask_magic(object who)
{
	int ali;
	string class1;
	class1 = (string)who->query("class");
	if( !class1 ) class1 = "adventurer";
	ali = (int) who->query("alignment");
	if ( class1 != "mage") {
	printf("��ħ˵��%sҲ�����ѧħ����û��ɱ��Ͳ����ˡ�\n",to_chinese(class1));
	kick_out(who);
	}
	else 
	if (ali > -200) {
		printf("��ħ˵��%s����Ҳ�����ѧħ����û��ɱ��Ͳ����ˡ�\n", STATS_D->alignment_string(ali));
	kick_out(who);
	}
	else
	if ((int) who->query_quest_level("wanfu") < 1)
	tell_object(who,"��ħ˵��Ҫ����ѧħ������Ҫ��֤�����Լ���������ȥ��������æ�ɣ�\n");
     else {
         tell_object(who,
	"��ħ˵��: ��ӭ����ڰ����������ڰ���������һ������\n"
	"ǿʳ�Ĳп����硣����Ҫ�Կ��������������������Ĺ�\n"
	"������Ҫ�������Ժڰ������ڲ�����ս��������ˣ�����\n"
	"����������������\n\n"
	"��ħ����˵���ڰ���ħ�������ٻ��ڰ���������ֻ��а��\n"
	"���˲ſ���ʩչ��������а����˿����ٻ����Ƚ�ǿ���\n"
	"�������������ҿ��Խ̸���ĺڰ�ħ����\n\n"
	"�������������ڰ�������ֱ�ӹ������˵����࣬ʹ������\n"
	"        ���ܵ��˺�������������˱���а���ٻ�����\n"
	"        ���������ṥ���㡣\n\n"
	"ħ�����Ķܣ������ڰ�����������ֹ�������Ĺ���������\n"
	"        �������ڰ���������սʱ�����Ը���ܴ�İ���\n"
	"        ���������ħ��ȴ���ǿ������������ʥϵ��ħ\n"
	"        ����ʹ��ʱҪС�ġ�\n\n"
	
	"��ħ����˵�������ѧ��ħ���ȼ�������(index)��\n\n"
         );
     }
}

