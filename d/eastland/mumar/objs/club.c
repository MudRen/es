#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "club", "����" );
        add( "id", ({ "club" }) );
        set_short("����" );
        set_long(
                "����һ֧һ��Ѳ�߱��õ�ľ����\n"
        );
        set( "unit", "֧" );
        setup_weapon( "blunt", 5, 3, 6 );
        set( "weight", 60 );
        set( "value", ({ 20, "silver" }) );
}
