
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("����");
        set_long( @C_LONG_DESCRIPTION
�����������ں�������Ϸ��ĵ�����˴��ֽ���һƬ�����͵ĵ��ݣ���һ����
������Ĵ�ҡҷ�������˿�����һƬ��Ţ�����ڴ˴���Ҫ���С�����⽦��������š
��
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/mroad4", 
                "south" : "/d/eastland/haiwei/cornfield1",
                "west" :  "/d/eastland/haiwei/cornfield2",
            "east" :  "/d/eastland/haiwei/cornfield3"
           ]) );
        reset();
}
