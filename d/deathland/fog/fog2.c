// Deathland/fog1.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("Fog","����");
    set_long(@Long
Long
,@Clong
һ���������������ȫ����ס��,��ķ�����Ѿ���ȫ��ʧȥ��
Clong
	);
   set("search_desc",([
       "here":"@@to_search_here",
       "blowhole":"@@to_search_blowhole",
       ]) );
   
   set("c_item_desc",([
       "blowhole":"һЩð������������.\n",
       ]) );
   
   set("exits",([
       "east":Deathland"/fog/fog2",
       "west":Deathland"/fog/fog2",
      // "north":Deathland"/fog/fog2",
      // "south":Deathland"/fog/fog2",
      ]) );
   reset();    

}
void init()
{
    // add_action("","");

}

string to_search_here()
{
   
   return "����ϸ��Ѱ�ҳ�·��ʱ��,�㷢�ֵ��ϳ�����һЩ����(blowhole)ð������\n"
          "ԭ���Ǿ���������ɢ��ԭ��.\n";

}

string to_search_blowhole()
{
  return "��Щ�ڵ��ϵ����׵���״ǧ��ٹ�,�������е�λ���൱���,�ƺ��γ�һ��.\n"
         "����ķ���.\n"; 
}
