#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("���ʦ��ۡ");
	set_long( @LONG
�����ǡ��׳ǹ�������ʦ��ס�Ĺ�ۡ����ۡ����������������춥���ʱ����
����������ɺ�����ξߣ�ǰ��һ�Ż�������������˿������磬�˵���һ�����
��������̻ԻͲ��ɶ���Ա߸���������ͨ�����á�
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "out" : SCITY"ne1"
        ]) );
        set( "objects", ([
           "elder" : SWMOB"wiz_elder1",
        ]) );
	reset();
}
