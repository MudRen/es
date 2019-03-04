#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("Knight Inner room", "��ʿ��");
        set_long( @LONG_DESCRIPTION
This is the inner hall of Knight's guild. Where the important meetings
are held. To the east is the guild.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
�����ڽ�������ʿ�����ڲ�����ʿ������������ʿ�ǿ���ĵط���ֻ����ʿ
������˲��ܽ���������������һ��������ʿս������(book)�������߿��Իص�
��ʿ���ᣬ������������ʿ�Ǵ�Ÿ߼�װ���Ĵ����ҡ�
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/knight/fortress/knight_storage",
                "south" : "/d/knight/fortress/knight_shop",
                "west" : "/d/knight/fortress/knight_guild" ]) );
        set( "item_func", ([
                "book": "look_book" ]) );
        reset();
}

int look_book()
{
        int ws;

        ws = (int)this_player()->query("war_score");
        if( !ws ) write( "�㵽ĿǰΪֹ��û�н����κ�ս����\n" );
        else write( "��Ŀǰ�ۻ���ս������ " + ws + " �㡣\n" );

        return 1;
}
