#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("captain's hook","̫��߮");
	add ("id",({ "hook"}) );
        set_short("̫��߮");
	set_long(@C_LONG
һ����ͭ��������Ȼ����������ĳ�������������ǰ�˷����Ѽ�����ë�Ͻ�����
�������ǰѾ�����˫�ı�����
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("thrusting", 45,28,47);
	set( "weight", 230 );
        set( "special_things",1);
	set( "nosecond",1);                                                     
	set( "value", ({ 3000, "silver" }) );
}

