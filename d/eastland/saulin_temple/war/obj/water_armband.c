
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("shell armband", "��ױۻ�");
        add( "id", ({"armband" }) );
        set_short("��ױۻ�");
        set_long(
                "����һ�����ڹ�׿����ɵıۻ����������̵����ÿ��ġ�\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "stone" );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 670, "silver" }) );
}
