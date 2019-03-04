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
������˲��ܽ��������������кü������ؽ����ķ�����(book)��
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
������д��һЩ�����ķ��������ѧ�Ļ������� train <��������> ѧ�á�

           ������   ����ȼ�  ������ļ���  ����������

      �δʽ���(song)     5         30            5
      ��ʫ����(tang)    10         55           10
      ��������(han)     15         80           15

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/hall" ]) );
    set_gonfus(([
          "song"        : ({  5  , 30  ,  5   }),
          "tang"        : ({  10 , 55  ,  10  }),
          "han"         : ({  15 , 80  ,  15  }),
	]));
	reset();
}
