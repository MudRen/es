#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult cloak", " ��������");
        add( "id", ({ "cloak" }) );
        set_short("��������");
        set_long(" ��������\n");
        set("unit","��");
        set( "type", "cloak" );
        set( "material" , "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set( "value", ({ 3000, "silver" }) );
}
