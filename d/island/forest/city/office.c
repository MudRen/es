#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("������");
    set_long(@LONG
�ſ���������ֻ��׳�����ʯʨ�ӣ��ݷ������ѱ��˲����ڴ���Ұ����
�Ϲ���д�������佫�������ĺ��ң�ԭ����������ܹ�ħ������ľ�������
��Ϊ���佫�����˿�ν��һ��֮�£�����֮�ϡ�������ǿ��ı�Ȩ������˾
���þ�η���֣�
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway3"]) );
    set("objects",([
        "general":TMOB"general"]) );
    reset();
#include <replace_room.h>
}




