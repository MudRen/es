#include <mudlib.h>
#include "../legend.h"
inherit LAKE"lakeii";
inherit ROOM;

void create()
{
    ::create();
    set( "light",1);
    reset();
}
void init()
{
    object *all;
    int i;
    ::init();
    all=all_inventory(this_object());
    for (i=0;i<sizeof(all);i++)
       if (!living(all[i]))
           all[i]->remove(); 
    add_action("do_get_off","get_off");
}

int do_get_off()
{
  tell_object(this_player(),@LONG
�㲻֪������ʲ��ħ����Ȼ��������ˮ......
���๾�����һ����ˮ����һ������������㸣�����������ش�������
LONG
  );
  this_player()->receive_damage(20);
  return 1;
}