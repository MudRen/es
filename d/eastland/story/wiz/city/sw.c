#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ϴ��");
	set_long( @LONG
���������ڡ����̳ǡ����ϴ���ϣ���������߷������죬������������֣�
������ͨ�����ſڡ��������ϴ���ϻ�������ɫ����Ľ������Ϊ�����Զ��
���ٵ�̨Σ¥�������в������ǣ�����������֣����߻��ӣ��ΰ��������ǡ�  
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ss",
       	   "north" : SCITY"ws",
        ]) );
	reset();
}
