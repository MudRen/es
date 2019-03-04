//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�������" );
	set_long(@C_LONG
��������վ��һ�������������յĴ���֮�У������������ĳ�ְ�
�д�������ɫ��·��ʯ�Ľ��ɵģ�һЩ��ɫ��ֲ���Ư���Ļ���װ������
�����ܵ�Բ���������ǽ���ϵ������Ϊ������ͼ��������������������
һ����ҫ�۵�ˮ����(crystal ball)����춿��С���һ������ͨ���Ϸ���
ð���߹��ᡣ����������￪ʼ���ð���ó̡�
C_LONG
	);
	
	set("item_desc",([
	    "crystalball":"@@c_quests_hint",
	    "ball":"@@c_quests_hint",
	]) );
	set( "light", 1 );
	set( "exits", ([
		"up"    : "/d/adventurer/hall/adv_guild",
	    "south" : "/d/noden/farwind/area_room",
       "north" : "/d/noden/farwind/bugroom",
	]) );
	set( "pre_exit_func", ([
        "south" : "wiz_limit"
    ]) );
/*
    set( "objects", ([
    	"explore_list" : "d/noden/farwind/items/explore_list",
   	]) );
*/
   	reset();
}

int wiz_limit()
{
    if( !wizardp(this_player()) ) {
        	write("�Բ���ֻ����ʦ���ܽ�ȥ��\n");
        return 1;
    }
    return 0;
}

void init()
{
     add_action("to_listen","listen");
}

string c_quests_hint()
{
   "/std/fun/quests_hint"->show_all_quests();
   return "\n";
}

int to_listen(string arg)     
{
    mixed num;
    
    if( !arg ) {
       write("�����ʹ�� listen ?(number) ��ø��������.\n");       
       return 1;
    } else if( sscanf(arg,"%d",num) == 1 ) {
        if( num <= (int)QUEST_D->query_quests_number() )
        return "/std/fun/quests_hint"->show_quest(num); 
    }
    write("�����ʹ�� listen ?(number) ��ø��������.\n");
    return 1;                 
}

/*
void reset()
{
	int	i;
	object	*all_ppl;

	::reset();
	all_ppl = users();
	i = sizeof(all_ppl) - 1;
	while ( i >= 0 ) {
		call_other(	find_object_or_load("/d/noden/farwind/items/top_explore"),
					"log_player", all_ppl[i]);
		i--;
	}
}
*/
