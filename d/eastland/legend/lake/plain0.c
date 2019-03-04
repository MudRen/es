#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "С��" );
    set_long(@C_LONG
��������һ������С��,С����������һ���Ų�֪������ľ,��֦��ס������,
�Ե���Щ����,����һЩ������౵ؽ����� �����Ա߻���һ�ò���ĺ���ľ,��
��Լ��Ҫ��ʮ���˺ϱ��Ŀ��,����һ��ǧ����ľ!�㲻����̧ͷһ��,��Ȼ������
�����֮�ġ�
C_LONG
    );
    set( "light",1);
    set( "exits", ([
     "up":LAKE"mountain8",
     "east":LAKE"plain1"
    ]) );
    set( "c_item_desc", ([
     "tree" : @C_LONG
����һ��ǧ����ľ����������ˣ������������������˯����(sleep)��
C_LONG
    ]) );
    reset();
}
void init()
{
   add_action("do_sleep","sleep");
}
int do_sleep(string arg)
{
   tell_object(this_player(),
      "�����ڵ���������ľС�һ��....\n");
   this_player()->set_temp("block_command",1);
   call_out("back",7,this_player());   
   return 1;    
}   
void back(object player)
{
   player->delete_temp("block_command");
   tell_object(player,"�ף�������ʱ��Ȼ����һ��������...\n");
   player->move(LAKE"tree1","SNEAK");
}