#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ϴ��");
	set_long( @LONG
���������ڡ����̳ǡ����ϴ���ϣ���������߷������죬�������Ƕ���֡�
������ǳ��������·�Σ��˳���ӿ�����䲻���������Ҫ�����Ӷ��������
��ϴ���ǳ��������ؾ�֮�أ���������ν�������֣���ʱ��Ѳ�߲��۾�����
ά���ΰ���
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ss",
       	   "north" : SCITY"es"
        ]) );
        set("objects", ([
           "policeman#1":SWMOB"wiz_guard2",         
           "policeman#2":SWMOB"wiz_guard2",
        ]) );
	reset();
}
