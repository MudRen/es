#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("golden needle","�ɽٽ���");
	add ("id",({ "needle","dagger"}) );
        set_short("�ɽٽ���");
	set_long(@C_LONG
����һ�Ѵ�������ϸ�룬�����ұ���������ѣ����������β�����ò����ˡ�
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("dagger", 30,19,33);
        set( "special_things",1);
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}

