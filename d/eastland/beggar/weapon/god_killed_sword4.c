#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("God-killed Shortsword","���ɽ�");
	add ("id",({ "shortsword","sword","god-killed" }) );
        set_short("���ɽ�");
	set_long(@C_LONG
������ͨ���������������ɽ������һ������,����͸��һ��������⡣��˵,
��������������������ɽ�֮��,�ɼ�����������ж���������
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("shortblade", 38,28,42);
	set( "weight", 100 );
	set( "no_sale", 1);
	set( "value", ({ 10, "silver" }) );
}

