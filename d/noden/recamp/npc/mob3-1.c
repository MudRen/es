
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "fire general", "���ʽ���" );
	add("id",({"fire","general"}));
	set_short( "���ʽ���" );
	set_long(
         "���ʽ�������һͷ���ĺ�ɫͷ��������������ܻ���İ��˱��졣\n"
	);
	set( "alignment", -2000 );
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

        wield_weapon(CAMPOBJ"firegun3") ;
        equip_armor(CAMPOBJ"plate3") ;
}

int my_tactic()
{
    object victim;

    if( random(50)>10 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "\n����������������Χ�����������ܻ��棬��������Χס.\n"
          );
      tell_room(environment(victim),
          "\n������������"+victim->query("c_name")
          +"��Χ�����������ܻ���.\n",victim);
      victim->receive_special_damage("fire",50+random(10));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}

int accept_item(object who,object item)
{
  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) return 1 ;
  if (!(who->query_temp("lulu_active"))) return 1 ;  

  command("give paper to "+who->query("name"));
  if ( (who->query_temp("lulu_mob2")) && (who->query_temp("lulu_mob4")) ) 
        tell_object( who,"˵��: лл�����������¶¶��!!\n");
  else  tell_object( who,"˵��: лл������Ѱ������������!!\n");

  return 1;
}
