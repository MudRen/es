#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ϴ��");
	set_long( @LONG
�������ڡ����̳ǡ����ϴ���ϣ�������������������죬�����������߿ɵ�
�����ſڡ��������˼�����ǽ����ԭ����ͨ���������Ҫ�Ĵ����ȴ��ΪĳЩԵ��
���صذ����������������ϴ���ϻ�������ɫ����Ľ������Ϊ�����Զ����
�ٵ�̨Σ¥���������˴�������һ����ƽʱ���������۹��˳���
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"se",
       	    "west" : SCITY"sw",
       	   "south" : SCITY"southgate",
        ]) );
	set("objects", ([
	   "visitor":SWMOB"visitor2"
	]) );
	reset();
}
