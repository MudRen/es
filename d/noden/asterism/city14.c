// File: /d/noden/asterism/city14.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("A city road", "���д�·");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵĴ��·�ľ�ͷ,��춰��������ɵ�
�����ݼ����˵Ľ������� ,����ĵ�·ʮ�ֿ���ֱ,���ҵ�·������
��ֲ����ľ�������໥����֮��,���˺��������һ�������Ĺ�԰ .����
�Ǻܼ�̵ĳ�ǽ,��������ķ紵��ɹ֮��,��Ȼ������ҡ.�ϱ���һ����
��(tower),�������������������˹������. ���Ϸ���һ�����ⰻȻ��С
��,�ƺ�ͨ��һ���ž��ĵط���
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
	    "tower":"һ�������ĺܺ�ΰ�ĸ���.\n"
	    ]) );
	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city13",
		"southwest":ASTR"path1"
		]) );
	reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str||str!="tower") return 0;
    write("�����������.\n");
    this_player()->move_player(ASTR"tower2-1",({
               "%s����������.\n","%s���������.\n",}),"");
     return 1;
}
