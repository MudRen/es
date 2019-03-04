#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Spark Leggings","ÑÅµäÄÈÉÁÁÁëÖ¼×" );
        add( "id", ({ "leggings","spark leggings" }) );
        set_short( "ÑÅµäÄÈÉÁÁÁëÖ¼×" );
        set_long(
                "Ï£À°Õ½ÉñÑÅµäÄÈ×îÏ²°®µÄëÖ¼×£¬ÉÁÉÁ·¢¹â£¬¿´À´ËÆºõ²»´í¡£\n"
        );
        set( "unit", "Ö»" );
        set("material","knight");
        set( "type", "legs" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 4700, "silver" }) );
}
