#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
        set_short("Sword room", "������");
	set_long(
@C_LONG_DESCRIPTION
���������ī���Ľ�����ϰ�Ҷ�������������������ϰ�������ĵط���ֻ������
������˲��ܽ���������������һ�����ؽ����ķ�����(book)��
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
������д��һЩ�����ķ��������ѧ�Ļ������� train <��������> ѧ�á�

����     �� �δʽ���(song) (level 5)
            ��ʫ����(tang) (level 10)
            ��������(han)  (level 15)

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/hall" ]) );
    set_gonfus(([
          "song"        : ({  5 ,    1500 }),
          "tang"        : ({  10,   10000 }),
          "han"         : ({  15,   15000 }),
	]));
	reset();
}
