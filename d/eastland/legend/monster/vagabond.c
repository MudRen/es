#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "vagabond","�о���å" );
	set_short( "�о���å" );
	set_long(@C_LONG
һ�������������µ���������ֻ���۸�һЩ���Ҹ�Ů�����������С��һ�㣬��Ҫ
��������
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set( "killer",1);
        set("alignment",-50);
        set_perm_stat( "str", 10 );
        set_perm_stat( "dex", 10 );
        set( "unit", "��" );
        set_natural_armor(50,1);
        set_natural_weapon( 15,10,18 );
}
