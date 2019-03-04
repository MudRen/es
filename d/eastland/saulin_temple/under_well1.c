#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "��\����" );
       set_long( @C_LONG_DESC
����һ����\���У����ܶ���������̦�ľ��ڣ���춳��ڵ�Ǭ�ԣ�����
���׶���һ�������ѷ죬��ؾ�ˮ�Ǵ����е�ĳЩ�ѷ�����ȥ�ġ�
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"herb_field",
       ]) );
       reset();
}

void init()
{
        add_action( "explore_crack", "explore" );
        add_action( "pass_crack", "pass" );
}

int explore_crack()
{
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    tell_object(this_player(),@ALONG
��С�ĵĲ�̽���ܵľ��ڣ�����������һ���ѷ�(crack)����������
�����ĺۼ�....����\����Դ���ȥ(pass)������
ALONG
    );
    return 1;
}

int pass_crack(string arg)
{
    
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    if( !arg || arg!="crack" )    
      return notify_fail( "ͨ��ʲ�᣿\n" );
    tell_object(this_player(),
      "������һ������Ȼ�����ѷ쵽����һ���ط���\n" 
    );
    this_player()->move_player( SAULIN"under_well2", "SNEAK" );
    return 1;
}
