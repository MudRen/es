#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("fur cloak", "��Ƥ����");
        add( "id", ({ "cloak" }) );
        set_short( "��Ƥ����" );
        set_long(
                "���Ǿ�������Ƥ�����Ƴɵ����硣\n"
        );
        set( "unit", "��");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set( "weight", 40 );
        set( "value", ({ 280, "silver" }) );
}
