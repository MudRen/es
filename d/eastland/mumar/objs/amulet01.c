#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Golden Necklace","金龙项□");
        add("id",({"necklace"}) );
        set_short("金龙项□");
        set_long(
"这是一条用相当粗的金子打造成龙型的项□,看来应该值不少钱才是。\n"
        );
        set( "unit", "条" );
        set( "weight", 50 );
        set( "type", "misc" );
        set( "material", "light_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_denense", (["fire":10]));
        set( "value", ({ 2300, "silver" }) );
        set( "no_sale", 1 );
}
