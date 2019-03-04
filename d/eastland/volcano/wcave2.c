#include "oldcat.h"

inherit ROOM;
inherit DOORS;
int check;
void create()
{
        ::create();
        set_short( "����" );
        set_long(
@LONG
������һ���ֺ�����ĵ��Σ��ǰ����������ץ������Ʒ���˵ĵط�����ʯ��
�̵ĵ��Ͼ���һЩ��Ǭ����Ѫ�����ʹ�ǰ���������������Ķ�����
LONG
        );
	set( "exits", ([
        "west" : ONEW"wcave1"
	]) );
        set("item_desc", ([
            "tunnel":"һ���ںڵĵص����������κ����⡣\n",
            ]) );
        create_door( "west","east", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "������",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "һ�Ⱥ���ľ�������и�Կ�ס�\n"
                    ]) );
        set("search_desc",([
            "here":"@@to_search_here",
            "plate":"@@to_search_plate",
            ]) );
        reset();
}

void init()
{
  add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel" || !check) {
    write("��Ҫ��ȥ���� ? \n");
    return 1;
  }
 write("���߽������ںڵĵص�����ʯ���ƻض�λ��ͻȻ�뵽����һ�������������ص������ˡ�\n");
  write("�����˺ܾã���������������ص�����һ����������....................\n");
  write("���ǰ�洫��һ�����⣬�Ѿ��������ˡ�.........\n");
  this_player()->move_player(ONEW"wcave3","SNEAK");
  check=0;
  return 1;
}

string to_search_here()
{
  string str;

  str="����������ϸ��������������һ��ʯ��(plate)�ƺ��е��ɶ���\n";
  return str;
}

string to_search_plate()
{
  string str;

  str="������ʯ����Χ�Ķ����ƿ�����ʯ�����������ƣ����־�Ȼʯ�������и��ص�(tunnel)��\n";
  check=1;
  return str;
}

void reset()
{ 
  ::reset();
  check=0;
}
