#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("����·");
        set_long( 
@LONG
�����������ĵ�·�ϣ�ӭ����������һ��ŨŨ���ȳ�ζ���ڵ��ϣ��ݺύ��
��Ѫˮ��Ǭ��С�ӣ�һ���Ų�Ӭ��������춸��õ������ϣ���ʱ�������˵�������
�ް���������գ������Ŵغ���һֻֻ����������צ��Ұ�ޣ�Ұ������ݺݵص���
�㣬���������˵���������ɣ������ɣ��ҵ�ʳ�����·�������ϱ����ꣻ����
�м䰫���ķ��ӣ�������һ��յء�
LONG);
    set( "light",1);
    set( "exits", ([
         "east":LAKE"village13",
        "south":LAKE"village11"
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
  object player;
  if ( !arg || arg!="house" )
       return notify_fail("��Ҫ��������?\n");
  player=this_player();
  tell_room( this_object(),
      sprintf("%s�߽������ڡ�\n", player->query("c_name") ), player );
  player->move_player(LAKE"house12","SNEAK");
  tell_room( environment(player),
      sprintf("%s(%s)���˽�����\n", player->query("c_name"),player->query("name"
      ) ), player );
   return 1;
 }