#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu amulet", "�������");
        add( "id", ({ "amulet" }) );
        set_short("tanyu amulet", "�������");
        set_long(@AAA
�������������еĻ����
AAA
        );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","light_metal");
        set("special_defense",(["cold":10,"fire":10,"electric":10]));
        set( "weight", 20 );
        set( "value", ({ 860, "silver" }) );
}
