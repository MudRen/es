#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "a drunk man", "�������ϵ���" );
    add( "id",({"man"}) );
    set_short( "�������ϵ���");
    set("no_attack",1);
    set_long(@C_LONG
һ���������ϵ�����
C_LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",300);
    set("chat_chance",2);
    set("chat_output",({
         "����:��С��,�þ�����\n"
    }) );
                                    

}        
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="chan letter")
         return 0;
//     if( (int)me->query_quest_level("dony1") ) {
       if ( me->query("finish_dony") ){
         tell_object( me,"��˵��:лл��\n");
         item->remove();
         return 0;
      }   
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
           "��˵��:�����Ǵ��Ƕ����Ķ�����?\n");
         command("give chan letter to "+my_name);
      }
      else {
         tell_object( me,
           "���ӹ�����ż�...........\n");
         item->remove();
         call_out("recover1",15,me);
      }
      return 1;
}
void recover1(object me)
{
     object ob1;
     
     tell_object( me ,
        "��������˵��:��.����...��..����......\n"
        "��̾��:��,ȫȻ���ˡ������Ҹ��׸��ҵ���֮��,�Ҳ�֪��ԭ�������˼��Ǿ�����ȡ\n"
        "         ,������������ȫ��һ��,�ұ���������˼ҳ���,Ȼ��ɱ����˷�������\n"
        "         �����,�ҿ������������,����........................................\n"
        "         �����������򹷰��ͻ�������,���Ҹ������˼�˵��̫�Բ����������ռ���\n"
        "         ,������ֻ��һ����Ը,��֮Ů����������ޡ�\n");
     ob1=new(DITEM"dog_blunt");
     ob1->set("master",me->query("name"));
     ob1->move(this_object());
     command("give dog blunt to "+me->query("name"));   
     tell_object( me ,
        "��˵��֮��Ͳ����ˡ�\n");
     this_object()->remove();   
}      