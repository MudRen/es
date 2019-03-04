#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the mystic altar","���ؼ�̳");
  set_long(@Long
Long
,@CLong
һ���ѷ�������ļ�̳.������Ȼ�м�����ж�,ĳ�����ƺ���������������һ������
�ļ���.��̳������һ�������һ�(fire)��ȼ����.
CLong
);
  set( "light",1 );
  set( "c_item_desc",([
       "fire":"һ���һ�,�ƺ���Զ����Ϩ�������,��������ȥϨ��(extinguish)���Ż���? \n"
     ]) );
  
  set( "exits",([
             "south":Deathland"/dwarf/village_0a",
             ]));

  reset();
}

void init()
{
	add_action("to_extinguish","extinguish");
}

int to_extinguish(string str)
{
   object *items,who;
   int i,j;
   
   if (!str||str!="fire") return 0;
   who=this_player();
   items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if ( ( j=items[i]->query("quest_action/muse_filled") ) ) {
              if (j==3) { //��ɫ
              write("������ɫƿ�ӵ�ˮ����ȥ, ��ʱ����ʱ��С��Щ, �����Ͽ��\n"
                    "�ѻ��е����ó���. �������ó����ͬʱ, �����ٶȵش�������. \n"
                    );
              items->set("quest_item/study_book",1);
              who->set_explore("deathland#17");
              }
              else 
              write("������ɫƿ�ӵ�ˮ����ȥ,���ǻ�ȴһ��Ҳû�б�С.\n");
              items->set("quest_action/muse_filled",0);
              return 1;
              }
  write(
  "���㳢����ȥϨ����һ�Ż��ʱ��, �㷢�����Ż�����һ�������鼮, ������춻�\n"
  "���¶�ʵ��̫����, ���޷��ó��Ǳ�����. \��\��\��Ӧ��ȥ��ˮ���ѻ�ŪϨ, ����һ��\n"
  "��ˮӦ��û�а취��Ϩ����. �����ҵ��ܹ�ŪϨ���������һ��ˮ����? \n");
   
   return 1;
}

