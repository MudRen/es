#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
����ɽ�������ǲ��͵��壬����һĻĻ���̲���ס��������졣���ϰ�����ͷ
��ֻ��������߶ȣ�һĨĨ������ɫ�ı��ӣ���Ҫѹ�����������ߵ�����һ��ãã
�Ķ��£�Ҳ��֪���ж����������������գ�Ư��һ���ķ��εĽ����
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "north" : SAREA"mountain2",
        ]) );
	reset();
}
