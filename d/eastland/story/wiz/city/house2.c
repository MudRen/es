#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("˽��");
	set_long( @LONG
�����ǡ����̳ǡ�������ѧϰ֪ʶ�ĵط���˽�����������֮�⣬����ǽ����
�����м�����īɽˮ���ͼ����漣������ѧ�������۾�����ء����̻壬��ʦ����
��ش������˵�֪ʶ���ڿ����У�����Ի��Ի������������������䣬������˵�
���������������ա�
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"nw2"
        ]) );
        set("objects", ([
             "teacher":SWMOB"teacher1",
           "student#1":SWMOB"student1",
           "teacher#2":SWMOB"student1",
           "teacher#3":SWMOB"student1",
        ]) );
	reset();
}
