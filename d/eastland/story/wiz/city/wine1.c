#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��������ջ��");
	set_long( @LONG
��������ջ���ڡ����̳ǡ���˵������һ���ջ���ϰ��ƺͰ����ף���Ǯ
������ƽʱ�����൱������ͥ���У�������ϯ�������أ��������˿�������ൽ
�������̳ǡ��۹���ÿͶ���������Ʒ���������ƣ�˳������ٴ���һЩ��Ϣ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ee",
        ]) );
        set("objects", ([
           "captain":SWMOB"wiz_captain2"
        ]) );
	reset();
}
