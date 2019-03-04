// File: /d/noden/farwind/wedding_store.c////#pragma save_binary

#include <mudlib.h>
#include <money.h>

inherit "/std/room/room";
inherit "/std/seller";

void create()
{
	::create();
	set_short("��������");
	set_long( @LONG_DESCRIPTION
��������������, ���޷ֺŵĻ�ɴ�����,
�㿴�����ܵĳ�������һ�������������, ����
��Ҳ�ṩ����������ָ. ��������: ��������
�ϰ�������!
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/noden/farwind/ebazz" ]) );
   set( "item_func", ([
		"menu" : "show_list",
        ]) );
   set_inventory( ({
         ({ "/d/noden/farwind/wedding_obj/boys_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_pants", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_scarf", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/swallowtail", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_cape", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_lace", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_skirt", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_suit", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_flower", 5, 5 }),
     }) );
   set( "objects", ([
        "boss" : "/d/noden/farwind/monster/meph"
     ]) );
	reset();
}

int show_list()
{
   show_menu();
   write("  ����ָ (wedding ring)          5000 ����        ���޹�Ӧ\n"
	 "  ��黤��Բ�� (wedding globe)     8000 ����        ���޹�Ӧ\n");
   return 1;
}

void reset()
{
     room::reset() ;
     seller::reset() ;
   return ;
}
