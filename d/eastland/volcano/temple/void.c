#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "The Void", "һƬ����" );
	set_long("�������ȥ�����ܾ��ǰ�ãã��һƬ���������߾����ѵ����������������� ? \n");
        set("exits",([
            "east":OTEMP"void",
            "west":OTEMP"void",
            "north":OTEMP"void",
            "south":OTEMP"void",
            ]) );
	set("light", 1);
}
