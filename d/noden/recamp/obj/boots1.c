#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "peg boots","��Ь");
        add( "id", ({ "boots" }) );
        set_short("Peg boots", "��Ь");
        set_long(@AAA
����һ˫��Ь��
AAA
        );
        set( "unit", "˫"); 
        set( "type", "feet" );
        set( "armor_class", 3 );
        set("material","light_metal");
	set( "weight", 32 );
        set( "value", ({ 100, "silver" }) );
}
