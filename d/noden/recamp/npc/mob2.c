#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "plesiosaurus statue", "�߾�������" );
	add("id",({"statue"}));
	set_short( "�߾�������" );
	set_long(
         "���߾������ഫ�ǹŴ�������ػ��ޣ�������������ܾɣ�ȴ���˸о�
          ����������\n"
	);
	set( "alignment", 800 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",300);
        set("max_hp",300);
        set("hit_points",300) ;
        set("exp_reward",800) ;
	set( "tactic_func", "my_tactic" );
}

int my_tactic()
{
    object victim;

    if( random(20)<15 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "\n��������³�һ��ǿ����ˮ������ͬ�ɽ�����������.\n"
          );
      tell_room(environment(this_object()),
        "\n��������³�һ��ǿ����ˮ������ͬ�ɽ�����"
        +victim->query("c_name")+"��ȥ.\n",this_object()) ;
      victim->receive_special_damage("evil",5+random(2));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if ( !(who->query_temp("lulu_active")))  return 1 ;  

    command("give paper to "+who->query("name"));
    write("\nͻȻһ��ҫ�۵Ĺ�â���������㼸�����������ǰ�Ķ���......\n") ;
    write("�ף��㲻�������Լ��ǲ����ۻ���...������ǰ���˸�İ�������ӣ�\n") ;

    tell_room( environment(), 
       sprintf("İ������%s(%s)��ͷ΢Ц��˵��: лл��\n",
       who->query("c_name"),who->query("name") ), who ) ;

    set("alt_corpse",CAMPMOB"mob2-1") ;
    if (code==1) return 1 ; 
    if ( !(who->query_temp("lulu_mob2")) ) { 
      who->set_temp("lulu_mob2",1) ;
    }
    if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob4")) )  
          tell_object( who,"İ����˵��: лл�����������¶¶��!!\n");
    else  tell_object( who,"İ����˵��: лл������Ѱ������������!!\n");

    die() ;
    return 1;
}

void die()
{
   ::die(1) ;
   return;
}
