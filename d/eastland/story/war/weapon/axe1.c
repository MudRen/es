#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "large axe", "�޸�" );
    add( "id", ({ "axe" }) );
    set_short( "�޸�" );
    set_long(@LONG
һ�����صĸ�ͷ��ǰ���൱������
LONG
    );
    set( "unit", "��" ); 
    set( "weight", 150 ); 
    set( "value", ({ 1800,"silver" }) ); 
    set( "bleeding",5); 
    setup_weapon("axe", 33,23,38);
}
