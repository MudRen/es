#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
����ɽ��������Զ���ǲ��͵��壬����һĻĻ���̲���ס��������졣���ߵ�
����һ��ãã�ĶϹȣ�Ҳ��֪���ж�������ڶϹ�����һ�����š�̧ͷһ����ͷ
�ϵİ���ֻ�����붥����߶ȣ�����һ����ɫ�ı��ӣ���Ҫѹ���������ڶ�������
��������᫵�С·����˵�������ɴ�ͨ�����̹���
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "ned"}) );
	set( "exits", ([ 
       	     "northeastdown" : SAREA"wiz2",
                       "ned" : SAREA"wiz2",
                      "west" : SAREA"bridge2"
        ]) );
	set("exit",({"west"}));
	reset();
}
