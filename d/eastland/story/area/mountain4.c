#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
����ɽ�������ǲ��͵��壬����һĻĻ���̲���ס��������졣���ϰ�����ͷ
��ֻ��������߶ȣ�һĨĨ������ɫ�ı��ӣ���Ҫѹ�����������ϸ��ӣ����ɽ֮
���ν���һ��Ϫ�Ⱥ�һ�����ţ���Ϫ�����������ȣ���ˢˢ����������֪�߶�����
��������һ�ζ����ˡ����㶫���Ǹ����£������ãã��һƬ��Ҳ��֪���ж���
�������ڶ����ϻ�Ư��һ�����š�
LONG
	);
        set("light",1);
	set( "exits", ([ 
              "east" : SAREA"bridge2",
       	      "west" : SAREA"bridge1",
        ]) );
        set("objects", ([
              "god":SMOB"lucky_god"
        ]) );
        set("exit",({"east","west"}));
	reset();
}
