
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Hero","Ӣ��Ĺ��");
  set_long(@Long
�����ǰ���Ӣ�۵�Ĺ��,Ĺ���������һλ�ݺ�ɳ����Ӣ��.��һ��Ĺ���ı�����
д��: һλ���˾������޵�Ӣ��.
Long
);
set("exits",([
            "east":Deathland"/city/g6",
            "west":Deathland"/city/g8",
            "north":Deathland"/city/gb",
             ]));
set("pre_exit_func",([
    "north":"to_north",
    ]) );
    
set("objects",([
    "guard":Monster"/guard05",
    ]) );
    
reset();    
}

int to_north()
{
    if (!present("guard")) return 0;
    write("�������㵲������.\n");
    return 1;
}
