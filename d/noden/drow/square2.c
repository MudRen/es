
inherit ROOM;

void create()
{
        ::create();
        set_short("������");
        set_long( @LONG_DESCRIPTION
�����Ǻڰ�����ʿ��ƽʱѵ���ĳ��أ�����Կ���ʮ�Ÿ�ʿ���������
�������ٿΡ�
LONG_DESCRIPTION
        );
        set( "objects", ([
		"tester" : "/d/noden/drow/mob/tester",
                        ]) );
        set( "exits", ([
                "north" : "/d/noden/drow/square1",
                     ]) );
    reset();
}//end of creat
