#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "������" );
        set_long(
@LONG
�����Ǳ������Ķķ���ֻ����һ�����«����֮������ʮ��ʺ���
ͨ����죬������������ϴ�������������ҵ�һ齺�Ϳ����������������
������Ǯ����Ĳ�ҵ����ʵ��ȴ����ĳ����йܣ������������ż����Ǯ
��Ź��С���⣬һ��û�д󰸷��������������ǻ��Ǻ����ⳣ�������ߣ�
��������΢����нˮ��
LONG
        );
        
        set( "exits", ([
                "north" : Goomay"kwi_yi2",
		"south" : Goomay"row15",
        ]) );
        
        set( "objects", ([
                "gambler1" : Mob"gambler",
                "gambler2" : Mob"gambler",
                "gambler3" : Mob"gambler",
                "gambler4" : Mob"gambler",
                "guard1"   : Mob"body_guard",
                "guard2"   : Mob"body_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if (present("bodyguard",this_object()) && !wizardp(this_player()))
	{
		tell_object(this_player(),
		"���ڵ�������ǰ˵�������������ںȾ� !! ��ϲ�����˴��� !!��\n");
	return 1;
	}
	else
        return 0;
}
