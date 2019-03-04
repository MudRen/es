#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "��ľС��" );
    set_long(@C_LONG
��������һ����ľС���ľ�ͷ��С����������һ���Ų�֪������ľ����֦��ס
�����⣬�Ե���Щ����������һЩ������౵ؽ���������������һ��Сľ�ݡ�
C_LONG
    );
    set( "light",1);
    set("c_item_desc",([
     "house":"һ���û�ľ���ɵ����ӣ�����Խ�ȥ���� ( enter )��\n"
    ]) );
    set( "exits", ([
     "south":LAKE"village2"
    ]) );
    reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("��Ҫ��������?\n");
   this_player()->move_player(LAKE"house1",({
      "%s������һ��Сľ�ݡ�\n",
      "%s���������˽���.\n"}),"");
   return 1;
}