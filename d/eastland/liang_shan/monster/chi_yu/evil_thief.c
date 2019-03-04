#include "mudlib.h"

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{
	::create();
	set_level(15);
	set_name( "evil thief", "����" );
	add("id",({"thief"}));
	set_short( "evil thief", "����" );
	set_long(query("c_name")+"����С͵ר�õ�����С����\n");
	set( "gender", "male" );
	set( "alignment", -2200 );
	set("player_invisible",1);
	set( "alt_corpse", "NONE" );
	set( "moving", 1 );
	set( "speed", 40 );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", query_level()*5 );
	set_skill( "dagger",query_level()*4 );
	set_skill( "anatomlogy", query_level()*4 );
	set( "aiming_loc", "ganglion" );
	set ("chat_chance",8);
	    set ( "att_chat_output",({
	    query("c_name")+"��ͣ�Ķ��ز�...\n"
	    }));
	set_natural_armor(60,22);
 	set_natural_weapon(35,10,27);
    set( "special_defense", (  ["all":25, "none": 5]  ) );
    set ("aim_difficulty",([ "critical":43,"vascular":18 ]) );
    set( "tactic_func", "my_tactic");	
    wield_weapon("/d/deathland/weapon/dagger04");
}

int my_tactic()
{
	object victim;

	if( random(22)>2 || !(victim= query_attacker()) ) return 0;
    else {
        tell_room(environment(this_object()),set_color(
	sprintf("%sͻȻһ����ת��%s���ᣬ����ɱ������ ...\n",
	query("c_name"),victim->query("c_name")),"HIR"),
	({this_object(),victim}));
    if ( random(5)<1 ) {
    tell_room(environment(this_object()),
	sprintf("%s��������ҹӰС������%s�ı���Ȼ���䣬��ѽ !! ��Ȼʧ���� ...\n",
	query("c_name"),victim->query("c_name")),
	({ this_object(),victim}) );
	tell_object(victim,set_color(
	sprintf("��ͻȻ�е�������ԣ��Ͽ�����һ����һ����׵Ļ��⿰������\n"
	"��ı�����е�һ��ë���Ȼ���ɶ� !! ��%s�ı��� ...\n",
	query("c_name")),"HIM"));
	set("stop_attack", 2 );
	return 1;
	}	
	else {
	tell_room(environment(this_object()),
	  sprintf("%s��������ҹӰС������%s�ı���Ȼ���䣬��ʱѪ���Ľ� ...\n",
	  query("c_name"),victim->query("c_name")),
		({ this_object(),victim}) );
	  tell_object(victim,set_color(
	  sprintf("��ͻȻ�е�һ���ʹ��һ��ѩ�׵ĵ��д�����ؿ�ð�˳�����\n"
		  "�㲻֪����Ŀ�����������һ����ѣ���ɶ� !! ��%s�ı��� ...\n",
				query("c_name")),"HIR"));
      victim->receive_special_damage("evil", 2*query("level") + random(20) );
      "/d/magic/magic"->report( this_object(), victim );
      return 1;
      }
    }
}
void die()
{
  object killer;
  if ( !killer = query("last_attacker") ) {
  ::die(1);
  }
  else 
  write(query("c_name")+"��Ϊһ�����̣���ʧ�ڿ�����...\n");
  ::die(1);
}  