#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("ƫ��");
    set_long(@LONG
�����ƫ�Ҳ��ɰɴ���������޹��������˴���ֻ���������㣬�Ĵ�
�����һ����Ⱦ����춹�����Ͳ����������ֻ��һЩ��ͨ�ĳ��裻����
��Ϊ������ϲ�����飬���ǽ������϶����������顣
LONG
             );
    set("exits",([
        "north":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "sasami":TMOB"sasami"]) );
/*    create_door("north","south",([
        "keyword":({"oak door","door"}),
        "status":"closed",
        "name":"Oak door",
        "c_name":"��ľ��",
        "c_desc":"һ�Ⱥ��ؽ�ʵ���̹���������ľ��"
        ]) );*/
     reset();
}

