
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("���˼�̳");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
����������������Ҫ��ʥ�أ��߸ߵĴ��������֮�ǵ���㡣����
����������һ˿һ˿��������������µ������Ʈ��Ʈ��������һ����ֻ
���������޾�����������ɫ����������Ʈ翵ĸо����㲻���е����
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room3-7",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god" ]) );
        reset();

}//end of creat

void init()
{
        add_action("to_jump","jump");
}

int to_jump()
{
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        return 1;
}
