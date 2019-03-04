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
    "north" : "/u/b/boss/demogorgon/demogorgon.c",
    "up"  : "/u/b/boss/workroom.c",  
        ]) );
        set( "item_func", ([ 
                "menu" : "show_menu" ]) );
        set_inventory( ({
                ({ "/d/island/hole/armor/amulet3", 10, 10 }),
                ({ "/d/island/hole/armor/arms1", 10, 10 }),
                ({ "/d/island/hole/armor/cloak1", 10, 10 }),
                ({ "/d/eastland/saulin_temple/obj/seed.c", 1000, 1000 }),
                ({ "/d/deathland/object/blueapple", 1000, 1000 }),
                ({ "/d/eastland/liang_shan/obj/snow_lily", 1000, 1000 }),
                ({ "/d/island/hole/armor/plate2", 10, 10 }),
                ({ "/d/island/hole/armor/helmet1", 10, 10 }),
                ({ "/d/island/hole/armor/shield2", 10, 10 }),
                ({ "/d/island/hole/armor/tail2", 10, 10 }),
                ({ "/d/island/hole/armor/ring1", 10, 10 }),
                ({ "/d/island/hole/armor/amulet4", 10, 10 }),
                ({ "/d/knight/fortress/weapons/battleaxe", 3, 3 }),
                ({ "/d/knight/fortress/weapons/waraxe", 5, 5 }),
                ({ "/d/knight/fortress/weapons/longsword", 10, 10 }),
                ({ "/d/knight/fortress/weapons/shortsword", 15, 15 }),
                ({ "/d/knight/fortress/armors/chainmail", 10, 10 }),
                ({ "/d/knight/fortress/armors/shield", 10, 10 }),
        }) );
        reset();
}

void reset()
{
        room::reset();
        seller::reset();
}
