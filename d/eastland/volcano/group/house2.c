#include "../oldcat.h"

inherit ROOM;
string str1="������ȫ������Ư����Ů������ס�������߽��������ŵ�һ�ɵ�������������\n���ڵĲ��������ţ����ӳ��г��������˵����ʡ�\n";
string str2="�㿴��һλŮ���ӣ��ó������㶼��������������������ȫ���δ�����궼����Ϊ׷\n��Ķ���ֻ������������˪�������е�����߽԰�����\n";
void create()
{
	::create();
    set_short("����");
	set("long","@@query_long" );
    set( "exits", ([
     "out" : OGROUP"warea6"
    ]) );
    set( "objects", ([
     "wmaid" : OMONSTER"wmaid"
    ]) );
    set("light",1);
    reset();
}

string query_long()
{
  if (present("the young lady"))
    return str1+str2;
  return str1;
}
