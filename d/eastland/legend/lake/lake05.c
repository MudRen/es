#include "../legend.h"

inherit LAKE"in_lake1";

void create()
{
        ::create();
    set_short("��");
        set_long( 
@LONG
�㻮�����������˺����ϣ���Ŀ��������һƬ��ƽ�˾�������󺣣�Զ������
�洬�����������ظ�����������Ⱥ�����ڵز����档�����ϲ�ʱ���������㣬��
�ⷴ�������ϣ�����һ�ſ�������������ʯ�����Ա߲�Զ���ƺ���һ�����죬�㲻
����ˮ����һ�����ƺ�������ǳ̲�����������(get_off)�´�������
LONG
    );
  ::reset();   
}

void init()
{
 ::init(); 
 add_action("do_get_off","get_off");
}

int do_get_off()
{ 
  if (present("oak oar",this_player()))
    get_object("oar",this_player())->remove(); 
  tell_object(this_player(),
       "��Ѵ������£���̤���ƺ���һ��ǳ̲������ˮ���У�������һ��ɳ̲�ϡ�\n");
  this_player()->move_player("/d/eastland/story/area/coast1.c","SNEAK");
//  this_player()->move_player("/d/eastland/17,6.east","SNEAK");
  tell_room(environment(this_player()),sprintf(
       "%s��ǳ̲��ˮ������\n",this_player()->query("c_name")),
       this_player());
  return 1;
}
