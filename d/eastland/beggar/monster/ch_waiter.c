#include <mudlib.h>

inherit "/std/seller";
inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "merchant", "�ڵ�����" );
	set_short( "�ڵ�����" );
	set_long(@C_LONG
�ڵ�����ƽʱ��Ĳ���������������۸� ( price ) ���Ƿ���ʲ�ᶫ����
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set( "no_attack", 1 );
        set_inventory( ({
            ({ "/d/eastland/beggar/item/nest", 10, 10 }),
            ({ "/d/eastland/beggar/item/bearpalm", 5, 5 })
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