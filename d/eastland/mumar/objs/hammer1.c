#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "huge hammer", "���ͷ" );
        add( "id", ({ "hammer" }) );
        set_short("���ͷ");
        set_long(
                "����һ֧�����ɲ���ֻ�Ĵ��ͷ�������൱���ء�\n"
        );
        set( "unit", "֧" );
        setup_weapon( "blunt", 25, 11, 28 );
        set( "weight", 300 );
        set( "value", ({ 50, "silver" }) );
}
