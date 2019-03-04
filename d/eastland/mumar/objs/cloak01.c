#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("asbestos net","石棉网");
        add("id",({"net","cloak"}) );
        set_short("石棉网");
        set_long(
"这是一件石棉网，你觉得穿上这玩意儿不会很舒服。\n"
        );
        set( "unit", "件" );
        set( "weight", 100 );
        set( "type", "cloak" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "value", ({ 1800, "silver" }) );
        set( "no_sale",1);
        set( "special_defense",(["fire":15]));
}
