
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("the college of studing trolls' attack mode","���˹���ģʽ�о���");
  set_long(@Long
Long
,@CLong
���������һЩ����ֵֹ�ģ��(model),��һ��ѵļ�¼(notes),������������˵�
���ֹ���ģʽ������.
CLong
);

set("c_item_desc",([
    "model":"��Ҫ�Ǿ��˵�ģ��,���滭��ȫ���Ѩ��������.\n",
    "notes":"һ���������µļ�¼,û�м������ܴ������ҳ�����Ҫ����.\n",
    ]) );
set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "general":Monster"/general",
    ]) );
::reset();
#include <../replace_room.h>
}

