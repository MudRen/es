// File: /u/l/layuter/elf/elf2.c
// Generated by Roommaker Thu Nov 11 16:10:41 1993

#include "../layuter.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("A empty room", "�����㳡");
        set_long( @LONG_DESCRIPTION
������һ���ô���ʯ��ɵĹ㳡���㳡������һ����ˮ��(fountain)
��������һ���޴�ĵ���(statue)��������м�ֻ��ƽ��(dove)��������
���м��ð�������(tree)�ߴ���ڱι��������ˡ�
LONG_DESCRIPTION
        );
        
    set("c_item_desc",([
       "fountain" : "��ˮ�ص�ˮ���峺�ֱ������Ǿ����ǵ���ҪˮԴ��\n",
       "dove" : "����һ�ְ�ɫ�����࣬������ʮ�ֵ���ѱ��\n",
       "tree" : "����������ʮ�ֵĸߴ�����������ƺ��޷�����ȥ(climb)��\n",
       "statue": @STATUE
 �������һ���޴��Ů������������·���һ����ʾ��(board)��
 ����ע�Ӵ�����ʱ���㷢����������ֺ����ر�Ǭ����      
STATUE
,
       "hand" : "���ֵ�λ��̫�ߣ��������ǿ����������\n",
       "board" : @BOARD
���Ǿ�����ػ���`ϣ��˹'���������������������ǵֿ�ħ������ԣ�
�������Ϊ�˴˴���ػ���ϣ��˹�������ǰ����ƽ���ʶ������ĸл�
֮�£������ľ����Ƕ�����������ϰ����ÿ͵�Ƣ����
BOARD
       ]));
    set("objects",([
        "little1" : "/d/noden/elf/monster/child",
        "little2" : "/d/noden/elf/monster/child",
        "dove" : "/d/noden/elf/monster/dove",
        ]));   
        set( "light", 1 );
   set( "exits", ([
        "east" : "/d/noden/elf/elf/elf1",
        "south" : "/d/noden/elf/elf/elf3",
        "north" : "/d/noden/elf/elf/elf4",
        "west" : "/d/noden/elf/elf/elf5",
     ]) );
        reset();
}

void init()
{
    add_action("do_pull","pull");
}

int do_pull(string arg)
{  
    if( !arg || arg != "hand" ) return 0;
    tell_room(this_object(),"�ذ���ͻȻ����һ���ض�,"+
        this_player()->query("c_name")+"���붴�У����ذ�ȴ���ָ̻�ԭ״��\n",
        this_player());
   this_player()->set_explore("noden#31");
   this_player()->move_player("/d/noden/elf/elf/elf35","SNEAK");
    return 1;
}