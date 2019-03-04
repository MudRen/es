#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("�յ�");
	set_long( 
@LONG_DESCRIPTION
��Ƭ�յ�ֻ�г���һЩ�Ӳݣ��󲿷���һЩ��С��һ��ʯͷ���㷢�������ʯͷ��
���ͱ�ط������е�����ɫֻ�к�ɫ�ġ���ɫ�ģ����Ǳ����չ������ӣ��������
��������֪�Ļ�ɽ�����γɵ��������ƣ���о������е��ȡ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest" : ONEW"wild8",
     "south" : ONEW"wild10",
     "northeast" : ONEW"wild14" ]) );
set("item_desc", ([
    "cave":"@@look_cave",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_dig","dig");
}

string look_cave()
{
  if (!this_player()->query_temp("s/check"))
    return "���뿴ʲ�� ?\n";
  return "һ��СС�ĵض�������ںڵģ��������κζ�����\n";
}

string to_search_here()
{
  string str;
  str="��������ط����츲��ʱ,һֻ����ͻȻ����ǰ���ܹ�������ϸ�Ĺ۲������\n"+
      "����������һ������(cave)��Ҳ��\�����ڴ�һ�㿴�������ɶ����\n";
  this_player()->set_temp("s/check",1);
  return str;
}

int do_dig(string arg)
{
    object ob1;

    if (!this_player()->query_temp("s/check"))
       return 0;
    if (!arg || arg!="cave")
    { 
      write("��Ҫ��ʯ����\n");
      return 1;
    };
    if (be_moved!=0)
    { 
        write("�����Ѩ�Ѿ����ڹ��ˡ�\n");
      return 1;
    };
    tell_object(this_player(),
         "���ڿ����Ե���ʯ�����ֽ�ȥ������������һ����ɫ�ɿ���\n"
          );
    be_moved=1;
    this_player()->delete_temp("s/check");
    ob1=new(OOBJ"s_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}
