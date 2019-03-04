
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "tyrannosaurus statue", "��������" );
	add("id",({"statue"}));
	set_short( "��������" );
	set_long(
          "�㿴��һ�����͵ı�������Ҳ���ñ�¶춻���Ĺ�ϵ���Ѿ�\n"
          "�ߺ۵���ˡ�\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
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
        "�������μ�ת����е����������������Ѿ��Ҳ��ˣ�\n"
      );
      tell_room(environment(this_object()),
        "�������μ�ת��"+victim->query("c_name")+"���Ϲ�ȥȥ.\n"
          ,this_object() );
      victim->receive_special_damage("fire",10+random(5));
      "/d/magic/magic"->report(this_object(),victim);

      tell_object(victim,"( �㷢������ĺ�������! )\n" );
      tell_room(environment(victim),
          "�㷢��"+victim->query("c_name")+
          "��Զ���������!\n", victim);
      victim->block_attack(2) ; 
      victim->set_temp("msg_stop_attacker","( �㷢����Զ���������! )\n") ; 
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

    set("alt_corpse",CAMPMOB"mob4-1") ;
    if (code==1) return 1 ; 
    if (!(who->query_temp("lulu_mob4"))) { 
      who->set_temp("lulu_mob4",1) ;
    }
    if ( (who->query_temp("lulu_mob2")) && (who->query_temp("lulu_mob3")) ) 
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
