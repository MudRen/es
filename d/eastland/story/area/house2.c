#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
������������С�ݣ�ƽʱ������ס�ĵط���������ľ�Ƴɵ����ӡ����Ӻ�һ��
�����Լ�һ¨¨װ�����ղ�������ɹǬ�����ѵĴ������ӡ�С����ʰ��һ����Ⱦ��
��Ȼ��Щ�򵥵İ��裬������Բ���������������˵���Ѿ��㹻�ˡ�
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"village1" 
        ]) );
        set( "objects", ([
           "older#1" : SMOB"older1",
           "older#2" : SMOB"older1",
           "older#3" : SMOB"older1",
        ]) );
	reset();
}
