#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��������������������Ʒ�ռ���");
    set_long(@LONG
�����ǡ�������������������Ʒ�ռ��������ڵ�����������ι�״����
����ֻ�������İ������������﹤������Ϊ���еĿ��ƶ���ħ�����ð���
�Ĺ�ħ���ڿ���������˵�������������ʱ���������Եĸе���һ�ɲ���
˼�����Դ�����������Χ���ϵ�������
LONG
            );
    set("light",1);
    set("exits",(["north":CITY"pasture3"]) );
    set("objects",([
        "cow#2":TMOB"milker",
        "cow#1":TMOB"milker",
        "worker#2":TMOB"worker",
        "worker#1":TMOB"worker"]) );    
    reset();
#include <replace_room.h>
}
