#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("Princess's fan","�Ž���");
	add ("id",({ "fan"}) );
        set_short("�Ž���");
	set_long(@C_LONG
һ���Ž�Ҷ��״�����ӡ������������������֮�����Ʒ����ⱦ������һͨ��  
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("blunt", 25,13,22);
        set( "special_things",1);
	set( "weight", 80 );
	set( "value", ({ 1000, "silver" }) );
}

