#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��С��");
	set_long( @LONG
������ɽ�����С���ϣ�С�������м���ɽ��ɽ�أ�����Щ��Ҫ�������˺ϱ�
�Ĳ���Ĺ��������ƶ˼��ײ���ͷ��������в�ʱ�з���������ͣפ����Щ��
ľ֦������ˢ�������鼫Ϊ�������ڡ��ڵ��ϣ������黨��ܣ�����֮�����
�����˱ǣ�΢�紵������������������ˬΪ֮һ������������泩������ǻ���֮
���� 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "swu","nwd" }) );
	set( "exits", ([ 
       	     "southwestup" : SAREA"wiz1",
           "northwestdown" : SAREA"wiz3",
                     "swu" : SAREA"wiz1",
                     "nwd" : SAREA"wiz3"
        ]) );
        set("objects", ([
           "vendor":SMOB"vendor1"
        ]) );
	reset();
}
