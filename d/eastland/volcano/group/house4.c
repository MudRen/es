#include "../oldcat.h"

inherit ROOM;

string str1 ="��վ��������ס�ķ����У�һ�ž޴�Ļ�Ƥ�Ͷ����޵ĽǷֱ���ڷ��ӵ�����\n����ǽ�ϣ����ϻ�����һ�ź���Ƥ������Ľ��仹��\��һЩ̴ľ�䣬��֪���Ƿ�ʲ\n�ᶫ����һ��ʯ�ΰ�\�ڷ��ݵ������롣\n";
string str2 ="������˹����������������ʯ���ϡ�\n";
string str3 ="���ĳ��ﱩ�ǰ������Ľ��Աߣ���ֻ�۾��������㡣\n";

void create()
{
	::create();
    set_short("����������");
	set("long", "@@query_look" );
set( "exits", ([
     "out" : OGROUP"warea13"
     ]) );
set( "objects", ([
     "wolf" : OMONSTER"wolf",
     "wchief" : OMONSTER"wchief"
     ]) );
set("light",1);
reset();
}

string query_look()
{
  if (present("basge")) {
    if (present("wolf"))
      return str1+str2+str3;
    return str1+str2;
  }
  return str1;
}