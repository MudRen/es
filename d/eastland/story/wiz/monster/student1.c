#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "student", "ѧ��" );
	set_short( "ѧ��" );
	set_long(@C_LONG
һ�������������ӣ������α�ר��춿����ϵ�Сѧ�ӡ�
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(25,0); 
        set_natural_weapon( 3,1,3 );
}
