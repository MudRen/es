#include <mudlib.h>

inherit ROOM;
inherit SELLER;

void create()
{       
        ::create();
        set_short("shop", "ҩ��");
        set_long( " no describe\n",
        "����һ��ҩ�꣡�����ڵƺڻ�Ŀ�����һ���ˣ�ֻ��Լ����ǽ����һ����Ӱ��\n"
        "������һ����ҽ�߱ر�������, ����Բο�����ǽ�ϵ�Ŀ¼(menu)��\n"
        );
        
        set("objects", ([
            "jack" : "/d/healer/building/monsters/jack"
        ]) );
        set( "light", 1 );
        set( "item_func", (["menu" : "show_menu"]) );
        set_inventory( ({
                ({"/d/healer/building/weapons/scalpel",5,5}),
        }) );
        reset();
}

void reset()
{
     room::reset();
     seller::reset();
     return;
}

int do_buy(string arg)
{
    if (this_player()->query("class") != "healer")
        return notify_fail("�Բ�������ֻ��ҽ�������⣬����ذ�!\n");
    return ::do_buy(arg);
}
