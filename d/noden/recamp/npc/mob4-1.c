
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "lighting general", "Ѹ�׽���" );
	add("id",({"lighting","general"}));
	set_short( "Ѹ�׽���" );
	set_long(
         "��Ѹ�׽������������³����ӿ�ͷ����˵�����Էų������粨���������
����Ů�ѡ�\n"
	);
	set( "alignment", 10 );
	set( "race","orc");
	set( "gender","male");
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "tactic_func", "my_tactic" );

        set_natural_armor(30,30);
        set_natural_weapon(30,10,30);
        set("aim_difficulty",
          (["critical":50,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("wealth/silver",1000) ;
        set("weight",900) ;
        set_skill("dodge",80) ;
        set_skill("parry",80) ;

        wield_weapon(CAMPOBJ"labo4") ;
        equip_armor(CAMPOBJ"plate4") ;
}

int my_tactic()
{
  object victim;

    if( random(50)>10 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
        "\n����ͻȻ�󺰣����ҵġ��׻��ؼơ����㿴�������������ӭ�����.\n");
      tell_room( environment(victim),
        "\n����ͻȻ�󺰣����ҵġ��׻��ؼơ����㿴�����������"
        +victim->query("c_name")+"��ȥ.\n",victim);
      victim->receive_special_damage("fire",50+random(10));
      "/d/magic/magic"->report(this_object(),victim);
 
      tell_object(victim,"( �㷢�ֱ���ĺ�������! )\n" );
      tell_room(environment(victim),
          "( �㷢��"+victim->query("c_name")+
          "����ĺ�������! )\n", victim);
      victim->block_attack(5) ; 
      victim->set_temp("msg_stop_attacker","( �㷢�ֱ���ĺ�������! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) return 1 ;
  if (!(who->query_temp("lulu_active"))) return 1 ;  

  command("give paper to "+who->query("name"));
  if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob2")) )  
        tell_object( who,"˵��: лл�����������¶¶��!!\n");
  else  tell_object( who,"˵��: лл������Ѱ������������!!\n");

  return 1;
}
