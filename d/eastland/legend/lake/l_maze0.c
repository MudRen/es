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
�ⷴ�������ϣ�����һ�ſ�������������ʯ��ǰ�治Զ�����Ǻ����ˣ����������
���Դ����ϵ̰���Ϣ(rest)��
LONG
    );
    ::reset();
}

void init()
{
  ::init();
  add_action("take_a_rest","rest");
}

int take_a_rest()
{
  object obj;
  if ( obj=present("oar",this_player())) obj->remove(); 
  this_player()->move_player(LAKE"village14","SNEAK");  
  tell_object(this_player(),
            "�ϴ���Ц������˵ :�����ͻ�������Ȼ��һ�Ѱ������ϰ�����\n");
  tell_room(environment(this_player()),sprintf(
          "�㿴��%s�´����˹�����\n",this_player()->query("c_name")),
          this_player());
  return 1;
}