#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("mahogany axe","�̹�֮��");
	add ("id",({ "axe"}) );
        set_short("�̹�֮��");
	set_long(@C_LONG
һ�ѹ��ϵ���ͭ����ľ�հ�С�����Խ�����ħ�������֮����	
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("axe", 25,18,25);
	set( "weight", 150 );
	set( "value", ({ 1430, "silver" }) );
}

