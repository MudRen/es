#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden pen","���");
	add ("id",({ "pen"}) );
        set_short("���");
	set_long(@C_LONG
һ֦�������ıʹܣ�ëմ��ī�������ˡ�
C_LONG
	);
	set( "unit", "֦" );
        setup_weapon("thrusting", 30,15,20);
	set( "weight", 100 );
        set("second",1);
        set( "special_things",1);
	set( "value", ({ 2500, "silver" }) );
}

