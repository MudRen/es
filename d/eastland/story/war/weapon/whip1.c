#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "Raingod's whip", "�����" );
    add( "id", ({ "whip" }) );
    set_short( "�����" );
    set_long(@LONG
һ��������ʮ�ߵı��ӣ��������������ͻ�����Ĵ̡�
LONG
    );
    set( "unit", "��" );
    set( "weight", 50 );
    set( "value", ({ 1000, "silver" }) );
    setup_weapon("whip", 30,13,22);
}
