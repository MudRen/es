#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside","dgnisld") ;
	set_short( "cellar",  "�ض�" );
	set_long(
	    "A mired swamp, You feel watery here. You can see a broad area\n"
	"of swamp. There is a hole on the ground, and a mired atair to down.\n"
	"The feeling here is very bad.\n",
            "��Ţ������ʮ����Ţ����о�������һƬ�ܴ��ʪ�أ�С�ı�������\n"
        " �ӣ��ǽ���Ҫ������ġ�������һ�����µ�¥�ݣ�����������������ġ�\n"
        );
               
        set( "exits", ([  "down" : DGNISLD"swamp5-5",  ]) );
        set( "objects", ([ "mire hand 3" : DGNISLD"monster/mhand.c", ]) );
        reset();
}
