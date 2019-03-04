#include "saulin_temple.h"

inherit SELLER;
inherit ROOM;

int book_found = 0;

void create()
{
	object ob,ob2;
	::create();
	set_short("�����");
	set_long( @C_LONG_DESCRIPTION
����һ�����������󴰻��ķ��䣬���ӵ��������������¯���ϸ�
��һ���������߷�����\��Ĳ�\�ߣ���������һ��ϴ��ۣ��˴���Ӧ����
����ǧɮ�µĻ�ʳ���˿�������\����������æ���в��󷹣����󷹲�����
������������������ʹ����������������Ũ�����㿴���ſ�������ֽ
(paper) �����Ǽ�Ŀ��  
C_LONG_DESCRIPTION
	);
	set("light", 1);
	set("exits", ([
        "east"  : SAULIN"grass5",
	]) );
    set( "item_func",([ "paper" : "show_menu" ]));
    set_inventory( ({
//       ({ SAULIN_OBJ"vege_food", 10, 10 }),
       ({ SAULIN_OBJ"apple" , 5, 5 }),
       ({ SAULIN_OBJ"banana", 5, 5 }),
    }) );

        ob = new( SAULIN_MONSTER"cooking_monk" );
        ob->move( this_object() );
        ob2 = new( SAULIN_MONSTER"gin_ping" );
        ob2->move( this_object() );

	reset();	
}

void init()
{
   seller::init();
   add_action("do_search","search");
}

int do_search()
{
   object obj,obj2;
   obj = this_player();
   if ( obj->query_temp("monk_movement") && book_found == 0 &&
        obj->query_temp("book_quest/step") == 3)
   {
       tell_object(obj,@MSG1

�����˻�ͷ�ӵĻ���, �������ϸѰ��, ��Ȼ�ڽ��䷢����һ�����顣
��Ͻ�����������, �������ǣ�����Ͼ���

��������첻��������, ������ҵ���, �Ͽ�ȥ�ر�������֪����!!
MSG1
);
       obj2 = new("/d/eastland/saulin_temple/obj/sutra.c");
       obj->set_temp("book_quest/step",4);
       obj2->move(obj);
       book_found = 1;
       return 1;
   }
   return 0;
}
void reset()
{
    ::reset();
    book_found = 0;
}
