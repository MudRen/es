
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "little fish", "Ư��С��" );
        set_short("Ư��С��");
        set("unit","��");
        set_long(
@C_LONG
    ����һ���ǳ��ɰ���С�㣬��������Ŀ����㡣
C_LONG
);
        set ("gender", "female");
        set( "likefish",1);
        set( "alignment", 300 );
        set_natural_weapon( 2, 1, 3 );

}
void init()
{
        add_action( "kill_me", "kill");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || ( name != "crumb") ) return 1;
{
     tell_object(me,
@CRUMB
С�㿪ʼ���ֵĳ������м.......
CRUMB
	);
		item->remove();
		this_player()->set_temp("feed_fish",1);
        return 1;
}
}