#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
������ܳ��������ι�״��ֲ������Ŀǰ�в�Ϊ��֪�ġ���Ҳ�Ѿ�
�ͻ����ˣ������������ǰ�ǿ�����£��Ĵ���������һ�������ö�������ż
�����ּ������˵����ĵ�������֪���δ�����ֿ��µĹ����أ��ϱߵĲݴ�
(thicket)���ƺ��е�Ź֣�
LONG
             );
    set("exits",([
            "north":AREA"way13"]) );
    set_outside("island");
    set("c_item_desc",(["thicket":@HOLE

           �ۣ�����ԭ������и���Ү����ſ������ȥ(enter)������

HOLE
                       ,"hole":@C_LONG
������ں�խխ�ģ��������ƺ��е����ˣ����治֪������ʲ����
C_LONG
                       ]) );
    reset();
}

void init()
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
    object victim;
    
    if( !str || str!="hole" )
         return notify_fail("��Ҫ���Ķ���\n");
         write("\n���������Щ΢�Ĳ������������л���ǰ������\n\n");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"�����������������Լ��������У�\n"
           ,this_player() );
         this_player()->move_player(AREA"hole1","SNEAK");
         tell_room( environment(this_player()),
           this_player()->query("c_name")+"�����Ľ��Լ������������˽�����\n"
           ,this_player() );
         return 1; 
}
