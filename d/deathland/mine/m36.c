
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" Drawf mine ","���˿��");
  set_long(@Long
Long
,@CLong
�����ǿ�ӵ��.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ��Լ�
��ľͷ�������������ݵ��Ҷ�.�ڵ���������������.ר���˿�ͨ��ʹ��.Ȼ��
����������ľ�ͷ,ǰ���·�ƺ���һ�����ݵ�ʯ����ľͷ��ס��ȥ·.
CLong
);
set("direction","block");
set("objects",([
    "rat":Monster"/rat",
]) );
set("exits",([
             "northeast":Mine"/m23",
             ]));
#include <replace_room.h>
}
