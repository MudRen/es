#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
��վ�ڸ����������ܹ�����������һϪ�ȣ��������ȣ���ˢˢ����������֪��
�����Σ�������һ�ζ����ˡ�������Զ���ǲ��͵��壬һĻĻ���̲���ס������
�����죻̧ͷһ��������ֻ������ͷ�����߸߶ȣ�����һ����ɫ�ı��ӣ���Ҫѹ
������
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"mountain4",
       	      "south" : SAREA"mountain2",
        ]) );
	set("exit",({"east"}));
	reset();
}
