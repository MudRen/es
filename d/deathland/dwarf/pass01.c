
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("house of truffle","ľ����ֲ��");
  set_long(@Long
Long
,@CLong
���ﵽ������һ���ŵ�ľ��,������������ľ��(truffle),һ����ζ��ʳ��.�����ǻ���
\��\�òŷ�������ֲ�ķ���,���ǰ����������������ĵص�.�ɴ˿ɼ������뿪�ر�����.
CLong
);

set("c_item_desc",([
    "truffle":"ľ��,һ����ζ��ʳ��.\n",
   ]) );
set("exits",([
     "southup":Deathland"/dwarf/pass02.c",
     ]) );
 ::reset();
#include <../replace_room.h>
}

