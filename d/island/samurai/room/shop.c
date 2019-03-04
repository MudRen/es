//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Farwind Shop", "�̵�" );
	set_long(
			"Welcome to the biggest and the only shop in Farwind. This shop\n"
        "is always full of adventuerers from everywhere. Because of this,\n"
		"the shop owner is very familar with various strange stuff from\n"
        "most adventurers. You can buy, sell, value, and list in the shop. If\n"
		"you have something that you don't know its real name, the shop\n"
        "owner would be gald to tell you its name. Just give him the item,\n"
		"and he'll tell you what you wish to know.\n",
			"��ӭ����Զ�������Ҳ��Ψһ���̵꣬����̵���ð��������\n"
		"���̵�֮һ����ΪԶ��������ð���߹���֮�ƣ�������ϰ��ð���ߴ�\n"
		"���ش������ĸ���ϡ��ŹֵĶ����������о������̵�������˿�����\n"
		"(buy)����(sell)������(value)����ֻ�ǲι�(list)���⣬�ϰ廹Ը��\n"
		"����ѡ�Ϊ����������ϵĶ�����������Ҫ��������Ʒ�ø��ϰ壬����\n"
		"���������Ʒ����ȷ���ơ�\n"
	);
	
	set( "exits", ([ "west" : FARWIND"smain" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"shop owner" : FARWIND"monster/shopowner",
		"traveller" : FARWIND"monster/traveller"
	]) );
	reset();
}

