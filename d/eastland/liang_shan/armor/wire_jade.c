#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("wire jade", "��������");
        add( "id", ({ "jade" }) );
        set_short("��������");
        set_long(
                "����һ�������ĵĹŴ�����....\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0);
        set( "defense_bonus", 7 );
        set( "special_defense",
             ([ "evil":6, "none":-6 ]) );
        set( "weight", 30 );
        set( "value", ({ 1470, "silver" }) );
}
