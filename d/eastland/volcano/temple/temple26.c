#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("����ص�");
	set_long(
@LONG_DESCRIPTION
������λ�����صأ��ı���Ȼ������һ���촰��Ŀ����ģ�����ûɶ�������뿪��
һλ������ĳ�����������չأ��������������������û�ɽֹͣ������
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple25",
     ]) );
set_outside("eastland");
set("objects", ([
    "elder":OMONSTER"elder",
    ]) );
set("have_book",1);
set("wall_box_for_mar_short",1);    
reset();
}

int reset()
{
  set("have_book",1);
  ::reset();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{
  object me;
  
  me=this_player();
  
  if (!((me->query_temp("known_book_of_sword"))||(me->query_quest_level("Ohio's_brother"))))
    return 0;
  if (present("wraith elder",environment(me))) {
    tell_object(me,"�����峤�������ص�������ǰ��ֹ������������ж�������\n");
    return 1;
  }
  tell_object(me,
 "�㾭��һ����ϸ��Ѱ�ң�������ǽ������һ����Կ�׿װ�����İ���(wall_hole)��\n");
  me->set_temp("can_insert_key",1); 
  return 1;
}
