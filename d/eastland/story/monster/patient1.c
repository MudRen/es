#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "patient","������" );
	set_short("������");
	set_long(@C_LONG
����һλ�������ص��ˣ������������״̬������ȫ���ϲ���ǧ�ٸ����ڣ�ÿ����
�ڶ�����ǣ��˿ڴ���������������������Ѫ��Ȼ������ȴ���֣�ÿ���˿��ƺ�
���о��������İ����������ز���������Ѫ����ϸ���������촽�ڵ����ˣ�������
����ĳ�־綾������������������ƺ�����Ҫ��İ�æ��
C_LONG
	);
	set("unit", "��" );
        set("race","human");
        set("gender","male");
        set("max_hp",10000000);
        set("hit_points",1);
        set("no_attack",1);
        set( "inquiry", ([
             "help":"@@ask_help",
             "trouble":"@@ask_help",
             "poison":"@@ask_help",
             "��æ":"@@ask_help",
             "�鷳":"@@ask_help",
             "�綾":"@@ask_help",
        ]) );
}
void ask_help( object asker )
{
write(@C_LONG
������˵�������˵�����̽�գ���С�ı������롹���ˣ�����������ء�
�������������˿ڴ��ѱ�·���ĸ��˰����ˣ�������ȴ�����޲߹������
��������������֮��������û�뵽�Ҿ�Ҫ���������ˣ���
��������������
C_LONG
      );
}
int accept_item(object me, object item)
{
    string my_name,item_name;
    
    my_name=(string)me->query("name");
    item_name=(string)item->query("name");
    if ( !item->query("drink_liquid")) {
       write("�����߲�Ҫ�����������\n");    
       command("give "+item_name+" to "+my_name);
       return 1;
    }    
    item->remove();
    write (@LONG       
�����ߺ�������������ġ����롹��Һ����ʱ�����������еĶ�ȫ����ˣ�
������˵������л��������������֮������һ�²��Ҳ����ߣ��Ǿ��ǣ���
����������������Ĵ��ֱ���ʩ֮��������֪�����������޷��߳�ȥ�ģ�ֻ
������������Ҫ�����������롹ʱ���ۻ����ߣ����ϣ����򶫣��ǾͿ�����
���������������ˡ�
LONG
    );
//    if ((int)me->query_quest_level("patient")<1 ) {
  if ((int)me->query("quests/patient")<1 ) {
      
    write (@LONG
        
  [ ��������ĵؽ���������ߵ����еĶ����������ػ�õ� 2000 ��ľ���]    
    
LONG     
    );
//    me->finish_quest("patient",1);
    me->set("quests/patient",1);
    me->gain_experience(2000);
    }
    return 1;
}                  