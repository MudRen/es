
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult tree", "������" );
        add( "id",({ "tree", "layuter_tree" }) );
        set_short( "������" );
        set_long(
            "����һ�û�����ʱ���ת����������֮���ƶ�������\n"
        );
        set( "unit", "��");
        set( "weight", 18000 );
        set( "value", ({ 0, "gold" }) );
}
