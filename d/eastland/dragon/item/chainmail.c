#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult chainmail", "���ء���");
        add( "id", ({ "mail","chainmail" }) );
        set_short("���ء���");
        set_long("���ء���\n");
        set("unit","��");
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 25 );
        set( "defense_bonus", 0 );
        set( "weight", 200 );
        set( "value", ({ 200, "gold" }) );
}