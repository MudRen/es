#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
������ɽ���£����ϳ����黨��ܣ��仨��֮����������˱ǣ�΢�紵����
��������������ˬΪ֮һ������������泩��Ұ�������������������������
���ò����Ƶ��߿գ��¶����У�մ��Щ��ʪ������һ��̫�࣬��һ�������
�㣬���Ǹ�����֮����·��������ͤ��һ��ʯ��(stone)�� 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	    "seu" }) );
	set( "exits", ([ 
       	  "southeastup" : SAREA"wiz2",
                  "seu" : SAREA"wiz2",
                "north" : SCITY"southgate",
                 "west" : SAREA"rest1"
        ]) );
        set("c_item_desc",([
          "stone":@LONG
ʯ���ϣ�
        ������̹����������̹������������̳ǡ����˵��˹�����
LONG
        ]) );                     
	reset();
}
