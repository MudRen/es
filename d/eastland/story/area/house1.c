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
       	      "west" : SAREA"village1" 
        ]) );
        set( "objects", ([
           "adult#1" : SMOB"adult1",
           "woman#1" : SMOB"woman1",
        ]) );
	reset();
}
