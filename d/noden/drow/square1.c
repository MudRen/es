
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
        set( "exits", ([
        "south" : "/d/noden/drow/square2",
                     ]) );
    reset();
}//end of creat
