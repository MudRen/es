#include "ruin.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("�����ϵ�ƽ̨");
	set_long(@CLong
��ǰ�ľ�ɫ������һ��, ��վ��һ��Լ��ʮ���ߴ�ľ�����, ������
һ��������ء������︩��������, ����һƬ���̡�������ȫ����, ��
�������⻹����, ����һ����������һ�㡣����������, ������ʲ�ᶫ��
��������? Ҳ����������µ������̽̽����, Ҳû��ʲ���İ취�˰�!
����, ·��? ��������ʮ���߸�, ��ͺͺ�ľ��Ҽ�ֱ�����Լ�������������
Ц!
    ���������ԭ����С��, �����ƺ���û�������ĳ�·�ˡ�
CLong
);
	set("exits",([ "back": FOREST"3n1w",]));
	reset();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg) 
{
	if( !arg || !(arg == "here" || arg == "plate") ) return 0;
	write( "���ұ߾�Ȼ�������µ�·! ��������ϸ��������������!\n" );
   if( this_player() ) this_player()->set_explore("noden#16");
//	set("pre_exit_func", ([ "down":"go_down", ]) );
	add("exits",([ "down" : RUIN"hidden_path" ]) );
	add("exit_suppress", ({ "down", }) );
	return 1;
}

void reset()
{
	::reset();
	set("exits",([ "back": FOREST"3n1w",]));
}
