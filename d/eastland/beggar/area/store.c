//#pragma save_binary

#include "../dony.h"
inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("�̵�");
	set_long(@C_LONG
��ӭ������н���塻���Ҳ��Ψһ���̵�,����̵����������˵��̵�֮
һ����Ȼ�����ձ�ƶ��,�������ǻ��Ǻ�������������һЩ�ճ�������Ʒ�����̵�
������˿�����(buy)����(sell)������(value)����ֻ�ǲι�(list)����,�ϰ廹
Ը�⡸��ѡ�Ϊ����������ϵĶ���,������Ҫ��������Ʒ�ø��ϰ�, ���ͻ����
����Ʒ����ȷ���ơ�
C_LONG
	);
	set( "exits", ([ "out" : DBEGGAR"east3.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
	replace_program(SHOP);
}
