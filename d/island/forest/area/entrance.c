#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������ɭ�֡����");
    set_long(@LONG
ɽ�µ��·�����һ��ͨ����ͨ���ľ�ͷ�ƺ���һ��Ƭ��ɭ�֣��Ƕ����
����ð���߿��еġ�����ɭ�֡��˰ɣ������������кܶ��ð���߶���ɭ��
��һ�зǳ�����Ȥ��ħ���һ֧�ڴ˽����ᣬ�������˵ص�������Ŭ���ķ�
չ����֪��Ŀǰ��ɭ�ֱ��������أ��Ա߱����ƺ���Щ����(words)��
LONG
    );
     set("c_item_desc",([
      "words":@LONG
�����������������˴�����ħ�������Ŀǰ��ֵ����ʱ�ڣ�
���������������������ÿ���������룬��ȷ�����Ұ�ȫ����
LONG
                      ]) );
    set_outside("island");
    set("exits",([
            "north":AREA"entrance1",
            "east":AREA"gangway2",
            "west":AREA"upriver",
            "south":AREA"entrance2"]) );
     reset();
#include <replace_room.h>
}
