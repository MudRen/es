#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "wing adult", "����׳��" );
	add( "id", ({ "adult" }) );
	set_short( "����׳��" );
	set_long(@C_LONG
һλ���͵�������������ӣ�������æ������ղ������������ѡ�
C_LONG
        );
        set( "race","����" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
}
