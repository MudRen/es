
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("well","����");
  set_long(@Long
Long
,@CLong
һ��ǳǳ�ľ�,�������ˮҲ���Ǻ���.�������ܳ�������̦,�ƺ�����ȥ����
��һ�����ѵ���.
CLong
);

 set("objects",([
    "frog":Monster"/frog",    
 ]) );
    
::reset();
}

void init()
{
    add_action("to_climb","climb");
}

int to_climb()
{
    say(this_player()->query("c_name")+"��������\n");
    write("�����׵���������\n");
    this_player()->set_explore( "deathland#8" );
    this_player()->move_player(Deathland"/palace/pa_07","SNEAK","");
    return 1;
}
