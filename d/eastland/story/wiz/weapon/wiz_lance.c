#include <mudlib.h>
inherit WEAPON;
void create()
{
        set_name("king lance","����ǹ");
	add ("id",({ "lance"}) );
        set_short("����ǹ");
	set_long(@C_LONG
����ǹ�ǡ������������õ�һ����������������ʹ͸����ģ��������ԣ�������
��������ս�����𣬡����������Ѿ�����ʹ����������ˣ�����������������Ǵ�
�ڵġ�
C_LONG
	);
	set( "unit", "��" );
        set( "nosecond", 1 );
        setup_weapon("jousting", 35,10,30);
	set("no_sale",1);
	set( "weight", 250 );
	set( "value", ({ 20000, "silver" }) );
}

