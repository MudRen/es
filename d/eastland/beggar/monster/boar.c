#include "../dony.h"

inherit DMONSTER"limit"; 

void create()
{
        ::create();
	set_level(6);
	set_name( "fat boar", "Ұ��" );
        add ("id", ({ "boar","fat" }) );
        set_short( "Ұ��" );
	set_long(@C_LONG
��ͷҰ��ʵ�ں���,�ֵ��㼸����������Ϊ������������\n"
C_LONG
	);
        set("lvlimit",10);
        set("alignment",-50);
	set_perm_stat( "str", 5 );
	set_perm_stat( "dex", 2 );
        set( "race", "beast" );
	set( "unit", "ͷ" );
        set_natural_armor(2,2);
	set_natural_weapon( 9,5,8 );
	set_c_verbs( ({ "%s��ͷ�ͳ壬ײ��%s", "%s�ڵ���һ������������%s��ȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "ƨ��" }) );
}
