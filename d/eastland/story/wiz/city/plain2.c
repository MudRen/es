#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
��������һƬ���֦��ס�����������Ĺ��ߣ��Ե��е��������������ﲻʱ
��������������������⻹��Щ�����������С����㱱�߻��м�СС��é��(house
)����é�ݲ��������ۣ�����Խ�ȥ����(enter)���ϱ����Ƕ�����
LONG
	);
	set( "exits", ([ 
            "south" : SCITY"plain1",
        ]) );
	reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
      return notify_fail("��Ҫ��������?\n");
      this_player()->move_player(SCITY"house3",({
                     "%s������һ��Сé�ݡ�\n",
                     "%s���������˽���.\n"}),"");
      return 1;
}