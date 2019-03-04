
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "brontosaurus statue", "��������" );
	add("id",({"statue"}));
	set_short( "��������" );
	set_long(
   "�㿴��һֻ�޴���������������е������һ������Ȼ�ܾ��ˣ�ȴ���ܸо�\n"
   "һ˫���������������������������\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",900) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
  object victim;

    if( random(50)<30 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,"( �㷢�ֱ���ĺ�������! )\n" );
      tell_room(environment(victim),
          "�㷢��"+victim->query("c_name")+
          "����ĺ�������!\n", victim);
      victim->block_attack(3) ; 
      victim->set_temp("msg_stop_attacker","( �㷢�ֱ���ĺ�������! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    write("\nͻȻһ��ҫ�۵Ĺ�â���������㼸�����������ǰ�Ķ���......\n") ;
    write("�ף��㲻�������Լ��ǲ����ۻ���...�������Ȼ���ˣ�\n") ;

// �Ѳ�Ƭ������*grin*
   item->remove();
    tell_object( who,"����˵��: лл��Ϊ�˱���������������������!!\n");
   kill_ob(who);
   if( who ) who->set_explore("noden#39");
    return 1;
}

