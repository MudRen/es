#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "host", "������");
        set_short("������" );
	set_long(@C_LONG
��������һλ����ͦ�Σ��������������ˣ�������֫�ٺ�ɢ����һ��������ȫ��
�����ƺ���������һ��ĺ���������һλ�ɷ���ǣ�ʹ�㲻�������׽���������
ʮ����ǰ��������ԭ����һλ�������ĸ�ʢ���Ľ��ͣ�ȴ�ڵ����۷�֮�ʼ���ӿ��
��һʱ������˴�㵣�����������������������ڴ������״̬�������Ϲ�����Ȼ
����Ӵ������Ը�����̽���������������������ġ�
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 35 );
	set_natural_weapon( 34 , 13 , 13);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);  
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",100);
	set("spouse","Hostress");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45, "none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"sun_ring");
        equip_armor(LARMOR"sun_amulet");
        wield_weapon(LWEAPON"phenix1");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                 "sword":"@@ask_sword",
                  "����":"@@ask_sword",
                 "first":"@@ask_first",
                 "second":"@@ask_second",
                 "third":"@@ask_third",
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void init()
{
   ::init();
   add_action("do_say","����");
}
void ask_sword(object asker)
{
write(@C_LONG
�����˵����ţ��ҷ����ݺὭ����ʮ�꣬��ܸ���������Ω�ޱ�������ܴ��ұ�
�������������ѧ�����������Ϊ�ҷ򸾵���ܣ������������Ҹ���������¡�
         ( first second & third)
C_LONG
      );
}
void ask_first(object asker)
{
write(@C_LONG
�����˵�����һ���£�
��������������ǰ�����ѡ�ؤ���������˷������˷��Ÿ���ϣ���ҷ�ǰȥ����
����������һ��֮���������δ�潭������֪����Ǻã���Ȼ������Ҫ��Ϊ���ǵ�
����������ͽ�ܣ�����������ǰ���������ţ�����������ɵ�һ��������
C_LONG
      );
}
void ask_second(object asker)
{
write(@C_LONG
�����˵����ڶ����£�
          �ڴ�ǰȥ����ʮ���и���壬���������Ҫ�������ˣ����ȥ��������
          ��������ǰ�Ķ��ˡ�ร����˸����㣬�������Ĵ峤�������ǵڶ���
          ������
C_LONG
      );
}
void ask_third(object asker)
{
write(@C_LONG
�����˵����������£�
          ���ҷ��˰ɡ����������������£����ҡ����� �����ˡ��Ϳ����ˡ�
C_LONG
      );
}
int do_say(string arg)
{
   object me;
   if ( !arg || arg!="������" )
      return notify_fail("��Ҫ��˭����?\n");
   me=this_player();
//      if( me->query_quest_level("couples") ) {
   if ( me->query("couples") ) {
      tell_object( me,"������˵������ͽ�ܣ�����Ϊʦ����ʲ����Ҫ��������\n");
      return 1;
   }
//   if ( !( (me->query_quest_level("dony1"))&&
   if( !( (me->query("finish_dony")) &&
          (me->query_temp("second")) &&
          (me->query_temp("third") )    ) )  {
       tell_object( me,"������˵�����ټӰѾ��ɣ�\n");      
      return 1;             
   }          
//   me->finish_quest("couples", 1);
    me->delete_temp("second");
    me->delete_temp("third");
    me->set("couples",1);
    me->gain_experience(8000);
    tell_object( me,@C_LONG 
�����˵����ú��ӣ�����춲�����������ҽ�������������������ã��Ҿ�����
����������Ϊͽ�ɣ�
         
      
      [���������˵��ʹ͵õ� 8000 �㾭��]\n\n");

C_LONG
    ); 
     me->delete("blind");
     me->set("medication_resistance",0);
     if ( me->query("class")!="scholar" ) {
        tell_object( me,@C_LONG
�����˼̵�����������Ϊʦ�봫��һ�׽�����������������ѣ����ʲ�����Ҳ����
���������������ˡ�
������ٰ�ذ��ң������˾��ǲ����㽣�����㲻�����ĵ�̾��һ������     
C_LONG             
     ); 
     return 1;
     }
     tell_object( me,@C_LONG
��������������ȫ��Ĺ�������
�����˺�����ص���������������ѣ�����ѧ�ҷ����ݺὭ��ʮ����Ľ�����

ֻ�������������Ӱ˵�˵�˼��仰����ȴһ��Ҳ�������ڽ�ʲ�ᣮ������
�����˿�����������ʵı��飬��ŭ�ص���ʲ�ᣬ����һ�仰Ҳ��û�мǵã��ع�
��������ú�����(ponder)����ɣ�
C_LONG
     );
     return 1;
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
int my_attack()
{ 
   object *couples,victim;
   int i;

   if( !victim =query_attacker() ) return 0;
                        
   if( query("force_points") < 50 ) set("force_points",500);
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), sprintf(
          "%sŭ��:��������������۸���,�����µ���ȥ��!!\n",couples[i]->query("c_name")),
          couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("hostress",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}
