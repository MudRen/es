
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("���˼�̳");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
����������������Ҫ��ʥ�أ��߸ߵĴ��������֮�ǵ���㡣������
һ����ֻ���������޾��İ�������Ʈ翵ĸо����㲻���е����
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southeast" : HAWK"room3-3",
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
        int alig,lev;
        alig = (int)this_player()->query("alignment");
        lev = (int)this_player()->query_level();
        if (!present("valor amulet",this_player() ))
        {
                tell_object(this_player(),@LONG
��о�����������������Ҳң�Ѫ��ζһ����ĳ���ӿ����Ϊ��������ȫ
��������ǲ�����ȥ�����ˡ�
LONG
                );
	return 1;
        }

        if ( lev < 17 )
        {
                tell_object(this_player(),
                        "������᲻Ҫ̫�嶯���ԣ���Ҫ�����\n" );
                return 1;
        }
        if (alig < 0)
        {
                this_player()->move_player(HAWK"square1","SNEAK");
                return 1;
        }
        else
        {
                this_player()->receive_damage(70);
                this_player()->move_player(HAWK"room1-18","SNEAK");
                return 1;
        }
        return 1;
}
