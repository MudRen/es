#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�Ǻ�");
    set_long(@LONG
�����һƬ��嫵��Ǻ��У����ܲ�����һ��һ����С���ǣ�����
���ڶ��������Ƶģ�����һ����ֻ������������Ĵ�½���м���˸�С
С�ĵ��죬ԭ�����������еİ�ͼ�������İ�����������ĸо���ͦ��
��ģ�ֻ�ǣ�����������ȥ�أ�
LONG
            );
    set("light",1);
    set("exits",(["northup":CITY"garden2"]) );
    set("exit_suppress",({"northup"}) );
    reset();
#include <replace_room.h>
}    