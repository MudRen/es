#include "../oldcat.h"

inherit ROOM;

string str1= "����һ�䰫������ҽ��ס��������ߵļ���һ���ƿƿ�޹޵�ҩˮ��ҩ�ۣ�\n���ߵļ�����һ����й�ҽҩ���飬�����л���һ������ӣ����������Һ��\n���ϵķ�������һ����̱ǵ�ζ����ʹ�㼸�������ٴ������\n";
string str2="�㿴��һ������ҽ���ô����������������Һ�塣\n";

void create()
{
      ::create();
      set_short( "����");
      set("long","@@query_look" );
      set( "exits", ([
         "out" : OGROUP"warea11"
       ]) );
      set( "objects", ([
        "wdoctor" : OMONSTER"wdoctor"
       ]) );
      set("light",1);
      reset();
}

string query_look()
{
  if (present("old shaman"))
    return str1+str2;
  return str1;
}
