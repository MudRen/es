#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "bookbug", "�ʷʵ������" );
        add("id",({"bug"}) );
        set_short( "�ʷʵ������" );
        set_long(@LONG
һֻ�ʷʵ�С�棬����ϸ�������������������˵Ŀ���ɢ�����ҳ��
����ľ��鿴������������С�ĳ�棬ֻҪ��һ�žͿɡ��ߡ�������
LONG
        );
        set( "gender", "male" );
        set( "race", "shapeshifter" );
        set( "alignment", -10 );
        set_natural_armor( 1, 2 );
        set_natural_weapon( 5 , 2 , 3 );
        set_perm_stat( "kar", 10 );
        set("exp_reward",1);
}
 
void init()
{
        add_action("to_kick","kick");
}
 
int to_kick(string str)
{
   object who, owner;
   
   who = this_player();
   owner = present( "book shop owner", environment(this_object()) );
   
   if (str != "bookbug" && str != "bug")
                return notify_fail( "������ɶ?\n" );
   tell_object(this_player(),@LONG
��ݺݵ���С������������ȥ��С���������Ļ���Ҳû�У����ó�һ�������ˡ�
LONG
        );
   if ( (int)who->query_quest_level("bookbug") > 0 ) {
        this_object()->remove();
        return 1;    
     }  
   if( !owner ) {
        this_object()->remove();
        return 1;
     }   
                   
   tell_object(who,@LONG
����ϰ�м������������˵ :
лл�����ɱ������! �������ҾͲ��ص������������ȥ��!
����Ƿǳ��ĸм�!
 
������ˡ�����ϰ�ķ��ա������񣬻�� 300 �㾭��㡣
LONG
        );
  
//��������Լ��һ����ߵĻ� ���������Ƚ��١�
   if ( (int)who->query_temp("findbug") < 1 )   
        who->finish_quest( "bookbug", 1 );
      
   who->finish_quest( "bookbug",2 );
   who->gain_experience(300);
   who->delete_temp("findbug");
   this_object()->remove();
  return 1;
}
 
void die()
{
  object who, owner;
  who = query( "last_attacker" );
  owner = present( "book shop owner", environment(this_object()) );
  
  if ( !who->query_quest_level("bookbug") && owner ) {
        tell_object(who,@LONG
����ϰ�м������������˵ :
лл�����ɱ������! �������ҾͲ��ص������������ȥ��!
����Ƿǳ��ĸм�!
 
������ˡ�����ϰ�ķ��ա������񣬻�� 300 �㾭��㡣
LONG
        );
     who->finish_quest( "bookbug", 1 );
     who->gain_experience(300);
  }
     
  ::die();
}
 
