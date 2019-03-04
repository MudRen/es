//#pragma save_binary

#include "farwind.h"
#include <daemons.h>
#define BOARD FARWIND"bugsboard"

inherit ROOM ;

void create ()
{
        ::create();
        set_outside("farwind") ;
        set_short("Զ����㳡");
        set_long(@C_LONG
������������Զ����Ĺ㳡���㳡������һ������ʯ��Ȫ����Ȫ
(fountain)�Ա�����һ����¥(clock) �������ʾ��ʱ������ڡ�Զ
����Ĵ�ִ����㳡���ϱ����죬��������Զ���������΢��·��
һ����ΰ��Ӣ�ۼ����λ춹㳡�Ķ��ߡ�
C_LONG
        );
        set( "light", 1 );
        
        BOARD->frog();
        
        set ("exits", ([
                "north" : FARWIND"nmain",
                "south" : FARWIND"smain",
                "east" : FARWIND"bazz1",
                "west" : FARWIND"ebazz",
        ]) );
        set("water_source", 1);
        set("item_desc", ([
                "fountain" : "��������ʯ��Ȫ��ԴԴ������ӿ��������Ȫˮ��\n"
        ]) );
        set("item_func/clock","look_at_clock");
        set("objects", (["torch"    :FARWIND"monster/dance_torch",
                         "beggar"   :FARWIND"monster/beggar",
                         "sheriff"  :FARWIND"monster/sheriff",]) );

        reset();
}
void init()
{
	add_action("do_drink","drink");
}
int do_drink(string arg)
{
	object me;

	if(!arg || (arg!="water" && arg!="Ȫˮ")) 
            return notify_fail("��Ҫ��ʲô? \n");
        me=this_player();
	if(me->query_level()<5 || wizardp(me) )
	{
		tell_object(me,"����������Ȫ, ���˹��˺��˼���Ȫˮ.... \n"
                               "��е������泩, �ƺ������ָ���!\n");
		tell_room(this_object(), me->query("c_name") +
                 	  "���������Ȫ, ���˹��˺��˼���Ȫˮ.... \n",
			   ({me}) );
		me->set("hit_points",me->query("max_hp"));
	}
	else return notify_fail("�Բ���, ֻ�еȼ�С��5 ���˲��������ˮ!!\n");
	return 1;
}

int look_at_clock()
{
        write( WEATHER_D->query_c_game_time()+"\n" );
        return 1 ;
}
