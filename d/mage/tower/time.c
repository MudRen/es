#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
        ::create();
        set_short("ʱ�����");
        set_long( @C_LONG_DESCRIPTION
һ��ȥ��ħ���ǵ�ʱ�������
C_LONG_DESCRIPTION
        );

        set( "exits", ([ 
                "west" : "/d/mage/tower/white_lib", 
                "south" : "/d/mage/tower/time1" ]) );
        create_door( "west", "east", ([
                "keyword" : ({ "rusty iron door", "iron door", "door" }),
                "name" : "rusty iron door",
                "c_name" : "��ħ��֮��",
                "c_desc" : "һ����ħ���İ�ɫ��",
                "status" : "locked",
                "lock" : "1"
        ]) );
        reset();
}
