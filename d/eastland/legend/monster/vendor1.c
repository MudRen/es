#include <mudlib.h>

inherit MONSTER;
inherit "/std/seller";
void create()
{
    ::create();
    set_level(6);
    set_name( "travel merchant", "��������" );
    add( "id",({"merchant"}) );
    set_short( "��������" );
    set_long(@LONG
һ���Ӷ�����½�������ˣ����ڿյ�����Ϣ����ƽʱϲ���������У��ύһЩӢ��
�ú���˳���������⡣�����Ķ������ǲ����ۣ�����Ҳ��͵�����ϣ����ԣ��ܶ���
�����������������������������Ǯ ( price ) ���Ƿ���ʲ����Ҫ�ġ�
LONG
    );
    set( "race", "human" );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set_inventory( ({
          ({ "/obj/bandage",10,10 }),
          ({ "/d/eastland/easta/obj/spicy_plaster", 10, 20 }),
          ({ "/d/eastland/easta/obj/green_pill", 10, 20 }),
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