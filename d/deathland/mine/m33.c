
#include "../echobomber.h"

inherit ROOM;

int be_digged;
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
    "chest":"@@to_look_chest", 
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    "chest":"@@to_look_chest",
    ]) );
set("direction","block");
set("exits",([
             "northeast":Mine"/m21",             ]));
reset();
}
string to_search_here()
{
     return "����������ط���ʱ��,���Ŀ��Ľ�������ǶѶ�ס·����ʯ(riprap)��\n";
}

string to_search_riprap()
{
    if (be_digged==0)
        return "һ���������µ�ʯͷ,�����ƺ�����������������һ������\n";
    else 
      return "һ���������µ�ʯͷ.�����ƺ��������ھ����\n"; 
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"�����ھ�����?\n" ); 
      return 1;
      }
    if ( be_digged!=0 ) { 
      tell_object(this_player(),"����������,����û�з����κζ���.\n"); 
      return 1;
      }
    else {
      tell_object(this_player(),
        // "you find a mystic chest in the underground,but seems no key to unlock it!\n " 
         "�㷢����һ�����صı���(chest),�����ƺ���������\n" 
          );
      be_digged++;   
      return 1;
      }
}
string to_look_chest()
{
    if ( be_digged==0 )
      return 0;
    else 
      return "һ�������صı���\n";
}
void reset()
{
  ::reset();
  be_digged=0;
}

