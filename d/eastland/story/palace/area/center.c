#include "../../story.h"

inherit SPALACE"RR";
void create()
{
        ::create();
	set_short("�춼���");
	set_long( @LONG
�����������춼�������ġ�������ԭ������Ƭ�侫���񽨳ɵģ������ؼ�
������������ë���ɼ������˵��ڣ��������ߣ�����������գ������߲���ת���
������һ�𶦣��̻���ɽ�����֣�������צ����ʽ���������ֲ��������治�У���
��������Եø���룬�����Ѽ��������ڵ��л��п��ɫ��ʯͷ(stone)��
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e1",
           "west" : SPALACE"w1",
          "north" : SPALACE"n1",
          "south" : SPALACE"s1",
        ]) );
	set( "c_item_desc", ([
	  "stone" : @LONG
һ����������ɫ��ʯͷ��ʯͷ��д����ɫ������Ҫ����˼�������б�����(touch)�ĺۼ���

LONG
	]) );
	reset();
}
void init()
{
   add_action("do_touch","touch");
   ::init();
}
int do_touch(string arg)
{
    if ( !arg || arg !="stone" ) 
       return notify_fail("��Ҫ��ʲ�ᶫ����\n");
    write("\n\n��������һ������ɫ��ʯͷ��ֻ��һ����ɫ�Ĺ��߹ᴩ������ӣ�\n\n\n\n\n");
    this_player()->move_player("/d/noden/14,9.noden",({
         "%s�����ӱ�һ����ɫ�Ĺ��߹ᴩ��\n",
         "%s����һ����ɫ����������.\n"}),"");
    write("\n�ڰ׹�֮�ᣬ�㱻����������½��\n");
    return 1;
}