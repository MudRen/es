#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
����һ�䲻���ķ��ӣ����ӵı��߷���һ�Ŵ�ͨ�̣��������������
��\��ʮ�����ޱ��������ǽ�ڿ������߲�������Ӧ����һ�γ��õ������ˣ�
������Ȼ�Ͼɵ�ȴһ����Ⱦ���ɴ˿�֪����ɮ�ɼ�֮�ϣ��˴���Сɳ�ּ�֪
��ɮ�ķ��䡣   
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
    set("objects",([
	"monka" : SAULIN_MONSTER"little_monk",
	"monkb" : SAULIN_MONSTER"little_monk",
        "monkc" : SAULIN_MONSTER"greet_monk",
        "monkd" : SAULIN_MONSTER"greet_monk",
    ]) );
	set("exits", ([
		"east" : SAULIN"stone_path0",
	]) );
	reset();	
#include <replace_room.h>
}
