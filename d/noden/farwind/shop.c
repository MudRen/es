//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("�̵�");
	set_long(@C_LONG
��ӭ����Զ�������Ҳ��Ψһ���̵꣬����̵���ð��������
���̵�֮һ����ΪԶ��������ð���߹���֮�ƣ�������ϰ��ð���ߴ�
���ش������ĸ���ϡ��ŹֵĶ����������о������̵�����˿�����
(buy)����(sell)������(value)����ֻ�ǲι�(list)���⣬�ϰ廹Ը��
����ѡ�Ϊ����������ϵĶ�����������Ҫ��������Ʒ�ø��ϰ壬����
���������Ʒ����ȷ���ơ�
C_LONG
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
	replace_program(SHOP);
}
