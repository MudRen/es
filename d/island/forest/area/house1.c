#include "../tsunami.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("ͥԺ");
    set_long(@LONG
�����Ȼ����ס����������һ����Ϊ�����ķ��ӣ�����������ƺ���ͥ
Ժ�����ӣ����ԵĻ��������ʮ�����룬�м��ɽ��С�ٲ��������˾�����
��������Ʒζ�ǳ��ǳ����ڡ���֪��������ס����ʲ���������أ�
LONG
             );
    set("exits",([
            "east":AREA"house2",
            "west":AREA"way4"]) );
    set_outside("island");
    create_door("east","west",([
         "keyword"   :  ({"Oak door","door"}),
         "status"    :"closed",
         "name"      :"oak door",
         "c_name"    :"��ľ��",
         "c_desc"    :"һ���������µ�̵���ľ��"
                ]) );
    reset();
}
