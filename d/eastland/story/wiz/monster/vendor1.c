#include "../../story.h"
inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "vendor", "·��С��" );
    set_short( "·��С��" );
    set_long(@LONG
һ�������������Ƶ�С�������������Ҫ�Ļ�����������������Ʒ��ֻҪ������Ǯ
(price)�����ͻ����㿴���Ļ������֮�⣬���ﻹ���������̹������ز�֮һ
���޵״�����֤�������⡣
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
	({ "/obj/bandage", 20, 20 }),
        ({ SWITEM"bag1", 10, 5}), 
        ({ SWITEM"crystal1",45,10 }),
    }) );
    set( "inquiry", ([
	"price" : "@@show_menu"
    ]) );
}
void init()
{
    npc::init();
    seller::init();
}

