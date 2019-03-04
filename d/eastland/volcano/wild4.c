#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("С����");
	set_long(
@LONG_DESCRIPTION
��վ��һ��С���ϣ������������һƬС���֣���ľ�ĸ߶�Լֻ�б�����������
�ٸ�һ�㣬�����뾭�����������������£�Ϊʲ�����������������С�أ���Ȼֻ��С
���֣�������Ҳ���������������⣬��Ҳ�����⸽������ʯ�ͱ�ĵط��Ƚϣ��ƺ�Ҳ��
��Ҳ��һ����
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "northeast" : ONEW"wild9",
     "northwest" : ONEW"wild2", ]) );
set("item_desc",([
    "rock":"@@look_rock",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_push","push");
}

string look_rock()
{
  if (!this_player()->query_temp("g/check"))
    return "���뿴ʲ�� ?\n";
  return "����ɫ��ʯͷ������������ȥ��ӡ�ӣ��ݷ���һ�����ơ�\n";
}

string to_search_here()
{
  string str;
  str="����������ط���ʱ��,�㷢���п�ʯͷ(rock)�����������⣬ʯͷ�����ƺ���\n������ӡ�ӡ�\n";
  this_player()->set_temp("g/check",1);
  return str;
}

int do_push(string arg)
{
    object ob1;

    if (!this_player()->query_temp("g/check"))
       return 0;
    if (!arg || arg!="rock")
    { write(
        "����ҪЧ���޹���ɽ��\n");
      return 1;
    };
    if (be_moved!=0)
    { write(
        "���ʯͷ�Ѿ����ƶ����ˡ�\n");
      return 1;
    };
    write("���ƿ�ʯͷ��������һ����ɫ�ɿ���\n");
    this_player()->delete_temp("g/check");
    be_moved=1;
    ob1=new(OOBJ"b_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}
