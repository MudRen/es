#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڶ�����ϣ�������ϡ����߷������죬��������ƥ��
���еĿ�ȣ��������Ƕ��š�����ֵĵ����ô���ʯ�̳ɵģ�����ĺ�Ǭ�����Դ�
�����������ᣬ����ֱ���˳��������ֵĵط���ԭ����������Ϊ�����Ҫ����
�Ӷ�������������ϡ�������һ�ҿ�ջ��
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"eastgate",
       	    "west" : SCITY"wine1",
       	   "south" : SCITY"es",
       	   "north" : SCITY"en1"
        ]) );
        set( "objects", ([
           "visitor":SWMOB"visitor2"
        ]) );
	reset();
}
