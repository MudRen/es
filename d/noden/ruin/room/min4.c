// min4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����̳");
    set_long(@C_LONG
���ǰ���и�һ����â��״�ĺ�ɫ��̳����â�ǵļ�˸�����һ����ɫ��
��������̳��������������ɫ�ķ��� (alphabet) ���ƺ�����ѪͿ��ȥ�ġ���
��ϸһ������â�ǵ������ƺ��б����չ��ĺۼ���
C_LONG
    );
    set("objects", (["archbishop" : MOB"archbishop"]));
    set("exits", ([
	"north" : AREA"min5",
	"south" : AREA"min3"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]));
    reset();
}

int exits_open()
{
    if (present("archbishop",this_object()))
    {
	if (this_player()->query_temp("lilia_pass") >= 2)
	    return 0;
        write ("���˾��ס���ȥ·����˵�����Բ����ȴ��Ҳ�����ǰ�ߡ�\n");
        return 1;
    }
    else return 0;
}

