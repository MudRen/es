#include "../healer.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "dog", "��֮��" );
    set_short( "��֮��");
    set("no_attack",1);
    set_long(@C_LONG
һֻ��ë�Ĵ�׹�������������ţ�һ�����óԵľͻ�����ȥ��
����Ϊ�˼�������������������������֡�
C_LONG
            );
    set("unit","λ");
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",3100);
    set( "moving", 1 );
    set( "speed", 30 );
    set( "patrol", ({ "east","west",
                      "east","west" } ));
    set("chat_chance",5);
    set("chat_output",({
         "��֮�ɶ��㡺���������ط�����\n",
         "��֮������Լ��Ĺ������������˯���ˡ�\n",
         "��֮�ɳ��������ϺóԵġ����������ط�����\n"
    }) );
}        
int accept_item(object me, object item)
{
      string name;
      
      name=item->query("name");
      if (this_object()->query_temp("feed")){
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "��������Ķ��������ڵ��¡���\n");
          return 0;
      }
      if (name!="white bone") {
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "��������Ķ�������ȥ����\n");
          return 0;
      }
      item->remove();
      this_object()->set_temp("feed",1);
      tell_room(environment(this_object()),this_object()->query("c_name")+
          "һ���̵ص���������Ķ����ܻ��Լ��Ĺ������ˡ���\n");  
      set_long(@C_LONG
��֮�ɡ������ڳ���������
C_LONG
            );
      return 1;
}
