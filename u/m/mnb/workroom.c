#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
        set_short( "��ѻ��С����" );
        set_long(
                "���Ǻ�ѻ������Ů��˯���ĵط�,���ԡ�����û���¿ɱ����Ŷ��\n"
	);
        set( "light",1 );

        set( "exits", ([

                "guild" : "/d/wiz/wiz_hall",
        ]) );
     reset();
}

