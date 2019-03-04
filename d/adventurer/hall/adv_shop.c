#include <mudlib.h>

inherit "/std/seller";
inherit "/std/room/room";
void create()
{

	object boss;
	::create();
	set_short("ð�չ���ר����");
	set_long( @C_LONG_DESCRIPTION
��������ð���߹����ڸ����ð�չ���ר���꣬һЩ�о����ð����
�ھ��������������ᷢ�֣���һЩ���ߣ����ܹ���֤ƽ�����ð�յ���Կ
������һЩ���ð���кܴ������Ϊ�˰�������������ڹ����п�������
���꣬���������Ҫ����ȥ̽�գ��������������ǲ�������⡣
ǽ������һ�ż�Ŀ��(menu)������д��������Ʒ������ͼ۸�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_libra1",
	             "west" : "/d/adventurer/hall/adv_shop1",
	                                         ]) );
	   boss = new( "/obj/morish" );
	   boss->move( this_object() );
//	set( "objects", ([
//	             "boss" : "/u/t/takeda/morish"
//	                 ]) );
	set_inventory( ({
/*
		({ "/d/eastland/goomay/obj/travel_bag", 5, 5 }),
*/
		({ "/d/adventurer/hall/weapons/adv-blade", 5, 5 }),
		({ "/d/noden/moyada/obj/pick",2,2 }),
		({ "/d/adventurer/hall/obj/salt_bottle",20,20 }),
		({ "/d/adventurer/hall/obj/knife",5,5 }),
		({ "/d/noden/moyada/obj/shovel",2,2 }),
		({ "/d/deathland/object/broom",1,1 }),
		({ "/obj/bandages",10,10 }),
	}) );
	seller::reset();
}
void init()
{
        ::init();
        seller::init();
// add_action("dont_update", "update");
//      add_action("dont_renew", "renew");
        return ;
} 
int dont_update()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont update here\n");
        return 1;
} 
int dont_renew()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont renew here\n");
        return 1;
}               
reset()
{
	room::reset();
	seller::reset();
}
int clean_up() { return 0; }
