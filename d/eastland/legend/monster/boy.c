#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "boy", "С�к�" );
	set_short( "С�к�" );
	set_long(@C_LONG
�������������������С�к��������ں�������С�����棬������ò����ֺ��ƺ�
������Ĵ��ڡ�
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(30,2);
        set_natural_weapon( 9,5,8 );
}
