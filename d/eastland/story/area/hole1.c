#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��Ѩ");
	set_long(@LONG
��������һ���ڰ��Ķ�Ѩ������ն������ƺ�û���κζ���������֮�⣬���
������ǳ������������л���Щ��ù��ζ�����������е����������������ȥ��
climb up )������ù�һ�㡣
LONG
	);
        set( "exit_suppress", ({
          "nd"}) );
	set("exits", ([
          "northdown" : SAREA"hole2",
                 "nd" : SAREA"hole2"
        ]) );
	reset();
}
void init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
   if ( !arg || arg!="up" ) return notify_fail("Syntax : <climb up> \n");
   this_player()->move_player(SAREA"plain3",({
         "%s������ȥ��\n",
         "%s���ߵ�С������������\n"}),"");
   return 1;
}