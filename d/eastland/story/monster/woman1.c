#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "wing woman", "��������" );
	add( "id", ({ "woman" }) );
	set_short( "��������" );
	set_long(@C_LONG
һλ���͵����������Ů�ӣ�������æ������ղ������������ѡ�
C_LONG
        );
        set( "race","����" );
	set( "gender", "female" );
	set( "alignment", 100 );
        set_natural_armor(50,2);
        set_natural_weapon( 17,9,10 );
}
