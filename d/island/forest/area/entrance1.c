#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","�ӱ�");
    set_long(@LONG
չ������ǰ����һƬ���ʵ�ɽ�ڣ�ƽʱ��Զ�����ܿ��ü����Ա߻���һ
���峺��С�������������Ϊ����ϡ�ٵĹ�ϵ������С�ӻ�����ά��ԭ����
��ò��
LONG
             );
    set("exits",([
            "south":AREA"entrance",
            "west":AREA"upriver1"]) );
    set_outside("island");
     reset();
#include <replace_room.h>
}
