#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "keeper hau", "������" );
    add( "id",({"keeper","hau"}) );
    set_short( "�ʷ� ������");
    set("no_attack",1);
    set_long(@C_LONG
������ԼĪ�ġ���ʮ�����, ����һֻСС�Ĳ�����Ƭ,��Ƭ����񿴲����κ���
���۾���ѶϢ��������Ƭ����һ��������, ����������ŨŨ�ľƳ�ζ,����·��
һҡһ�ڵĺ��񱻷�һ���ͻ�ˤ���ڵ�,�ɼ���ƽʱ�Ⱦ�֮�ࡣ����������������
�鷳��,Ҳ��ȥƽʱȥ�ġ�н���塻�Ƶ�Ⱦơ�
C_LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",45);
    set("gender","man" );
    set("no_attack",1);
    set("chat_chance",4);
    set("chat_output",({
            "��������ͣ��������ȥ��\n",
            "������ͣ���������컨���ƺ��������顣\n",
            "�����������̾��һ����,������̾��:��~~��\n"
    }) );
    set("inquiry", ([
             "trouble":"@@ask_trouble",
             "help":"@@ask_help" 
    ]) );
}        
void ask_trouble(object asker)
{
    tell_object(asker,
     "������˵��:��λӢ�ۺú�,�������ܰ��� ( help ) ����?\n"
       );
}
void ask_help(object asker)
{
    tell_object(asker,
     "������˵��:������������:��һ������,���������ҿ��ܼ�����Կ��, ��֪��\n"
     "           ��˭, ��������͵͵������һ���������������������һϢ, ��\n"
     "           ���ϻ�������Ҫ����������ȥ��̹����, ���˵������\n"
     "           ĳ������������,��Ҫ����ɽ��ת�����衻( pill ) ���ܹ�ҽ��\n"
     "           ��,������������ɽ����Զ,������Ҫ��������ǰ��, ��������\n"
     "           ����ȡ����?�һ�ܸм����\n"   
                );
}
int accept_item(object me, object item)
{
      string name,my_name;
      object ob;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
         
      if ( (name!="bear-snake pill") && (name!="sun pill") )
         return 0;
      
      switch ( name ) {
      case ( "bear-snake pill"):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "������˵��:��,�����Ǵ�����͵���ľ�ת������? �û�ȥ��, ����\n"
            "           ��Ҳ��Ը����͵����ҩ!!\n");      
            command("give pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "�������ܸм��ؽӹ����������,������˵���һ��,����ȥ�����˷���...\n"
            "������������������ø���ߵ�ͯ�ӽ�������������ȥ��\n");
            item->remove();
            me->set_temp("keeper_finish1",1);
            call_out("recover1",10,me);
         }
         return 1;
      case ( "sun pill" ):
         if ( ( item->query("master") ) != my_name ) {
            tell_object( me,
            "������˵��:��,�����Ǵ�����͵��������������? �û�ȥ��, ����\n"
            "           ��Ҳ��Ը����͵����ҩ!!\n");
            command("give sun pill to "+my_name);
            return 1;}
         else {
            tell_object( me,
            "�������ӹ����������,�������ͯ�Ӵ�������ȥ��\n");
            item->remove();
            me->set_temp("keeper_finish2",1);
            call_out("recover2",10,me);
         }              
      }
}      
void recover1( object obj)
{
    tell_object( obj,
      "\n���Ȼ����һ����ҵĽ���!!!!\n\n\n"
      "������һ��ͯ���ܵ�������������ҧ���䡣\n"
      "������˵��:���������?����,���ȥ��ҽ������!!�����˷������������\n"
      "           ��ת������֮��Ϳ��°�ĭ�ε���!!\n"
        );     
}
void recover2( object obj)
{
    tell_object( obj,
      "�������ܳ�����ͯ�����ɵ�������������ҧ�����\n"
      "������΢Ц������л��:�������л,���˵Ĳ���춺��ˡ�\n"
      "������˵��:����,����˵һ����,���˸�˵����͵Ϯ�����˺�������\n"  
      "           ���� ( jail ) �Ǹ�����,�������֪������������,��\n"
      "           ��ȥ��̰��и߲���ӡ�\n" );
}