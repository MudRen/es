#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
��վ�ڸ����������ܹ�����������һƬ��ãã�ĶϹȣ���֪���ж��������
��Զ���ǲ��͵��壬һĻĻ���̲���ס����������죻̧ͷһ��������ֻ������ͷ
�����߸߶ȣ���������ɽ������˵�����̹��ɴ˶�ȥ��
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"wiz1",
       	       "west" : SAREA"mountain4",
        ]) );
        set("exit",({"east","west"}));  
	reset();
}
