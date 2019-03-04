#include "hawk.h"
#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("���ɭ��");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
���ߵ�ɭ�ֵ������������һƬ���ԲԵ�����Χ�����㣬����ܵ�һ����
����Ϣ�Ļ���������ĸ������䴫������ʱ�䣬�����������ʲ�ᣬ����˵����
��ʲ�ᡣ
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room1-16",
                        ]) );
    reset();
}//end of creat

void init()
{
        mixed *condis;
        if( !(condis = this_player()->query( "conditions/_heal_sp" ))) return 0;
        HEAL_SP->apply_effect(this_player(),condis[0]-5,condis[1]);
        add_action( "remove_sp_recover", "go" );
        add_action( "do_cast", "cast");
        add_action( "remove_sp_recover", "sneak" );
        add_action( "see_mirror","see" );
}

int see_mirror(string str)
{
        if (!str || str != "mirror") return 0;
        write ("�㷢����ľ���һƬ������ģ�ɶ��������������ǹⱻ���ָ���ס�ˡ�\n");
        return 1;
}

int do_cast()
{
        write("\n\nһ�����ص�������ֹ����������䡣\n\n\n��ľ����ɢ�ˡ�������\n");
        this_player()->set("spell_points",10);
        return 1;
}

int remove_sp_recover(string str)
{
        mixed *condis;
        condis = this_player()->query( "conditions/_heal_sp" );
        if( !str || str == "southwest" )
        {
                HEAL_SP->apply_effect( this_player(), (condis[0]+5), condis[1] );
                return 0;
        }

        return 0;
}
