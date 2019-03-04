#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("broad_brimmed rain hat", "ÕÚÈÕºÚóèóÒ");
        add( "id", ({ "hat" }) );
        set_short( "broad_brimmed rain hat", "ÕÚÈÕºÚóèóÒ");
        set_long(
                "A broad_brimmed rain hat .\n",
                "Ò»¶¥ÕÚÑôÓÃµÄ´ó¶·óÒ£¬¿É±ÜÃâÑô¹âÖ±Éä£® \n"
        );
        set("unit","¶¥");
        set( "type", "head" );
        set( "material", "wood");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "energy":6, "fire":6]) );
        set( "weight", 40 );
        set( "value", ({ 56, "gold" }) );
}



