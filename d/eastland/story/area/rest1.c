#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����ͤ��");
	set_long( @LONG
����ͤ��Ϊ����ͤ�����ˡ����̹�����һ��ʦ���죬���ͺ�ۣ���ͤ��������
��ʯ���񹤾�ϸ�����������黨��ݣ�����������������µ�һͤ����ͤ������һ
���أ�ˮ����ף�����������ڣ�����һ�⡣
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	  "out" : SAREA"wiz3",
        ]) );
        set("objects", ([
           "poet#1" : SMOB"poet1",
           "poet#2" : SMOB"poet1",
           "poet#3" : SMOB"poet1",
        ]) ); 
	reset();
}
