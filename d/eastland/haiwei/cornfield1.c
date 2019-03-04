
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("����");
        set_long( @C_LONG_DESCRIPTION
�����������ں�������Ϸ��ĵ�����˴��ֽ���һƬ�����͵ĵ��ݣ���һ����
������Ĵ�ҡҷ�������˿�����һƬ��Ţ�����ڴ˴���Ҫ���С�����⽦��������š
����һ��Ƭ���е�һ��, ������һ��é�ݡ�
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/cornfield", 
                "west" :  "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield5"
           ]) );
        set("objects",([
            "rabbit":"/d/noden/elf/monster/rabbit"]));   
        reset();
}

void init()
{
      add_action("do_search","search") ;
      add_action("do_enter","enter") ;
}

int do_search(string arg)
{
    object player ;
    player = this_player() ;
    
    if(!wizardp(player)) 
        { player->set("action_points",player->query("action_points")/5+1) ;
        
         }
    write("����רע���Ѱ��ʱ��,��ͻȻʧ����һ��,�������С�\n") ;
    tell_room(this_object(),player->query("c_name")+
              "ͻȻ�������,ˤ�˸�������͡�\n",player) ;     
    if(!arg || ( arg != "é��" && arg != "reed"))
           return notify_fail("���������ң���û�з����κζ�����\n") ;
    player->set_temp("beggar_enter",1) ;
    write("����������Ҫ������ʱ������é�����ƺ��и���ڡ�\n") ;
    
    return 1 ;
}

int do_enter(string arg)
{
    if(!arg || arg!="entrance" || !this_player()->query_temp("beggar_enter"))
         return 0 ;
      
    write("����������,�ڲ���é����, һ��С������ʱӳ�����������\n\n") ;
    this_player()->delete_temp("beggar_enter") ;
    this_player()->move_player("/d/eastland/beggar/area/cross",
                   ({"","%s�Ӵ��������˽�����\n"}),) ;    
    return 1 ;
}
