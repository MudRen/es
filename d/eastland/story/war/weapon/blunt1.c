#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "wood club", "ľ��" );
    add( "id", ({ "club" }) );
    set_short( "ľ��" );
    set_long(@LONG
һ���߳���ľ�����������һ���������ӡ�
LONG
    );
    set( "unit", "��" );
    set( "weight", 80 );
    set( "value", ({ 300, "silver" }) );
    setup_weapon("blunt", 15,5,14);
}
