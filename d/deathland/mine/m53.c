
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" Drawf mine ","���˿��");
  set_long(@Long
Long
,@CLong
�����ǿ�ӵ��.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ��Լ�
��ľͷ�������������ݵ��Ҷ�.�ڵ���������������.ר���˿�ͨ��ʹ��.Ȼ��
����������ľ�ͷ,ǰ���·�ƺ���һ�����ݵ�ʯ����ľͷ��ס��ȥ·.
CLong
);
set("c_item_desc",([
    "riprap":"@@to_search_riprap",
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    ]) );
set("direction","block");
set("exits",([
             "north":Mine"/m47",
             ]));
reset();
}
string to_search_here()
{
     return "����������ط���ʱ��,���Ŀ��Ľ�������ǶѶ�ס·����ʯ(riprap)��\n";
}

string to_search_riprap()
{
    return "һ���������µ�ʯͷ,�����ƺ�����������������һ������\n";
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"�����ھ�����?\n" ); 
      return 1;
      }
    tell_object(this_player(),
             "��Щʯͷ�����Ŭ��֮��,�����Щ�ɶ���,�����㲻����ͨ����,\n"
             "��ȻһЩ�����϶�������ʯͷ�����洫��,������ֻ�ܴ�����վ��\n"
             "����������޲�,�ѵ���ЩСʯͷ����ס����?���е�,ֻ����û��\n"
             "ʹ����,�������һ�ɴ�������������,\��\��\����Է��������\n"
             "�������.\n");
    this_player()->set_explore("deathland#7");
    return 1;
}
