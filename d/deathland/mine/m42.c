
#include "../echobomber.h"


inherit ROOM;

int be_digged;
void create()
{
	::create();
  seteuid(getuid());	
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
             "north":Mine"/m31",
             ]));
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
      tell_room(this_object(),
         "һ�����˾��µ���ħ,����֮�۳�����\n" 
          );
      be_digged++;   
      ob1=new(Monster"/beholder01");
      ob1->move(this_object());
      ob1->kill_ob( this_player() );
      return 1;
      }
}

void reset()
{
  ::reset();
  be_digged=0;
}
