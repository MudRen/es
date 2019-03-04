#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
        ::create();
        set_short("A empty room", "ħ���̵�");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
������������ħ�񹫻��ڲ���������̵꣬�������Ķ�����Ȼ���Ƕ��ã���
����춸�������������ħ����ԣ�һЩ����װ���������������ģ�����Է���
���ϵļ�Ŀ��(menu)������������Щʲ�ᡣ
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits",([
    "north" : "/u/b/boss/god/guild/god_guild.c",
    "up"  : "/u/b/boss/workroom.c",  
        ]) );
        set( "item_func", ([ 
                "menu" : "show_menu" ]) );
        set_inventory( ({
              ({ "/d/eastland/saulin_temple/obj/seed", 10,10 }),
                ({ "/d/eastland/liang_shan/obj/snow_lily", 10, 10 }),
        }) );
        reset();
}

void reset()
{
        room::reset();
        seller::reset();
}
