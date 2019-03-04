#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "a white dog", "С�׹�" );
    set_short( "С�׹�");
    set("no_attack",1);
    set_long(@C_LONG
һֻ��ë��С�׹���ƽʱϲ���ҵ���,�����ֽС���𹷡���
C_LONG
            );
    set("unit","λ");
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",3100);
    set("chat_chance",5);
    set("chat_output",({
         "С�׹����㡺���������ط�����\n"
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
          "һ���̵ص���������Ķ����ܵ���ĵط�ȥ�ˡ���\n");  
      set_long(@C_LONG
һֻ��ë��С�׹���������Ŭ��������������
C_LONG
            );
      this_object()->move(DBEGGAR"forest6");
      call_out("recover",180,this_object());
      return 1;
}
void recover(object obj)
{
    tell_room( environment(obj),obj->query("c_name")+
         "�����궫��֮����������ˡ���\n");
    set_long(@C_LONG
һֻ��ë��С�׹���ƽʱϲ���ҵ���,�����ֽС���𹷡���
C_LONG
    );
    environment(obj)->delete_temp("be_searched");
    obj->delete_temp("feed");
    obj->move(DBEGGAR"vice_master_room");
}
