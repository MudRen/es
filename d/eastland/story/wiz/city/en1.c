#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڶ�����ϣ�������ϱ߷������죬��������ƥ����
�Ŀ�ȣ��������Ǳ���֡�����ֵĵ����ô���ʯ�̳ɵģ�����ĺ�Ǭ�����Դ���
���������ᣬ�����ٲȻ����˳��������ŵĵش���ԭ����������Ϊ�����Ҫ��
���Ӷ�������������ϣ��������춽ӽ������ĵ�·��ƽʱ�˳�Я���������ò���
�֡������ǳ����ĵ�·��ͨ���ʹ�����������һ���ŵ��̵ꡣ
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne1",
       	   "south" : SCITY"ee",
       	   "north" : SCITY"en2"
        ]) );
        set("objects", ([
               "vendor" : SWMOB"vendor1",
           "merchant#1" : SWMOB"merchant1",
           "merchant#2" : SWMOB"merchant2",
        ]) );
	reset();
}
