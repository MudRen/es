#include "../oldcat.h"

inherit ROOM;
string str1 ="������һ����ͨ������ס������һ��֧������������ϵ���һ��ʨ�ӵ�ͷ������\n����һ��¹Ƥ�������������������˶����Ի������еġ�\n";
string str2 ="������и�������üͷ��������ͷ�����������������⣬����Ϊ��ʲ�����ڷ��ա�\n";

void create()
{
	::create();
set_short("����");
set("long","@@query_look" );
set( "exits", ([
     "out" : OGROUP"warea4"
     ]) );
set( "objects", ([
     "wman" : OMONSTER"wman"
     ]) );
set("light",1);
reset();
}

string query_look()
{
  if (present("the young man"))
    return str1+str2;
  return str1;
}
