#include "/d/eastland/beggar/dony.h"
//inherit "/d/eastland/beggar/area/ch_stun.c";
inherit ROOM;
void create()
{
	object mob;
	::create();
        set_short( "north2", "��·" );
     	set_long(@C_LONG
������������һ����Ϊ���Ĵ�·��,Լ��������ƥ���С���·���ϡ�����
�����졣������·�������Ǭ����,·�Ե�ֲ���޼��ĺ�����,������������,����
�㳡��Ƭ��ͺͺ�ľ������ǲ��ɶ���Ͼ����������Ӽ����ϴ�����,��˵�Ǵ���
����ĵ�·���������, ȴ�������κ��˹������������ĺۼ�,��һ���ǳ����
ĳλ����֮�֡�������һ�Ҵ����̡�
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "west":DBEGGAR"smith.c",
                      "south":DBEGGAR"north1.c",
	              "north":DBEGGAR"north3.c"
	]) );
        mob=new(DMONSTER"soothsayer");
        mob->move(this_object());
     reset();
}
void init()
{
    add_action("do_backstab","backstab");
}
int clean_up()
{
    return 0;
}        
void do_backstab(string str)
{
    object temp;
   if (str){
      tell_object(this_player(),
       "�� bs ? ��ɵ�ˡ�\n");
      this_player()->set_temp("block_command",1);
      call_out("recover1",5,this_player());
      return ;
   }
      return ;
}
void recover1(object obj)
{
     obj->delete_temp("block_command");
     tell_object(obj,
         "���� bs ֮��,�ѵ�û�б�ķ���?\n");
}
