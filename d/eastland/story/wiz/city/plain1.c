#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long( @LONG
���ǡ����̳ǡ���Ķ�������Լ�ߡ���ʮ�߼������������߿��Խ��롸���̳�
�������ܲ�Զ�������������������֡��˼��Ƶ����ᣬ�������£���������������
����ʱ��¹���������б������ߣ��Ǹ����Եĺõط���
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"eastgate",
            "north" : SCITY"plain2",
        ]) );
        set( "pre_exit_func", ([
            "north":"do_north",
            "west":"do_west"
        ]) );
	reset();
}
int do_north()
{
    if ( ( (this_player()->query_temp("north")) > 5 ) &&
         present("crystal glass",this_player()) ) { 
       this_player()->delete_temp("north");
       return 0;
    }       
    this_player()->move_player(SCITY"plain1","SNEAK");
    this_player()->add_temp("north",1);
    return 1;
} 
int do_west()
{
    this_player()->delete_temp("north");
    return 0;
}
