#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "fish merchant", "�㷷" );
	add( "id", ({ "merchant" }) );
	set_short( "�㷷" );
	set_long(@C_LONG
�㷷�ļ���������������ص����Ҫȥ���г���������������������·������б
б������󺹣������������ӣ��㲻�������һ�ѡ�
C_LONG
        );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
}
