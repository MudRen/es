#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
	set_level(10);
	set_name( "cricket", "��" );
        add ("id", ({ "cricket" }) );
        set_short( "��" );
	set_long(@C_LONG
һֻ�������е����档
C_LONG
	);
	set_perm_stat( "str", 8 );
	set_perm_stat( "dex", 8 );
	set_natural_armor(10,4);
	set( "unit", "ֻ" );
	set_natural_weapon( 13,8,15 );
	set_c_verbs( ({ "%s����������%s"}) );
	set_c_limbs( ({ "ͷ��", "�ز�", "����" }) );
}
