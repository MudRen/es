#include "forest.h"
inherit ROOM;

void create()
{
	::create();
	set_short("��ɭ��");
	set_long(@CLong
��������ɭ�ĺ�ɭ����, һ���޷����ӵ�а����Ϣ��������쳣��
�����������ﵽ�������ܳ�����Σ��, ע���������! С�Ĳ�Ҫ���˺ڰ�
�����ǵĵ��ġ�
CLong
);
	set("exits",([
			"east"	: HERE"3n1w",
			"south"	: HERE"2n2w",
    ]));
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
    set("exit_suppress", ({ "south", }) );
	reset();

}
