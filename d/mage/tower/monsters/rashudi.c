#include <races.h>
#include <guilds.h>
#include "/d/mage/tower/monsters/mobs.h"
 
inherit RACE_ELF;
 
#define kick_damage 25
#define heal_point 80
#define first_max_ali   6000
#define first_min_ali  -7000
#define second_max_ali  4000
#define second_min_ali -5000
 
void create()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "Rashudi", "���޵�" );
	add ("id", ({ "rashudi", "mage", "archmage", "wizard", }) );
	set_short( "������ʦ ���޵�" );
	set_long(@DESC
    ħ��ʿ���޵��Ǻ��ϵ�ʮ���о����ħ��ʦ��������������㼸���޷���
���������м��꣡��������ħ��ʦ������ϴ�����������������ħ��ʦ��
�����ѯ�����й�ħ��ʦ�����һЩ��Ѷ(guild,spells)��
DESC
	);
	set( "alignment", 2500 );
    set( "gender", "male" );
    set( "unit", "λ" );
    set( "class", "mage" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 15 );
	set_perm_stat( "piety", 25 );
	set_perm_stat( "karma", 25 );
	set_skill("elemental", 100 );
	set_skill("white-magic", 100 );
	set_skill("wand", 100 );
	set_skill("dodge", 100 );
	set_skill("concentrate",100);
	set_skill("target", 100);
	set("max_hp", 1350);
	set("max_sp", 2700);        
        set("max_fp", 1000);
	set("hit_points", 1350);
	set("spell_points", 2700);
        set("force_points",1000);
	set("wealth/gold",1500 );
	set_natural_weapon(45, 15, 30);
	set_natural_armor(50, 60);
	set("unbleeding", 1);
        set("special_defense", ([ "all" : 75, "none" : 50, "monk":20, "scholar":20]) );
	set("aim_difficulty", ([ "critical" : 100, "weakest":100, "ganglion":100, ]) );
	set("magic_delay", 1);
	set("spells/fireball",7);
	set("spells/heal",2);
    set("weight", 350);
    set("exp_reward", 65535 );
    set("inquiry", ([
        "guild" : "@@ask_mage",
        "spells" : "@@ask_spells", ]) 
    );
	wield_weapon(TOWERWEAPON"ice_wand");
    equip_armor(TOWERARMOR"wizard_amulet" );
    equip_armor(TOWERARMOR"wizard_robe" );
    equip_armor(TOWERARMOR"wizard_shoe" );
    equip_armor(TOWERARMOR"wizard_cloak" );
    equip_armor(TOWERARMOR"wizard_ring" );
    equip_armor(TOWERARMOR"wizard_glove" );
    equip_armor(TOWERARMOR"wonderful_hat" );
    set( "hunt_list", ({ }) );
    set( "tactic_func", "cast_spell" );
}
 
void init()
{
	object ob;
	string tmp;
	add_action("to_join","join");
	ob = this_player();
	//  If object is not a monster...think about attacking.
	if( !ob->query("npc") && !ob->query("ghost") &&
		!ob->query("no_attack") ) {
		if( will_attack && member_array(ob, will_attack) != -1 ) { 
			will_attack -= ({ ob });
			kill_ob( ob );
			if( ! (this_object()->catch_huntee(ob) ))
				tell_room( environment(this_object()), 
					"���޵۽е�: �ɶ������㣡\n", 
					this_object() );
		} 
 		// If heartbeat is turned off ... turn it back on.
		if( !hb_status ) {
			hb_status = 1;
			set_heart_beat(1);
		}
	}
}


//void init()
//{
//    ::init();
//    add_action("to_join","join");
//}
 
int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
    sprintf("���޵ۺܲ�м����%s˵: �㻹�ҽ�������Ĳ��ͷ��ˣ��Ҿͳ�ȫ�㣬����!\n",who->query("c_name"))
    ,  ({ this_object(), who }) );
    tell_object( who, 
      "���޵ۺܲ�м������˵: �㻹�ҽ�������Ĳ��ͷ��ˣ��Ҿͳ�ȫ�㣬����!\n"
    );
    return 1;
}
 
int can_help( object obj )
{
    if( obj->query_attackers() || wizardp(obj) ) return 0;
    if( (string)obj->query("class")=="mage" ||
        (string)obj->query("name")=="summoned monster" ) return 1;
    return 0;
}
 
int member_killer( string a, string *b )
{
    int i;
    if( !b ) return 0;
    for( i=0; i<sizeof(b); i++ )
      if( a == b[i] ) return 1;
    return 0;
}
 
void all_attack_spell(object caster)
{
    object *victim;
    int i,damage;
    
    damage = 150 + random( (int)caster->query_stat("int") );
    tell_room( environment(caster), @MSG1

���޵۵�����ǰһ�ӣ��󺰡���ѩ�籩����
ͻȻ�䣬�����ı�����ʼ�������������������������춿��µ�
����ѩ֮�У�������ѩ���������ǰ���裬�ݷ�Ҫ��������ɣ�

MSG1
	, caster);
	victim = (object *)caster->query_attackers();
	if( sizeof(victim) )
	  for( i=0; i<sizeof(victim); i++ ) {
	    damage -= random( (int)victim[i]->query("int") );
	    if( damage < 0 ) damage = 1;
	    victim[i]->receive_special_damage( "cold", damage, 0 );
	    "/d/magic/magic"->report( caster, victim[i] );
	  }
}
 
int cast_spell()
{//  50% call summoned monster -> 60% type1 40% type2 and stop.
 //  if( hp < 100 ) -> 30% hp+80 stop. 
 //  else 30% kick victim out! damage = 25-30.
 //       15% cast spells -> 60%  fireball 7, 24% heal 2, 16% sleet 6.
 //       35% normal attack.
    object victim, monster, *mages, env;
    string name, victim_name, *hunt_list;
    int i;
    
    hunt_list = (string *)this_object()->query("hunt_list");
    if( !(victim = query_attacker()) ) return 0;
    victim_name = (string)victim->query("name");
    if( !hunt_list )
      hunt_list = ({ victim_name });
    else if( !member_killer( victim_name, hunt_list ) )
      hunt_list += ({ victim_name });
    this_object()->set("hunt_list", hunt_list);
    env = environment(this_object());
    mages = filter_array( all_inventory(env), "can_help", this_object() );
    for( i=0; i<sizeof(mages); i++ ) {
      tell_room( env,  
        sprintf("%s�ܹ�ȥ�������޵۹���%s��\n", mages[i]->query("c_name"),victim->query("c_name")),
        ({ mages[i], victim })
      );
      tell_object( victim,
        sprintf("%s�ܹ����������޵۹����㡣\n",mages[i]->query("c_name")));
      tell_object( mages[i], 
        sprintf("���ܹ�ȥ�������޵۹���%s��\n",victim->query("c_name")));
      mages[i]->kill_ob(victim);
    }
    
    name = victim->query("name");
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2700);
    if( random(10) < 5 && !present("summon",environment(this_object())) ) {
      tell_room( environment(this_object()), 
         "���޵ۺ������ٻ���������������\n");
      if( random(10) < 6 )
        monster = new(TOWERMONSTER"summon_monster1");
      else
        monster = new(TOWERMONSTER"summon_monster2");
      monster->move(environment(this_object()));
      monster->kill_ob(victim);
      return 1;
    }
    
    if( (this_object()->query("hit_points")<100) && (random(100)<30) ) {
      tell_room( environment(this_object()), 
      "���޵����������˿ڡ�\n", this_object()
      );
      this_object()->receive_healing(heal_point);
      return 1;
    }
    
    if( (int)victim->query_level()<11 ||
        ( (random(10)<3) && !wizardp(victim) ) ) {
      tell_object( victim, "���޵�һ�Ű������˳�ȥ��\n" );
      tell_room( environment(this_object()), 
        sprintf("���޵�һ�Ű�%s���˳�ȥ��\n",victim->query("c_name")),
        victim);
      victim->receive_special_damage("physical", kick_damage+random(5), 1);
      victim->move_player(MOYADA"rndplza", "SNEAK", "");
      return 1;
    }
    
    if( random(10) > 3 ) return 0;
    
    if( random(10) > 4 )
      command("cast fireball on "+name);
    else if( random(10) > 4 )
      command("cast heal on rashudi");
    else {
      tell_room( environment(this_object()),  
        "���޵ۿ�ʼ�����\n", this_object() 
	  );
	  call_out( "all_attack_spell", 3, this_object() );
    }
    return 1;
}
 
int hunt_check( object rashudi, object victim )
{
    int i;
    object *attackers;
    string *hunt_list;
    
    hunt_list = rashudi->query("hunt_list");
    attackers = rashudi->query_attackers();
    if( victim && !member_group( victim, attackers ) &&
        member_killer( (string)victim->query("name"), hunt_list ) ) {
      tell_room( environment(this_object()),
        sprintf("���޵۴�Ц��˵: %s������Ϊ quit �����ӳ��ҵ���������? ����!\n",victim->query("c_name"))
        , rashudi
      );
      kill_ob( victim );
      return 1;
    }
    return 0;
}
 
int to_join()
{
    string race;
    race = this_player()->query("race");
    if( race == "lizardman" || race == "hawkman" || race == "orc" ) {
      tell_object( this_player(),
        "���޵ۿ��˿��㣬ҡҡͷ˵����ȥ�ɣ��㲻���ܳ�Ϊħ��ʦ�ġ�\n");
      return 1;
    }
    return 0;
}
 
void ask_mage( object who )
{
    tell_object( who,@MSG2
���޵�˵: ��ӭ����ħ��ʦ���ᣬ���������ˡ��������Լ�����֮�⣬
          ����ʲ�����壬ֻҪ��ħ������Ȥ�����ܹ���Ϊ���ǵ�һԱ��
MSG2
);
}
 
void ask_spells( object who )
{
    tell_object( who,
      "���޵�˵: ����Ե�¥�ϵ�ħ��ͼ���ȥ��������Ҫѧ�����ġ�\n");
}
 
void relay_message(string class1, string msg)
{
     string who,str;
     object obj;
     int ali;
     
     ::relay_message(class1, msg);
if( sscanf( msg, "%s(%s)���˽�����", str,who )==2 ) {
                if( !obj = find_player(lower_case(who)) ) return;
       if( hunt_check(this_object(), obj) ) return;
if( wizardp(obj) || GUILD_MASTER("mage")->is_guild_member(obj) ) return;
       ali = (int)obj->query("alignment");
       if( ali > first_max_ali || ali < first_min_ali ) {
       	 call_out( "warning1", 1, obj );
         call_out( "begin_attact", 20, who );
       }
       else if( ali > second_max_ali || ali < second_min_ali ) {
         call_out( "warning2", 1, obj );
         call_out( "kick_out", 10, obj );
       }
     }
}
 
void warning1(object obj)
{
     if( !present( "rashudi", environment(obj) ) ) return;
     tell_object( obj,
       "���޵ۺݺݵص����㣡�������ʮ�ֲ�ˬ���ƺ�׼��Ҫɱ����!\n" );
     tell_room( environment( obj ), 
       sprintf("���޵ۺݺݵص���%s���������ʮ�ֲ�ˬ��\n" ,obj->query("c_name")), obj
     );
}
 
void warning2(object obj)
{
     if( !present( "rashudi", environment(obj) ) ) return;
     tell_object( obj,
       "���޵�ʮ�ֲ����˵Ŀ����㡣\n" );
     tell_room( environment( obj ), 
       sprintf("���޵�ʮ�ֲ����˵Ŀ���%s��\n" ,obj->query("c_name")), obj
     );
}
 
void begin_attact( string name )
{
     command( "kill " + name );
}
 
void kick_out( object obj )
{
     if( !present( "rashudi", environment(obj) ) ) return;
     tell_object( obj,
       "���޵۰�����˳�ȥ��\n" );
     tell_room( environment(obj), 
       sprintf("���޵۰�%s���˳�ȥ��\n" ,obj->query("c_name"))
     );
     obj->move_player(MOYADA"rndplza", "SNEAK", "" );
}

void die()
{
	object *usr, player;
	int i;

	player = query("last_attacker");
	if( !player ) {
		::die();
		return;
	}

	tell_object( player,"\n\n���޵ۺ޺޵�˵: ����⣬���е�ħ��ʦ�Ƕ�����Ҹ����!\n\n\n");
	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment( usr[i] ) || usr[i] == player ) continue;
		if( (string)usr[i]->query("class") == "mage" )
			tell_object( usr[i], 
			set_color(sprintf("\n\n[ħ��ʦ]�����ϴ�%sɱ�ˣ���ҿ�ع���!\n\n\n",player->query("c_name")), "HIR"));
	  	else
			tell_object( usr[i], 
			sprintf("\n\n���޵۱�%sɱ�ˣ�ħ��ʦ���ᱻ������!\n\n\n" ,player->query("c_name")));
	}
	::die();
}


