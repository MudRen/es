#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "������" );
	set_long(
@LONG_DESCRIPTION
���޷������������������ģ�һ������������ɫ�Ĺ�ԵĹ�������������
ɺ����ɣ���һ�ſ����������������ɵĽ����ϣ��ݶ�����Ƭ��ʵ�Ǻ��񣬹�
�����Ե����ӿ������ĸ��������۾�������ɫ����ʯ����������һ������
����д������������
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"well4",
	     "north" : OTEMP"palace2",
	]) );
        set("objects", ([
            "fish_soldier#1":OMONSTER"fish_soldier",
            "fish_soldier#2":OMONSTER"fish_soldier"
            ]) );
        set("light",1);
        reset();
}
