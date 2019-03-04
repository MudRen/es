#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "gem necklace","琉璃珠项□" );
        add( "id", ({ "necklace" }) );
        set_short( "琉璃珠项□");
        set_long(@long
由一颗颗反覆烧制而成的琉璃珠所串成的项□，非常名贵。在这串项□上闪烁著一
闪闪的光芒，把全室照著通亮。
long    );
        set( "unit", "串" );
        set( "weight", 30 );
        set( "type", "misc" );
        set( "material", "element");
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
        set( "equip_func","equip_cloth");
        set( "unequip_func","unequip_cloth" );
        set("extra_stats",(["str":-1]));
                 
}
int equip_cloth()
{
    set("light",1);
    return 1;
}
int unequip_cloth()
{
    set("light",0);
    return 1;
}
