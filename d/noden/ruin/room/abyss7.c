// abyss7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("ڤ���й�");
    set_long(@C_LONG
������ڤ�����й���������ɭ�ֲ�֮�����һ�ء��㲻�������Լ���ǰ;
������������Ϊ�⿴����Ĳ��ã���֪������������Ǹ�ϲ�������µ����ļ�
������ö�����һ���ĺ��ˣ������뿪����Ļ��ᡣ
C_LONG
    );
    set("light", 1);
    set("objects", (["archfiend" : MOB"archfiend"]) );

    reset();
}
 
