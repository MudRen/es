
#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name( "occult club", "���ع�" );
        add( "id",({ "club" }) );
        set_short( "���ع�" );
        set_long(
            "���������������ľ�����ӵ�о�����ƥӲ�ȡ�\n"
        );
        set("layuter_club",1);
        set( "unit", "��");
        set( "weight", 400 );
        set( "value", ({ 0, "gold" }) );
}
