#include "oldcat.h"

inherit ROOM;

int be_searched;
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
     "northwest" : ONEW"wild10",
     "northeast" : ONEW"wild16" ]) );
set("item_desc",([
    "moss":"@@look_moss",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    "moss":"@@to_search_moss"
    ]) );
set_outside("eastland");
reset();
}

string look_moss()
{
  if (!this_player()->query_temp("r/check"))
    return "���뿴ʲ�� ?\n";
  return "һƬ����ɫ��̦޺��̦޺���ƺ��������⡣\n";
}

string to_search_here()
{
  string str;
  str="����������ط���ʱ��,�㷢����Ƭ̦޺(moss)�����������⡣\n";
  this_player()->set_temp("r/check",1);
  return str;
}

int to_search_moss()
{
    object ob1;

    if (!this_player()->query_temp("r/check"))
       return 0;
    if (be_searched!=0)
    { write(
        "��û���ҵ��κζ�����\n");
      return 1;
    };
    tell_room(this_object(),
         "�㷭��̦޺��������һ����ɫ�ɿ���\n"
         );
    this_player()->delete_temp("r/check");
    be_searched=1;
    ob1=new(OOBJ"r_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_searched=0;
}
