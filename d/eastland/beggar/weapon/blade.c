#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "bone blade", "�ǵ�" );
        set_short( "�ǵ�" );
        add ("id", ({ "blade",}) );
	set_long(@C_LONG
�ǵ��ǲ�ȡ�������Ϲ������������ɵ�, ��Ȼ���, �����Ǻܼ���ġ�
C_LONG	
	);
	set( "unit", "��" );
	set( "weight", 100 );
	setup_weapon("longblade",15,13,18);
        set( "value", ({ 400, "silver" }) );
}

