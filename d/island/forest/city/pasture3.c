#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����������������");
    set_long(@LONG
�����ǡ�����������������Ҳ��ħ�弰����������Ʒʳ�����Ҫ��Ӧ��
���������﹤������Ҫ���ǰ������ˣ������Ĵ���Ǿ�����ѡ������ţֻ
����ħ�岻�ϵĸĽ���������������������ϸ�ĵ��չ�֮�£�ÿ�춼������
�����������Թ����úͼӹ���
LONG
            );
    set_outside("island");
    set("exits",([
        "south":CITY"pasture6",
        "north":CITY"w3"]) );
    reset();
#include <replace_room.h>
}
