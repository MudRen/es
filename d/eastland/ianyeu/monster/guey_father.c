#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "���ϵ�" );
   add( "id", ({ "guey", "father" }) );
   set_short( "���ϵ�" );
	set_long(
        "�㿴��һ��״�Ƴմ�, ��Ƽ��ݵ���ͷ, ������������������ա�\n"
        "�����㲻ʱ����һ�����ĵ���, �������޵�̾Ϣ����\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
	set( "inquiry", ([
       "cut" : "ȥ����Ů����!\n",
       "sheaumei" : "TEST\n",
       "sheaumei" : @DAUGHTER
�� .... �ҿ�����Ů�� ........

������ǵð���֮ǰ, �Ǹ���ɫ�谵��ҹ�� ........
С÷��Ů���������, �����߱���֮��; �ϰ���æ��
��ʰ���̲���, ��Ů��ȴ������춵�, �Ϸ�ֻ����ȥ
����Ů���������Ҹ�����ǰʱ, �������ų���, Ů��
����춵�! ��Ǽ�æ���뷿��̽��СŮ, ��̾������
���� ...............

���̤�뷿��֮��, ����һ��ӰԾ������, �䱳Ӱ��
�ݷ�һֻ��Ȯ! �Ϸ���޲������̴�����֮��!!
����, ���ܷ�������ɴ�Ը?
DAUGHTER
	]) );
}

int accept_item(object who,object item)
{
   object devil;

   if ( !item->query_cutted() ) {
         tell_room( environment(), 
@NOEAT
���ϵ�ϲ��: ��л������
���ϵ�����������һ������ ......
�������Ե�, ���޷������� ......
���ϵ�̾��: ����, �����ٰ�������(cut)����?
NOEAT
   );
         command("give heart to "+who->query("name"));
         return 1;
             }
   item->remove();

     tell_room( environment(), 
@CHANGE
���ϵ�ϲ��: ��л������
���ϵ��������������һ������ ......

ͻȻ���ϵ���ɫ����, ��Ц��: �� ...�� ...�� ......
��ֻ�����������! �Ǹ��ɺ޵ļһ�����������������,
��л�����ҳ�ȥһ���鷳����Ů����ʵ����ɱ��, ��Ϊ��
���������ӡ�, ���ϡ�Т�����������, �޴�����, �µ�
�������ǰ�!

CHANGE
   );

   devil = new( IANMOB"devil" );
   devil->move(environment(this_object()));
   devil->kill_ob(who);
   this_object()->remove();
   return 1;
}
