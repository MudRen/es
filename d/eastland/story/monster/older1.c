#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "wing older", "��������" );
	add( "id", ({ "older" }) );
	set_short( "��������" );
	set_long(@C_LONG
һλ����ܴ���������ˣ����ں�һ�Ե�����̸�졣
C_LONG
        );
        set( "race","����" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_natural_armor(65,2);
        set_natural_weapon( 25,11,25 );
}
