#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's amulet","护国师□符□");
        add( "id", ({ "amulet" }) );
        set_short( set_color("护国师□符□","HIY"));
        set_long(@C_LONG
一张不时闪耀著五色祥云的护符，上面有些弯弯曲曲的蝌蚪型文字。
C_LONG
        );
        set("unit","张");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 8 );
        set( "weight", 5 );
        set("special_defense",
           (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
        set( "value", ({ 5050, "silver" }) );
}



