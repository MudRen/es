#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
        ::create();
	set_level(9);
	set_name( "grey moth", "С�Ҷ�" );
        add ("id", ({ "moth","grey" }) );
        set_short( "С�Ҷ�" );
	set_long(@C_LONG
һֻ�ɲ�������С�Ҷꡣ
C_LONG
	);
        set("lvlimit",15);
        set("alignment",-50);
	set_perm_stat( "str", 8 );
	set_perm_stat( "dex", 8 );
	set( "unit", "ֻ" );
        set_natural_armor(8,4);
	set_natural_weapon( 13,8,15 );
	set_c_verbs( ({ "%s�ó������%s","%s�ó���Ļ�%s" }) );
	set_c_limbs( ({ "ͷ��", "�ز�", "����" }) );
}
	