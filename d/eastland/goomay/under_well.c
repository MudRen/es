#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "����" );
        set_long(
@LONG
���Ǿ����һ��С��Ѩ����ɫ�ľ���������̦���������������
����С�Ŀռ��ﾹȻ���˻�������������ǵ���������\��һЩʳ��
�Ĳ����ͻҽ���
LONG
        );
        
        set( "exits", ([
		"out"  : Goomay"ruin3",
        ]) );
        set( "objects", ([
                "prisoner" : Mob"prisoner",
		]));
        reset();
}
