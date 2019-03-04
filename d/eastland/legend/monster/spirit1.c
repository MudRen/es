#include "../legend.h"
#include "../magic.c"

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "wood spirit","��ľ����" );
	add ("id", ({"spirit"}) );
	set_short("��ľ����");
	set_long(@C_LONG
����ǰ������һλ��Ŀ���飬�������׵����ߡ���Ȼ����������Լ��������ʮ���
��ͣ�ȴ���ܲ����κβ��ϵ�ѶϢ������������һ�ֻ��õ�ȪԴ����ľ����ԭ����
�������ˣ����˰���ǰ���˹�����������·��䣬���ƺ������鷳�ˣ����üĿ
������
C_LONG
	);
        set("be_asked",0);
	set("unit", "��" );
        set("no_attack",1);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        set( "inquiry", ([
             "mistake":"@@ask_mistake",
             "����":"@@ask_mistake",
             "trouble":"@@ask_mistake",
             "�鷳":"@@ask_mistake"
        ]) );
}
void ask_mistake( object asker )
{
     object lock;
     if ( query("be_asked") ) {
        tell_room(environment(this_object()),
         "��ľ����˵��:�Ұ��������������ˣ�ϣ������һ�Ǻ��������ˡ���֧����\n");
        return ; 
     }
     set("be_asked",1);
write(@C_LONG
��ľ����̾��:�˰���ǰ����һʱ�����ˮ�֡���֧�����ų�����˱����·��䡣
 ������������һֱ��������Ϊ����δ�ɣ��Ŵ���ս����֧����û�취ʹ��֧��
 �����������������ϣ�����ܰ����ҡ����ˣ�����ɱ������֧��֮��ǵ�����
 �������������� ( iron_lock ) ������Ȼ���ֻ��������������л��

��ľ���˴������ͳ�һ����������
C_LONG
      );
      lock=new(LITEM"iron_lock");
      lock->move(environment(this_object()));  
      call_out("recover",300,this_object());
}
void recover(object obj)
{ obj->set("be_asked",0);}
