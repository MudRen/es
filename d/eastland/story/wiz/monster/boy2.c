#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "boy", "小男孩" );
	set_short( "小男孩" );
	set_long(@C_LONG
一个居住在「巫咸城」里的小孩。他年约七、八岁，头上梳了两个ㄚ髻，一对大眼
睛骨溜溜地正围在一团游戏，活泼极了。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(25,0); 
        set_natural_weapon( 7,1,3 );
}
