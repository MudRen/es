
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set("light",1);
set_short("The road toward the sleeping hall","ͨ��");
  set_long(@Long
Long
,@CLong
���Ӵ���������ҵ�ͨ��.ͨ�����Ե�ǽ�ڷֱ�������ΰ��˹���Ī��������
(Molader V)�Լ�����ȥ�Ĵ���ӷ����ڵĻ���(icons).
CLong
);

set("c_item_desc",([
    "icons":"Ī��������������һ���Ͱ����׵�����,�������ڿ��������������"
            "������.\n"         
    ]) );    
set("search_desc",([
     "icons": "@@to_search_icons",
     "icon": "@@to_search_icons",
     ]) );    
set("exits",([
               "west":Deathland"/palace/pa_01",
               "east":Deathland"/palace/pa_05",
             ]));
::reset();
}

int to_search_icons()
{
     write("�㷢����һ��ͨ�����ڻ�����,���������ȥ����һ̽������\n");
     this_player()->set_explore( "deathland#10" );
     this_player()->move_player(Deathland"/palace/pa_0b","SNEAK");
     return 1;
}
