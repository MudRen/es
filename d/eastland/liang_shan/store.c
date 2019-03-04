//#pragma save_binary

#include "takeda.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "�̵�" );
	set_long(
		"������ɽ�����Ҳ��Ψһ��һ���̵꣬�Ƕ������õ�ʱǨ���ʵ�\n"
		"����Ϊ���������ҪĿ���������Լ�͵�����ã�Ϊ�������˿ͣ������\n"
		"��Ʒ�۸񷴶��ر𹫵���Ҳ����Ϊ��ˣ���ɽ����ǿ������춽�������\n"
		"�ٵ������ڴ˼�����������½�ܵ���Ŀ���Ҳ���������ѹ����˵���Ʒ\n"
		"��\n"
	);
	
	set( "exits", ([ "west" : TROOM"path2" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"owner" : "/d/noden/farwind/monster/shopowner",
		"shi" : TMONSTER"shi",
	]) );
	reset();
}

int clean_up() { return 0; }