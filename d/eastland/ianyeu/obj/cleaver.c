#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name( "cleaver", "����" );
    set_short( "����" );
	set_long(
        "����һ��ʮ����ڵľ޵�, ����ʮ�ֻ�����˭��ʹ���˵�?\n"
	);
    set( "unit", "��" );
    setup_weapon( "longblade", 20, 10, 25 );
    set( "weight", 350 );
    set( "value", ({ 3, "silver" }) );
}
