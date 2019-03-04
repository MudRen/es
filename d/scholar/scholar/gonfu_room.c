#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
    set_short("Gonfu room", "��\����");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
���ڽ��������������ڲ��Ĺ�\���ң�������������ϰ��ĵط���ֻ������
������˲��ܽ���������������һ�������书\�ķ�����(book)��
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
������д��һЩ�书\�ķ��������ѧ�Ļ������� train <��\������> ѧ�á�

������\ �� ������\(booyi)
�Ṧ\     �� ���޲�(tanlo)
�˹�\�ķ� �� �˹�\����(force-heal)    
����     �� ��������(unknow)

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/scholar_inner" ]) );
    set_gonfus(([
          "tanlo"        : ({  3 ,  1000 }),
          "force-heal"   : ({  6 ,  3000 }),
          "booyi"        : ({  8,   8000 }),
          "unknow"       : ({ 10 , 15000 }),
	]));
	reset();
}
