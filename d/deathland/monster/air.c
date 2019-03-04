#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "Air", "����" );
	add ("id", ({ "air", }) );
	set_short( "Dwarf prince Air", "�������Ӱ���" );
	set_long(
	"�������Ӱ���, ��С�Ͷ����صĶ���������Ȥ. �����ħ����ҽ�����к�\n"
	"����о�. Ŀǰ���ǰ���Ī���µ�Ψһ�̳���, Ϊ�˶Կ����˵����о���\n"
	", �������о�һ���ر�ķ���, �����ܹ���ס��ʼ��������µľ��˴�˾\n"
	"�������������(hotredchili)�ĺڰ�ħ��.\n"
	);

    set("alignment",200);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 25);
	set_skill("dodge",100);
	set_skill("target",100);
    set_skill("elemental",100);
    set_skill("black-magic",100);
    set_skill("concentrate",100);
	set("magic_delay",1);
	set("spells/sleet",5);
    set("spells/fireball",5);
	set("special_defense", (["all":30,"none":40]) );
	set ("aim_difficulty",([ "vascular": 50, "weakest":40 ]) );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy", 100 );
	set ("max_hp", 440);
	set ("hit_points", 440);
	set ("wealth", ([ "gold": 35 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set( "inquiry", ([
         "hotredchili" : "@@ask_chili",
           ]) );
    set( "tactic_func", "cast_spell");
    set("echo_dwarfsoldier",1);
    wield_weapon(Weapon"/dagger01");    
}

void ask_chili(object who)
{
    tell_object(who,
    "��������һ������ǿ��ħ���ľ�����? ��������������������һ������.\n"
    "���ĺڰ�ħ���ǳ��Ŀ���, ��˵�����Ѿ���ȫ�ĵõ�а��֮��ĵ���, ����\n"
    "������˼���洫, ����˵Ҫ������Ƿǳ����ѵ�, ����Ҳ����û�л���. ��\n"
    "������ȥ���˶�Ѩ�ĸ����Ӵ���������Ϣ, һ�Ѵ�����а��YANG������, ��\n"
    "��ķ�����Դ, ���÷�����˶�Ѩ�����, ֻҪ�ܹ�����һ������������\n"
    "�µĽ���, ���л����õ�YANG������, ��������ķ����Ͳ���Ϊ����.\n" 
    "��Ȼ, ������ܹ�֤�����Ǹ�����(valor),����һ�ж�������������, ����\n"
    "���˷�ʱ�����.\n"
    );
    return ;
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_dwarfsoldier") ) return 1;
    return 0;
}

int echo_valor(object player,object card)
{
    if (! card || ! card->query("echo_quest_card") ) return 0;
    if( (string)player->query("name") != (string) card->query("someone_id") )
          tell_object(player,
          "�����⿨Ƭ�ǷǷ�������,��������Ҫ����һ������,��������.\n"
           );
    else {
      tell_object(player,
      "����лл��ϰ�������, ��Ҫ�ȸ�\��\��һЩ����,ϣ�����ܹ�"
      );
      }      
    return 1; 
}

int cast_spell()
{
    object victim,*guard;
    string name;
    int i;
    
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
   
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
        guard[i]->query("c_name")+"Ϊ�˰���ⷰ����ʼ������!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
    
    if( random(10) < 2 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else if ( random(10)<2 ) {
      tell_room( environment(this_object()), 
        "**����ʩչȺ��ҽ�ư�������ⷰ����Լ�.**\n",
        this_object() );
      for( i=0; i<sizeof(guard); i++ ) 
          guard[i]->receive_heal( 25+random(20) );
      return 1;
      }  
    else return 0;   
}


