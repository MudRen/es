//#pragma save_binary

// translation done. -Elon 03-10-94 left out minor details.
#include "../moyada.h"
#include <money.h>

inherit SHOP;
inherit DOORS;

void create()
{
	::create() ;
	set("light", 1);
	set_short( "�̵�" );
	set_long( @C_LONG
��ӭ����Ħ�Ǵ������Ҳ��Ψһ���̵꣬����̵���ϰ�������Զ
���й������������﷢չ�����ԭ���Ǹ�����ʦ����������Ĳ˿�˵��
Զ������������̵��¿����ã�����ȫ���µģ��Ĵ������һ����Ⱦ��
ǽ�ϵ�ȼ�����ѻ�棬�����������ӡ�
C_LONG
);
	set( "exits", ([ 
	  "west" : MOYADA"mainrd1", 
	  "down" : MOYADA"shop/cellar",
	]) );
	
	storeroom()->set("storage", 2);
    storeroom()->set( "objects", ([
        "lamp" : "/obj/lamp",
        "bandage" : "/obj/bandage",
    ]) );
	set( "objects", ([
	    "trashcan" : "/obj/trashcan",
		"Wan Fu"  : MOYADA"monster/wanfu",
		"grey"    : MOYADA"monster/grey",
	]) );
    create_door( "west", "east", ([
	  "keyword" : ({ "wodden door", "door", }),
	  "name"    : "wodden door",
	  "c_name"  : "ľ��",
	  "c_desc"  : "���ӳ��ڵ�ľ��",
	  "status"  : "open",
	]) );
	reset();
	replace_program(SHOP);
}
