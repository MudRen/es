#include "mercury.h"

inherit MONSTER ;
inherit SELLER  ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "fruit merchant","ˮ����" );
        add ("id", ({ "merchant"}) );
        set_short( "fruit merchant","ˮ����");
        set("unit","λ");
        set_long(@ANGEL
����һ����ˮ����С���������������춼�Ǯ(price)����
ANGEL
        );
        set_inventory( ({
        ({MIT"orange", 20, 20 }),
        ({MIT"apple", 15, 15 }),
        ({MIT"lemon", 10, 10 })
        }));
        set("inquiry",([
              "price":"@@show_menu"
              ]));
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
}

void init()
{
	npc::init();
	seller::init();
}