#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "girl", "СŮ��" );
	set_short( "СŮ��" );
	set_long(@C_LONG
�������������������СŮ����������һ�Կ�������С�������棬һ���ֵ����ӡ�
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
        set_perm_stat( "str", 6 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(35,1);
        set_natural_weapon( 10,6,8 );
}
