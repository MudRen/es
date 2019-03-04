
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "fire dragon statue", "�����ĵ���" );
	add("id",({"fire","dragon","statue"}));
	set_short( "�����ĵ���" );
	set_long(
         "���������ǹŴ��ػ���������ޣ���ľ޴�ĵ��񾭹����÷紵����Ѿ�
        �ƾɲ���������ȴ�о��������ӵ����ؿ����㡣\n"
	);
	set( "alignment", -500 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",800) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
    object victim;

    if( random(20)<15 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "��������³�һ��������һ����������ӭ�����.\n"
          );
      tell_room(environment(this_object()),
          "��������³�һ����������"+victim->query("c_name")+"��ȥ.\n"
          ,this_object() );
      victim->receive_special_damage("fire",6+random(2));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}
 
int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    command("give paper to "+who->query("name"));
    write("\nͻȻһ��ҫ�۵Ĺ�â���������㼸�����������ǰ�Ķ���......\n") ;
    write("�ף��㲻�������Լ��ǲ����ۻ���...������ǰ���˸�İ�������ӣ�\n") ;

    tell_room( environment(), 
       sprintf("İ������%s(%s)��ͷ΢Ц��˵��: лл��\n",
       who->query("c_name"),who->query("name") ), who ) ;

    set("alt_corpse",CAMPMOB"mob3-1") ;
    if (code==1) return 1 ; 
    if (!(who->query_temp("lulu_mob3"))) { 
      who->set_temp("lulu_mob3",1) ;
    }
    if ( (who->query_temp("lulu_mob2")) && (who->query_temp("lulu_mob4")) )  
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
