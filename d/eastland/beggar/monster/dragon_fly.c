#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
        ::create();
	set("lvlimit",15);
	set_level(10);
	set_name( "dragon fly", "����" );
        add ("id", ({ "dragon","fly" }) );
        set_short( "����" );
	set_long(@C_LONG
һֻ������ʳ�����档
C_LONG
	);
        set("alignment",-50);
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 10 );
	set( "unit", "ֻ" );
        set_natural_armor(10,4);
	set_natural_weapon( 15,10,18 );
	set_c_verbs( ({ "%s�ó������%s","%s����ҧ��%s" }) );
	set_c_limbs( ({ "ͷ��", "�ز�", "β��" }) );
}
