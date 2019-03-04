#include <../takeda.h>

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "vendor", "��ɽ������" );
	set_short( "��ɽ������" );
	set_long(@C_LONG
�㿴��һ��ȫ����µľ�װ���ӣ����ϱ���һ���󲼰�����������ò������
��Ϊ����һ�����ˣ�����Ҳ��\ֻ�й�ȥ�����й� price ���²���֤������뷨
C_LONG
	);
	set( "race", "drow" );
	set( "gender", "male" );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "kar", 9 );
	set_skill( "dodge", 70 );
	set("player_invisible",1);
	set("max_fp",250);
	set("force_points",250);
	set_natural_weapon( 30, 20, 30 );
	set( "wealth/silver", 200 );
	set( "shop_name", "vendor" );
	set_inventory( ({
//		({ "/d/eastland/liang_shan/obj/flag", 2, 2 }),
		({ "/obj/bandages", 8, 8 }),
	        ({ "/d/thief/hall/misc/bag", 1, 1}),
	        
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