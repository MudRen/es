#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�̳�");
    set_long(@LONG
������Ľ̳��У�ֻ������½�������±����������ѵ�����ɼ���
ħ���Ƕ��ᵣ�������˺���ʿ�Ż��Ż�͵Ϯ�ˡ�    
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway2"]) );
    set("objects",([
        "soldier#2":TMOB"soldier01",
        "soldier#1":TMOB"soldier01",
        "warrior"  :TMOB"warrior01"]) );
    reset();
#include <replace_room.h>
}
