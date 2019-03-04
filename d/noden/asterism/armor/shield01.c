#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name( "shield of Alaits", "阿莱特斯之盾");
        add( "id", ({ "shield" }) );
        set_short( "阿莱特斯之盾");
        set_long(
           "矮人皇室阿莱斯特家族传家的盾牌,盾上还刻了两只雄壮的狮鹫兽。\n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 10 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set("special_defense",
              (["evil":10,"fire":10,"cold":10]) );
        set( "value", ({ 250, "gold" }) );
        
}






