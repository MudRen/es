#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("˽��");
    set_long(@LONG
�����ħ���һ���˿���˽�ӣ�Ŀ�����Խ���ѧ������ȡ���˵����
������Ȼһ���˰�С���͵�˽������ѧ�ʵķ�������ʢ������Ǯ�˼���ϣ��
�Լ����ӵ��ܶ��ñȱ��˶࣬�����Լ����ڱ�����ǰ̧����ͷ����˱�Ѻ�
����˽���ͣ����ڿΡ�����ְҵҲ��˵��Դ����ȥ��
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway1"]) );
    set("objects",([
        "teacher":TMOB"teacher",
        "student#4":TMOB"student",
        "student#3":TMOB"student",
        "student#2":TMOB"student1",
        "student#1":TMOB"student1"]) );
    reset();
#include <replace_room.h>
}
