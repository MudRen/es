#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "katana", "������" );
        set_short( "������" );
	set_long(@C_LONG
����һ�Ѻ�����ϲ���õ�����, ���������״������Χ�������,һ��С�ı�����
����ɨ���ͷ�������, ����Ϊ�������Ϻ��Ἰ���������Ĵ���,�������ʺ�ɱ����
��սʿ�õġ� 
C_LONG	
	);
	set( "unit", "��" );
	set( "weight", 40 );
	setup_weapon("longblade",25,15,20);
	set( "value", ({ 1200, "silver" }) );
}

