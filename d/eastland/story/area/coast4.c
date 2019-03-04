#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ���ȴ����������������Ǹ߼�ͷ����ާ��ֲ������������Ҫʹ
����赹�ڵأ����������ֲ�����С�棬��ס�ض������ȫ�������ѹ��Ѽ���
�������Ҹ������ĵط���Ϣһ�£��ټ����ߣ���ù�һ�㡣��Ȼ����Զ�Ķ��ߴ�
������Ұ�޵Ľ������������������Ѽ�������ò�Ҫ���Ǳ���ȥ�����ⷢ��Σ�ա�
LONG
	);
	set("exits", ([ 
       	    "east" : SAREA"coast5", 
            "west" : SAREA"coast3",
           "south" : SAREA"coast6"
        ]) );
        set("pre_exit_func",([                                                  
	    "east" : "do_east",
	   "west"  : "do_west",
	   "south" : "do_south"
	]) );
	reset();
}
int do_east()
{
     object player;
     player=this_player();
     if ( player->query_temp("east_times")<2+random(6) ) {
         player->add_temp("east_times",1);
         player->move_player(SAREA"coast4","SNEAK");
         return 1;     
     }    
     player->set_temp("can_south",1);
     player->delete_temp("east_times");
     return 0;
}
int do_west()
{
    this_player()->delete_temp("east_times");
    this_player()->delete_temp("can_south");
    return 0;
}
int do_south()
{
    object player;
    player=this_player();
    if ( !player->query_temp("can_south") ) {
        player->move_player(SAREA"coast4","SNEAK");
        player->delete_temp("east_times");
        return 1;
    }
    player->delete_temp("can_south");
    player->delete_temp("east_times");
    return 0;
}