#include "farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
   set_short( "Զ�����" );
   set_long(
@LONG
������Զ����Ψһ����꣬Ҳ������ŵ�ٴ�½��������ꡣ
����һ���˽�������е�һ���������Ϣ��������(left)�ߵ����
�ϰ���һ�ŵ�С˵������(right )������һЩ�ŵ���ѧ����顣��
���ڹ�̨(table )�ϵģ���һЩ����ĳ����鼮��
LONG
       );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz2" ,
        ]) );
        
        set_inventory( ({
                       ({ "/d/noden/farwind/items/book.c",10,10}),		       			
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "ľ��",
		     "c_desc"  : "����һ�ȿɰ���Сľ�ţ����Ϲ���һ����������",		
		     "status"  : "open",
		]) );
	set("c_item_desc",([
		"left" : 
"�㿴������Ͽտ���Ҳ��ʲ�ᶼû��...\n"
		,"table" : 
"��ֻ����һ����Ϊ���������¼�(story)�����飬����ʲ���鶼û��...\n"
		,"right" : 
"�㿴������Ͽտ���Ҳ��ʲ�ᶼû��...\n"
		])	);		 	
        set( "objects", ([
                "shop owner" : "/d/noden/farwind/monster/book_owner",
        ]) );
        reset();
}

void reset()
{
	room::reset();
	seller::reset();
}
