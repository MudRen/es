#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("ice-ghost","����");
	add ("id",({ "dagger","ghost","ice"}) );
        set_short("����");
	set_long(@C_LONG
����һ��ǧ�꺮���ľ�������Ȼ����Բ����δ������ĥ�������������ˣ�����͸��
���ǿ����  
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("dagger", 20,13,20);
        set( "special_things",1);
	set( "weight", 50 );
	set( "value", ({ 1000, "silver" }) );
}

