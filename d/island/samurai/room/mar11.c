//#pragma save_binary

#include <mercury.h>
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Small Shop", "С�̵�" );
	set_long(@AAA
����һ��СС�����۵������̵꣬�����ṩ�����������Ĺ��ܣ����
������һ����Ʒ�ļ۸���ֻ�ܿ���ľ����������ˣ����ﲻ�ṩ�����
����
AAA
	);
	
	set( "exits", ([ "west" : MR"mar08" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
}

