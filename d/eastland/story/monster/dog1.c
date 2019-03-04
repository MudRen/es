#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "hell dog", "������Ȯ" );
	add ("id", ({ "dog" }) );
	set_short( "������Ȯ" );
	set_long(@C_LONG
һͷ��Ŀ�����ĺ�ɫ��Ȯ��������֧�����ľ��ˣ�������һ���˵����������
һ���۾�������ͭ���ǰ������ݺݵص����㣻��֫���������ˣ��ж�����ƾ�
����ʮ������������ؿ���������������Ȯ����ǻ���������Ѫ���գ�ԭ������
������������Ѫ��������������˹������ж�Ѹ���Ѽ���
C_LONG
	);
        set("killer",1);
        set_temp("bs",10);
        set( "alignment",-1000);
        set( "unit", "ͷ" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "karma", 30);
	set_skill("dodge",100);
	set("special_defense", (["all":30,"none":20,"fire":-20]) );
        set("aim_difficulty",
           (["critical":50,"vascular":50,"ganglion":50,"weakest":50]) );
	set("stun_difficulty",50);
	set("max_hp", 1000);
	set("hit_points", 1000);
	set("max_fp",300);
	set_natural_weapon(80,32,50);
	set_natural_armor(1,1);
        set("weight", 2000);
        set("tactic","assault");
        set("bodyguard",1);
        set("unbleeding",1);
        set_c_verbs( ({ "%s����֧���������%sһɨ",
                        "%s��ͷ��%sһײ", 
                        "%s�ſ�����Ѫ����%s�ݺ�һҧ"
                    }) );
        set_c_limbs(({"����","ͷ��","ǰ֫","����"}));
        set("tactic_func","my_tactic");
}
void init()
{
   object player;
   player=this_player();
   if ( player->query_temp("wonderful_spell") ){ 
      tell_object(player,"���������ƭ��������Ȯ��û���ܵ����Ĺ�����\n");
      return ;
   }
   else return ::init();
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("bodyguard") ) return 1;
       return 0;
}
int my_tactic()
{
   object victim,*couples;
   int i,max;
   if ( !victim=query_attacker() ) return 0;
   couples=filter_array(all_inventory(environment(this_object())),
        "can_help",this_object());
   max=sizeof(couples);
   for (i=0;i<max;i++)
      couples[i]->kill_ob(victim);
   if ( random(14)>1 ) return 0;  
   tell_object(victim,"\n��Ȼ����������Ȯ�����㲻����ʱ���㱳��͵ҧһ�ڣ���ʱ��Ѫ���죡\n\n");
   tell_room(environment(this_object()),sprintf(
    "\n��������Ȯ����%s����һҧ����ʱ��Ѫ���죡\n\n",victim->query("c_name")),victim);
   (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,3 );
    return 1;               
}
