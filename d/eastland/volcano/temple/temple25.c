#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("������");
	set_long( 
@LONG_DESCRIPTION
һ���������������յİ�������������Ķ��˵��л��˵�ͼ����
���﹩����ǻ��ˣ��ڰ�����Ĵ�˵�л����ǻ��������֮һ��
����������صأ������˵Ȳ��ܽ��롣
LONG_DESCRIPTION
	);
set( "exits", ([
     "south":OTEMP"temple25",
     "northeast": OTEMP"temple24",
     "northwest": OTEMP"temple23",
     ]) );
set( "pre_exit_func", ([
     "south":"to_south" ]) );
reset();
}

int to_south()
{
  if (((this_player()->query_quest_level("Dragon_box"))>0)||(this_player()->query("npc"))) {
    this_player()->move_player(OTEMP"temple26","SNEAK");
    return 1;
  }
  write("\n\n���˴��ݶ��������������������ǰ˵���Բ���������������ܹ���ȥ��\n\n");
  return 0;
}
